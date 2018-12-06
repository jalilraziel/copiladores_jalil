
#include "Ctabsym.h"


bool CopilerCore::Ctabsym::addsymbol(std::string name, std::string type, E_SCOPE scope, int dimencion, void *value, CLocalNode * localNode)
{
	std::map<std::string, CglobalNode>::iterator* iterator = new std::map<std::string, CglobalNode>::iterator();
	if (!stmbolExist(name, iterator))
	{
		CglobalNode newSymbol( name, type, scope, dimencion, value, localNode);
		m_symbols.insert(std::make_pair(name, newSymbol));
	}
	else
	{
		CLocalNode* node = new CLocalNode(name, type, scope, dimencion, value, localNode);
		(*iterator)->second.add_lNode(node);
	}
	return true;
}

bool CopilerCore::Ctabsym::stmbolExist(std::string name, E_SCOPE scope, std::string func)
{
	if (m_symbols.find(name) != m_symbols.end())
	{

	}
	else
	{
		return false;
	}
	return true;
}

bool CopilerCore::Ctabsym::stmbolExist(std::string name, std::map<std::string, CglobalNode>::iterator * A)
{
	*A = m_symbols.find(name);
	return (*A != m_symbols.end());
}

std::string CopilerCore::Ctabsym::GetSymbolType(std::string name, E_SCOPE scope, std::string func)
{
	return std::string();
}

std::string CopilerCore::Ctabsym::GetSymbolScape(std::string name)
{
	return std::string();
}

bool CopilerCore::Ctabsym::UpdateSymbolType()
{
	return false;
}

int CopilerCore::Ctabsym::GetSymbolDimen(std::string name, E_SCOPE scope, std::string func)
{
	return 0;
}

void CopilerCore::Ctabsym::reset() {
m_symbols.clear();
}

void CopilerCore::Ctabsym::getSymbols(std::map<std::string, CglobalNode>* symbols)
{
	*symbols = m_symbols;
}

CopilerCore::Ctabsym::Ctabsym()
{
}


CopilerCore::Ctabsym::~Ctabsym()
{
}
