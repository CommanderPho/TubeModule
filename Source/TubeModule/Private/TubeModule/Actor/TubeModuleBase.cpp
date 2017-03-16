// Fill out your copyright notice in the Description page of Project Settings.

#include "TubeModule.h"
#include "TubeModuleBase.h"


// Sets default values
ATubeModuleBase::ATubeModuleBase()
{
	PrimaryActorTick.bCanEverTick = true;
	SetRootComponent(CreateDefaultSubobject<UStaticMeshComponent>(FName("SM")));

    Spline = CreateDefaultSubobject<USplineComponent>(FName("Spline"));
	Spline->SetupAttachment(StaticMesh);

    ProcedualSplineDirector = CreateDefaultSubobject<UProcedualSplineDirector>(FName("SplineDirector"));
    ProcedualSplinePointBuilder = CreateDefaultSubobject<UProcedualSplinePointBuilder>(FName("SplinePointBuilder"));
    ProcedualSplineActorsBuilder = CreateDefaultSubobject<UProcedualSplineActorsBuilder>(FName("SplineActorsBuilder"));
	TubeModuleEntity = FTubeModuleEntity(2);

	DeletedSplineLengthsDiff = 0;

	SplineUnits = SplineUnitGenerator->GenerateSplineUnits("splinetest2.json");
}

// Called when the game starts or when spawned
void ATubeModuleBase::BeginPlay()
{
	Super::BeginPlay();
	ProcedualSplineDirector->Initialize(
		Spline,
		SplineUnits,
		SpawnedSplineUnits,
		DeletedSplineLengthsDiff,
		TubeModuleEntity,
		ProcedualSplinePointBuilder,
		ProcedualSplineActorsBuilder
	);

	ProcedualSplineDirector->CreateInitialSpline();
}

void ATubeModuleBase::WatchSplineLifeCycle(float CurrentLength)
{
	ProcedualSplineDirector->CheckTubeModuleEntity(CurrentLength);
}

FVector ATubeModuleBase ::GetCurrentLocationAlongSpline(float distance)
{
	//if (GEngine) { GEngine->AddOnScreenDebugMessage(-1, 1.f, FColor::Black, FString::SanitizeFloat(ProcedualSplineDirector->DeletedSplineLengthsDiff)); }
	return Spline->GetWorldLocationAtDistanceAlongSpline(distance - ProcedualSplineDirector->DeletedSplineLengthsDiff);
}

FVector ATubeModuleBase::GetCurrentDirectionAlongSpline(float distance)
{
	return Spline->GetWorldDirectionAtDistanceAlongSpline(distance - ProcedualSplineDirector->DeletedSplineLengthsDiff);
}

FRotator ATubeModuleBase::GetCurrentRotationAlongSpline(float distance)
{
	return Spline->GetWorldRotationAtDistanceAlongSpline(distance - ProcedualSplineDirector->DeletedSplineLengthsDiff);
}