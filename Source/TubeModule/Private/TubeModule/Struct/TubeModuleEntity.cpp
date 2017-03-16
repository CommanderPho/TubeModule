// Fill out your copyright notice in the Description page of Project Settings.

#include "TubeModule.h"
#include "TubeModuleEntity.h"

FTubeModuleEntity::FTubeModuleEntity(int32 UnitLimit)
{
	DisplayableSplineUnitBuffer = UnitLimit;
	TopmostNextSpawnableCounter = 0;
	RearmostNextSpawnableCounter = 0;
	TopRefreshSplineLength = 0;
	RearRefreshSplineLength = 0;
}

FString FTubeModuleEntity::ToDebugString()
{
	FString Result;
	Result =
		"DisplayableSplineUnitBuffer: " + FString::FromInt(DisplayableSplineUnitBuffer) + "  |   " +
		"TopmostSplineUnitNumber: " + FString::FromInt(TopmostNextSpawnableCounter) + "  |   " +
		"RearmostSplineUnitNumber: " + FString::FromInt(RearmostNextSpawnableCounter) + "  |   " +
		"TopRefreshSplineLength: " + FString::SanitizeFloat(TopRefreshSplineLength) + "  |   " +
		"RearRefreshSplineLength: " + FString::SanitizeFloat(RearRefreshSplineLength);

	return Result;
}

int32 FTubeModuleEntity::DisplayableSplineUnitSum()
{
	return (DisplayableSplineUnitBuffer * 2) + 1;
}
