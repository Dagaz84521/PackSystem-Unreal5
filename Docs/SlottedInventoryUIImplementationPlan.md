# Slotted Inventory UI 施工计划

本文档描述 `SlottedInventoryComponent` 的第一版可交互 UI 接下来应如何实现。

本文档不是完整 UI 设计规范，而是一份施工顺序和验收清单。每个阶段都应先形成可以编译、可以运行、可以单独验证的结果，再进入下一阶段。

相关用例定义见 [InventoryUseCases.md](InventoryUseCases.md)。界面结构参考见 [Design/SlottedInventoryUIConcept.html](Design/SlottedInventoryUIConcept.html)。

## 1. 当前状态

已经具备的部分：

- `UInventoryComponent` 提供稳定的 `FInventoryEntryHandle`，以及 `Added`、`Changed`、`Removed`、`Reset` 四类事件。
- `USlottedInventoryComponent` 使用固定 Entry 表示固定格子，并已实现拿起、放置、合并、交换和自动放回所需的库存操作。
- `UInventoryInteractionContext` 保存 Cursor Payload 和来源信息，并已实现拿起、放置与取消操作。
- `UInventorySlottedUIController` 可以绑定 Slotted Inventory，并持有唯一的 `UInventoryInteractionContext`。
- `FInventorySlottedEntryViewData` 已包含基础物品显示信息。
- `UInventorySlottedEntryWidget` 已具备 `SetViewData()` 到 `RefreshView()` 的刷新入口。
- `UInventorySlottedUIWidget` 已建立类型，但暂时没有 View 契约。

目前缺少的闭环：

```text
Inventory 数据事件
    -> UIController 生成 ViewData
    -> Panel Widget 创建或刷新 Slot Widget
    -> Slot Widget 提交点击意图
    -> UIController 调用 InteractionContext
    -> Inventory 数据发生变化
    -> UI 再次刷新
```

## 2. 本阶段目标

第一阶段只完成玩家自己的固定格背包，并实现以下能力：

1. 打开界面后显示全部格子，包括空格。
2. 非空格显示图标和数量。
3. Inventory 中的格子内容改变后，只刷新对应格子。
4. 左键点击非空格时拿起整个物品堆。
5. Cursor 持有物品时，左键点击目标格执行放置、合并或交换。
6. Cursor Payload 改变后立即刷新鼠标持有物显示。
7. UI 关闭或 Controller 重新绑定时正确解除事件绑定。

完成这些内容后，应形成从显示到交互再到数据回刷的第一个完整闭环。

## 3. 本阶段明确不做的内容

以下内容不进入第一轮施工：

- 右键拿取一半或指定数量。
- 原生 UMG Drag and Drop。
- 玩家与箱子之间的双容器交互。
- 动态扩容、缩容和格子重新排序。
- 装备槽、格子类型限制和物品过滤规则。
- 快捷栏数字键与当前选中状态。
- 耐久度、品质框和复杂 Tooltip。
- 网络同步。
- ListView、TileView 或对象池优化。

这些内容不能反向影响第一版接口，除非施工过程中发现第一版接口会阻止后续扩展。

## 4. 已确定的架构规则

### 4.1 Model 事件继续复用父类事件

保留以下四类事件，不将它们合并成一个无类型事件：

- `OnEntryAdded`
- `OnEntryChanged`
- `OnEntryRemoved`
- `OnInventoryReset`

不同库存类型对这些事件的使用方式不同：

| Inventory 类型 | Added | Changed | Removed | Reset |
| --- | --- | --- | --- | --- |
| Slotted | 初始化或格子结构变化 | 主要运行时事件 | 正常运行时通常不发生 | 重建全部格子 |
| Aggregate | 新物品堆出现 | 物品堆数量或内容改变 | 物品堆消失 | 重建全部条目 |

对于固定格 Slotted Inventory，Entry 表示格子，Payload 表示格子内容。拿起、清空、放置、合并和交换都只改变 Payload，因此正常运行时主要触发 `OnEntryChanged`。

### 4.2 Controller 负责 Model 与 ViewData 之间的转换

职责划分如下：

