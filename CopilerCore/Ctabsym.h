#pragma once
#include "CglobalNode.h"
#include <map>

namespace CopilerCore
{
	class Ctabsym
	{
		std::map<std::string, CglobalNode *> m_symbols;
	public:
		bool addsymbol(std::string name, E_SCOPE scope, int dimen, std::string func);
		bool stmbolExist(std::string name, E_SCOPE scope, std::string func);
		std::string GetSymbolType(std::string name, E_SCOPE scope, std::string func);
		std::string GetSymbolScape(std::string name);
		bool UpdateSymbolType();
		int GetSymbolDimen(std::string name, E_SCOPE scope, std::string func);
		Ctabsym();
		~Ctabsym();

	};

}