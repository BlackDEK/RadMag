using System.IO;
using UnrealBuildTool;

public class RadMag : ModuleRules
{
	public RadMag(ReadOnlyTargetRules Target) : base(Target)
	{
		PCHUsage = PCHUsageMode.NoSharedPCHs;
		PrivatePCHHeaderFile = "MainPCH.h";
		CppStandard = CppStandardVersion.Cpp17;

		PublicDependencyModuleNames.AddRange(new string[] {"Core", "CoreUObject", "Engine", "InputCore", "EnTT"});
		PrivateDependencyModuleNames.AddRange(new string[] { });
	}
}