#pragma once
#include "cst_Program.h"
#include "LexAnalyzer.h"

namespace CopilerCore
{
	class SintAnalyzer
	{
		LexAnalyzer* m_lex;
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;

	public:
		SintAnalyzer(LexAnalyzer* m_lex, ErrorsModule^ errormod, Ctabsym* tabsyb);
		void checkSyntax();
	};
}
