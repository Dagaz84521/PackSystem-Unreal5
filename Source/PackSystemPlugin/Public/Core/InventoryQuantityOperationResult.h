#pragma once

#include "CoreMinimal.h"
#include "Core/InventoryEntryArray.h"
#include "Core/InventoryItemPayload.h"
#include "InventoryQuantityOperationResult.generated.h"

/** 数量类库存操作的执行状态。 */
UENUM(BlueprintType)
enum class EInventoryQuantityOperationStatus : uint8
{
	Failed UMETA(DisplayName = "失败"),
	PartialSucceeded UMETA(DisplayName = "部分成功"),
	Succeeded UMETA(DisplayName = "成功")
};

/**
 * 添加、提取和定点放置等库存操作共用的执行结果。
 *
 * OutputPayload 表示操作完成后返回给调用者的物品：
 * 添加时是未能加入的剩余物品，提取时是实际提取出来的物品，
 * 定点放置时是操作后 Cursor 继续持有的物品。
 * 操作没有物品需要返回时，该字段为空。
 */
USTRUCT(BlueprintType)
struct PACKSYSTEMPLUGIN_API FInventoryQuantityOperationResult
{
	GENERATED_BODY()

	/** 本次操作的整体执行状态。 */
	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Operation")
	EInventoryQuantityOperationStatus Status = EInventoryQuantityOperationStatus::Failed;

	/** 调用者请求操作的数量。 */
	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Operation", meta = (ClampMin = "0"))
	int64 RequestedQuantity = 0;

	/** 本次实际成功添加、提取或转移的数量。 */
	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Operation", meta = (ClampMin = "0"))
	int64 ChangedQuantity = 0;

	/**
	 * 本次操作返回给调用者的物品。
	 * AddItem 返回未加入的剩余部分；ExtractItem 返回实际提取出的部分；
	 * PlaceItemAtSlot 返回操作后的 Cursor Payload，交换时即为目标格原 Payload。
	 */
	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Operation")
	FInventoryItemPayload OutputPayload;

	/** 请求数量中尚未完成的部分。 */
	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Operation", meta = (ClampMin = "0"))
	int64 RemainingQuantity = 0;

	/** 本次操作主要影响的 Entry；Entry 被删除后，该 Handle 仅用于标识原 Entry。 */
	UPROPERTY(BlueprintReadOnly, Category = "Inventory|Operation")
	FInventoryEntryHandle AffectedEntry;

	void Set(EInventoryQuantityOperationStatus status, int64 requestedQuantity, int64 changedQuantity, const FInventoryItemPayload& outputPayload, const FInventoryEntryHandle& affectedEntry)
	{
		Status = status;
		RequestedQuantity = requestedQuantity;
		ChangedQuantity = changedQuantity;
		OutputPayload = outputPayload;
		AffectedEntry = affectedEntry;
		RemainingQuantity = RequestedQuantity - ChangedQuantity;
	}

	/** 返回本次操作是否向调用者返回了有效物品。 */
	bool HasOutputPayload() const
	{
		return OutputPayload.IsValid();
	}
};