| 对象 | 职责 |
| --- | --- |
| `USlottedInventoryComponent` | 保存格子和物品，执行库存规则，广播数据事件 |
| `UInventoryInteractionContext` | 保存 Cursor Payload，协调拿起、放置和取消 |
| `UInventorySlottedUIController` | 监听 Model 与 View 请求，制作 ViewData，调用交互接口 |
| `UInventorySlottedUIWidget` | 管理格子视图和 Cursor 视图，向外提交用户意图 |
| `UInventorySlottedEntryWidget` | 显示单个格子，不直接读取或修改 Inventory |

Widget 不允许直接执行以下操作：

- 查询 `UInventoryComponent` 或 `FInventoryEntry`。
- 查询 `UInventoryItemDefinition` 或 Item Fragment。
- 调用库存修改接口。
- 使用可能已经过期的 ViewData 数量作为实际库存命令参数。

### 4.3 空格也是必须存在的 ViewData

Aggregate UI 可以不显示空 Entry，但 Slotted UI 必须显示每一个固定格子。

因此，`MakeSlotViewData()` 在 Entry 存在但 Payload 为空时仍然必须成功。空格 ViewData 应保留有效的 `EntryHandle` 和 `SlotIndex`，只清空物品显示字段。

### 4.4 View 只提交意图

第一版 View 只提交：

```text
玩家点击了哪个 SlotHandle
```

Controller 收到请求后重新查询 Inventory 和 InteractionContext 的当前状态，再决定拿起还是放置。这样不会把库存规则复制进 Widget。

## 5. 阶段一：修正 Slotted 初始化通知顺序

### 5.1 问题

当前注册顺序是：

```text
UInventoryComponent::OnRegister
    -> RebuildRuntimeState
    -> OnInventoryReset.Broadcast

USlottedInventoryComponent::OnRegister
    -> EnsureSlotsInitialized
    -> 缺少的每个空格分别触发 OnEntryAdded
```

这意味着 `OnInventoryReset` 广播时，Slotted Inventory 的固定格可能还没有补齐。它不符合“Reset 表示最终状态已经准备完毕”的语义。

### 5.2 目标

调整为：

```text
重建通用 Entry 运行时状态
    -> 补齐 Slotted 固定格
    -> 最后广播一次 OnInventoryReset
```

初始化补格过程不应让监听者看到一系列中间状态。

### 5.3 推荐实现方向

将父类中的“重建状态”和“发送通知”分离，或者提供受保护的批量初始化入口。不要让派生类直接操作父类的私有计数器，也不要为了绕过事件而直接向数组随意写入 Entry。

本阶段只调整初始化通知时机，不实现运行时扩容或缩容。

### 5.4 涉及文件

- `Public/Core/InventoryComponent.h`
- `Private/Core/InventoryComponent.cpp`
- `Public/Inventory/Slotted/SlottedInventoryComponent.h`
- `Private/Inventory/Slotted/SlottedInventoryComponent.cpp`

### 5.5 验收标准

- Slotted Inventory 注册完成后，Entry 数量不小于配置的 `SlotCount`。
- 初始化过程最多对外产生一次完整 Reset 通知。
- Reset 监听者在回调中能够立即读取全部固定格。
- 已存在 Entry 多于配置 SlotCount 时仍然不会静默删除物品。

## 6. 阶段二：完善 Slot ViewData

### 6.1 修改 `FInventorySlottedEntryViewData`

建议增加：

```cpp
UPROPERTY(BlueprintReadOnly)
int32 SlotIndex = INDEX_NONE;

UPROPERTY(BlueprintReadOnly)
bool bIsEmpty = true;
```

保留现有字段：

```cpp
FInventoryEntryHandle EntryHandle;
FText DisplayName;
FText Description;
int64 Quantity;
TSoftObjectPtr<UTexture2D> Icon;
```

### 6.2 字段规则

| 状态 | EntryHandle | SlotIndex | bIsEmpty | 物品显示字段 |
| --- | --- | --- | --- | --- |
| 有物品 | 有效 | 有效 | `false` | 从 Definition 和 Fragment 生成 |
| 空格 | 有效 | 有效 | `true` | 名称、说明、图标为空，数量为 0 |
| 无效输入 | 无效 | `INDEX_NONE` | `true` | 全部保持默认值 |

