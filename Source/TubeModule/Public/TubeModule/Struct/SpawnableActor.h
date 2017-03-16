// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SpawnableActor.generated.h"

UENUM(BlueprintType)
enum class ESpawnableActorPlacementType : uint8
{
    EACH_POINT  UMETA(DisplayName = "EachPoint")
};

USTRUCT(BlueprintType)
struct FSpawnableActor
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnyWhere, BluePrintReadWrite, Category = "Struct")
    ESpawnableActorPlacementType PlacementType;

    UPROPERTY(EditAnyWhere, BluePrintReadWrite, Category = "Struct")
    TSubclassOf<class AActor> WhatToSpawn;

public:
	static FSpawnableActor GenerateSpawnableActor(
		ESpawnableActorPlacementType PlacementType,
		TSubclassOf<class AActor> WhatToSpawn
	);

	static FSpawnableActor GenerateSpawnableActor(
		FString PlacementType,
		FString WhatToSpawn
	);

	void AssignPlacementType(FString Str);
	void AssignWhatToSpawn(FString Str);

};