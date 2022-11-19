class KPPlayerData
{
	
	
	ref array<ref KPDataBase> m_Data;
	
	void KPPlayerData(string steamid, int rep, int rank)
	{
		m_Data = new array<ref KPDataBase>;
		m_Data.Insert(new KPDataString("steamid","string",steamid));
		m_Data.Insert(new KPDataInt("reputation","int",rep));
		m_Data.Insert(new KPDataInt("rank","int",rank));
		
	
	}
	
	void GetField(string kpfield, out int result)
	{
		
		KPDataBase kData = FindField(kpfield);
		
		auto converter = CF_TypeConverter.Get(string);

		converter.SetString(kData.m_Value);

		result = converter.GetInt();
	}
	
	void GetField(string kpfield, out string result)
	{
		KPDataBase kData = FindField(kpfield);
		result =  kData.m_Value;
	}
	
	KPDataBase FindField(string kpfield)
	{
		foreach (KPDataBase elem : m_Data)
		{
			if (elem.m_Name == kpfield)
			{
				return elem;
			}
		
		}
		return null;
	
	
	}
	
	
	
	

	void SetField(string kpfield, int id)
	{
		auto converter = CF_TypeConverter.Get(string);

		converter.SetInt(id);

		converter.Write(this, kpfield);
	}
	
}