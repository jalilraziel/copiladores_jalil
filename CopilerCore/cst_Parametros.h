#pragma once
#include "LexAnalyzer.h"
#include "ErrorsModule.h"
#include "Ctabsym.h"
#include "CglobalNode.h"
#include "CLocalNode.h"

namespace CopilerCore
{
	class cst_Parametros
	{
		LexAnalyzer* m_lex;
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;

	public:
		cst_Parametros(LexAnalyzer* m_lex, ErrorsModule^ errormod, Ctabsym* tabsyb);
		void checkSyntax();
	};
}
