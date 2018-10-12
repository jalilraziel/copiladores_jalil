#include "SyntAnalyzer.h"




CopilerCore::SintAnalyzer::SintAnalyzer(LexAnalyzer *a)
{
	LexAnalyzer* m_lex = a;
}



void CopilerCore::SintAnalyzer::checkSyntax()
{
	cst_Program* p = new cst_Program(m_lex);
	p->checkSyntax();
}

