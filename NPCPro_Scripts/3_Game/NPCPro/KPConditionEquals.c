class KPConditionEquals extends KPCondition
{
	int m_comparator;
	
	void KPConditionEquals(KPPlayerData data, string kpfield, int comparator)
	{
		m_comparator = comparator;
		m_field = kpfield;
		m_data = data;
	}

	override bool SatisfiesCondition()
	{
		
		int intRank ;
		m_data.GetField(m_field, intRank);
		if(m_comparator == intRank)
		{
			return true;
		}
	
		
		return false;
	}

}