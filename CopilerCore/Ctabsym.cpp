
#include "Ctabsym.h"


bool CopilerCore::Ctabsym::addsymbol(std::string name, E_SCOPE scope, int dimen, std::string func)
{
	return false;
}

bool CopilerCore::Ctabsym::stmbolExist(std::string name, E_SCOPE scope, std::string func)
{
	return false;
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

CopilerCore::Ctabsym::Ctabsym()
{
}


CopilerCore::Ctabsym::~Ctabsym()
{
}
