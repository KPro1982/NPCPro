class KPOption
{

	ref KPCondition m_condition;
	
	void SetCondition(KPCondition cond)
	{
		m_condition = cond;
	
	}

	bool IsSatisfied()
	{
		return m_condition.SatisfiesCondition();
	}
}