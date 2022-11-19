class KPOption
{

	ref KPConditionBase m_condition;
	
	void SetCondition(KPConditionBase cond)
	{
		m_condition = cond;
	
	}

	bool IsSatisfied()
	{
		return m_condition.SatisfiesCondition();
	}
	
	void PrintOption()
	{
		
	}

}