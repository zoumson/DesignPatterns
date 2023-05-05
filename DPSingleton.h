#pragma once
#include "DPUtilities.h"

/*
* Creational Pattern
5. Singleton
only one insatnce of the class
only used for logging 
Not thread safe
sol: lazy initialization
lock the section  of creating the instance
*/

namespace za
{
	namespace dp
	{
		namespace creational
		{
			namespace sin
			{

				class Leader
				{
				private:
					static Leader* _instance;
					Leader()
					{
						std::cout << "New leader elected" << std::endl;
					}
				public:
					static Leader* getInstance()
					{
						if (_instance == nullptr)
						{
							_instance = new Leader;
						};
						return _instance;
					};
					void giveSpeech()
					{
						std::cout << "Address the public" << std::endl;
					}
				};
				
			}
		}
	}
}