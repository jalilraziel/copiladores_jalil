#include "SyntAnalyzer.h"




CopilerCore::SyntAnalyzer::SyntAnalyzer(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}

CopilerCore::SyntAnalyzer::~SyntAnalyzer()
{
}



void CopilerCore::SyntAnalyzer::checkSyntax()
{
	cst_Program* p = new cst_Program(m_lex, errormod, tabsyb);
	p->checkSyntax();
}

void CopilerCore::SyntAnalyzer::GetSymbols(map<string, CglobalNode>* symbols)
{
}

