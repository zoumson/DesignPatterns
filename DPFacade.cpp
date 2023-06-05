#pragma once
#include "DPFacade.h"

/*
* Structural Pattern
Facade


*/

namespace za
{
	namespace dp
	{
		namespace structural
		{
			namespace fa
			{
#pragma region Example1

#pragma region Product1

				void Alarm1::alarmOn()
				{
					std::cout << "Alarm is on and house is secured" << std::endl;
				}
				void Alarm1::alarmOff()
				{
					std::cout << "Alarm is off and you can go into the house" << std::endl;
				}
				
				void Ac1::acOn()
				{
					std::cout << "Ac is on" << std::endl;
				}
				void Ac1::acOff()
				{
					std::cout << "AC is off" << std::endl;
				}
								
				void Tv1::tvOn()
				{
					std::cout << "Tv is on" << std::endl;
				}
				void Tv1::tvOff()
				{
					std::cout << "TV is off" << std::endl;
				}

#pragma endregion Product1

#pragma region Group1

				void HouseFacade1::goToWork()
				{
					ac.acOff();
					tv.tvOff();
					alarm.alarmOn();
				}
				void HouseFacade1::comeHome()
				{
					alarm.alarmOff();
					ac.acOn();
					tv.tvOn();
				}

#pragma endregion Group1

#pragma endregion Example1

			}
		}
	}
}