# Inventory 用例与接口设计

本文档用于先整理会改变物品存储的游戏场景，再从这些场景中提取 `InventoryComponent`、`SlottedInventoryComponent` 和库存交互层的接口。

当前阶段只考虑单机下的库存逻辑，不考虑网络同步。

## 使用方法

1. 从“场景清单”中选一个场景。
2. 复制“用例模板”并填写。
3. 明确操作前后的存储变化，以及成功和失败结果。
4. 将用例需要的能力记入“候选接口”。
5. 多个用例都需要同一种能力时，再确定正式函数。

## 场景清单

状态可以填写：`待整理`、`已定义`、`已提取接口`、`已实现`、`已测试`。

| 阶段 | ID | 场景 | 涉及的存储 | 状态 |
| --- | --- | --- | --- | --- |
| 第一阶段 | INV-001 | 从格子拿起完整或部分物品 | 玩家背包 -> 鼠标暂存 | 已提取接口 |
| 第一阶段 | INV-002 | 将鼠标物品放入空格 | 鼠标暂存 -> 玩家背包 | 已提取接口 |
| 第一阶段 | INV-003 | 将鼠标物品合并到已有堆叠 | 鼠标暂存 -> 玩家背包 | 已提取接口 |
| 第一阶段 | INV-004 | 将鼠标物品与目标格交换 | 鼠标暂存 <-> 玩家背包 | 已提取接口 |
| 第一阶段 | INV-005 | 取消并归还鼠标物品 | 鼠标暂存 -> 玩家背包 | 已提取接口 |
| 第二阶段 | INV-006 | 玩家与箱子之间转移物品 | 两个容器 | 待整理 |
| 第三阶段 | INV-007 | 拾取世界物品 | 世界 -> 玩家背包 | 待整理 |
| 第三阶段 | INV-008 | 丢弃物品 | 玩家背包 -> 世界 | 待整理 |
| 第四阶段 | INV-009 | 消耗物品 | 玩家背包 | 待整理 |
| 第四阶段 | INV-010 | 获得奖励物品 | 系统 -> 玩家背包 | 待整理 |
| 第四阶段 | INV-011 | 扣除制作或任务材料 | 玩家背包 | 待整理 |
| 第四阶段 | INV-012 | 装备物品 | 背包 -> 装备槽 | 待整理 |
| 第四阶段 | INV-013 | 更换装备 | 背包 <-> 装备槽 | 待整理 |
| 第四阶段 | INV-014 | 卸下装备 | 装备槽 -> 背包 | 待整理 |
| 第四阶段 | INV-015 | 放下或捡起装有物品的背包 | 世界与背包容器 | 待整理 |
| 第四阶段 | INV-016 | 改变容器容量 | 单个容器 | 待整理 |
| 第四阶段 | INV-017 | 玩家死亡并掉落物品 | 玩家背包 -> 世界 | 待整理 |
| 第四阶段 | INV-018 | 销毁装有物品的容器 | 容器 -> 世界或其他容器 | 待整理 |
| 第四阶段 | INV-019 | 保存与加载物品 | 存档与容器 | 待整理 |

## 用例模板

复制本节，为一个场景建立独立小节。

### INV-XXX 场景名称

**目的**

玩家或游戏系统想完成什么？不要写按钮、Widget 或函数名。

**输入**

- 来源：
- 目标：
- 物品：
- 数量：
- 指定格子（可选）：

**前置条件**

- 

**操作规则**

- 是否允许部分成功：
- 是否自动寻找可用位置：
- 是否受堆叠上限影响：
- 是否受容器或格子的物品类型限制：
- 其他规则：

**成功时的变化**

```text
操作前：

操作后：
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| 输入无效 | 不改变库存 |
| 来源没有足够物品 | |
| 目标空间不足 | |
| 目标不允许该物品 | |
| 其他 | |

**操作结果需要提供的信息**

- 是否成功：
- 实际变化数量：
- 失败原因：
- 受影响的物品、Entry 或 Slot：

**候选接口**

先记录需要什么能力，不必立刻确定最终函数签名。

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| 例如：判断指定格子能否放入物品 | 查询 | SlottedInventoryComponent |
| | | |

**测试场景**

- 正常成功：
- 空容器：
- 满容器：
- 数量不足：
- 只能完成一部分：
- 输入无效：

## 用例记录

下面的记录顺序与总表一致。第一阶段用例已经定义，`INV-007` 保留为后续阶段的填写示例。

### 第一阶段：玩家背包与 UI

完成玩家背包与 UI 的鼠标暂存交互。交互状态由 UI Controller 或专门的交互状态对象持有，不能只保存在临时 Widget 中。

交互状态至少包含：

- Cursor Payload：鼠标当前持有的物品；空 Payload 表示没有持有物品。
- Origin Inventory：本次拿起操作的来源背包。
- Origin Entry Handle：本次拿起操作的来源格子，用于取消时优先归还。

#### INV-001 从格子拿起完整或部分物品

**目的**

玩家点击一个非空格子，将完整物品堆或指定数量取到鼠标上，随后可以选择目标格子。

**输入**

- 来源：玩家背包中的来源格子。
- 目标：Cursor Payload。
- 物品：来源格子中的物品。
- 数量：全部数量或指定的部分数量。
- 指定格子：来源格子。

**前置条件**

- Cursor Payload 为空。
- 来源格子有效且属于当前打开的背包。
- 来源格子保存有效物品。
- 请求数量大于 0 且不超过来源数量。

**操作规则**

- 拿起全部数量时，来源格子清空，Cursor Payload 接收原 Item Instance 和全部数量。
- 拿起部分数量只适用于没有 Item Instance 的普通堆叠；来源与 Cursor 共享同一个 Definition，只拆分数量，不创建 UObject。
- 带有独立 Item Instance 的物品当前数量固定为 1，只能完整拿起。
- 指定数量必须完整满足，不允许部分成功。
- 成功后记录 Origin Inventory 和 Origin Entry Handle。
- UI 只负责提交拿起请求和显示 Cursor Payload，不直接修改格子。
- Cursor Payload 非空时不能再次执行本用例，应先放置、交换或取消当前物品。

**成功时的变化**

```text
示例 A：拿起全部
操作前：Slot 2 = 木材 x20，Cursor = 空
操作后：Slot 2 = 空，Cursor = 木材 x20

