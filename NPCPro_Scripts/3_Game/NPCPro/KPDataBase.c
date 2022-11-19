class KPDataBase
{
	string m_Name;
	string m_TypeName;
	string m_Value;
	
	
	
	void PrintData()
	{
		Print(string.Format("-- KPDATA -- Name: %1, Type: %2, Value: %3", m_Name, m_TypeName, m_Value));
	
	}
	
	

}

class KPDataInt extends KPDataBase
{
	void KPDataInt(string name, string typeName, int value)
	{
		m_Name = name;
		m_TypeName = typeName;
		
		auto converter = CF_TypeConverter.Get(string);
		converter.SetInt(value);
		m_Value = converter.GetString();
		PrintData();
	
	}

}

class KPDataString extends KPDataBase
{

	void KPDataString(string name, string typeName, string value)
	{
		m_Name = name;
		m_TypeName = typeName;
		m_Value = value;
		PrintData();
	
	}


}