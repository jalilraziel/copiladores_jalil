#include "cStament.h"

//////////////////     BLOCK STATEMENT     //////////////////
CopilerCore::cStamnet_Block_Statement::cStamnet_Block_Statement(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

bool CopilerCore::cStamnet_Block_Statement::checkSyntax()
{
	const Token *t = m_lex->peekToken();
	while (t->getLex().compare("}")) {
		t = m_lex->getNextToken();
		if (!t->getLex().compare("if"))
		{
			cStamnet_If* s = new cStamnet_If(m_lex, errormod, tabsyb);
			if (!s->checkSyntax())
				return false;
		}
		if (!t->getLex().compare("while"))
		{
			cStamnet_While* s = new cStamnet_While(m_lex, errormod, tabsyb);
			if (!s->checkSyntax())
				return false;
		}
		if (!t->getLex().compare("for"))
		{
			cStamnet_For* s = new cStamnet_For(m_lex, errormod, tabsyb);
			if (!s->checkSyntax())
				return false;
		}
		if (!t->getLex().compare("switch"))
		{
			cStamnet_Switch* s = new cStamnet_Switch(m_lex, errormod, tabsyb);
			if (!s->checkSyntax())
				return false;
		}
		if (t->getType() == TOKEN_TYPE::ID)
		{
			t = m_lex->getNextToken();

		}
	}

}

//////////////////     IF     //////////////////
CopilerCore::cStamnet_If::cStamnet_If(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

bool CopilerCore::cStamnet_If::checkSyntax()
{
	const Token *t = m_lex->peekToken();
	if (!t->getLex().compare("if")) {
		t = m_lex->getNextToken();
	}
	if (!t->getLex().compare("(")) {
		t = m_lex->getNextToken();
		while (t->getLex().compare(")")) {
			t = m_lex->getNextToken();
		}
	}
	else{
		//error
	}
	cStamnet_Block_Statement* bs = new cStamnet_Block_Statement(m_lex, errormod, tabsyb);
	bs->checkSyntax();
	t = m_lex->getNextToken();
	if (!t->getLex().compare("else")) {
		t = m_lex->getNextToken();
		cStamnet_Block_Statement* bs1 = new cStamnet_Block_Statement(m_lex, errormod, tabsyb);
		bs1->checkSyntax();
		t = m_lex->getNextToken();
	}
	return true;
}

//////////////////     WHILE     //////////////////
CopilerCore::cStamnet_While::cStamnet_While(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

bool CopilerCore::cStamnet_While::checkSyntax()
{
	const Token *t = m_lex->peekToken();
	if (!t->getLex().compare("while")) {
		t = m_lex->getNextToken();
	}
	if (!t->getLex().compare("(")) {
		t = m_lex->getNextToken();
		while (t->getLex().compare(")")) {
			t = m_lex->getNextToken();
		}
	}
	else {
		//error
	}
	cStamnet_Block_Statement* bs = new cStamnet_Block_Statement(m_lex, errormod, tabsyb);
	bs->checkSyntax();
	t = m_lex->getNextToken();

	return true;
}

//////////////////     FOR     //////////////////
CopilerCore::cStamnet_For::cStamnet_For(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

bool CopilerCore::cStamnet_For::checkSyntax()
{
	const Token *t = m_lex->peekToken();
	if (!t->getLex().compare("for")) {
		t = m_lex->getNextToken();
	}
	if (!t->getLex().compare("(")) {
		t = m_lex->getNextToken();
		int i = 0;
		while(t->getLex().compare(")")){
			t = m_lex->getNextToken();
			if (!t->getLex().compare(";")) i++;
		}
		if (i != 2){
			//error
		}
	}
	else {
		//error
	}
	cStamnet_Block_Statement* bs = new cStamnet_Block_Statement(m_lex, errormod, tabsyb);
	bs->checkSyntax();
	t = m_lex->getNextToken();
	return true;
}

//////////////////     SWITCH     //////////////////
CopilerCore::cStamnet_Switch::cStamnet_Switch(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

bool CopilerCore::cStamnet_Switch::checkSyntax()
{
	const Token *t = m_lex->peekToken();
	if (!t->getLex().compare("switch")) {
		t = m_lex->getNextToken();
	}
	return true;
}

//////////////////     ASSIGN     //////////////////
CopilerCore::cStamnet_Assign::cStamnet_Assign(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

bool CopilerCore::cStamnet_Assign::checkSyntax()
{
	const Token *t = m_lex->peekToken();
	if (t->getType() != ID)
	{
		//Error
	}
	if (!t->getLex().compare("["))
	{
		t = m_lex->getNextToken();
		if (t->getType() != INT)
		{
			//error
		}
		else
		{
			t = m_lex->getNextToken();
			if (!t->getLex().compare("]"))
			{
				//error
			}
		}
	}
	t = m_lex->getNextToken();
	if (t->getLex().compare("="))
	{
		//error
	}
	t = m_lex->getNextToken();
	//
	// revision exp_log
	//
	t = m_lex->getNextToken();
	if (!t->getLex().compare(";"))
	{
		//error
	}
	return true;
}

//////////////////     READ     //////////////////
CopilerCore::cStamnet_Read::cStamnet_Read(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

bool CopilerCore::cStamnet_Read::checkSyntax()
{
	const Token *t = m_lex->peekToken();
	if (!t->getLex().compare("(")) {
		t = m_lex->getNextToken();
		if (t->getType() != ID)
		{
			//Error
		}
		t = m_lex->getNextToken();
		if (!t->getLex().compare("["))
		{
			t = m_lex->getNextToken();
			if (t->getType() != INT){
				//error
			}
			else{
				t = m_lex->getNextToken();
				if (!t->getLex().compare("]")){
					//error
				}
				else{
					if (!t->getLex().compare(")")){
						//error
					}
				}
			}
		}

	}
	if (!t->getLex().compare(";"))
	{
		//error
	}
	return true;
}

//////////////////     PRINT     //////////////////
CopilerCore::cStamnet_Print::cStamnet_Print(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

bool CopilerCore::cStamnet_Print::checkSyntax()
{
	const Token *t = m_lex->peekToken();
	if (!t->getLex().compare("print")) {
		t = m_lex->getNextToken();
	}
	return true;
}

//////////////////     RETURN     //////////////////
CopilerCore::cStamnet_Return::cStamnet_Return(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

bool CopilerCore::cStamnet_Return::checkSyntax()
{
	const Token *t = m_lex->peekToken();
	if (!t->getLex().compare("return")) {
		t = m_lex->getNextToken();
	}
	while (t->getLex().compare(";")) {
		t = m_lex->getNextToken();
	}
	return true;
}

//////////////////     FUNC_CALL     //////////////////

CopilerCore::cStamnet_Func_Call::cStamnet_Func_Call(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

bool CopilerCore::cStamnet_Func_Call::checkSyntax()
{
	const Token *t = m_lex->peekToken();
	if (t->getType() != ID)
	{
		//Error
	}
	if (!t->getLex().compare("(")) {
		t = m_lex->getNextToken();
		while (t->getLex().compare(")")) {
			t = m_lex->getNextToken();
		}
	}
	else{
		//error
	}
	if (!t->getLex().compare(";"))
	{
		//error
	}
	return true;
}

CopilerCore::Exp_Log::Exp_Log(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

CopilerCore::Exp_Log::~Exp_Log()
{
}

bool CopilerCore::Exp_Log::checkSyntax()
{
	const Token *t = m_lex->getNextToken();
	if (t->getType() == TOKEN_TYPE::OPERADOR_LOGICO_UNARIO)
	{
		t = m_lex->getNextToken();
	}
	if (!t->getLex().compare("("))
	{
		Exp_Log* e = new Exp_Log(m_lex, errormod, tabsyb);
		if (!e->checkSyntax())
			return false;
		t = m_lex->getNextToken();
		if (t->getLex().compare(")"))
		{
			//Error - Expected ")"
			if (!errormod->addErrorSin(t->getLineNumber(), "se experab un )"))
				return false;
		}
	}
	else if (t->getType() == TOKEN_TYPE::INT || t->getType() == TOKEN_TYPE::FLOAT || t->getType() == TOKEN_TYPE::STRING || !t->getLex().compare("false") || !t->getLex().compare("true"))
	{

	}
	else if (t->getType() == TOKEN_TYPE::ID)
	{
		if (!m_lex->peekToken()->getLex().compare("["))
		{
			t = m_lex->getNextToken();
			Exp_Log* e = new Exp_Log(m_lex, errormod, tabsyb);
			if (!e->checkSyntax())
				return false;
			t = m_lex->getNextToken();
			if (t->getLex().compare("]"))
			{
				//Error - Expected "]"
				if (!errormod->addErrorSin(t->getLineNumber(), "se expera un '{' "))
					return false;
			}
		}
		else if (!m_lex->peekToken()->getLex().compare("("))
		{
			t = m_lex->getNextToken();
			cStamnet_Func_Call* f = new cStamnet_Func_Call(m_lex, errormod, tabsyb);
			if (!f->checkSyntax())
				return false;
		}
	}
	if (m_lex->peekToken()->getType() == TOKEN_TYPE::OPERADOR_ARITMETICO || m_lex->peekToken()->getType() == TOKEN_TYPE::OPERADOR_LOGICO || m_lex->peekToken()->getType() == TOKEN_TYPE::OPERADOR_RELACIONAL)
	{
		Exp_Log* e = new Exp_Log(m_lex, errormod, tabsyb);
		if (!e->checkSyntax())
			return false;
	}
	return true;
}
