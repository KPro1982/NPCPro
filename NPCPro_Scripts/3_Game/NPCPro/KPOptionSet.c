class KPOptionSet
{
	ref array<ref KPOption> m_options = {};

	void KPOptionSet()
	{
	
		// constructor
	
	}
	
	void AddOption(KPOption opt)
	{
		m_options.Insert(opt);
	
	}
	
	KPOption GetFirstMatch()
	{
		foreach (KPOption opt : m_options)
		{
			if(opt.IsSatisfied())
			{
				return opt;
			}
		
		}
		
		return null;
	
	}
	
}