示例 B：拿起一半
操作前：Slot 2 = 木材 x20，Cursor = 空
操作后：Slot 2 = 木材 x10，Cursor = 木材 x10
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| Cursor Payload 非空 | 不改变来源和 Cursor |
| 来源格子无效或来自其他背包 | 不改变状态 |
| 来源格子为空 | 不改变状态 |
| 请求数量小于等于 0 | 不改变状态 |
| 请求数量大于来源数量 | 不改变状态 |
| 尝试部分拿起带 Item Instance 的物品 | 不改变状态 |

**操作结果需要提供的信息**

- 是否成功。
- 请求数量和实际拿起数量。
- 失败原因。
- 来源格子的 Handle。
- 得到的 Cursor Payload。

**候选接口**

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| 查询 Cursor Payload 是否为空 | 查询 | Inventory Interaction Controller |
| 从指定格子提取完整或部分 Payload | 修改 | SlottedInventoryComponent |
| 记录来源背包和来源格子 | 修改 | Inventory Interaction Controller |
| 设置 Cursor Payload | 修改 | Inventory Interaction Controller |
| 返回数量操作结果和提取出的 Payload | 结果类型 | 可复用 FInventoryQuantityOperationResult |

**测试场景**

- 左键拿起完整物品堆。
- 按指定数量拿起部分物品堆。
- 拿起数量 1 的完整物品堆。
- Cursor 非空时再次拿起，失败。
- 请求 0、负数或超过来源数量，失败。
- 普通物品部分拿起后两堆数量守恒、Definition 相同且均没有 Item Instance。
- 带 Item Instance 的物品不能部分拿起。
- 完整拿起后来源格子保持有效但 Payload 为空。

#### INV-002 将鼠标物品放入空格

**目的**

玩家点击一个空格子，将鼠标当前持有的完整 Payload 放入该格子。

**输入**

- 来源：Cursor Payload。
- 目标：玩家背包中的目标空格。
- 物品：鼠标当前持有的物品。
- 数量：Cursor Payload 的全部数量。
- 指定格子：目标格子。

**前置条件**

- Cursor Payload 有效。
- 目标格子有效且属于当前可交互的背包。
- 目标格子为空。
- 目标格子允许放入 Cursor Payload 中的物品。

**操作规则**

- 当前用例默认放入 Cursor Payload 的全部数量。
- 放置不复制 Item Instance，目标格子直接接收 Cursor Payload。
- 成功后 Cursor Payload 清空。
- Cursor 清空后，同时清除记录的来源信息。
- 目标非空时不执行本用例，改由合并或交换用例处理。
- 失败时目标格子和 Cursor Payload 均保持原状。

**成功时的变化**

