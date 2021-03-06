#pragma once

#include "windows.h"
#include "vcclr.h"
#include "ErrorsModule.h"
#include "Token.h"

using namespace System;

#include <map>
#include <ctype.h>
#include <vector>
#include <stack>
using namespace std;

namespace CopilerCore
{
#define LEX_ERROR_INVALID_CHARACTER         "Invalid character"
#define LEX_ERROR_STRING_NOT_CLOSED         "String constant not closed"
#define LEX_ERROR_COMMENT_NOT_CLOSED        "Comment not closed"
#define LEX_ERROR_INVALID_FLOAT             "Invalid floating point number. Digit expected"
#define LEX_ERROR_INVALID_LOGICAL_OP_AND    "Invalid logical 'AND' operator."
#define LEX_ERROR_INVALID_LOGICAL_OP_OR     "Invalid logical 'OR' operator."
#define LEX_ERROR_INVALID_STATE             "Internal error. Invalid state."

	// LEX analyzer class
	class LexAnalyzer
	{
	private:
		msclr::gcroot<ErrorsModule ^> managedRef_errorsModule;

		std::map<std::string, std::string> m_Keywords;
		std::vector<Token *> m_Tokens;
		int id = -1;
		// ...
		// ...

	public:
		LexAnalyzer(ErrorsModule ^errorsModule);
		~LexAnalyzer();
		int tokensize();
		bool parseSourceCode(const char *sourceCode);
		void reset();
		void getTokens(std::vector<Token *> *tokensVec) const;
		const Token* getNextToken();
		const Token* peekToken();
	};
}
