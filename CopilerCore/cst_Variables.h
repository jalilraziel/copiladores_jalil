#pragma once
#include "LexAnalyzer.h"
#include "ErrorsModule.h"

namespace CopilerCore
{

	class cst_Variables
	{
		LexAnalyzer* m_lex;

	public:
		cst_Variables(LexAnalyzer*);;
		void checkSyntax();
	};

}