```text
操作前：
Slot 7 = 空
Cursor = 木材 x20

操作后：
Slot 7 = 木材 x20
Cursor = 空
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| Cursor Payload 为空或不合法 | 不改变目标 |
| 目标格子无效 | Cursor 保持不变 |
| 目标格子非空 | Cursor 和目标均保持不变 |
| 目标格子拒绝该物品 | Cursor 和目标均保持不变 |

**操作结果需要提供的信息**

- 是否成功。
- 失败原因。
- 目标格子的 Handle。
- 实际放入数量。
- 操作后的 Cursor Payload。

**候选接口**

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| 判断目标格子是否为空 | 查询 | SlottedInventoryComponent |
| 判断目标格子能否接收 Payload | 查询 | SlottedInventoryComponent |
| 将完整 Payload 放入指定空格 | 修改 | SlottedInventoryComponent |
| 成功后清空 Cursor 和来源信息 | 修改 | Inventory Interaction Controller |

**测试场景**

- 将完整 Cursor Payload 放入空格。
- 放回原来源格子。
- 目标格子无效，失败且 Cursor 不变。
- 目标格子非空，失败且 Cursor 不变。
- 目标格子拒绝物品，失败且 Cursor 不变。
- 成功后 Item Instance 和数量没有改变。

#### INV-003 将鼠标物品合并到已有堆叠

**目的**

玩家点击一个相容物品堆，将 Cursor Payload 中能够容纳的数量合并到目标格子。

**输入**

- 来源：Cursor Payload。
- 目标：玩家背包中的相容物品堆。
- 物品：Cursor Payload 与目标格子中的物品。
- 数量：Cursor Payload 的全部数量。
- 指定格子：目标格子。

**前置条件**

- Cursor Payload 有效。
- 目标格子有效且保存有效物品。
- Cursor Item Instance 与目标 Item Instance 满足匹配规则。
- 目标堆叠尚未达到单格堆叠上限。

**操作规则**

- 实际合并数量取 Cursor 数量和目标剩余容量的最小值。
- 目标容量不足时允许部分成功。
- 目标格子保留自己的 Item Instance，只增加数量。
- 部分成功后 Cursor 保留原 Item Instance 和剩余数量。
- 完全成功后 Cursor Payload 清空，并清除来源信息。
- 物品不相容时不执行合并，UI 可以改为请求交换。
- 合并前后 Cursor 与目标的总数量必须一致。

**成功时的变化**

```text
操作前：
Slot 7 = 木材 x18
Cursor = 木材 x12
单格上限 = 20

操作后：
Slot 7 = 木材 x20
Cursor = 木材 x10
结果 = 部分成功，实际合并 2
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| Cursor Payload 无效 | 不改变目标 |
| 目标格子无效或为空 | 不改变 Cursor 和目标 |
| 两个 Item Instance 不相容 | 不改变 Cursor 和目标 |
| 目标达到堆叠上限 | 不改变 Cursor 和目标 |
| 无法取得有效堆叠上限 | 不改变 Cursor 和目标 |

**操作结果需要提供的信息**

- 成功、部分成功或失败。
- 实际合并数量和 Cursor 剩余数量。
- 失败原因。
- 目标格子的 Handle。
- 操作后的 Cursor Payload。

**候选接口**

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| 判断 Payload 与目标格物品是否相容 | 查询 | SlottedInventoryComponent |
| 查询目标堆叠剩余容量 | 查询 | SlottedInventoryComponent |
| 向目标格合并指定 Payload | 修改 | SlottedInventoryComponent |
| 根据操作结果更新 Cursor Payload | 修改 | Inventory Interaction Controller |
| 返回未能放入的剩余 Payload | 结果类型 | 可复用 FInventoryQuantityOperationResult |

**测试场景**

- Cursor 全部合并后清空。
- 目标空间不足，部分合并且 Cursor 保留剩余数量。
- 目标已满，失败。
- 物品不相容，失败。
- 合并前后总数量守恒。
- 完全合并后目标保留自己的 Item Instance。

#### INV-004 将鼠标物品与目标格交换

**目的**

玩家点击一个不能直接合并的非空格子，将 Cursor Payload 与目标格子的完整 Payload 交换。

**输入**

- 来源：Cursor Payload。
- 目标：玩家背包中的非空目标格。
- 物品：Cursor Payload 与目标格物品。
- 数量：两个完整 Payload。
- 指定格子：目标格子。

**前置条件**

- Cursor Payload 有效。
- 目标格子有效并保存有效物品。
- 目标格子允许放入 Cursor Payload。
- 当前交互规则选择交换，而不是合并。

**操作规则**

- 目标格子接收原 Cursor Payload。
- Cursor Payload 接收目标格子的原 Payload。
- 两个 Item Instance 和各自数量均不改变。
- 交换后 Cursor 仍然非空，因此不能清除交互状态。
- Origin Inventory 和 Origin Entry Handle 只作为优先归还位置，不承诺能够撤销全部历史操作。
- 目标拒绝 Cursor 物品时，交换整体失败。
- UI 只提交一次交换请求，不能先取出目标再尝试放入 Cursor。

**成功时的变化**

