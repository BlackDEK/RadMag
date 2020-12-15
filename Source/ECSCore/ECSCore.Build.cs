using System.IO;
using UnrealBuildTool;

public class ECSCore : ModuleRules
{
	public ECSCore(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.NoSharedPCHs;
		PrivatePCHHeaderFile = "MainPCH.h";
		CppStandard = CppStandardVersion.Cpp17;

		PublicDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine", "InputCore", "EnTT"});
		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}