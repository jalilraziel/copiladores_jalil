#include "cst_Program.h"

CopilerCore::cst_Program::cst_Program(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c) {
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

CopilerCore::cst_Program::~cst_Program() {
}

bool CopilerCore::cst_Program::checkSyntax() {
	cst_BloqFunciones *bf = new cst_BloqFunciones(m_lex, errormod, tabsyb);

	const Token* t = m_lex->getNextToken();
	while (t->getLex().compare("var") == 0) {
		cst_Variables* v = new cst_Variables(m_lex, errormod, tabsyb);
		if(!v->checkSyntax(GLOBAL_VAR)) return false;
		t = m_lex->getNextToken();
	}
	while (t->getLex().compare("function") == 0) {
		cst_Funcion *f = new cst_Funcion(m_lex, errormod, tabsyb);
		if (!f->checkSyntax()) return false;
		t = m_lex->getNextToken();
	}
	if (t->getLex().compare("main") == 0)
	{
		t = m_lex->getNextToken();
		if (t->getType() == m_lex->peekToken()->getType()) {
			t = m_lex->getNextToken();
			t = m_lex->getNextToken();
			if (!t->getLex().compare("{"))
			{
				cst_BloqFunciones *bf = new cst_BloqFunciones(m_lex, errormod, tabsyb);
				bf->checkSyntax("main");
			}
			else
			{
				if (!errormod->addErrorSin(t->getLineNumber(), "se esperaba }"))
					return false;
			}
		}
	}
	else
	{

	}
	return true;
}