```text
操作前：
Slot 7 = 石头 x12
Cursor = 木材 x20

操作后：
Slot 7 = 木材 x20
Cursor = 石头 x12
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| Cursor Payload 无效 | 不改变目标 |
| 目标格子无效或为空 | 不改变 Cursor 和目标 |
| 目标格子拒绝 Cursor 物品 | 不改变 Cursor 和目标 |
| 交换过程中无法形成有效 Payload | 不改变 Cursor 和目标 |

**操作结果需要提供的信息**

- 是否成功。
- 失败原因。
- 目标格子的 Handle。
- 交换前后的 Cursor Payload。
- 目标格交换后的 Payload。

**候选接口**

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| 判断目标格能否接收 Cursor Payload | 查询 | SlottedInventoryComponent |
| 用 Cursor Payload 替换目标并返回原 Payload | 修改 | SlottedInventoryComponent |
| 将返回的目标 Payload 设置为新的 Cursor | 修改 | Inventory Interaction Controller |
| 返回目标原 Payload 和受影响格子 | 结果类型 | Slotted Inventory |

**测试场景**

- 两个不相容物品成功交换。
- 两个相容物品在明确选择交换时成功交换。
- 目标格子拒绝 Cursor 物品，整体失败。
- 目标为空时不进入交换用例。
- 交换后两件 Item Instance 和数量保持不变。
- 连续点击多个非空格子，可以连续交换 Cursor 内容。

#### INV-005 取消并归还鼠标物品

**目的**

玩家取消当前鼠标暂存状态，或关闭背包 UI 时，将 Cursor Payload 安全归还到玩家背包。

**输入**

- 来源：Cursor Payload。
- 目标：优先为 Origin Entry Handle，其次为背包中其他可用格子。
- 物品：鼠标当前持有的物品。
- 数量：Cursor Payload 的全部数量。
- 指定格子：记录的来源格子，可失效或不可用。

**前置条件**

- Cursor Payload 有效；Cursor 为空时可直接视为无操作成功。
- Inventory Interaction Controller 仍可访问来源背包或当前玩家背包。

**操作规则**

- 首先尝试按普通放置或合并规则归还到来源格子。
- 来源格子无法接收时，再查找其他相容未满堆叠和空格子。
- 归还可以分布到多个相容堆叠和空格，但必须报告剩余数量。
- 完全归还后清空 Cursor Payload 和来源信息。
- 无法完全归还时，不得静默删除剩余物品。
- 当前阶段没有世界丢弃兜底；仍有剩余时取消失败，交互状态继续存在。
- Widget 可以关闭显示，但持有 Cursor Payload 的 Controller 不能随 Widget 一起销毁。
- 本用例只保证物品安全归还，不保证撤销玩家此前的全部移动和交换历史。

**成功时的变化**

```text
操作前：
Origin Slot 2 = 空
Cursor = 木材 x20

操作后：
Origin Slot 2 = 木材 x20
Cursor = 空
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| Cursor 为空 | 返回无操作成功 |
| 来源格子已无法使用 | 尝试其他可用位置 |
| 来源格子被不相容物品占用 | 尝试其他可用位置 |
| 背包只能容纳一部分 | 放入可容纳部分，Cursor 保留剩余数量 |
| 背包完全无空间 | Cursor 保持不变，取消失败 |
| 来源背包已不可访问 | Cursor 保持不变并报告失败 |

**操作结果需要提供的信息**

- 成功、部分成功、失败或无操作。
- 实际归还数量和剩余数量。
- 失败原因。
- 被修改的格子集合。
- 操作后的 Cursor Payload。

**候选接口**

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| 尝试将 Payload 放回优先格子 | 协调 | Inventory Interaction Controller |
| 查找相容堆叠和可用空格 | 查询 | SlottedInventoryComponent |
| 将 Payload 自动放入多个格子 | 修改 | SlottedInventoryComponent |
| 保留未能归还的 Cursor Payload | 修改 | Inventory Interaction Controller |
| 请求关闭 UI 前处理 Cursor 状态 | 用例接口 | Inventory UI Controller |

**测试场景**

- Cursor 为空时取消，无操作成功。
- 原格子为空，完整归还。
- 原格子存在相容未满堆叠，完成合并。
- 原格子不可用，归还到其他空格。
- 需要使用多个格子才能完全归还。
- 空间不足，只归还一部分，Cursor 保留剩余。
- 完全无空间时不丢失物品。
- Widget 关闭后 Cursor Payload 仍然存在于 Controller。

### 第二阶段：箱子

完成玩家背包与箱子之间的双容器交互。

#### INV-006 玩家与箱子之间转移物品

**目的**

- 待填写。

**输入**

- 来源：玩家背包或箱子
- 目标：另一个容器
- 物品：来源中的物品
- 数量：请求转移的数量
- 指定格子：来源格子和目标格子均可选

**前置条件**

- 待填写。

**操作规则**

- 是否允许部分成功：
- 是否自动寻找可用位置：
- 堆叠、容量或类型限制：
- 其他规则：

**成功时的变化**

```text
操作前：

操作后：
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| 输入无效 | 不改变库存 |
| 待填写 | |

**操作结果需要提供的信息**

- 是否成功：
- 实际变化数量：
- 失败原因：
- 受影响的 Entry 或 Slot：

**候选接口**

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| | | |

**测试场景**

- 正常成功：
- 容量或数量边界：
- 操作失败：

### 第三阶段：世界物品

完成物品在玩家背包与世界之间的进入和离开。

#### INV-007 拾取世界物品（示例）

**目的**

玩家拾取世界中的物品，并将背包能够容纳的数量存入背包。

**输入**

- 来源：世界中的物品对象
- 目标：玩家背包
- 物品：世界物品所代表的 Definition、可选 Item Instance 与数量
- 数量：世界物品当前可拾取数量
- 指定格子：无，交由背包自动选择

**前置条件**

- 世界物品有效且尚未被销毁。
- 玩家拥有可用的背包组件。
- 拾取行为已经由交互系统判定为有效。

**操作规则**

- 优先合并到未满的已有堆叠。
- 剩余物品再放入可用空格。
- 允许部分成功，只拾取背包实际能够容纳的数量。
- 背包完全无法接收时，不改变背包和世界物品。
- InventoryComponent 不负责判断交互距离或播放动画。

**成功时的变化**

```text
操作前：世界中有 10 个木材，玩家背包还能容纳 6 个。
操作后：玩家背包增加 6 个，世界物品剩余 4 个。
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| 世界物品无效 | 不改变库存 |
| 请求数量小于等于零 | 不改变库存 |
| 玩家没有背包组件 | 不改变世界物品 |
| 背包没有空间或拒绝该物品 | 不改变两边状态 |

