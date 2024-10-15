// Fill out your copyright notice in the Description page of Project Settings.


#include "YaksueComponentVisualizer.h"

void FYaksueComponentVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View,
	FPrimitiveDrawInterface* PDI)
{
	// FComponentVisualizer::DrawVisualization(Component, View, PDI);
	//四面体的四个顶点：
	FVector Pos[4] = { FVector(0,0,100),FVector(100,0,0), FVector(-50,-86,0),FVector(-50,86,0) };
	//在所有顶点之间画线：
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 4; j++)
			PDI->DrawLine(
				Pos[i],						//起点
				Pos[j],						//终点
				FLinearColor(0, 1, 1, 1),	//颜色
				SDPG_Foreground);			//前景
}
