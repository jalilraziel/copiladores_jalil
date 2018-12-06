#pragma once
#include "LexAnalyzer.h"
#include "ErrorsModule.h"
#include "Ctabsym.h"
#include "cst_Variables.h"
#include "cStament.h"

namespace CopilerCore
{
	class cst_BloqFunciones
	{
		LexAnalyzer* m_lex;
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;

	public:
		cst_BloqFunciones(LexAnalyzer* m_lex, ErrorsModule^ errormod, Ctabsym* tabsyb);
		~cst_BloqFunciones();
		bool checkSyntax(std::string funcName);
	};
}

