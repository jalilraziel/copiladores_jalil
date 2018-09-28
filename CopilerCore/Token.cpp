#include "Token.h"

CopilerCore::Token::Token(std::string lex, TOKEN_TYPE type, int lineNum)
{
}

CopilerCore::Token::~Token()
{
}

std::string CopilerCore::Token::getTypeStr(TOKEN_TYPE token)
{
	if (token = KEYWORD){
		return "KEYWORD";
	}
	else if (token = ID){
		return "ID";
	}
	else if (token = INT){
		return "INT";
	}
	else if (token = FLOAT){
		return "FLOAT";
	}
	else if (token = STRING){
		return "STRING";
	}
	else if (token = OPERADOR_LOGICO){
		return "OPERADOR_LOGICO";
	}
	else if (token = OPERADOR_LOGICO_UNARIO){
		return "OPERADOR_LOGICO_UNARIO";
	}
	else if (token = OPERADOR_ARITMETICO){
		return "OPERADOR_ARITMETICO";
	}
	else if (token = OPERADOR_ASIGNADOR) {
		return "OPERADOR_ASIGNADOR";
	}
	else if (token = OPERADOR_AGRUPADOR) {
		return "OPERADOR_AGRUPADOR";
	}
	else if (token = OPERADOR_DIMENCIONAL) {
		return "OPERADOR_DIMENCIONAL";
	}
	else if (token = DELIMITADOR) {
		return "DELIMITADOR";
	}
	return NULL;
}
