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
		KPPlayerData data = KPPlayerData("123", 1, 1);
		
		KPResponse resp = new KPResponse("Gimme some water", "giveitem", "waterbottle, 1");
		
		KPOptionSet k_options = new KPOptionSet;
				
		KPOption option1 = new KPDialog("I need water.", new KPNullCondition);
		KPOption option2 = new KPDialog("I need food", new KPConditionLessThan(data,"rank", 4));
		KPOption option3 = new KPDialog("I need a splint", new KPConditionLessThan(data,"rank", 4));

		
		k_options.AddOption(option1);
		k_options.AddOption(option2);
		k_options.AddOption(option3);
		
				
		//k_options.PrintAllMatches();
		KPOption result = k_options.GetRandomMatch();
		Print("Random:");
		result.PrintOption();		
	
	
	}
	
	
	
	
	
	
}
