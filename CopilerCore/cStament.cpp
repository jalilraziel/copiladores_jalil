#include "cStament.h"

//////////////////     BLOCK STATEMENT     //////////////////
CopilerCore::cStamnet_Block_Statement::cStamnet_Block_Statement(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

void CopilerCore::cStamnet_Block_Statement::checkSyntax()
{
	const Token *t = m_lex->peekToken();
	if (!t->getLex().compare("{")) {
		t = m_lex->getNextToken();
		while (t->getLex().compare("}")) {
			t = m_lex->getNextToken();
		}
	}
	else{
		//error
	}
}

//////////////////     IF     //////////////////
CopilerCore::cStamnet_If::cStamnet_If(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

void CopilerCore::cStamnet_If::checkSyntax()
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
}

//////////////////     WHILE     //////////////////
CopilerCore::cStamnet_While::cStamnet_While(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

void CopilerCore::cStamnet_While::checkSyntax()
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
}

//////////////////     FOR     //////////////////
CopilerCore::cStamnet_For::cStamnet_For(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

void CopilerCore::cStamnet_For::checkSyntax()
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
}

//////////////////     SWITCH     //////////////////
CopilerCore::cStamnet_Switch::cStamnet_Switch(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

void CopilerCore::cStamnet_Switch::checkSyntax()
{
	const Token *t = m_lex->peekToken();
	if (!t->getLex().compare("switch")) {
		t = m_lex->getNextToken();
	}
}

//////////////////     ASSIGN     //////////////////
CopilerCore::cStamnet_Assign::cStamnet_Assign(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

void CopilerCore::cStamnet_Assign::checkSyntax()
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
}

//////////////////     READ     //////////////////
CopilerCore::cStamnet_Read::cStamnet_Read(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

void CopilerCore::cStamnet_Read::checkSyntax()
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
}

//////////////////     PRINT     //////////////////
CopilerCore::cStamnet_Print::cStamnet_Print(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

void CopilerCore::cStamnet_Print::checkSyntax()
{
	const Token *t = m_lex->peekToken();
	if (!t->getLex().compare("print")) {
		t = m_lex->getNextToken();
	}
}

//////////////////     RETURN     //////////////////
CopilerCore::cStamnet_Return::cStamnet_Return(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

void CopilerCore::cStamnet_Return::checkSyntax()
{
	const Token *t = m_lex->peekToken();
	if (!t->getLex().compare("return")) {
		t = m_lex->getNextToken();
	}
	while (t->getLex().compare(";")) {
		t = m_lex->getNextToken();
	}
}

//////////////////     RETURN     //////////////////

CopilerCore::cStamnet_Func_Call::cStamnet_Func_Call(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

void CopilerCore::cStamnet_Func_Call::checkSyntax()
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
}
