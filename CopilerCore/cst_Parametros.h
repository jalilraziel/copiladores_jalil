#pragma once
#include "LexAnalyzer.h"
#include "ErrorsModule.h"

namespace CopilerCore
{
	class cst_Parametros
	{
		LexAnalyzer* m_lex;

	public:
		cst_Parametros(LexAnalyzer*);
		void checkSyntax();
	};
}
