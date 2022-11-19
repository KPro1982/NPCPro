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
		array<ref KPOption> matches = GetAllMatching();
		
		if(matches.Count() > 0)
		{
			return matches.Get(0);
		}
		return null;
	
	}
	KPOption GetRandomMatch()
	{
		array<ref KPOption> matches = GetAllMatching();
		
		if(matches.Count() > 0)
		{
			return matches.GetRandomElement();
		}
		return null;
	
	
	}
	
	array<ref KPOption> GetAllMatching()
	{
	
		array<ref KPOption> matches = new array<ref KPOption>;
	
		foreach (KPOption opt : m_options)
		{
			if(opt.IsSatisfied())
			{
				matches.Insert(opt);
			}
		
		}
		
		return matches;
	
	
	}
	
	void PrintAllMatches()
	{
		array<ref KPOption> matches = GetAllMatching();
		Print("--Matches--");
		Print(string.Format("Matches: %1", matches.Count()));
		foreach (KPOption opt : matches)
		{
				opt.PrintOption();
		}
	
	}
	
}