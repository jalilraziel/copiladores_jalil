#include "SyntAnalyzer.h"




CopilerCore::SintAnalyzer::SintAnalyzer(LexAnalyzer * a, ErrorsModule ^ b, Ctabsym * c)
{
	m_lex = a;
	errormod = b;
	tabsyb = c;
}



void CopilerCore::SintAnalyzer::checkSyntax()
{
	cst_Program* p = new cst_Program(m_lex, errormod, tabsyb);
	p->checkSyntax();
}

