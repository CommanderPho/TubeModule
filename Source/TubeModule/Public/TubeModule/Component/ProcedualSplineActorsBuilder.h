// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "SplineUnit.h"
#include "SpawnedSplineUnit.h"
#include "Components/PrimitiveComponent.h"
#include "Components/SplineComponent.h"
#include "ProcedualSplineActorsBuilder.generated.h"

/**
 * 
 */
UCLASS()
class TUBEMODULE_API UProcedualSplineActorsBuilder : public UPrimitiveComponent
{
	GENERATED_BODY()

public:
	void SpawnActors(AActor *Owner, USplineComponent *Spline, FSpawnedSplineUnit &SpawnedSplineUnit);

};