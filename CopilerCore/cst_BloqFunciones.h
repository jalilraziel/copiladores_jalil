#pragma once
#include "LexAnalyzer.h"
#include "ErrorsModule.h"

namespace CopilerCore
{
	class cst_BloqFunciones
	{
		LexAnalyzer* m_lex;

	public:
		cst_BloqFunciones(LexAnalyzer*);
		void checkSyntax();
	};
}