`SlotIndex` 表示 UI 排列位置，`EntryHandle` 表示操作目标。Widget 使用 SlotIndex 排列，但提交操作时必须使用 EntryHandle。

### 6.3 涉及文件

- `Public/UI/Slotted/InventorySlottedEntryViewData.h`

### 6.4 验收标准

- 空格和非空格都能构造合法 ViewData。
- ViewData 不包含 `FInventoryEntry`、Payload 或 Inventory 指针。
- Widget 不需要访问 Item Definition 就能完成第一版显示。

## 7. 阶段三：定义 Slotted Panel View 契约

### 7.1 修改 `UInventorySlottedUIWidget`

参考 Aggregate Panel 的形式，为 Slotted Panel 增加 Blueprint 可实现的显示入口：

```cpp
UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Inventory|UI")
void RebuildSlots(const TArray<FInventorySlottedEntryViewData>& Slots);

UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Inventory|UI")
void UpdateSlot(const FInventorySlottedEntryViewData& SlotData);
```

第一版不需要 `AddSlot` 和 `RemoveSlot`。固定格布局发生结构变化时直接调用 `RebuildSlots()`，普通 Payload 变化调用 `UpdateSlot()`。

### 7.2 增加点击请求

建议声明：

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE_OneParam(
    FInventorySlotClickedSignature,
    FInventoryEntryHandle,
    SlotHandle);
```

Panel 对外提供：

```cpp
UPROPERTY(BlueprintAssignable, Category = "Inventory|UI")
FInventorySlotClickedSignature OnSlotClicked;

UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
void RequestSlotClick(const FInventoryEntryHandle& SlotHandle);
```

`RequestSlotClick()` 只检查 Handle 是否已设置，然后广播意图，不执行库存操作。

### 7.3 Cursor View 契约

增加独立的 Cursor ViewData，例如：

```cpp
USTRUCT(BlueprintType)
struct FInventoryCursorViewData
{
    GENERATED_BODY()

    UPROPERTY(BlueprintReadOnly)
    bool bIsVisible = false;

    UPROPERTY(BlueprintReadOnly)
    FText DisplayName;

    UPROPERTY(BlueprintReadOnly)
    int64 Quantity = 0;

    UPROPERTY(BlueprintReadOnly)
    TSoftObjectPtr<UTexture2D> Icon;
};
```

Panel 增加：

```cpp
UFUNCTION(BlueprintImplementableEvent, BlueprintCallable, Category = "Inventory|UI")
void SetCursorViewData(const FInventoryCursorViewData& CursorData);
```

Cursor ViewData 不应伪装成 Slot ViewData，因为 Cursor 没有 SlotIndex，也不对应当前目标 Entry。

### 7.4 涉及文件

- `Public/UI/Slotted/InventorySlottedUIWidget.h`
- `Private/UI/Slotted/InventorySlottedUIWidget.cpp`
- 新增 `Public/UI/Slotted/InventoryCursorViewData.h`

### 7.5 验收标准

- C++ Controller 可以命令 Blueprint Panel 重建全部格子。
- C++ Controller 可以命令 Blueprint Panel 更新单个格子。
- Blueprint Panel 可以将 SlotHandle 点击请求提交给 Controller。
- Panel 不持有 InventoryComponent。

## 8. 阶段四：完成 Slotted UIController

### 8.1 绑定 Inventory 与 View

将初始化入口改为同时接收 Inventory 和 View：

```cpp
UFUNCTION(BlueprintCallable, Category = "Inventory|UI")
void Initialize(
    USlottedInventoryComponent* InInventory,
    UInventorySlottedUIWidget* InView);
```

初始化顺序：

1. 调用 `Shutdown()` 解除旧绑定。
2. 验证 Inventory 和 View。
3. 保存 View。
4. 调用 `BindInventory()`。
5. 确保 InteractionContext 存在。
6. 绑定 View 的 `OnSlotClicked`。
7. 绑定 InteractionContext 的 `OnHeldPayloadChanged`。
8. 调用 `RefreshAllSlots()`。
9. 调用 `RefreshCursor()`。

任一步失败都应保持明确的未绑定状态，不能留下只绑定了部分事件的 Controller。

### 8.2 制作 Slot ViewData

增加：

```cpp
bool MakeSlotViewData(
    int32 SlotIndex,
    FInventorySlottedEntryViewData& OutViewData) const;
