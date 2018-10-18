#include "cst_Variables.h"

CopilerCore::cst_Variables::cst_Variables(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

void CopilerCore::cst_Variables::checkSyntax(bool node)
{
	std::vector<int> tempDimen;
	std::vector<string> tempIDs;
	std::vector<string> IDtype;
	std::vector<int> IDtypeDimen;
	const Token *t = m_lex->peekToken();
	while (!t->getLex().compare("var"))
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
			if (!t->getLex().compare("[") )
			{
				t = m_lex->getNextToken();
				if (t->getType() != INT)
				{
					//error
				}
				else
				{
					tempDimen.push_back(stoi(t->getLex()));
					t = m_lex->getNextToken();
					if (!t->getLex().compare("]"))
					{
						//error
					}
				}
			}
			else
			{
				tempDimen.push_back(0);
			}
			t = m_lex->getNextToken();
		} while (!t->getLex().compare(","));
		IDtypeDimen.push_back(sizes);
		
		if (t->getLex().compare(":"))
		{
			//Error
		}
		else
		{
			t = m_lex->getNextToken();
		}
		if (!t->getLex().compare("int") || !t->getLex().compare("float") || !t->getLex().compare("string") || !t->getLex().compare("bool"))
		{
			IDtype.push_back(t->getLex());
			t = m_lex->getNextToken();
		}
		else
		{
			//Error
		}
		if (t->getLex().compare(";"))
		{
			//Error
		}
	}

	int j = 0;
	for (size_t x = 0; x > IDtype.size(); x++)
	{
		for (size_t i = 0; i > IDtypeDimen[j]; i++)
		{
			if (node = true) {
				CglobalNode(tempIDs[i], IDtype[i], GLOBAL_VAR, tempDimen[i]);
			}
			else
			{
				CglobalNode(tempIDs[i], IDtype[i], LOCAL_VAR, tempDimen[i]);
			}
		}
		
		j++;
	}
}
