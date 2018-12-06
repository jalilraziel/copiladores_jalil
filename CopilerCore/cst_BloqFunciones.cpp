#include "cst_BloqFunciones.h"



CopilerCore::cst_BloqFunciones::cst_BloqFunciones(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

CopilerCore::cst_BloqFunciones::~cst_BloqFunciones() {
}

bool CopilerCore::cst_BloqFunciones::checkSyntax(std::string funcName)
{
	bool returnFound = false;
	const Token *t = m_lex->peekToken();
	while (!t->getLex().compare("var"))
	{
		cst_Variables* v = new cst_Variables(m_lex, errormod, tabsyb);
		if (!v->checkSyntax(LOCAL_VAR, funcName)) return false;
		t = m_lex->getNextToken();
	}
	while (t->getLex().compare("}"))
	{
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
			if (!t->getLex().compare("("))
			{
				cStamnet_Func_Call* s = new cStamnet_Func_Call(m_lex, errormod, tabsyb);
				if (!s->checkSyntax())
					return false;
			}
			else
			{
				if (!t->getLex().compare("["))
				{
					//Evaluate logical expression for the dimension
					while (t->getLex().compare("]"))
					{
						t = m_lex->getNextToken();
					}
					t = m_lex->getNextToken();
					if (!t->getLex().compare("="))
					{
						//Evaluate logical expresion for assignment
						while (t->getLex().compare(";"))
						{
							t = m_lex->getNextToken();
						}
					}
					else
					{
						//Assignment error
					}
				}
				else if (!t->getLex().compare("="))
				{
					//Evaluate logical expresion for assignment
					while (t->getLex().compare(";"))
					{
						t = m_lex->getNextToken();
					}
				}
				else
				{
					//Assignment error
				}
			}
		}
		if (!t->getLex().compare("read"))
		{
			cStamnet_Read* s = new cStamnet_Read(m_lex, errormod, tabsyb);
			if (!s->checkSyntax())
				return false;
		}
		if (!t->getLex().compare("print"))
		{
			cStamnet_Print* s = new cStamnet_Print(m_lex, errormod, tabsyb);
			if (!s->checkSyntax())
				return false;
		}
		if (!t->getLex().compare("return"))
		{

			cStamnet_Return* s = new cStamnet_Return(m_lex, errormod, tabsyb);
			if (!s->checkSyntax())
				return false;
			returnFound = true;
			break;
		}
	}
}
