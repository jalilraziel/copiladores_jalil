#include "LexAnalyzer.h"

enum class e_state
{
	START = 0,
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
	DELIMITADOR,
	COMENTARIO
};

CopilerCore::LexAnalyzer::LexAnalyzer(ErrorsModule ^ errorsModule)
{
	managedRef_errorsModule = errorsModule;
	m_Keywords.insert(std::make_pair("var", ""));
	m_Keywords.insert(std::make_pair("int", ""));
	m_Keywords.insert(std::make_pair("float", ""));
	m_Keywords.insert(std::make_pair("string", ""));
	m_Keywords.insert(std::make_pair("bool", ""));
	m_Keywords.insert(std::make_pair("void", ""));
	m_Keywords.insert(std::make_pair("function", ""));
	m_Keywords.insert(std::make_pair("if", ""));
	m_Keywords.insert(std::make_pair("else", ""));
	m_Keywords.insert(std::make_pair("while", ""));
	m_Keywords.insert(std::make_pair("for", ""));
	m_Keywords.insert(std::make_pair("inc", ""));
	m_Keywords.insert(std::make_pair("dec", ""));
	m_Keywords.insert(std::make_pair("switch", ""));
	m_Keywords.insert(std::make_pair("case", ""));
	m_Keywords.insert(std::make_pair("default", ""));
	m_Keywords.insert(std::make_pair("print", ""));
	m_Keywords.insert(std::make_pair("read", ""));
	m_Keywords.insert(std::make_pair("return", ""));
	m_Keywords.insert(std::make_pair("true", ""));
	m_Keywords.insert(std::make_pair("false*", ""));
}


CopilerCore::LexAnalyzer::~LexAnalyzer()
{
	m_Keywords.clear();
	m_Tokens.clear();
}

int CopilerCore::LexAnalyzer::tokensize()
{
	return m_Tokens.size();
}

