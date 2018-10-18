#pragma once
#include "LexAnalyzer.h"
#include "ErrorsModule.h"
#include "Ctabsym.h"
#include "cst_Variables.h"

namespace CopilerCore
{
	class cst_BloqFunciones
	{
		LexAnalyzer* m_lex;
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;

	public:
		cst_BloqFunciones(LexAnalyzer* m_lex, ErrorsModule^ errormod, Ctabsym* tabsyb);
		void checkSyntax();
	};
}

