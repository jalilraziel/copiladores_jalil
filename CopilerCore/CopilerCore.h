#pragma once

using namespace System;

namespace CopilerCore {
	public ref class CUALQUIEROTRCOSA
	{
	public:
		CUALQUIEROTRCOSA();
		~CUALQUIEROTRCOSA();

		cli::array<String^> ^ copilerProgram(String^ sourcecode);
	};
}
