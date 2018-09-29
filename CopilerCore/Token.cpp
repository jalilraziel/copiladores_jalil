#include "Token.h"

CopilerCore::Token::Token(std::string lex, TOKEN_TYPE type, int lineNum)
{
	m_Lex = lex;
	m_Type = type;
	m_LineNumber = lineNum;
	
}

CopilerCore::Token::~Token()
{
}

std::string CopilerCore::Token::getTypeStr()
{
	if (this->m_Type == KEYWORD){
		return "KEYWORD";
	}
	else if (this->m_Type == ID){
		return "ID";
	}
	else if (this->m_Type == INT){
		return "INT";
	}
	else if (this->m_Type == FLOAT){
		return "FLOAT";
	}
	else if (this->m_Type == STRING){
		return "STRING";
	}
	else if (this->m_Type == OPERADOR_LOGICO){
		return "OPERADOR_LOGICO";
	}
	else if (this->m_Type == OPERADOR_LOGICO_UNARIO){
		return "OPERADOR_LOGICO_UNARIO";
	}
	else if (this->m_Type == OPERADOR_ARITMETICO){
		return "OPERADOR_ARITMETICO";
	}
	else if (this->m_Type == OPERADOR_ASIGNADOR) {
		return "OPERADOR_ASIGNADOR";
	}
	else if (this->m_Type == OPERADOR_AGRUPADOR) {
		return "OPERADOR_AGRUPADOR";
	}
	else if (this->m_Type == OPERADOR_DIMENCIONAL) {
		return "OPERADOR_DIMENCIONAL";
	}
	else if (this->m_Type == DELIMITADOR) {
		return "DELIMITADOR";
	}
	return "no alle";
}
