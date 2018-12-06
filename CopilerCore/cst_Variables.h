#pragma once
#include "LexAnalyzer.h"
#include "ErrorsModule.h"
#include "Ctabsym.h"
#include "cst_Parametros.h"
#include "CglobalNode.h"
#include "CLocalNode.h"

namespace CopilerCore
{

	class cst_Variables
	{
		LexAnalyzer* m_lex;
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;

	public:
		cst_Variables(LexAnalyzer* m_lex, ErrorsModule^ errormod, Ctabsym* tabsyb);
		~cst_Variables();
		bool checkSyntax(E_SCOPE scope, string funcName = "");
	};

}