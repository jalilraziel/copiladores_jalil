#pragma once
#include "LexAnalyzer.h"
#include "ErrorsModule.h"
#include "Ctabsym.h"
#include "cst_Variables.h"
#include "cst_Parametros.h"
namespace CopilerCore
{
	class cst_Funcion
	{
		LexAnalyzer* m_lex;
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;

	public:
		cst_Funcion(LexAnalyzer* m_lex, ErrorsModule^ errormod, Ctabsym* tabsyb);
		void checkSyntax();
	};
}
