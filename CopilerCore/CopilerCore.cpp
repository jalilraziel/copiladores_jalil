#include "CopilerCore.h"

CopilerCore::CUALQUIEROTRCOSA::CUALQUIEROTRCOSA()
{

}

CopilerCore::CUALQUIEROTRCOSA::~CUALQUIEROTRCOSA()
{

}

cli::array<String^> ^ CopilerCore::CUALQUIEROTRCOSA::copilerProgram(String^ sourcecode)
{
	cli::array<String ^>^ copilerProgram = gcnew cli::array<String ^> (1);
	copilerProgram[0] = gcnew String("hola mundo");
	return copilerProgram;
}