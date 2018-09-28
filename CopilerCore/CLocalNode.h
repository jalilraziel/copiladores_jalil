#pragma once
#include "E_SCOPE.h"
#include <string>
#include "CLocalNode.h"


class CLocalNode
{
private:
	std::string m_type; 
	std::string m_funcName;
	E_SCOPE m_scope; 
	int m_dimen;
	void *m_values;
	CLocalNode* m_localNode;

public:
	std::string GetSymbolType(std::string name, E_SCOPE scope, std::string func);
	int GetSymbolDimen(std::string name, E_SCOPE scope, std::string func);
	CLocalNode();
	~CLocalNode();

};

