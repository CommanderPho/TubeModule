// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "Components/PrimitiveComponent.h"
#include "Components/SplineComponent.h"
#include "SplineUnit.h"
#include "TubeModuleEntity.h"
#include "ProcedualSplinePointBuilder.h"
#include "ProcedualSplineActorsBuilder.h"
#include "ProcedualSplineDirector.generated.h"

/**
 * 
 */
UCLASS()
class TUBEMODULE_API UProcedualSplineDirector : public UPrimitiveComponent
{
	GENERATED_BODY()

public:
	USplineComponent *Spline;
	TArray<FSplineUnit> SplineUnits;
	TArray<FSpawnedSplineUnit> SpawnedSplineUnits;
	FTubeModuleEntity Entity;
	UProcedualSplinePointBuilder *ProcedualSplinePointBuilder;
	UProcedualSplineActorsBuilder *ProcedualSplineActorsBuilder;

	AActor *Owner;

	float DeletedSplineLengthsDiff;

	bool Refreshable;

public:
	void Initialize(
		USplineComponent *InSpline,
		TArray<FSplineUnit> &InSplineUnits,
		TArray<FSpawnedSplineUnit> &InSpawnedSplineUnits,
		float &InDeletedSplineLengthsDiff,
		FTubeModuleEntity &InEntity,
		UProcedualSplinePointBuilder *InProcedualSplinePointBuilder,
		UProcedualSplineActorsBuilder *InProcedualSplineActorsBuilder
	);

	void CreateInitialSpline();

	void CheckTubeModuleEntity(float CurrentLength);

private:
	void GenerateNextSpawnedSplineUnit();

	void RefreshEntityParameters();

	void DeleteFirstSpawnedSplineUnit();

	void UProcedualSplineDirector::UpdateSpline();

};