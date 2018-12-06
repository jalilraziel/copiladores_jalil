#include "CLocalNode.h"

void CopilerCore::CLocalNode::add_lNode(CLocalNode * node) {
	if (m_localNode){
		m_localNode->add_lNode(node);
	}
	else{
		m_localNode = node;
	}
}

CopilerCore::CLocalNode::CLocalNode(std::string funcname, std::string type, E_SCOPE scope, int dimencion, void * value, CLocalNode * localNode) {
	m_funcName = funcname;
	m_type = type;
	m_scope = scope;
	m_dimen = dimencion;
	m_values = value;
	m_localNode = localNode;
}

CopilerCore::CLocalNode::CLocalNode()
{
}

CopilerCore::CLocalNode::~CLocalNode() {
	if (m_localNode) delete m_localNode;
}
