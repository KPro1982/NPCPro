modded class MissionServer extends MissionBase
{
	override void OnInit() {
		super.OnInit();
		
		Print("[NPC_NPCPro] OnInit");
		NPC_GetKonfig();
		GetRPCManager().AddRPC( "NPC_NPCPro", "RPCNPC_Konfig", this, SingeplayerExecutionType.Both );
		GetRPCManager().AddRPC( "NPC_NPCPro", "RPCNPC_Update", this, SingeplayerExecutionType.Both );
	}
	
	// Server responds to client request
	void RPCNPC_Konfig( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {
		PlayerIdentity RequestedBy = PlayerIdentity.Cast(sender);
		
		if (RequestedBy){
			GetRPCManager().SendRPC("NPC_NPCPro", "RPCNPC_Konfig", new Param1< NPC_Konfig >( NPC_GetKonfig() ), true, RequestedBy);
			Print("#########config requested");
		}
	}
	
	
	// Server responds to client update request
	void RPCNPC_Update( CallType type, ref ParamsReadContext ctx, ref PlayerIdentity sender, ref Object target ) {		
		Param1< NPC_Konfig > data;
		if ( !ctx.Read( data ) ) return;
		Print("########[NPC_NPCPro][Client] Received Config From Server");
		m_NPC_Konfig = data.param1;
		m_NPC_Konfig.Save();
	}
	

}




