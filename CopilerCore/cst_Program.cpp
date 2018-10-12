#include "cst_Program.h"

CopilerCore::cst_Program::cst_Program(LexAnalyzer *a)
{
	LexAnalyzer* m_lex = a;
}

void CopilerCore::cst_Program::checkSyntax()
{
	const Token* t = m_lex->getNextToken();
	while (t->getLex().compare("var") == 0)
	{
		cst_Variables* v = new cst_Variables(m_lex);
		v->checkSyntax();
		t = m_lex->getNextToken();
	}
	while (t->getLex().compare("function") == 0)
	{
		cst_Funcion *f = new cst_Funcion(m_lex);
		f->checkSyntax();
		t = m_lex->getNextToken();
	}

	throw gcnew System::NotImplementedException();
}
