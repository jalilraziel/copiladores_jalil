#include "cst_Variables.h"
#include "cst_Parametros.h"


CopilerCore::cst_Variables::cst_Variables(LexAnalyzer *a)
{
	LexAnalyzer* m_lex = a;
}

void CopilerCore::cst_Variables::checkSyntax()
{
	std::vector<int> tempDimen;
	std::vector<string> tempIDs;
	std::vector<string> IDtype;
	const Token *t = m_lex->peekToken();
	while (!t->getLex().compare("id"))
	{
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

				}
				else
				{
					tempDimen.push_back(t->getLex());
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
		if (t->getLex().compare(":"))
		{
			//Error
		}
		t = m_lex->getNextToken();
		if (!t->getLex().compare("int") || !t->getLex().compare("float") || !t->getLex().compare("string"))
		{
			IDtype.push_back(t->getLex());
			//Ciclo For para agregar IDs a la tabla de símbolos
		}
		else
		{
			//
		}
		//Leer “;”
	}

}
