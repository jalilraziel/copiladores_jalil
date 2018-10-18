#pragma once
#include "CLocalNode.h"
#include <string>
#include "E_SCOPE.h"

namespace CopilerCore
{
	class CglobalNode
	{
	private:
		std::string m_name;
		std::string m_type;
		E_SCOPE m_scope;
		int m_dimen;
		void *m_values;
		CLocalNode* m_localNode;

	public:
		std::string GetSymbolType(std::string name, E_SCOPE scope, std::string func);
		int GetSymbolDimen(std::string name, E_SCOPE scope, std::string func);
		CglobalNode(std::string name, std::string type, E_SCOPE scope, int dimencion);
		CglobalNode(std::string name, std::string type, E_SCOPE scope, int dimencion, CLocalNode* localNode);
		~CglobalNode();
	};
}