**操作结果需要提供的信息**

- 是否添加物品。
- 实际添加数量和剩余数量。
- 失败原因。
- 受影响的格子。

**候选接口**

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| 查询背包最多能够接收多少数量 | 查询 | InventoryComponent |
| 自动将 Payload 放入已有堆叠和空格 | 修改 | SlottedInventoryComponent |
| 根据实际添加数量修改世界物品 | 修改 | 拾取用例或世界物品 |

**测试场景**

- 背包为空，全部拾取。
- 优先合并已有堆叠。
- 空间不足，只拾取一部分。
- 背包已满，完全无法拾取。
- 请求数量无效。

#### INV-008 丢弃物品

**目的**

- 待填写。

**输入**

- 来源：玩家背包
- 目标：世界
- 物品：背包中的物品
- 数量：要丢弃的数量
- 指定格子：来源格子（Slotted 时）

**前置条件**

- 待填写。

**操作规则**

- 是否允许部分成功：
- 是否自动寻找可用位置：
- 堆叠、容量或类型限制：
- 其他规则：

**成功时的变化**

```text
操作前：

操作后：
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| 输入无效 | 不改变库存 |
| 待填写 | |

**操作结果需要提供的信息**

- 是否成功：
- 实际变化数量：
- 失败原因：
- 受影响的 Entry 或 Slot：

**候选接口**

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| | | |

**测试场景**

- 正常成功：
- 容量或数量边界：
- 操作失败：

### 第四阶段：其他系统

在背包与箱子稳定后，再接入消耗、制作、装备、容量、死亡和存档等系统。

#### INV-009 消耗物品

**目的**

- 待填写。

**输入**

- 来源：玩家背包
- 目标：使用该物品的游戏逻辑
- 物品：要消耗的物品
- 数量：要消耗的数量
- 指定格子：来源格子（可选）

**前置条件**

- 待填写。

**操作规则**

- 是否允许部分成功：
- 是否自动寻找可用位置：
- 堆叠、容量或类型限制：
- 其他规则：

**成功时的变化**

```text
操作前：

操作后：
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| 输入无效 | 不改变库存 |
| 待填写 | |

**操作结果需要提供的信息**

- 是否成功：
- 实际变化数量：
- 失败原因：
- 受影响的 Entry 或 Slot：

**候选接口**

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| | | |

**测试场景**

- 正常成功：
- 容量或数量边界：
- 操作失败：

#### INV-010 获得奖励物品

**目的**

- 待填写。

**输入**

- 来源：奖励系统
- 目标：玩家背包
- 物品：奖励物品
- 数量：奖励数量
- 指定格子：通常不指定

**前置条件**

- 待填写。

**操作规则**

- 是否允许部分成功：
- 是否自动寻找可用位置：
- 堆叠、容量或类型限制：
- 其他规则：

**成功时的变化**

```text
操作前：

操作后：
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| 输入无效 | 不改变库存 |
| 待填写 | |

**操作结果需要提供的信息**

- 是否成功：
- 实际变化数量：
- 失败原因：
- 受影响的 Entry 或 Slot：

**候选接口**

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| | | |

**测试场景**

- 正常成功：
- 容量或数量边界：
- 操作失败：

#### INV-011 扣除制作或任务材料

**目的**

- 待填写。

**输入**

- 来源：玩家背包
- 目标：制作或任务系统
- 物品：所需材料
- 数量：需要扣除的数量
- 指定格子：通常不指定

**前置条件**

- 待填写。

**操作规则**

- 是否允许部分成功：
- 是否自动寻找可用位置：
- 堆叠、容量或类型限制：
- 其他规则：

**成功时的变化**

```text
操作前：

操作后：
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| 输入无效 | 不改变库存 |
| 待填写 | |

**操作结果需要提供的信息**

- 是否成功：
- 实际变化数量：
- 失败原因：
- 受影响的 Entry 或 Slot：

**候选接口**

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| | | |

**测试场景**

- 正常成功：
- 容量或数量边界：
- 操作失败：

#### INV-012 装备物品

**目的**

- 待填写。

**输入**

- 来源：玩家背包
- 目标：对应装备槽
- 物品：可装备物品
- 数量：通常为一件
- 指定格子：来源位置与装备槽

**前置条件**

- 待填写。

**操作规则**

- 是否允许部分成功：
- 是否自动寻找可用位置：
- 堆叠、容量或类型限制：
- 其他规则：

**成功时的变化**

