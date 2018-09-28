#include "ErrorsModule.h"

using namespace System;

/*
*/
CopilerCore::ErrorsModule::ErrorsModule()
{
	m_numErrors = 0;
	m_errorsArray = gcnew cli::array<String ^>(MAX_UAD_COMPILER_ERRORS);

	for (int i = 0; i < MAX_UAD_COMPILER_ERRORS; ++i)
	{
		m_errorsArray[i] = gcnew String("");
	}
}

/*
*/
CopilerCore::ErrorsModule::~ErrorsModule()
{
}

/*
*/
int CopilerCore::ErrorsModule::ErrorSize()
{
	return 0;
}
void CopilerCore::ErrorsModule::reset()
{
	m_numErrors = 0;
}

/*
*/
bool CopilerCore::ErrorsModule::addErrorLex(int lineNum, const char *desc, const char *line)
{
	String ^ strDesc = gcnew String(desc);
	String ^ strLine = gcnew String(line);
	return addError(CopilerCore::ERROR_PHASE::LEXIC_ANALYZER, lineNum, strDesc, strLine);
}

/*
*/
bool CopilerCore::ErrorsModule::addError(ERROR_PHASE errorPhase, int lineNumber, String ^ errorDesc, String ^ errorLine)
{
	if (m_numErrors < MAX_UAD_COMPILER_ERRORS)
	{
		String ^ errLine = gcnew String("");
		if (errorLine->Length > 20)
		{
			errLine = errorLine->Substring(0, 20);
		}
		else
		{
			errLine = errorLine;
		}

		m_errorsArray->SetValue(String::Format("<{0}>: \t{1} \t\t{2} \t\t{3}", errorPhase.ToString(), lineNumber, errorDesc, errLine), m_numErrors);
		++m_numErrors;

		return true;
	}

	return false;
}
