// Fill out your copyright notice in the Description page of Project Settings.

#include "TubeModule.h"
#include "ProcedualSplineActorsBuilder.h"
#include "ProcedualSplineActorsBuilder.h"

void UProcedualSplineActorsBuilder::SpawnActors(
	AActor *Owner,
	USplineComponent *Spline,
	FSpawnedSplineUnit &SpawnedSplineUnit
)
{
	for (FAssignedSplineUnitPoint AssignedSplineUnitPoint : SpawnedSplineUnit.AssignedSplineUnitPoints)
	{
		if (Owner && Spline) {
			for(FSpawnableActor SpawnableActor : SpawnedSplineUnit.SplineUnit.SpawnableActors)
			{
				FActorSpawnParameters SpawnParams;
				SpawnParams.Owner = Owner;

				AActor* const SpawningObject = 
					GetWorld()->SpawnActor<AActor>(
						SpawnableActor.WhatToSpawn,
					    AssignedSplineUnitPoint.Location,
						AssignedSplineUnitPoint.Rotation,
						SpawnParams
					);


				SpawnedSplineUnit.PushSpawnedSplineUnitActor(SpawningObject);
			}

		}
		else {
			if (GEngine) {
				GEngine->AddOnScreenDebugMessage(-1, 5.f, FColor::Yellow, TEXT("UProedualSplineActorsBuilder doesn't initialized"));
			}
		}

	}
}