```

推荐输入 SlotIndex，而不是只输入 Handle，因为 Slotted ViewData 必须包含排列位置。函数内部通过 `GetSlotHandle(SlotIndex)` 和 `GetEntry()` 获取当前数据。

转换规则：

1. 先将 `OutViewData` 重置为默认值。
2. 验证 Inventory、SlotIndex 和 EntryHandle。
3. 写入 SlotIndex 与 EntryHandle。
4. Payload 为空时写入 `bIsEmpty = true` 并返回成功。
5. Payload 有效时写入 Definition 提供的名称、说明、数量。
6. Icon Fragment 是可选数据；缺少图标不能导致转换失败。
7. Payload 畸形时返回失败，并触发诊断信息，不把它表现成普通空格。

### 8.3 完整刷新

增加：

```cpp
void RefreshAllSlots();
```

流程：

```text
读取 SlotCount
    -> 依次用 SlotIndex 构造 ViewData
    -> 保持 SlotIndex 顺序写入数组
    -> View->RebuildSlots
```

不要使用“只收集有效物品”的 Aggregate 逻辑。Slotted 数组长度应与 SlotCount 一致。

### 8.4 单格刷新

覆写：

```cpp
virtual void InventoryEntryChanged(
    const FInventoryEntryHandle& EntryHandle) override;
```

Controller 需要找到该 Handle 当前对应的 SlotIndex。推荐在 `USlottedInventoryComponent` 增加明确查询接口：

```cpp
UFUNCTION(BlueprintPure, Category = "Inventory|Slotted")
int32 FindSlotIndex(const FInventoryEntryHandle& SlotHandle) const;
```

不要让 UIController 直接访问 `EntryArray`。

找到后生成最新 ViewData，并调用 `View->UpdateSlot()`。

### 8.5 其他 Inventory 事件

第一版处理策略：

```text
Added   -> RefreshAllSlots
Changed -> 只刷新对应 Slot
Removed -> RefreshAllSlots
Reset   -> RefreshAllSlots
```

Added 和 Removed 在固定格正常运行时不应频繁出现，因此直接完整重建比维护复杂增量逻辑更稳妥。

### 8.6 点击处理

增加：

```cpp
UFUNCTION()
void HandleSlotClicked(FInventoryEntryHandle SlotHandle);
```

处理流程：

```text
验证 View、Inventory、Context 和 SlotHandle
    |
    +-- Context 正在持有物品
    |       -> PlaceHeldItemAtSlot(SlotHandle)
    |
    +-- Context 没有持有物品
            -> 重新查询该 Entry
            -> 空格：不操作
            -> 非空：TakeItemFromSlot(SlotHandle, Entry.Payload.Quantity)
```

第一版点击拿起整个堆叠。Controller 必须在点击发生时重新查询 Quantity，不能使用 Widget 中可能过期的 ViewData。

库存操作完成后不手动修改 Slot Widget；Inventory 的 `OnEntryChanged` 会驱动格子刷新，InteractionContext 的事件会驱动 Cursor 刷新。

### 8.7 Cursor 刷新

增加：

```cpp
UFUNCTION()
void HandleHeldPayloadChanged();

void RefreshCursor();

bool MakeCursorViewData(
    FInventoryCursorViewData& OutViewData) const;
