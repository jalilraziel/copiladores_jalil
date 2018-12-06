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
		void add_lNode(CLocalNode* node);
		CglobalNode(std::string name, std::string type, E_SCOPE scope, int dimencion, void *value, CLocalNode* localNode);
		CglobalNode();
		~CglobalNode();
	};
}