#include "cst_Funcion.h"



CopilerCore::cst_Funcion::cst_Funcion(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

void CopilerCore::cst_Funcion::checkSyntax()
{
	std::vector<string> tempIDs;
	std::vector<string> IDtype;
	std::vector<int> IDtypeDimen;
	const Token *t = m_lex->peekToken();
	while (!t->getLex().compare("function"))
	{
		t = m_lex->getNextToken();
		if (t->getLex().compare("(")) {
			//error
		}
		if (t->getType() != ID) {
			cst_Parametros* p = new cst_Parametros(m_lex, errormod, tabsyb);
			p->checkSyntax();
			t = m_lex->getNextToken();
		}
		if (t->getLex().compare(":"))
		{
			//Error
		}
		if (t->getLex().compare(":"))
		{
			//Error
		}
		else
		{
			t = m_lex->getNextToken();
			if (!t->getLex().compare("int") || !t->getLex().compare("float") || !t->getLex().compare("string") || !t->getLex().compare("bool"))
			{
				IDtype.push_back(t->getLex());
				t = m_lex->getNextToken();
			}
			else
			{
				//Error
			} 
		}

		int j = 0;
		for (size_t i = 0; i > IDtypeDimen[j]; i++)
		{
				CglobalNode(tempIDs[i], IDtype[i], FUNCION, 0);	
		}
	}
}
