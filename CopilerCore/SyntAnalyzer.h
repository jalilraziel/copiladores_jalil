#pragma once
#include "cst_Program.h"
#include "LexAnalyzer.h"

namespace CopilerCore
{
	class SintAnalyzer
	{
		LexAnalyzer* m_lex;

	public:
		SintAnalyzer(LexAnalyzer*);
		void checkSyntax();
	};
}
