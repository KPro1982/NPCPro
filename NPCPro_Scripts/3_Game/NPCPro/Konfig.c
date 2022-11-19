class NPC_Konfig
{

	protected static string ConfigPATH = "$profile:\\NPCPro\\Config_settings.json";
	private static const string configRoot = "$profile:\\NPCPro\\";	
	

/////////////////////////////////////////////////////////////////////////////////////////////////////	
// Variables to save go here
//
	string ConfigVersion = "1";
	string ConfigString = "Hello World!";
	
	
// NonSerialed Variables that should not be saved go here
	[NonSerialized()]
	int ConfigInt = 1;
	
	
//////////////////////////////////////////////////////////////////////////////////////////////////
	
	void NPC_Konfig()
	{
	
		// insert default settings here
	
	
	}
	
	// Setters are required to ensure SHumanCommandMoveSettings
	
	void SetConfigString(string value)
	{
		ConfigString = value;
		Save();
	}

	
	void Load(){
		Print("[NPCPro] Loading Config");
		if (GetGame().IsServer()){
			
			if (FileExist(configRoot)==0) // Save Directory Does not Exist
	        {
	            Print("[NPCPro] '" + configRoot + "' does not exist, creating directory");
	            MakeDirectory(configRoot);
	        }
			
			if (FileExist(ConfigPATH)){ //If Config File exist load File
			    JsonFileLoader<NPC_Konfig>.JsonLoadFile(ConfigPATH, this);
				if (ConfigVersion != "1"){
					ConfigVersion = "1";
					Save();
				}
			}else{ //File does not exist create file
				Save();
			}
		}
	}
	
	void Save(){
		if (GetGame().IsServer()){
		
			JsonFileLoader<NPC_Konfig>.JsonSaveFile(ConfigPATH, this);
			
		} else {
		
			GetRPCManager().SendRPC("NPC_NPCPro", "RPCNPC_Update", new Param1< NPC_Konfig >( this ), true, NULL);
		}

		
	}


		
}
ref NPC_Konfig m_NPC_Konfig;

//Helper function to return Config
static ref NPC_Konfig NPC_GetKonfig()
{
	if (!m_NPC_Konfig)
	{
		m_NPC_Konfig = new NPC_Konfig;
			
		if ( GetGame().IsServer() ){
			m_NPC_Konfig.Load();
		}
	}

	return m_NPC_Konfig;
};