```

Context 没有持有物品时仍然向 View 发送默认 Cursor ViewData，以确保旧显示被隐藏。

### 8.8 Shutdown

`Shutdown()` 必须按以下顺序清理：

1. 从 View 解除 `OnSlotClicked`。
2. 从 InteractionContext 解除 `OnHeldPayloadChanged`。
3. 清除 View 引用。
4. 调用 `Super::Shutdown()` 解除 Inventory 事件。

`Shutdown()` 不清空 InteractionContext，也不静默销毁 Held Payload。关闭界面时如何取消或保留 Cursor 属于更高层生命周期规则。

### 8.9 涉及文件

- `Public/UI/Slotted/InventorySlottedUIController.h`
- `Private/UI/Slotted/InventorySlottedUIController.cpp`
- `Public/Inventory/Slotted/SlottedInventoryComponent.h`
- `Private/Inventory/Slotted/SlottedInventoryComponent.cpp`

### 8.10 验收标准

- Initialize 后立刻显示完整格子布局。
- 修改一个格子的 Payload 时只调用一次单格刷新。
- 点击空格不会产生库存变化。
- 点击非空格可以拿起完整物品堆。
- Cursor 非空时点击目标格可以放置、合并或交换。
- 失败操作不会吞掉 Cursor Payload。
- Shutdown 后旧 View 和旧 Inventory 不再收到 Controller 回调。

## 9. 阶段五：实现 Slot Widget Blueprint

### 9.1 创建 Widget Blueprint

创建：

```text
WBP_InventorySlot
Parent Class: UInventorySlottedEntryWidget
```

建议的最小层级：

```text
Button_Slot
└── Overlay
    ├── Image_Icon
    ├── Text_Quantity
    └── Border_Selected
```

第一版可以不实现 Selected，保留节点即可。

### 9.2 实现 `RefreshView`

空格：

- 隐藏 Item Icon。
- 隐藏 Quantity。
- 保留 Button 和格子背景。
- 清除旧 Tooltip 数据。

非空格：

- 设置 Item Icon。
- `Quantity > 1` 时显示数量。
- `Quantity <= 1` 时隐藏数量。
- 设置基础 Tooltip 文本。

每次刷新都必须同时处理“显示”和“隐藏”分支，防止 Widget 从非空状态变成空状态后残留旧图标或数量。

### 9.3 提交点击请求

Slot Widget 不直接持有 Controller。它可以向父 Panel 广播自己的 EntryHandle，或者由 Panel 在创建 Slot Widget 时绑定 Slot Widget 的点击 Delegate，再转发为 Panel 的 `OnSlotClicked`。

推荐链路：

```text
WBP_InventorySlot.OnClicked
    -> Slot Widget OnClicked(EntryHandle)
    -> WBP_InventorySlottedPanel 转发
    -> UInventorySlottedUIWidget::RequestSlotClick
    -> UInventorySlottedUIController::HandleSlotClicked
```

### 9.4 验收标准

- 同一个 Slot Widget 可以从空格刷新成物品格。
- 同一个 Slot Widget 可以从物品格刷新回空格。
- 数量从 2 变为 1 时数量文本正确隐藏。
- 点击事件携带当前 ViewData 中的 EntryHandle。

## 10. 阶段六：实现 Slotted Panel Widget Blueprint

### 10.1 创建 Widget Blueprint

创建：

```text
WBP_InventorySlottedPanel
Parent Class: UInventorySlottedUIWidget
```

建议的最小层级：

```text
Overlay_Root
├── Border_Panel
│   └── UniformGridPanel_Slots
├── WBP_InventoryTooltip
└── WBP_InventoryCursorPayload
```

Tooltip 可以在第一版只保留占位。Cursor Widget 必须位于格子层上方，并设置为不阻挡鼠标命中。

### 10.2 实现 `RebuildSlots`

流程：

1. 清空 `UniformGridPanel_Slots`。
2. 清空 Panel 保存的 Slot Widget 引用。
3. 按 ViewData 数组顺序创建 `WBP_InventorySlot`。
4. 调用 Slot Widget 的 `SetViewData()`。
5. 绑定 Slot Widget 点击事件。
6. 使用 `SlotIndex` 计算 Row 和 Column。
7. 加入 Uniform Grid。
8. 保存 `SlotIndex -> SlotWidget` 的映射或数组。

第一版建议使用按 SlotIndex 排列的 Widget 数组。只要 SlotIndex 连续，它比以 Handle 为键的 Blueprint Map 更直接。

```text
Row    = SlotIndex / ColumnCount
Column = SlotIndex % ColumnCount
```

`ColumnCount` 应作为 Panel 的可配置属性，并保证大于 0。

### 10.3 实现 `UpdateSlot`

流程：

1. 验证 SlotIndex。
2. 从数组找到已有 Slot Widget。
3. 调用 `SetViewData()`。
4. 找不到 Widget 或布局状态不一致时，记录诊断信息并请求完整重建。

### 10.4 实现 Cursor 显示

`SetCursorViewData()` 应做到：

- `bIsVisible == false` 时隐藏 Cursor Widget。
- `bIsVisible == true` 时更新图标和数量并显示。
- Cursor Widget 不接收鼠标命中。
- 第一版可以让 Cursor Widget 跟随鼠标位置，不实现拖放操作对象。

### 10.5 验收标准

- SlotCount 为 0 时 Panel 正常显示为空。
- SlotCount 不是 ColumnCount 整数倍时最后一行排列正确。
- 完整重建不会遗留旧 Slot Widget 或重复点击绑定。
- 单格刷新不会重建整个 Grid。
- Cursor Widget 不阻挡下方 Slot Button 点击。

## 11. 阶段七：接入游戏生命周期

需要确定一个高于 Widget 的对象负责创建并持有 UIController。推荐由 PlayerController、HUD 或玩家 UI 管理对象持有，而不是由临时 Slot Widget 持有。

建议顺序：

```text
创建 WBP_InventorySlottedPanel
    -> 创建 UInventorySlottedUIController
    -> Controller.Initialize(PlayerInventory, Panel)
    -> Panel.AddToViewport
