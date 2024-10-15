// Fill out your copyright notice in the Description page of Project Settings.


#include "YaksueComponentVisualizer.h"

#include "YaksueComponent.h"

DEFINE_LOG_CATEGORY_STATIC(LogYaksueComponentVisualizer, Log, All);
//UE_LOG(LogYaksueComponentVisualizer, Warning, TEXT("log %s"),);

IMPLEMENT_HIT_PROXY(HYaksuePointVisProxy, HComponentVisProxy);

HYaksuePointVisProxy::HYaksuePointVisProxy(const UActorComponent * InComponent, int32 InPointIndex)
	: HComponentVisProxy(
		InComponent,	//组件
		HPP_Wireframe),	//优先级
		PointIndex(InPointIndex)
{
}

void FYaksueComponentVisualizer::DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI)
{
	//将组件类型转换为UYaksueComponent
	const UYaksueComponent* comp = (UYaksueComponent*)Component;

	//在所有顶点之间画线：
	for (int i = 0; i < 4; i++)
		for (int j = i + 1; j < 4; j++)
			PDI->DrawLine(
				comp->Points[i],			//起点
				comp->Points[j],			//终点
				FLinearColor(0, 1, 1, 1),	//颜色
				SDPG_Foreground);			//前景

	//绘制四个顶点并放置Proxy
	for (int i = 0; i < 4; i++)
	{
		//开始设置Proxy
		PDI->SetHitProxy(new HYaksuePointVisProxy(Component, i));
		
		//画点：
		PDI->DrawPoint(
			comp->Points[i],						//位置
			FLinearColor(1, 0, 0, 1),	//颜色
			20.f,						//大小
			SDPG_Foreground);			//前景
		
		//结束设置Proxy
		PDI->SetHitProxy(NULL);
	}
}

bool FYaksueComponentVisualizer::VisProxyHandleClick(FEditorViewportClient* InViewportClient, HComponentVisProxy* VisProxy, const FViewportClick& Click)
{
	const HYaksuePointVisProxy* Proxy = (HYaksuePointVisProxy*)VisProxy;

	//设置当前正在编辑的组件：
	CurrentEditingComponent = (UYaksueComponent*)Proxy->Component.Get();

	//设置当前所选的点的序号
	CurrentEditingComponent->SelectingPointIndex = Proxy->PointIndex;
	
	//测试输出所点击的点的序号
	UE_LOG(LogYaksueComponentVisualizer, Warning, TEXT("click point : %d"), Proxy->PointIndex);

	return true;
}

bool FYaksueComponentVisualizer::GetWidgetLocation(const FEditorViewportClient* ViewportClient, FVector& OutLocation) const
{
	//位置就是当前所选点的位置：
	if (CurrentEditingComponent->SelectingPointIndex >= 0 && CurrentEditingComponent->SelectingPointIndex < CurrentEditingComponent->Points.Num())
	{
		OutLocation = CurrentEditingComponent->Points[CurrentEditingComponent->SelectingPointIndex];

		return true;
	}
	return false;
}

bool FYaksueComponentVisualizer::HandleInputDelta(FEditorViewportClient* ViewportClient, FViewport* Viewport, FVector& DeltaTranslate, FRotator& DeltalRotate, FVector& DeltaScale)
{
	//处理位移：
	if (!DeltaTranslate.IsZero())
	{
		//当前所选的顶点加上位移：
		CurrentEditingComponent->Points[CurrentEditingComponent->SelectingPointIndex] += DeltaTranslate;
	}

	return true;
}