#include "cst_Program.h"

CopilerCore::cst_Program::cst_Program(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

void CopilerCore::cst_Program::checkSyntax()
{
	const Token* t = m_lex->getNextToken();
	while (t->getLex().compare("var") == 0)
	{
		cst_Variables* v = new cst_Variables(m_lex, errormod, tabsyb);
		v->checkSyntax(true);
		t = m_lex->getNextToken();
	}
	while (t->getLex().compare("function") == 0)
	{
		cst_Funcion *f = new cst_Funcion(m_lex, errormod, tabsyb);
		f->checkSyntax();
		t = m_lex->getNextToken();
	}
	while (t->getLex().compare("main") == 0)
	{
		cst_BloqFunciones *bf = new cst_BloqFunciones(m_lex, errormod, tabsyb);
		bf->checkSyntax();
		t = m_lex->getNextToken();
	}

	throw gcnew System::NotImplementedException();
}
