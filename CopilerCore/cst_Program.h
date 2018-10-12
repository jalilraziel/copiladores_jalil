#pragma once
#include "LexAnalyzer.h"
#include "ErrorsModule.h"
#include "cst_Variables.h"
#include "cst_Funcion.h"
#include "cst_Parametros.h"
#include "cst_BloqFunciones.h"


namespace CopilerCore
{
	class cst_Program
	{
		LexAnalyzer* m_lex;

	public:
		cst_Program(LexAnalyzer*);
		void checkSyntax();
	};
}

