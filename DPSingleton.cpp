#pragma once
#include "DPSingleton.h"

/*
* Creational Pattern
5. Singleton


*/

namespace za
{
	namespace dp
	{
		namespace creational
		{
			namespace sin
			{
				//the static need to be in source file not in header
				Leader* Leader::_instance = nullptr;
			}
		}
	}
}