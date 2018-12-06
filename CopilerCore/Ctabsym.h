#pragma once
#include "CglobalNode.h"
#include <map>

namespace CopilerCore
{
	class Ctabsym
	{
		std::map<std::string, CglobalNode> m_symbols;
	public:
		bool addsymbol(std::string name, std::string type, E_SCOPE scope, int dimencion, void *value, CLocalNode * localNode);
		bool stmbolExist(std::string name, E_SCOPE scope, std::string funcname);
		bool stmbolExist(std::string name, std::map<std::string, CglobalNode>::iterator* A);
		std::string GetSymbolType(std::string name, E_SCOPE scope, std::string funcname);
		std::string GetSymbolScape(std::string name);
		bool UpdateSymbolType();
		int GetSymbolDimen(std::string name, E_SCOPE scope, std::string func);
		void reset();
		void getSymbols(std::map<std::string, CglobalNode>* symbols);
		Ctabsym();
		~Ctabsym();

	};

}