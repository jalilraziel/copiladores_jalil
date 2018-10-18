#include "CglobalNode.h"

std::string CopilerCore::CglobalNode::GetSymbolType(std::string name, E_SCOPE scope, std::string func)
{
	return std::string();
}

int CopilerCore::CglobalNode::GetSymbolDimen(std::string name, E_SCOPE scope, std::string func)
{
	return 0;
}

CopilerCore::CglobalNode::CglobalNode(std::string name, std::string type, E_SCOPE scope, int dimencion)
{
	this->m_name = name;
	this->m_type = type;
	this->m_scope = scope;
	this->m_dimen = dimencion;
}

CopilerCore::CglobalNode::CglobalNode(std::string name, std::string type, E_SCOPE scope, int dimencion, CLocalNode * localNode)
{
	this->m_name = name;
	this->m_type = type;
	this->m_scope = scope;
	this->m_dimen = dimencion;
	this->m_localNode = localNode;
}

CopilerCore::CglobalNode::~CglobalNode()
{
}