```text
操作前：

操作后：
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| 输入无效 | 不改变库存 |
| 待填写 | |

**操作结果需要提供的信息**

- 是否成功：
- 实际变化数量：
- 失败原因：
- 受影响的 Entry 或 Slot：

**候选接口**

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| | | |

**测试场景**

- 正常成功：
- 容量或数量边界：
- 操作失败：

#### INV-013 更换装备

**目的**

- 待填写。

**输入**

- 来源：玩家背包与当前装备槽
- 目标：装备槽与背包
- 物品：新装备与旧装备
- 数量：通常各一件
- 指定格子：背包位置与装备槽

**前置条件**

- 待填写。

**操作规则**

- 是否允许部分成功：
- 是否自动寻找可用位置：
- 堆叠、容量或类型限制：
- 其他规则：

**成功时的变化**

```text
操作前：

操作后：
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| 输入无效 | 不改变库存 |
| 待填写 | |

**操作结果需要提供的信息**

- 是否成功：
- 实际变化数量：
- 失败原因：
- 受影响的 Entry 或 Slot：

**候选接口**

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| | | |

**测试场景**

- 正常成功：
- 容量或数量边界：
- 操作失败：

#### INV-014 卸下装备

**目的**

- 待填写。

**输入**

- 来源：装备槽
- 目标：玩家背包
- 物品：当前装备
- 数量：通常为一件
- 指定格子：装备槽；背包目标位置可选

**前置条件**

- 待填写。

**操作规则**

- 是否允许部分成功：
- 是否自动寻找可用位置：
- 堆叠、容量或类型限制：
- 其他规则：

**成功时的变化**

```text
操作前：

操作后：
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| 输入无效 | 不改变库存 |
| 待填写 | |

**操作结果需要提供的信息**

- 是否成功：
- 实际变化数量：
- 失败原因：
- 受影响的 Entry 或 Slot：

**候选接口**

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| | | |

**测试场景**

- 正常成功：
- 容量或数量边界：
- 操作失败：

#### INV-015 放下或捡起装有物品的背包

**目的**

- 待填写。

**输入**

- 来源：玩家或世界
- 目标：世界或玩家
- 物品：背包物品及其内部容器
- 数量：一件背包
- 指定格子：背包装备槽或携带位置

**前置条件**

- 待填写。

**操作规则**

- 是否允许部分成功：
- 是否自动寻找可用位置：
- 堆叠、容量或类型限制：
- 其他规则：

**成功时的变化**

```text
操作前：

操作后：
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| 输入无效 | 不改变库存 |
| 待填写 | |

**操作结果需要提供的信息**

- 是否成功：
- 实际变化数量：
- 失败原因：
- 受影响的 Entry 或 Slot：

**候选接口**

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| | | |

**测试场景**

- 正常成功：
- 容量或数量边界：
- 操作失败：

#### INV-016 改变容器容量

**目的**

- 待填写。

**输入**

- 来源：当前容器配置
- 目标：调整后的同一容器
- 物品：容器中的现有物品
- 数量：增加或减少的容量
- 指定格子：受影响的尾部格子（Slotted 时）

**前置条件**

- 待填写。

**操作规则**

- 是否允许部分成功：
- 是否自动寻找可用位置：
- 堆叠、容量或类型限制：
- 其他规则：

**成功时的变化**

```text
操作前：

操作后：
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| 输入无效 | 不改变库存 |
| 待填写 | |

**操作结果需要提供的信息**

- 是否成功：
- 实际变化数量：
- 失败原因：
- 受影响的 Entry 或 Slot：

**候选接口**

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| | | |

**测试场景**

- 正常成功：
- 容量或数量边界：
- 操作失败：

#### INV-017 玩家死亡并掉落物品

**目的**

- 待填写。

**输入**

- 来源：玩家背包与装备槽
- 目标：世界或死亡掉落容器
- 物品：需要处理的全部物品
- 数量：由死亡规则决定
- 指定格子：通常不指定

**前置条件**

- 待填写。

**操作规则**

- 是否允许部分成功：
- 是否自动寻找可用位置：
- 堆叠、容量或类型限制：
- 其他规则：

**成功时的变化**

```text
操作前：

操作后：
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| 输入无效 | 不改变库存 |
| 待填写 | |

**操作结果需要提供的信息**

- 是否成功：
- 实际变化数量：
- 失败原因：
- 受影响的 Entry 或 Slot：

**候选接口**

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| | | |

**测试场景**

- 正常成功：
- 容量或数量边界：
- 操作失败：

#### INV-018 销毁装有物品的容器

**目的**

- 待填写。

**输入**

- 来源：即将销毁的容器
- 目标：世界或其他目标容器
- 物品：容器中的全部物品
- 数量：容器中的实际数量
- 指定格子：通常不指定

**前置条件**

- 待填写。

**操作规则**

- 是否允许部分成功：
- 是否自动寻找可用位置：
- 堆叠、容量或类型限制：
- 其他规则：

**成功时的变化**

