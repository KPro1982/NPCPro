class KPConditionEquals extends KPCondition
{
	int m_rank;
	
	void KPConditionEquals(KPPlayerData data, int rank)
	{
		m_rank = rank;
		m_data = data;
	}

	override bool SatisfiesCondition()
	{
		if(m_data.m_rank == m_rank)
			return true;
		
		return false;
	}

}