class KPPlayerData
{
	string m_steamid;
	int m_reputation;
	int m_rank;
	
	void KPPlayerData(string steamid, int rep, int rank)
	{
		m_steamid = steamid;
		m_reputation = rep;
		m_rank = rank;
	
	}
}