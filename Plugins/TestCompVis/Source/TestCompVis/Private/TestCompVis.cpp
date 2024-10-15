// Copyright Epic Games, Inc. All Rights Reserved.

#include "TestCompVis.h"

#include "UnrealEdGlobals.h"
#include "YaksueComponent.h"
#include "YaksueComponentVisualizer.h"
#include "Editor/UnrealEdEngine.h"

#define LOCTEXT_NAMESPACE "FTestCompVisModule"

void FTestCompVisModule::StartupModule()
{
	// This code will execute after your module is loaded into memory; the exact timing is specified in the .uplugin file per-module

	// 注册组件可视化器
	if (GUnrealEd != NULL)
	{
		TSharedPtr<FYaksueComponentVisualizer> Visualizer = MakeShareable(new FYaksueComponentVisualizer());
    
		if (Visualizer.IsValid())
		{
			GUnrealEd->RegisterComponentVisualizer(UYaksueComponent::StaticClass()->GetFName(), Visualizer);
			Visualizer->OnRegister();
		}
	}
}

void FTestCompVisModule::ShutdownModule()
{
	// This function may be called during shutdown to clean up your module.  For modules that support dynamic reloading,
	// we call this function before unloading the module.

	// 解除注册组件可视化器
	if (GUnrealEd != NULL)
	{
		GUnrealEd->UnregisterComponentVisualizer(UYaksueComponent::StaticClass()->GetFName());
	}
}

#undef LOCTEXT_NAMESPACE
	
IMPLEMENT_MODULE(FTestCompVisModule, TestCompVis)