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

	if (cpp_SyntAnalyzer != nullptr)
	{
		delete cpp_SyntAnalyzer;
		cpp_SyntAnalyzer = nullptr;
	}

	if (cpp_SemAnalizer != nullptr)
	{
		delete cpp_SemAnalizer;
		cpp_SemAnalizer = nullptr;
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

	synAnalysis();

	semAnalysis();

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

void CopilerCore::Manager::synAnalysis()
{
	if (cpp_SyntAnalyzer != nullptr)
	{
		cpp_SyntAnalyzer->checkSyntax();
	}
}

void CopilerCore::Manager::semAnalysis()
{
	if (cpp_SemAnalizer != nullptr)
	{
		cpp_SemAnalizer->checkExpressions();
	}
}


cli::array<String ^> ^CopilerCore::Manager::getCompilationDetails()
{
	int j = 0;
	int a = 0;
	for (j = 0;managed_errorsModule->Errors[j]!= ""; j++){}
	cli::array<String^>^ ErrorArray = gcnew cli::array<String^>(j + (int)cpp_lexAnalyzer->tokensize() + 2);

	vector<Token*> ArregloTokens = vector<Token*>((int)cpp_lexAnalyzer->tokensize());
	cpp_lexAnalyzer->getTokens(&ArregloTokens);

	//cli::array<String^>^ ErrorArray = managed_errorsModule->Errors;
	for (size_t i = 0; i < j; i++)
	{
		ErrorArray[i] = managed_errorsModule->Errors[i];
	}
	if (ErrorArray[j] = "")
	{
		ErrorArray[j] = "wea magica de separion";
		a = 1;
	}
	else
	{
		ErrorArray[j + 1] = "wea magica de separion";
		j = j + 1;
		a = 2;
	}

	for (int x = j+1; x < ArregloTokens.size(); x++)
	{
		std::string st = ArregloTokens[x-a]->getLex() +"@" + ArregloTokens[x-a]->getTypeStr() + "@" + std::to_string(ArregloTokens[x-a]->getLineNumber());
		ErrorArray[x] = gcnew String(st.c_str());
	}

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
	return ErrorArray;
}