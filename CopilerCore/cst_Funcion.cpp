#include "cst_Funcion.h"



CopilerCore::cst_Funcion::cst_Funcion(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

CopilerCore::cst_Funcion::~cst_Funcion(){
}

bool CopilerCore::cst_Funcion::checkSyntax()
{
	std::string name;
	std::string type;
	const Token* t = m_lex->getNextToken();
	if (t->getType() != ID) {
		if (!errormod->addErrorSin(t->getLineNumber(), "no se reconoce variable")) return false;
	}
	name = t->getLex();
	t = m_lex->getNextToken();
	if (t->getType() != OPERADOR_AGRUPADOR) {
		cst_Parametros* p = new cst_Parametros(m_lex, errormod, tabsyb);
		if(!p->checkSyntax(name)) return false;
	}
	t = m_lex->getNextToken();
	if (t->getType() != OPERADOR_AGRUPADOR) {
		if (!errormod->addErrorSin(t->getLineNumber(), "se esperaba &")) return false;
	}
	t = m_lex->getNextToken();
	if (t->getLex().compare(":")) {
		if (!errormod->addErrorSin(t->getLineNumber(), "se esperaba :")) return false;
	}
	t = m_lex->getNextToken();
	if (!t->getLex().compare("int") || !t->getLex().compare("float") || !t->getLex().compare("string") || !t->getLex().compare("bool")) {
		type = t->getLex();
	}
	else
	{
		errormod->addErrorSin(t->getLineNumber(), "tipo de variable sin identificar");
	}
	t = m_lex->getNextToken();
	if (t->getType() != OPERADOR_AGRUPADOR) {
		if (!errormod->addErrorSin(t->getLineNumber(), "se esperaba }")) return false;
	}
	tabsyb->addsymbol(name, type, FUNCION, 0, nullptr, nullptr);
	cst_BloqFunciones* fb = new cst_BloqFunciones(m_lex, errormod, tabsyb);
	if (!fb->checkSyntax(name)) return false;
	return true;
}
