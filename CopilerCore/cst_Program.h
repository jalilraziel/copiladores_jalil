#pragma once
#include "LexAnalyzer.h"
#include "ErrorsModule.h"
#include "Ctabsym.h"
#include "cst_Variables.h"
#include "cst_Funcion.h"
#include "cst_Parametros.h"
#include "cst_BloqFunciones.h"


namespace CopilerCore
{
	class cst_Program
	{
		LexAnalyzer* m_lex; 
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;

	public:
		cst_Program(LexAnalyzer* m_lex, ErrorsModule^ errormod, Ctabsym* tabsyb);
		void checkSyntax();
	};
}

