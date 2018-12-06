#include "cst_Parametros.h"



CopilerCore::cst_Parametros::cst_Parametros(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

CopilerCore::cst_Parametros::~cst_Parametros() {
}

bool CopilerCore::cst_Parametros::checkSyntax(std::string funcName)
{
	std::vector<string> tempIDs;
	std::vector<string> IDtype;
	std::vector<int> IDtypeDimen;
	const Token *t = m_lex->peekToken();
	while (m_lex->peekToken()->getLex().compare(")"))
	{
		int  sizes = 0;
		do
		{
			t = m_lex->getNextToken();
			if (t->getType() != ID) {
				if (!errormod->addErrorSin(t->getLineNumber(), "no se reconoce variable")) return false;
			}
			else{
				tempIDs.push_back(t->getLex());
			}			
			t = m_lex->getNextToken();
		} while (!t->getLex().compare(","));
		if (t->getLex().compare(":")) {
			if (!errormod->addErrorSin(t->getLineNumber(), "se esperaba :")) return false;
		}
		t = m_lex->getNextToken();
		if (!t->getLex().compare("int") || !t->getLex().compare("float") || !t->getLex().compare("string") || !t->getLex().compare("bool")) {
			for (int i = 0; i < tempIDs.size(); i++) {
				tabsyb->addsymbol(tempIDs[i], t->getLex(), PARAMETRO, 0, nullptr, nullptr);
			}
		}
		else
		{
			if (!errormod->addErrorSin(t->getLineNumber(), "no se reconoce variable")) return false;
		}
	}
	return true;	
}