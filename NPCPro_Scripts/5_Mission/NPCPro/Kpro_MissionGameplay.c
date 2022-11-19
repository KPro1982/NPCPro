modded class MissionGameplay
{   
// This runs on the client

	
	
	
	override void OnMissionStart()
	{
		super.OnMissionStart();
		NPC_GetKlient();
		GetRPCManager().AddRPC( "NPC_NPCPro", "RPCNPC_Konfig", this, SingeplayerExecutionType.Both );
		Print("#########[NPC_NPCPro][Client] Requesting Config From Server");
		GetRPCManager().SendRPC("NPC_NPCPro", "RPCNPC_Konfig", new Param1< NPC_Konfig >( NULL ), true, NULL);
	}
	
	// Client requests Konfig from Server
	void RPCNPC_Konfig( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
		Param1< NPC_Konfig > data;
		if ( !ctx.Read( data ) ) return;
		Print("########[NPC_NPCPro][Client] Received Config From Server");
		m_NPC_Konfig = data.param1;
	}
	
	
	override void OnUpdate(float timeslice)
	{        		
		super.OnUpdate(timeslice);		
		if ( GetGame().GetInput().LocalPress("SSActionName") && GetGame().GetUIManager().GetMenu() == NULL ) 
		{				
			Print(string.Format("Building OptionSet!"));
			BuildOptionSet();

							
								
		}
			
	}
	
	
	void BuildOptionSet()
	{
		KPPlayerData data = KPPlayerData("123", 1, 2);
		KPOptionSet k_options = new KPOptionSet;
				
		KPOption option1 = new KPOption;
		KPOption option2 = new KPOption;
		option1.SetCondition(new KPCondition(data));		
		option2.SetCondition(new KPCondition(data));

		k_options.AddOption(option1);
		k_options.AddOption(option2);
		
		Print(k_options.GetFirstMatch());
	
	}
	
	
	
	
	
	
}
