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
		KPOptionSet k_options = new KPOptionSet;
				
		KPOption option1 = new KPDialog("hello");
		KPOption option2 = new KPDialog("world");
		option1.SetCondition(new KPConditionEquals(data,1));		
		option2.SetCondition(new KPConditionEquals(data,2));

		k_options.AddOption(option1);
		k_options.AddOption(option2);
		
		KPDialog k_dialog;
		if(KPDialog.CastTo(k_dialog, k_options.GetFirstMatch()))
		{
			Print(k_dialog.m_text);
		} else {
			Print("No match!")
		}
		
	
	
	}
	
	
	
	
	
	
}
