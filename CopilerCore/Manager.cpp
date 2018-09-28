#include "ErrorsModule.h"
#include"Manager.h"

/*
*/
CopilerCore::Manager::Manager()
{
	managed_errorsModule = gcnew ErrorsModule();
	cpp_lexAnalyzer = new LexAnalyzer(managed_errorsModule);
}

/*
*/
CopilerCore::Manager::~Manager()
{
	// Free memory of LEX analyzer
	if (cpp_lexAnalyzer != nullptr)
	{
		delete cpp_lexAnalyzer;
		cpp_lexAnalyzer = nullptr;
	}

	// Memory of ERRORS MODULE is automatically collected (allocated with gcnew)
}

int CopilerCore::Manager::Conteo_errores()
{
	return managed_errorsModule->ErrorSize();
}

/*
 * Main entry point into the compiler logic
 */
cli::array<String ^> ^ CopilerCore::Manager::compileProgram(String ^ sourceCode)
{
	cli::array<String ^> ^ compilationDetails;

	// Clear state if all pointers are valid
	if (managed_errorsModule && cpp_lexAnalyzer != nullptr)
	{
		managed_errorsModule->reset();
		cpp_lexAnalyzer->reset();
	}
	else
	{
		// invalid pointers, return error...
	}

	lexAnalysis(sourceCode);

	compilationDetails = getCompilationDetails();

	return compilationDetails;
}

/*
*/
void CopilerCore::Manager::lexAnalysis(String ^ sourceCode)
{
	if (cpp_lexAnalyzer != nullptr)
	{
		cpp_lexAnalyzer->parseSourceCode((const char *)System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(sourceCode).ToPointer());
	}
}

cli::array<String ^> ^CopilerCore::Manager::getCompilationDetails()
{
	int j = 0;
	cli::array<String^>^ ErrorArray = managed_errorsModule->Errors;

	/*cli::array<String^>^ Detalles = gcnew cli::array<String^>(cpp_lexAnalyzer->tokensize()+managed_errorsModule->ErrorSize()+1);
	for (int i = 1; managed_errorsModule->Errors[i] != ""; i++,j++)
	{
		Detalles[i] = managed_errorsModule->Errors[i];
	}
	Detalles[j+1] = "weamagicadeseparacion";

	vector<Token*> ArregloTokens;
	cpp_lexAnalyzer->getTokens(&ArregloTokens);
	for (int i = j + 2; i > cpp_lexAnalyzer->tokensize() + j + 1; i++ )
	{
		std::string st = ArregloTokens[i]->getLex() + "," + ArregloTokens[i]->getTypeStr(ArregloTokens[i]->getType()) + "," + (char)ArregloTokens[i]->getLineNumber();
		Detalles[i] = gcnew String(st.c_str());
	}*/
	return Detalles;
}