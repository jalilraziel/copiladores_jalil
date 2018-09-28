#pragma once

#include "windows.h"
using namespace System;

#include "LexAnalyzer.h"
#include "ErrorsModule.h"

namespace CopilerCore
{
	public ref class Manager
	{
	private:
		LexAnalyzer  * cpp_lexAnalyzer;      // LEX ANALYZER INSTANCE
		ErrorsModule ^ managed_errorsModule; // ERRORS MODULE

		void lexAnalysis(String ^ sourceCode);
		cli::array<String ^> ^ getCompilationDetails();

	public:
		Manager();
		~Manager();
		int Conteo_errores();

		cli::array<String ^> ^ compileProgram(String ^ sourceCode);
		//...
	};
}

