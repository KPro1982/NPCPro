class KPParam
{
	string m_delimText;
	ref array<string> m_params = {};
	
	void KPParam(string text)
	{
		m_delimText = text;	
		m_params = Split(m_delimText);
	}
	
	int Count()
	{
		return m_params.Count();
	}
	
	array<string> Split(string delim)
	{
		array<string> tokens = new array<string>;
		delim.Split(",", tokens);
		
		return tokens;
		
	}
	
	string Get(int i)
	{
		return m_params.Get(i);
	
	}

}