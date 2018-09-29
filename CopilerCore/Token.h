#pragma once

#include <string>
using namespace std;

namespace CopilerCore
{
	public enum TOKEN_TYPE
	{
		UNDEFINED = 0,
		KEYWORD,
		ID,
		INT,
		FLOAT,
		STRING,
		OPERADOR_LOGICO,
		OPERADOR_LOGICO_UNARIO,
		OPERADOR_ARITMETICO,
		OPERADOR_RELACIONAL,
		OPERADOR_ASIGNADOR,
		OPERADOR_AGRUPADOR,
		OPERADOR_DIMENCIONAL,
		DELIMITADOR
	};

	class Token
	{
	private:
		std::string m_Lex;
		TOKEN_TYPE m_Type;
		int m_LineNumber;

	public:
		Token(std::string lex, TOKEN_TYPE type, int lineNum);
		~Token();

		std::string getLex() const { return m_Lex; }
		std::string getTypeStr(); 
		TOKEN_TYPE getType() const { return m_Type; }
		int getLineNumber() const { return m_Type; }
	};
}