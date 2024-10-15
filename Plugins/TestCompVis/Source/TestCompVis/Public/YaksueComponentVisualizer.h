// Fill out your copyright notice in the Description page of Project Settings.

#pragma once

#include "ComponentVisualizer.h"

class FYaksueComponentVisualizer : public FComponentVisualizer
{
public:
	//当前正在编辑的组件，应在VisProxyHandleClick中设置。
	class UYaksueComponent* CurrentEditingComponent;

	//绘制组件可视化的图形：
	virtual void DrawVisualization(const UActorComponent* Component, const FSceneView* View, FPrimitiveDrawInterface* PDI) override;
	
	//接收点击事件
	virtual bool VisProxyHandleClick(FEditorViewportClient* InViewportClient, HComponentVisProxy* VisProxy, const FViewportClick& Click) override;

	//指定操纵器控件的位置
	virtual bool GetWidgetLocation(const FEditorViewportClient* ViewportClient, FVector& OutLocation) const override;

	//处理操纵器控件的输入
	virtual bool HandleInputDelta(FEditorViewportClient* ViewportClient, FViewport* Viewport, FVector& DeltaTranslate, FRotator& DeltalRotate, FVector& DeltaScale) override;
};

//针对点的VisProxy(点击响应事件)
struct HYaksuePointVisProxy : public HComponentVisProxy
{
	DECLARE_HIT_PROXY();
	HYaksuePointVisProxy(const UActorComponent* InComponent, int32 InPointIndex);
	//记录哪一个点：
	int32 PointIndex;
};

