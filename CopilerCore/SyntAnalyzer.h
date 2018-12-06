#pragma once
#include "cst_Program.h"
#include "LexAnalyzer.h"
#include "SemAnalizer.h"

namespace CopilerCore
{
	class SyntAnalyzer
	{
		LexAnalyzer* m_lex;
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;
		SemAnalizer* m_sem;

	public:
		SyntAnalyzer(LexAnalyzer* m_lex, ErrorsModule^ errormod, Ctabsym* semAnalyzer);
		~SyntAnalyzer();
		void checkSyntax();
		void GetSymbols(map<string, CglobalNode>* symbols);
	};
}
