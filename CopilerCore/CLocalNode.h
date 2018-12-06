#pragma once
#include "E_SCOPE.h"
#include <string>
#include "CLocalNode.h"

namespace CopilerCore {
	enum class SCOPE{
		UNDEFINED,
			FUNC,
			GLOBAL_VAR,
			LOCAL_VAR,
			PARAM
	};

	class CLocalNode{
	private:
		std::string m_type;
		std::string m_funcName;
		E_SCOPE m_scope;
		int m_dimen;
		void *m_values;
		CLocalNode* m_localNode;

	public:
		void add_lNode(CLocalNode* node);
		CLocalNode(std::string funcname, std::string type, E_SCOPE scope, int dimencion, void *value, CLocalNode* localNode);
		CLocalNode();
		~CLocalNode();

	};
}
