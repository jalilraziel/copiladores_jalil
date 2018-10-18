#include "cst_BloqFunciones.h"



CopilerCore::cst_BloqFunciones::cst_BloqFunciones(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

void CopilerCore::cst_BloqFunciones::checkSyntax()
{
	const Token *t = m_lex->peekToken();
	if (t->getLex().compare("{")) {

		while (!t->getLex().compare("var"))
		{
			cst_Variables* v = new cst_Variables(m_lex, errormod, tabsyb);
			v->checkSyntax(false);
			t = m_lex->getNextToken();
		}
	}
	else
	{
		//error
	}
	if (!t->getLex().compare("}")) {
	//error
	}
}
