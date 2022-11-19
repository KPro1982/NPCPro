class CfgPatches
{
	class NPCPro_Scripts
	{
        units[] = {};
        weapons[] = {};
        requiredVersion = 0.1;
		requiredAddons[] = {"DZ_Data","JM_CF_Scripts", "RPC_Scripts", "JM_CF_GUI", "JM_CF_Defines"}; // add required mods here if any "mod1", "mod2"
	};
};

class CfgMods 
{
	class Kpro_NPCPro
	{
		name = "Kpro1982";
		dir = "NPCPro";
		credits = "Kpro1982";
		author = "Kpro1982";
		overview = "A new mod";
		creditsJson = "NPCPro/NPCPro_Scripts/Data/Credits.json";
		versionPath = "NPCPro/NPCPro_Scripts/Data/Version.hpp";
		type = "mod";
		
		 inputs="NPCPro\NPCPro_Scripts\data\inputs.xml";
		
		dependencies[] =
		{
			"Game", "World", "Mission"
		};

		
		class defs
		{
			
			class engineScriptModule
			{
				value = "";
				files[] =
				{
					"scripts/1_core"
					"NPCPro/NPCPro_Scripts/common",
					"NPCPro/NPCPro_Scripts/1_core"
				};
			};

			class gameScriptModule
			{
				value="";
				files[] = 
				{
					"scripts/3_Game"
					"NPCPro/NPCPro_Scripts/common",
					"NPCPro/NPCPro_Scripts/3_Game"
				};
			};
			class worldScriptModule
			{
				value="";
				files[] = 
				{
					"scripts/4_World"
					"NPCPro/NPCPro_Scripts/common",
					"NPCPro/NPCPro_Scripts/4_World"
				};
			};

			class missionScriptModule 
			{
				value="";
				files[] = 
				{
					"scripts/5_Mission"
					"NPCPro/NPCPro_Scripts/common",
					"NPCPro/NPCPro_Scripts/5_Mission"
				};
			};
		};
	};
};
