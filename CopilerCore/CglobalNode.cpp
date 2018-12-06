#include "CglobalNode.h"

void CopilerCore::CglobalNode::add_lNode(CLocalNode * node) {
	if (m_localNode) {
		m_localNode->add_lNode(node);
	}
	else {
		m_localNode = node;
	}
}

CopilerCore::CglobalNode::CglobalNode(std::string name, std::string type, E_SCOPE scope, int dimencion, void *value, CLocalNode * localNode) {
	m_name = name;
	m_type = type;
	m_scope = scope;
	m_dimen = dimencion;
	m_values = value;
	m_localNode = localNode;
}

CopilerCore::CglobalNode::CglobalNode() {
}

CopilerCore::CglobalNode::~CglobalNode() {
	if (m_localNode) delete m_localNode;
}
