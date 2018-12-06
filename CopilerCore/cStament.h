#pragma once
#include "LexAnalyzer.h"
#include "ErrorsModule.h"
#include "Ctabsym.h"

namespace CopilerCore
{
	////////  IF
	class cStamnet_If
	{
		LexAnalyzer* m_lex;
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;

	public:
		cStamnet_If(LexAnalyzer* m_lex, ErrorsModule^ errormod, Ctabsym* tabsyb);
		bool checkSyntax();
	};

	////////  WHILE
	class cStamnet_While
	{
		LexAnalyzer* m_lex;
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;

	public:
		cStamnet_While(LexAnalyzer* m_lex, ErrorsModule^ errormod, Ctabsym* tabsyb);
		bool checkSyntax();
	};

	////////  FOR
	class cStamnet_For
	{
		LexAnalyzer* m_lex;
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;

	public:
		cStamnet_For(LexAnalyzer* m_lex, ErrorsModule^ errormod, Ctabsym* tabsyb);
		bool checkSyntax();
	};

	////////  SWITCH
	class cStamnet_Switch
	{
		LexAnalyzer* m_lex;
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;

	public:
		cStamnet_Switch(LexAnalyzer* m_lex, ErrorsModule^ errormod, Ctabsym* tabsyb);
		bool checkSyntax();
	};

	////////  ASSIGN
	class cStamnet_Assign
	{
		LexAnalyzer* m_lex;
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;

	public:
		cStamnet_Assign(LexAnalyzer* m_lex, ErrorsModule^ errormod, Ctabsym* tabsyb);
		bool checkSyntax();
	};

	////////  READ
	class cStamnet_Read
	{
		LexAnalyzer* m_lex;
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;

	public:
		cStamnet_Read(LexAnalyzer* m_lex, ErrorsModule^ errormod, Ctabsym* tabsyb);
		bool checkSyntax();
	};

	////////  PRINT
	class cStamnet_Print
	{
		LexAnalyzer* m_lex;
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;

	public:
		cStamnet_Print(LexAnalyzer* m_lex, ErrorsModule^ errormod, Ctabsym* tabsyb);
		bool checkSyntax();
	};

	////////  RETURN
	class cStamnet_Return
	{
		LexAnalyzer* m_lex;
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;

	public:
		cStamnet_Return(LexAnalyzer* m_lex, ErrorsModule^ errormod, Ctabsym* tabsyb);
		bool checkSyntax();
	};

	////////  FUNCTION CALL
	class cStamnet_Func_Call
	{
		LexAnalyzer* m_lex;
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;

	public:
		cStamnet_Func_Call(LexAnalyzer* m_lex, ErrorsModule^ errormod, Ctabsym* tabsyb);
		bool checkSyntax();
	};

	////////  BLOCK STATEMENT
	class cStamnet_Block_Statement
	{
		LexAnalyzer* m_lex;
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;

	public:
		cStamnet_Block_Statement(LexAnalyzer* m_lex, ErrorsModule^ errormod, Ctabsym* tabsyb);
		bool checkSyntax();
	};

	////////  TERM
	class cStamnet_Term
	{
		LexAnalyzer* m_lex;
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;

	public:
		cStamnet_Term(LexAnalyzer* m_lex, ErrorsModule^ errormod, Ctabsym* tabsyb);
		~cStamnet_Term();
		bool checkSyntax();
	};

	////////  EXP_LOG
	class Exp_Log
	{
		LexAnalyzer* m_lex;
		msclr::gcroot<ErrorsModule ^> errormod;
		Ctabsym* tabsyb;

	public:
		Exp_Log(LexAnalyzer* lexAnalyzer, ErrorsModule^ errorModule, Ctabsym* symTable);
		~Exp_Log();
		bool checkSyntax();
	};
}
