class KPNullCondition extends KPConditionBase
{
	


}
class KPConditionEquals extends KPConditionBase
{

	
	void KPConditionEquals(KPPlayerData data, string kpfield, int comparator)
	{
		m_comparator = comparator;
		m_field = kpfield;
		m_data = data;
	}

	override bool SatisfiesCondition()
	{
		
		int intField ;
		m_data.GetField(m_field, intField);
		if(m_comparator == intField)
		{
			return true;
		}
	
		
		return false;
	}

}

class KPConditionGreaterThan extends KPConditionBase
{
	
	void KPConditionGreaterThan(KPPlayerData data, string kpfield, int comparator)
	{
		m_comparator = comparator;
		m_field = kpfield;
		m_data = data;
	}

	override bool SatisfiesCondition()
	{
		
		int intField ;
		m_data.GetField(m_field, intField);
		if(intField > m_comparator )
		{
			return true;
		}
	
		
		return false;
	}

}

class KPConditionLessThan extends KPConditionBase
{
	
	void KPConditionLessThan(KPPlayerData data, string kpfield, int comparator)
	{
		m_comparator = comparator;
		m_field = kpfield;
		m_data = data;
	}

	override bool SatisfiesCondition()
	{
		
		int intField ;
		m_data.GetField(m_field, intField);
		if(intField < m_comparator )
		{
			return true;
		}
	
		
		return false;
	}

}