```text
操作前：

操作后：
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| 输入无效 | 不改变库存 |
| 待填写 | |

**操作结果需要提供的信息**

- 是否成功：
- 实际变化数量：
- 失败原因：
- 受影响的 Entry 或 Slot：

**候选接口**

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| | | |

**测试场景**

- 正常成功：
- 容量或数量边界：
- 操作失败：

#### INV-019 保存与加载物品

**目的**

- 待填写。

**输入**

- 来源：当前容器或存档数据
- 目标：存档数据或目标容器
- 物品：需要持久化的物品及其状态
- 数量：全部
- 指定格子：需要保留的 Slot 索引

**前置条件**

- 待填写。

**操作规则**

- 是否允许部分成功：
- 是否自动寻找可用位置：
- 堆叠、容量或类型限制：
- 其他规则：

**成功时的变化**

```text
操作前：

操作后：
```

**失败情况**

| 失败原因 | 期望结果 |
| --- | --- |
| 输入无效 | 不改变库存 |
| 待填写 | |

**操作结果需要提供的信息**

- 是否成功：
- 实际变化数量：
- 失败原因：
- 受影响的 Entry 或 Slot：

**候选接口**

| 能力 | 查询或修改 | 可能属于 |
| --- | --- | --- |
| | | |

**测试场景**

- 正常成功：
- 容量或数量边界：
- 操作失败：

## 接口汇总

以下是从第一阶段五个用例中提取出的最小接口集。函数签名是实现前的设计草案；实现过程中可以调整参数形式，但不应改变这里定义的职责边界。

### InventoryComponent 通用接口

第一阶段没有提出新的通用公开修改接口。`InventoryComponent` 继续只负责 Entry 的稳定标识、通用查询、受保护的修改原语和变更事件。

| 来源用例 | 能力 | 输入 | 结果 | 最终函数 |
| --- | --- | --- | --- | --- |
| INV-001 至 INV-005 | 判断 Handle 是否仍能解析 | Entry Handle | 是否有效 | 现有 `IsValidEntryHandle` |
| INV-001 至 INV-005 | 查询格子当前 Entry | Entry Handle | Entry 副本 | 现有 `GetEntry` |
| INV-001 至 INV-005 | 通知单个格子内容变化 | Entry Handle | 事件 | 现有 `OnEntryChanged` |
| INV-001 至 INV-005 | 修改格子 Payload | Entry Handle、Payload | 是否成功 | 现有受保护接口 `SetEntryPayload` / `ClearEntry` |

结论：格子规则不属于基础 Entry 存储职责，因此定点放置、合并和交换等接口全部留给 `SlottedInventoryComponent`。

### 操作结果类型

现有 `FInventoryQuantityOperationResult` 继续统一表示提取、自动放入、合并和交换，不再增加 `FInventorySlotPlacementResult`。其中 `OutputPayload` 在定点放置时表示操作后的 Cursor Payload：

- 放入空格或完全合并后为空。
- 部分合并后保存未能放入的剩余部分。
- 交换后保存目标格子原来的完整 Payload。
- 失败后等于调用前传入的 Cursor Payload。

### SlottedInventoryComponent 接口

涉及格子查询、提取、定点放置、合并或交换的能力放在这里。

| 来源用例 | 能力 | 输入 | 结果 | 最终函数 |
| --- | --- | --- | --- | --- |
| UI 初始化 | 查询固定格子数量 | 无 | Slot 数量 | `GetSlotCount` |
| UI 初始化 | 根据顺序查询格子 | Slot Index | Entry Handle | `GetSlotHandle` |
| INV-002 | 判断格子是否为空 | Slot Handle | bool | `IsSlotEmpty` |
| INV-001 | 从指定格子提取完整或部分物品 | Slot Handle、Quantity | 数量操作结果及提取 Payload | `ExtractItemFromSlot` |
| INV-002 至 INV-004 | 将 Cursor Payload 应用到指定格子 | Slot Handle、Payload | 放置结果及新的 Cursor Payload | `PlaceItemAtSlot` |
| INV-005 | 自动放入相容堆叠和空格，优先指定来源格 | Payload、Preferred Slot | 数量操作结果及剩余 Payload | `AddItem` |

建议签名：

```cpp
UFUNCTION(BlueprintPure, Category = "Inventory|Slotted")
int32 GetSlotCount() const;

UFUNCTION(BlueprintPure, Category = "Inventory|Slotted")
FInventoryEntryHandle GetSlotHandle(int32 SlotIndex) const;

UFUNCTION(BlueprintPure, Category = "Inventory|Slotted")
bool IsSlotEmpty(const FInventoryEntryHandle& SlotHandle) const;

UFUNCTION(BlueprintCallable, Category = "Inventory|Slotted")
FInventoryQuantityOperationResult ExtractItemFromSlot(
	const FInventoryEntryHandle& SlotHandle,
	int64 Quantity);

UFUNCTION(BlueprintCallable, Category = "Inventory|Slotted")
FInventoryQuantityOperationResult PlaceItemAtSlot(
	const FInventoryEntryHandle& SlotHandle,
	const FInventoryItemPayload& CursorPayload);

UFUNCTION(BlueprintCallable, Category = "Inventory|Slotted")
FInventoryQuantityOperationResult AddItem(
	const FInventoryItemPayload& Payload,
	const FInventoryEntryHandle& PreferredSlot);
