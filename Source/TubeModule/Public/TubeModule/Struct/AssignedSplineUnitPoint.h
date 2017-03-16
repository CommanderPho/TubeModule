// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/SplineComponent.h"
#include "AssignedSplineUnitPoint.generated.h"

USTRUCT(BlueprintType)
struct FAssignedSplineUnitPoint
{
	GENERATED_BODY()

public:
    UPROPERTY(EditAnyWhere, BluePrintReadWrite, Category = "Struct")
    FVector Location;

    UPROPERTY(EditAnyWhere, BluePrintReadWrite, Category = "Struct")
    FVector Direction;

    UPROPERTY(EditAnyWhere, BluePrintReadWrite, Category = "Struct")
    FRotator Rotation;

    UPROPERTY(EditAnyWhere, BluePrintReadWrite, Category = "Struct")
    int32 Index;

public:
	static FAssignedSplineUnitPoint GenerateAssignedSplineUnitPoint(USplineComponent *Spline, int32 PointsIndex);
};