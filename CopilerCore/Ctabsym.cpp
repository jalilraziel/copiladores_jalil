
#include "Ctabsym.h"


bool Ctabsym::addsymbol(std::string name, E_SCOPE scope, int dimen, std::string func)
{
	return false;
}

bool Ctabsym::stmbolExist(std::string name, E_SCOPE scope, std::string func)
{
	return false;
}

std::string Ctabsym::GetSymbolType(std::string name, E_SCOPE scope, std::string func)
{
	return std::string();
}

std::string Ctabsym::GetSymbolScape(std::string name)
{
	return std::string();
}

bool Ctabsym::UpdateSymbolType()
{
	return false;
}

int Ctabsym::GetSymbolDimen(std::string name, E_SCOPE scope, std::string func)
{
	return 0;
}

Ctabsym::Ctabsym()
{
}


Ctabsym::~Ctabsym()
{
}
