class KPResponse extends KPOption
{
	string m_displayText;
	string m_command;
	ref KPParam m_params;

	void KPResponse(string displayText, string command, string delim)
	{
		m_params = new KPParam(delim);
		m_displayText = displayText;
		m_command = command;
	
	}


}