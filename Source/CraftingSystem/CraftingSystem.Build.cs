// Copyright Epic Games, Inc. All Rights Reserved.

using UnrealBuildTool;

public class CraftingSystem : ModuleRules
{
	public CraftingSystem(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.UseExplicitOrSharedPCHs;

        PublicDependencyModuleNames.AddRange(new[]
        {
	        "Core", 
	        "CoreUObject", 
	        "Engine", 
	        "InputCore", 
	        "NavigationSystem", 
	        "AIModule",
	        "Niagara",
	        "EnhancedInput",
	        "UMG"
        });
    }
}
