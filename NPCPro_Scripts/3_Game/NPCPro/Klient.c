class NPC_Klient
{

	private static string ConfigSettingsPATH = "$profile:\\NPCProConfig\\Client_settings.json";
	private static string configRoot = "$profile:\\NPCProConfig\\";	

	string ConfigVersion = "2";
	string m_hello = "Hello World";
	
	void NPC_Klient()
	{
	

	
	
	}
	
	void Load(){
		if (GetGame().IsClient() || !GetGame().IsMultiplayer()){
			
			if (FileExist(configRoot)==0) // Save Directory Does not Exist
	        {
	            Print("[NPCProConfig] '" + configRoot + "' does not exist, creating directory");
	            MakeDirectory(configRoot);
	        }
			
			
			
			
			if (FileExist(ConfigSettingsPATH)){ //If config exist load File
			    JsonFileLoader<NPC_Klient>.JsonLoadFile(ConfigSettingsPATH, this);
				if (ConfigVersion != "2"){
					ConfigVersion = "2";
					Save();
				}
			}
		}
	}
	
	void Save(){
		JsonFileLoader<NPC_Klient>.JsonSaveFile(ConfigSettingsPATH, this);
	}
	
	
	
}


static ref NPC_Klient m_NPC_Klient;

//Helper function to return Config
static NPC_Klient NPC_GetKlient()
{
	if (!m_NPC_Klient)
	{
		m_NPC_Klient = new NPC_Klient;
			
		if ( !GetGame().IsServer() ){
			m_NPC_Klient.Load();
		}
	}
	return m_NPC_Klient;
};