```

关闭界面时：

```text
先处理 Held Payload 的关闭策略
    -> Controller.Shutdown
    -> Panel.RemoveFromParent
```

当前第一阶段可以规定：玩家常驻栏不销毁 Controller，Panel 只切换可见性。这样 Cursor Context 可以稳定存在，也为后续箱子 Controller 共享 Context 留出空间。

验收标准：

- 重复打开和关闭界面不会重复绑定点击事件。
- 切换可见性不会丢失合法的 Cursor Payload。
- 销毁 Panel 前一定解除 Controller 对 View 的绑定。
- Controller 的 Outer 和持有位置能够覆盖 UI 使用周期。

## 12. 阶段八：测试与验证

### 12.1 C++ 自动化测试

现有库存逻辑测试之外，补充以下测试：

- 空 Slot 可以生成 ViewData。
- 非空 Slot 可以生成正确名称、数量和图标 ViewData。
- SlotIndex 与 `GetSlotHandle()` 顺序一致。
- 无效 SlotIndex 无法生成 ViewData。
- `FindSlotIndex()` 对有效、外部和失效 Handle 返回正确结果。
- Context 拿起后 Cursor ViewData 可见。
- Context 清空后 Cursor ViewData 不可见。

如果 View 是 BlueprintImplementableEvent，Controller 到 View 的调用可以先通过一个 C++ 测试 View 子类或测试替身验证；不要只依赖人工点击。

### 12.2 PIE 手动测试

按以下顺序测试：

1. 全空背包打开后显示正确数量的空格。
2. 初始有物品时，图标和数量显示正确。
3. 点击非空格，来源格清空且 Cursor 显示物品。
4. 点击空格，物品移入目标且 Cursor 隐藏。
5. 点击相同物品，能够完全合并。
6. 目标容量不足时部分合并，Cursor 显示剩余数量。
7. 点击不同物品，目标和 Cursor 完成交换。
8. 点击已满的相同堆叠，数据和 Cursor 均不改变。
9. 连续打开和关闭 UI，不产生重复回调。
10. 将一个格子从数量 2 改为 1，再改为空，旧数量和图标不残留。

### 12.3 编译验证

每完成一个 C++ 阶段至少执行一次 Editor Target 编译。修改 USTRUCT、UFUNCTION、Delegate 或 UPROPERTY 后，应关闭可能影响 UHT/Hot Reload 的旧编辑器实例，使用完整构建验证反射代码。

## 13. 每日施工安排

以下安排按 7 个开发日划分。默认每天有约 3 至 5 小时可用于实现和验证；如果每天只有 1 至 2 小时，可以将每个开发日拆成两个自然日，但不要跳过当天的验收步骤。

### 第 1 天：整理初始化与事件语义

当天目标：让 Slotted Inventory 在对外发送 Reset 时已经处于完整可读状态。

任务：

- 调整 `InventoryComponent` 的运行时状态重建与 Reset 广播顺序。
- 让 `SlottedInventoryComponent` 先补齐固定格，再统一广播 Reset。
- 避免初始化补格时向外暴露一系列不完整的中间状态。
- 为初始化后的 SlotCount、Entry 数量和 Reset 时机补充测试。

当天验收：

- Reset 回调中可以立即读取全部固定格。
- 初始化只产生一次对外完整刷新通知。
- 原有 Slotted Inventory 操作测试仍然通过。
- Editor Target 编译通过。

当天不要继续做 UI，先确保 Model 通知语义稳定。

### 第 2 天：完成 ViewData 与 View 契约

当天目标：确定 Controller 能向 Widget 发送什么，以及 Widget 能向 Controller 请求什么。

任务：

- 为 `FInventorySlottedEntryViewData` 增加 `SlotIndex` 和 `bIsEmpty`。
- 新增 `FInventoryCursorViewData`。
- 为 `UInventorySlottedUIWidget` 增加 `RebuildSlots()`、`UpdateSlot()` 和 `SetCursorViewData()`。
- 增加 `OnSlotClicked` 与 `RequestSlotClick()`。
- 确认空格 ViewData 仍包含有效 EntryHandle。

当天验收：

- UHT 和 C++ 编译通过。
- Blueprint 中可以看到新增 Struct、Event、Delegate 和函数。
- Panel View 契约不暴露 InventoryComponent、Entry 或 Payload。

### 第 3 天：完成 Controller 的只读显示链路

当天目标：暂时不处理点击，先让 Inventory 能稳定显示到 UI。

任务：

- 将 `UInventorySlottedUIController::Initialize()` 改为同时绑定 Inventory 和 View。
- 实现 `MakeSlotViewData()`。
- 在 Slotted Component 中增加 `FindSlotIndex()`。
- 实现 `RefreshAllSlots()`。
- 实现 Added、Changed、Removed、Reset 的 UI 更新策略。
- 在 `Shutdown()` 中解除 Inventory 与 View 的绑定。

当天验收：

- Initialize 会向 View 发送完整且按 SlotIndex 排序的 ViewData。
- 空格不会被过滤。
- Changed 只更新一个格子。
- Added、Removed、Reset 会触发完整重建。
- 重复 Initialize 不会产生重复回调。

如果当天还有余量，只补 Controller 单元测试，不提前加入点击操作。

### 第 4 天：制作 Slot 与 Panel Widget Blueprint

当天目标：在 PIE 中看到正确的固定格背包，但暂时不要求可以操作。

任务：

- 创建 `WBP_InventorySlot`，实现图标和数量显示。
- 完成空格与非空格之间的双向刷新。
- 创建 `WBP_InventorySlottedPanel`。
- 使用 Uniform Grid 动态生成全部 Slot Widget。
- 保存按 SlotIndex 排列的 Slot Widget 引用。
- 实现 `RebuildSlots()` 和 `UpdateSlot()`。

当天验收：

- 全空背包显示正确数量的格子。
- 有物品的格子显示正确图标和数量。
- 数量为 1 时隐藏数量文本。
- 将物品格清空后不残留旧图标或旧数量。
- 单格变化不会重建整个 Grid。

### 第 5 天：接通左键库存交互

当天目标：完成“点击格子 → 修改库存 → 事件回刷 UI”的闭环。

任务：

- 为 Slot Widget 增加点击 Delegate。
- 由 Panel 统一转发为 `OnSlotClicked`。
- 在 Controller 中实现 `HandleSlotClicked()`。
- Cursor 为空时，从非空格拿起整个堆叠。
- Cursor 非空时，向目标格请求放置、合并或交换。
- 保证 Controller 在点击时重新查询 Entry 和 Quantity。

当天验收：

- 点击空格且 Cursor 为空时不发生变化。
- 点击非空格可以拿起整个物品堆。
- 可以放入空格。
- 可以与相容堆叠完全或部分合并。
- 可以与不同物品交换。
- 失败操作不改变目标格，也不吞掉 Cursor Payload。

当天先通过日志或调试器确认 Cursor 数据变化；Cursor 可视化留到第 6 天。

### 第 6 天：完成 Cursor 显示与 UI 生命周期

当天目标：让整个交互在视觉上完整，并保证关闭或重复打开 UI 不留下错误绑定。

任务：

- 在 Controller 中绑定 `OnHeldPayloadChanged`。
- 实现 `MakeCursorViewData()` 和 `RefreshCursor()`。
- 创建或完善 `WBP_InventoryCursorPayload`。
- 让 Cursor Widget 跟随鼠标，并确保它不阻挡 Slot 点击。
- 将 Panel 和 Controller 接入 PlayerController、HUD 或玩家 UI 管理对象。
- 明确界面隐藏、关闭和 Shutdown 的调用顺序。

当天验收：

- 拿起物品后 Cursor 图标和数量立即出现。
- 完全放置后 Cursor 立即隐藏。
- 部分合并和交换后 Cursor 显示正确剩余物品。
- 多次打开和关闭 UI 不会重复触发点击。
- UI 隐藏时不会意外清空合法的 Held Payload。

### 第 7 天：集中测试、修正与收尾

当天目标：不再扩充功能，只验证并修正第一阶段闭环。

任务：

- 执行本文档中的全部 C++ 自动化测试。
- 按 PIE 手动测试清单逐项验证。
- 检查空背包、满背包、部分合并、交换和失败操作。
- 检查 Widget 从非空刷新为空时的视觉残留。
- 检查 Initialize、Shutdown、重复打开和关闭的 Delegate 生命周期。
- 清理临时日志、过期注释和 Blueprint 调试节点。
- 执行一次完整 Editor Target 构建。

当天验收：

- 本文档“第一阶段完成定义”中的所有条件均满足。
- 没有已知的物品丢失、重复回调或旧 UI 残留问题。
- 编译、自动化测试和 PIE 手动测试全部通过。
- 未完成事项明确记录到后续列表，而不是临时塞进第一阶段。

### 每日工作原则

- 每天开始前先确认前一天的验收结果仍然成立。
- 每完成一个 C++ 反射接口阶段就进行编译，不连续积累多天的 UHT 错误。
- 当天最后至少保留一段时间用于测试，不以“代码写完”作为完成标准。
- Blueprint 只负责显示与提交意图；发现业务规则进入 Blueprint 时立即退回 Controller 或 Model。
- 如果某天没有完成，第二天先完成原验收项，再继续后续任务，不带着已知断链向前施工。

## 14. 推荐提交顺序

为了让每个提交都保持职责单一，推荐拆成以下顺序：

1. `Fix slotted inventory initialization notification order`
2. `Extend slotted slot view data`
3. `Add slotted panel view contract`
4. `Connect slotted UI controller to inventory and view`
5. `Add slot click interaction through interaction context`
6. `Add cursor view data and refresh flow`
7. `Create slotted slot and panel widget blueprints`
8. `Add slotted UI tests and PIE test map`

不要求实际 Git 提交名称完全一致，但施工过程中应保持上述依赖顺序。

## 15. 第一阶段完成定义

只有同时满足以下条件，第一阶段才算完成：

- UI 显示全部固定格，包括空格。
- Widget 不直接依赖或修改 Inventory Model。
- Controller 是唯一的 ViewData 制作和交互协调入口。
- 左键整堆拿起、放置、合并和交换形成完整闭环。
- Inventory 事件驱动格子刷新，Context 事件驱动 Cursor 刷新。
- 初始化 Reset 在固定格准备完成后广播。
- 重复初始化、关闭和重新打开不会产生重复事件绑定。
- 自动化测试和 PIE 手动测试通过。
- Editor Target 完整编译通过。

完成第一阶段后，再开始第二阶段的箱子 UI 和多个 Slotted Inventory 共享同一个 InteractionContext。届时应先补充 `INV-006` 的详细用例，再决定多个 Controller 与根 UI 之间的生命周期关系。