```

`PlaceItemAtSlot` 是一次点击的统一入口：

- 目标为空时放入。
- 目标相容且未满时合并。
- 目标不相容但允许接收 Cursor 物品时交换。
- 其他情况失败并原样返回 Cursor Payload。

这样 UI Controller 不需要自己读取 Payload 后拼装底层修改，也不会分别调用“移动、合并、交换”造成规则重复。

### 更上层的用例接口

鼠标暂存是一次交互会话的状态，不属于任何单个 Inventory。建议由 `InventoryInteractionContext` 持有；第一阶段也可以先把同样的字段和接口放在 Slotted UIController 中，第二阶段加入箱子时再原样提取。

| 来源用例 | 能力 | 参与对象 | 最终函数或系统 |
| --- | --- | --- | --- |
| INV-001 | 从格子拿起物品并设置 Cursor | Context、来源 Slotted Inventory | `TakeItemFromSlot` |
| INV-002 至 INV-004 | 根据目标格执行放置、合并或交换，并更新 Cursor | Context、目标 Slotted Inventory | `PlaceHeldItemAtSlot` |
| INV-005 | 优先归还来源格，再自动寻找其他位置 | Context、来源 Slotted Inventory | `CancelHeldItem` |
| INV-001 至 INV-005 | 查询是否正在持有物品 | Context | `IsHoldingItem` |
| INV-001 至 INV-005 | 查询鼠标当前 Payload | Context | `GetHeldPayload` |
| INV-001 至 INV-005 | 通知 View 更新鼠标图标和数量 | Context、View | `OnHeldPayloadChanged` |

建议签名：

```cpp
DECLARE_DYNAMIC_MULTICAST_DELEGATE(FInventoryHeldPayloadChangedDelegate);

UCLASS(BlueprintType)
class UInventoryInteractionContext : public UObject
{
	GENERATED_BODY()

public:
	UFUNCTION(BlueprintPure, Category = "Inventory|Interaction")
	bool IsHoldingItem() const;

	UFUNCTION(BlueprintPure, Category = "Inventory|Interaction")
	FInventoryItemPayload GetHeldPayload() const;

	UFUNCTION(BlueprintCallable, Category = "Inventory|Interaction")
	FInventoryQuantityOperationResult TakeItemFromSlot(
		const FInventoryEntryHandle& SourceSlot,
		int64 Quantity);

	UFUNCTION(BlueprintCallable, Category = "Inventory|Interaction")
	FInventoryQuantityOperationResult PlaceHeldItemAtSlot(
		const FInventoryEntryHandle& TargetSlot);

	UFUNCTION(BlueprintCallable, Category = "Inventory|Interaction")
	FInventoryQuantityOperationResult CancelHeldItem();

	UPROPERTY(BlueprintAssignable, Category = "Inventory|Interaction")
	FInventoryHeldPayloadChangedDelegate OnHeldPayloadChanged;

private:
	UPROPERTY(Transient)
	FInventoryItemPayload HeldPayload;

	UPROPERTY(Transient)
	TWeakObjectPtr<UInventoryComponent> OriginInventory;

	UPROPERTY(Transient)
	FInventoryEntryHandle OriginSlot;
};
```

### 调用关系

```text
点击非空格
  -> InteractionContext.TakeItemFromSlot
  -> SlottedInventoryComponent.ExtractItemFromSlot
  -> Context 保存 OutputPayload

鼠标持有物品时点击目标格
  -> InteractionContext.PlaceHeldItemAtSlot
  -> SlottedInventoryComponent.PlaceItemAtSlot
  -> Context 使用 CursorPayloadAfter 更新 HeldPayload

取消或关闭界面
  -> InteractionContext.CancelHeldItem
  -> SlottedInventoryComponent.AddItem（优先 OriginSlot）
  -> Context 保存未能归还的剩余 Payload
```

## 基本不变量

- 物品数量不能小于零。
- 数量为零的 Entry 不应继续占用存储位置。
- 堆叠数量不能超过物品的堆叠上限。
- 一个格子同时最多保存一个物品堆叠。
- 物品必须满足容器和格子的限制规则。
- 失败的操作不能只完成一半。
- 跨容器转移不能凭空增加或丢失物品。
- 缩小容量时不能静默删除超出容量的物品。
- Cursor Payload 必须始终为空或满足有效 Payload 约束。
- 同一件 Item Instance 不能同时存在于 Cursor 和任何格子中。
- 关闭或销毁 Widget 不能导致 Cursor Payload 丢失。
- 有效 Payload 必须始终拥有 Item Definition。
- 当前模型中，带 Item Instance 的 Payload 数量必须为 1。

## 目前需要逐步决定的问题

- Slotted Inventory 未指定目标格子时，应该如何自动放置物品？
- 部分成功由每个操作单独决定，还是统一处理？
- 装备槽是否可以看作带物品类型限制的 Slotted Inventory？
- 卸下扩容背包时，超出基础容量的物品如何处理？
- 地上的背包是否继续持有原来的容器和物品数据？
- 跨容器转移应该由哪个对象负责协调？
