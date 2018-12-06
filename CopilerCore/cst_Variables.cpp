#include "cst_Variables.h"

CopilerCore::cst_Variables::cst_Variables(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c) {
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

CopilerCore::cst_Variables::~cst_Variables() {
}

bool CopilerCore::cst_Variables::checkSyntax(E_SCOPE scope, string funcName) {
	std::vector<int> tempDimen;
	std::vector<string> tempIDs;
	std::vector<string> IDtype;
	std::vector<int> IDtypeDimen;
	const Token *t = m_lex->peekToken();
	
		int  sizes = 0;
		do
		{
			t = m_lex->getNextToken();
			if (t->getType() != ID){
				if(!errormod->addErrorSin(t->getLineNumber(), "no se reconoce variable")) return false;
			}
			else{
				tempIDs.push_back(t->getLex());
			}
			t = m_lex->getNextToken();
			if (!t->getLex().compare("[") ){
				t = m_lex->getNextToken();
				if (t->getType() != INT){
					if (!errormod->addErrorSin(t->getLineNumber(), "falta el tamaño entero")) return false;
				}
				else{
					tempDimen.push_back(stoi(t->getLex()));
				}
				t = m_lex->getNextToken();
				if (t->getLex().compare("]"))
				{
					if (!errormod->addErrorSin(t->getLineNumber(), "se esperaba ']'")) return false;
				}
				t = m_lex->getNextToken();
			}
			else
			{
				tempDimen.push_back(0);
			}
		} while (!t->getLex().compare(","));
		IDtypeDimen.push_back(sizes);
		
		if (t->getLex().compare(":")) {
			if (!errormod->addErrorSin(t->getLineNumber(), "se esperaba  ';'")) return false;
		}
		else {
			t = m_lex->getNextToken();
		}
		if (!t->getLex().compare("int") || !t->getLex().compare("float") || !t->getLex().compare("string") || !t->getLex().compare("bool")) {
			if (scope == GLOBAL_VAR){
				for (int i = 0; i < tempIDs.size(); i++){
					tabsyb->addsymbol("<GLOBAL SCOPE>", t->getLex(), scope, tempDimen[i], nullptr, nullptr);
				}
			}
			else{
				for (int i = 0; i < tempIDs.size(); i++){
					tabsyb->addsymbol(funcName, t->getLex(), scope, tempDimen[i], nullptr, nullptr);
				}
			}
		}
		else
		{
			errormod->addErrorSin(t->getLineNumber(), "tipo de variable sin identificar");
		}
		t = m_lex->getNextToken();
		if (t->getLex().compare(";"))
		{
			errormod->addErrorSin(t->getLineNumber(), "se esperaba ';'");
		}
		return true;
}
