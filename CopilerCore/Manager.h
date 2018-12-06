#pragma once

#include "windows.h"
using namespace System;

#include "LexAnalyzer.h"
#include "SemAnalizer.h"
#include "SyntAnalyzer.h"
#include "ErrorsModule.h"

namespace CopilerCore
{
	public ref class Manager
	{
	private:
		LexAnalyzer  * cpp_lexAnalyzer;      // ANALISADOR LEXICO
		ErrorsModule ^ managed_errorsModule; // ERRORS MODULE
		SyntAnalyzer  * cpp_SyntAnalyzer;    // ANALISADOR SINTACTICO INSTANCE
		SemAnalizer  * cpp_SemAnalizer;      // ANALISADOR SEMANTICO INSTANCE

		void lexAnalysis(String ^ sourceCode);
		void synAnalysis();
		void semAnalysis();
		cli::array<String ^> ^ getCompilationDetails();

	public:
		Manager();
		~Manager();
		int Conteo_errores();

		cli::array<String ^> ^ compileProgram(String ^ sourceCode);
		//...
	};
}

