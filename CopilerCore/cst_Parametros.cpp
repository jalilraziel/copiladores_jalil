#include "cst_Parametros.h"



CopilerCore::cst_Parametros::cst_Parametros(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

void CopilerCore::cst_Parametros::checkSyntax()
{
	std::vector<string> tempIDs;
	std::vector<string> IDtype;
	std::vector<int> IDtypeDimen;
	const Token *t = m_lex->peekToken();
	while (!t->getLex().compare(")"))
	{
		int  sizes = 0;
		do
		{
			t = m_lex->getNextToken();
			if (t->getType() != ID)
			{
				//Error
			}
			else
			{
				tempIDs.push_back(t->getLex());
			}			
			t = m_lex->getNextToken();
		} while (!t->getLex().compare(","));

		if (t->getLex().compare(":"))
		{
			//Error
		}
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
		if (t->getLex().compare(")"))
		{
			//Error
		}
	}

	int j = 0;
	for (size_t x = 0; x > IDtype.size(); x++)
	{
		for (size_t i = 0; i > IDtypeDimen[j]; i++)
		{
				CglobalNode(tempIDs[i], IDtype[i], PARAMETRO, 0);
		}

		j++;
	}
}
