// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "TubeModuleEntity.generated.h"

/**
 * 
 */
USTRUCT(BlueprintType)
struct FTubeModuleEntity
{
    GENERATED_BODY()

public:
	FTubeModuleEntity(int32 UnitLimit = 1);
	FString ToDebugString();

    // ���݂�SplineUnit����̓����\���\�ȃo�b�t�@�����K��
    UPROPERTY(EditAnyWhere, BluePrintReadWrite, Category = "Struct")
	int32 DisplayableSplineUnitBuffer;

	// ���̐�[��Spawn�\��counter�ԍ�
    UPROPERTY(EditAnyWhere, BluePrintReadWrite, Category = "Struct")
	int32 TopmostNextSpawnableCounter;

	// ���̌�[��Spawn�\��counter�ԍ�
    UPROPERTY(EditAnyWhere, BluePrintReadWrite, Category = "Struct")
	int32 RearmostNextSpawnableCounter;

    // ����PointBuilder/AssetsBuilder�̋N���|�C���g
    UPROPERTY(EditAnyWhere, BluePrintReadWrite, Category = "Struct")
	float TopRefreshSplineLength;

    // �߂�ꍇ��PointBuilder/AssetsBuilder�̋N���|�C���g
    UPROPERTY(EditAnyWhere, BluePrintReadWrite, Category = "Struct")
	float RearRefreshSplineLength;

public:
	// �����\���\��SplineUnit�̐����v�l
	int32 DisplayableSplineUnitSum();

};