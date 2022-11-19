class KPDialog extends KPOption
{
	string m_text;
	
	void KPDialog(string text, KPConditionBase cond)
	{
	
		m_text = text;
		SetCondition(cond);
	}
	
	override void PrintOption()
	{
		Print(m_text);
	}


}