bool CopilerCore::LexAnalyzer::parseSourceCode(const char * sourceCode)
{

	int linenumber = 1;
	const char* CurrChar = sourceCode;
	bool continua = true;
	std::string buffer;
	std::string LineBuffer;
	e_state state = e_state::START;

	Token* token1;

	while (continua == true)
	{
		switch (state)
		{
		case e_state::START:

				if (*CurrChar == '_') {
					buffer.clear();
					buffer.append(CurrChar, 1);
					CurrChar++;
					state = e_state::ID;
				}
				else if (isalpha(static_cast<unsigned char>(*CurrChar))){
					buffer.clear();
					buffer.append(CurrChar, 1);
					CurrChar++;
					state = e_state::ID;
				}
				else if (isdigit(static_cast<unsigned char>(*CurrChar))){
					buffer.clear();
					buffer.append(CurrChar, 1);
					CurrChar++;
					state = e_state::INT;
				}
				else if (*CurrChar == '"'){
					buffer.clear();
					buffer.append(CurrChar, 1);
					CurrChar++;
					state = e_state::STRING;
				}
				else if (*CurrChar == '&' || *CurrChar == '|'){
					buffer.clear();
					buffer.append(CurrChar, 1);
					CurrChar++;
					state = e_state::OPERADOR_LOGICO;
				}
				else if (*CurrChar == '+' || *CurrChar == '-' || *CurrChar == '/' || *CurrChar == '*' || *CurrChar == '%' || *CurrChar == '^'){
					buffer.clear();
					buffer.append(CurrChar, 1);
					CurrChar++;
					state = e_state::OPERADOR_ARITMETICO;
				}
				else if (*CurrChar == '<' || *CurrChar == '>' || *CurrChar == '!' || *CurrChar == '=')
				{
					buffer.clear();
					m_Tokens.push_back(token1);
					buffer.append(CurrChar, 1);
					CurrChar++;
					state = e_state::OPERADOR_RELACIONAL;
				}
				else if (*CurrChar == '.' || *CurrChar == ',' || *CurrChar == ';' || *CurrChar == ':')
				{
					buffer.clear();
					buffer.append(CurrChar, 1);
					CurrChar++;
					state = e_state::DELIMITADOR;
				}
				else if (*CurrChar == '(' || *CurrChar == ')' || *CurrChar == '{' || *CurrChar == '}')
				{
					token1 = new Token(buffer, CopilerCore::TOKEN_TYPE::OPERADOR_AGRUPADOR, linenumber);
					m_Tokens.push_back(token1);
					CurrChar++;
				}
				else if (*CurrChar == '[' || *CurrChar == ']')
				{
					token1 = new Token(buffer, CopilerCore::TOKEN_TYPE::OPERADOR_DIMENCIONAL, linenumber);
					m_Tokens.push_back(token1);
					CurrChar++;
				}
				else if (*CurrChar == ' ')
				{
					CurrChar++;
				}
				else if (*CurrChar == ' ')
				{
					CurrChar++;
				}
				else if (*CurrChar == '\t')
				{
					CurrChar++;
				}
				else if (*CurrChar == '\0')
				{
					continua = false;
				}
				if (*CurrChar == '\n')
				{
					linenumber++;
					CurrChar++;
				}
			break;
		case e_state::ID:
			if (isalpha(static_cast<unsigned char> (*CurrChar)) || isdigit(static_cast<unsigned char>(*CurrChar)) || *CurrChar == '_')
			{
				buffer.append(CurrChar, 1);
				CurrChar++;
				break;
			}
			else
			{
				if (m_Keywords.find(buffer) != m_Keywords.end())
				{
					token1 = new Token(buffer, CopilerCore::TOKEN_TYPE::KEYWORD, linenumber);
					m_Tokens.push_back(token1);
					CurrChar++;
				}
				else
				{
					token1 = new Token(buffer, CopilerCore::TOKEN_TYPE::ID, linenumber);
					m_Tokens.push_back(token1);
					CurrChar++;
				}
				state = e_state::START;
			}
			break;
		case e_state::INT:
			if (*CurrChar == '.')
			{
				buffer.append(CurrChar, 1);
				CurrChar++;
				state = e_state::FLOAT;
			}
			else if (isdigit(static_cast<unsigned char>(*CurrChar)))
			{
					buffer.append(CurrChar, 1);
					CurrChar++;			
			}
			else
			{
				token1 = new Token(buffer, CopilerCore::TOKEN_TYPE::INT, linenumber);
				m_Tokens.push_back(token1);
				state = e_state::START;
			}
			break;
		case e_state::FLOAT:
			if (isdigit(static_cast<unsigned char>(*CurrChar)))
			{
				buffer.append(CurrChar, 1);
				CurrChar++;
			}
			else if (buffer.back() == '.')
			{
				managedRef_errorsModule->addErrorLex(linenumber,LEX_ERROR_INVALID_FLOAT, buffer.c_str());
				state = e_state::START;
			}
			else
			{
				token1 = new Token(buffer, CopilerCore::TOKEN_TYPE::FLOAT, linenumber);
				m_Tokens.push_back(token1);
				state = e_state::START;
			}
			break;
		case e_state::STRING:
			if (*CurrChar != '"')
			{
				if (*CurrChar == '\0')
				{
					managedRef_errorsModule->addErrorLex(linenumber, LEX_ERROR_STRING_NOT_CLOSED, buffer.c_str());
					state = e_state::START;
				}
				else if (*CurrChar == '\n')
				{
					managedRef_errorsModule->addErrorLex(linenumber, LEX_ERROR_STRING_NOT_CLOSED, buffer.c_str());
					CurrChar++;
					state = e_state::START;
				}
				else
				{
					buffer.append(CurrChar, 1);
					CurrChar++;
				}
			}
			else
			{
				buffer.append(CurrChar, 1);
				token1 = new Token(buffer, CopilerCore::TOKEN_TYPE::STRING, linenumber);
				m_Tokens.push_back(token1);
				CurrChar++;
				state = e_state::START;
			}
			break;
		case e_state::OPERADOR_LOGICO:
			if (*CurrChar == buffer[0])
			{
				buffer.append(CurrChar, 1);
				token1 = new Token(buffer, CopilerCore::TOKEN_TYPE::OPERADOR_LOGICO, linenumber);
				m_Tokens.push_back(token1);
				CurrChar++;
				state = e_state::START;
				break;
			}
			else
			{
				if (buffer.back() == '&')
				{
					managedRef_errorsModule->addErrorLex(linenumber, LEX_ERROR_INVALID_LOGICAL_OP_AND, buffer.c_str());
					CurrChar++;
					state = e_state::START;
				}
				else
				{
					managedRef_errorsModule->addErrorLex(linenumber, LEX_ERROR_INVALID_LOGICAL_OP_OR, buffer.c_str());
					CurrChar++;
					state = e_state::START;
				}
			}
			break;
		case e_state::OPERADOR_ARITMETICO:
			
			if (buffer.back() == '=')
			{
				if (isdigit(static_cast<unsigned char>(*CurrChar)))
				{
					buffer.append(CurrChar, 1);
					CurrChar++;
					state = e_state::INT;
				}
				else
				{
					
					token1 = new Token(buffer, CopilerCore::TOKEN_TYPE::OPERADOR_ARITMETICO, linenumber);
					m_Tokens.push_back(token1);
					state = e_state::START;
					break;
				}
			}
			if (buffer.back() == '/')
			{
				if (*CurrChar == '*')
				{
					buffer.clear();

					CurrChar++;
					state = e_state::COMENTARIO;
				}
				else
				{
					token1 = new Token(buffer, CopilerCore::TOKEN_TYPE::OPERADOR_ARITMETICO, linenumber);
					m_Tokens.push_back(token1);
					state = e_state::START;
					break;
				}
			}
			else
			{
				token1 = new Token(buffer, CopilerCore::TOKEN_TYPE::OPERADOR_ARITMETICO, linenumber);
				m_Tokens.push_back(token1);
				state = e_state::START;
				break;
			}
			break;
		case e_state::OPERADOR_RELACIONAL:
			if (*CurrChar == '=')
			{
				buffer.append(CurrChar, 1);
				token1 = new Token(buffer, CopilerCore::TOKEN_TYPE::OPERADOR_RELACIONAL, linenumber);
				m_Tokens.push_back(token1);
				CurrChar++;
				state = e_state::START;
				break;
			}
			else
			{
				if (buffer[0] == '!')
				{
						token1 = new Token(buffer, CopilerCore::TOKEN_TYPE::OPERADOR_LOGICO_UNARIO, linenumber);
						m_Tokens.push_back(token1);
						state = e_state::START;
						break;
				}
				if (buffer[0] == '=')
				{
					token1 = new Token(buffer, CopilerCore::TOKEN_TYPE::OPERADOR_ASIGNADOR, linenumber);
					m_Tokens.push_back(token1);
					state = e_state::START;
					break;
				}
			}
			break;
		case e_state::DELIMITADOR:
			if (isdigit(static_cast<unsigned char>(*CurrChar)))
			{
				
					buffer.append(CurrChar, 1);
					CurrChar++;
					state = e_state::FLOAT;
					break;
			}
			else
			{
				token1 = new Token(buffer, CopilerCore::TOKEN_TYPE::DELIMITADOR, linenumber);
				m_Tokens.push_back(token1);
				CurrChar++;

				state = e_state::START;
			}
			break;
		case e_state::COMENTARIO:
			if (*CurrChar == '\0')
			{
				
				managedRef_errorsModule->addErrorLex(linenumber, LEX_ERROR_COMMENT_NOT_CLOSED, buffer.c_str());
				state = e_state::START;
				break;
			}
			else if (*CurrChar == '/')
			{
				if (buffer.back() == '*')
				{
					buffer.append(CurrChar, 1);
					CurrChar++;
					state = e_state::START;
				}
				else
				{
					buffer.append(CurrChar, 1);
					CurrChar++;
				}
			}
			else
			{
				buffer.append(CurrChar, 1);
				CurrChar++;
			}
			break;
		default:
			break;
		}
	}

	return false;
}

void CopilerCore::LexAnalyzer::reset()
{
	m_Keywords.clear();
	m_Tokens.clear();
}

void CopilerCore::LexAnalyzer::getTokens(std::vector<Token*>* tokensVec) const
{
	*tokensVec = m_Tokens;
}