#pragma once
#include "LexAnalyzer.h"
#include "ErrorsModule.h"

namespace CopilerCore
{
	class cst_Funcion
	{
		LexAnalyzer* m_lex;

	public:
		cst_Funcion(LexAnalyzer*);
		void checkSyntax();
	};
}
