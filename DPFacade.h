#pragma once
#include "DPUtilities.h"

/*
* Structural Pattern
Facade

Facade is one of the easiest patterns I think... And this is very simple example.

Imagine you set up a smart house where everything is on remote. So to turn the lights on you push lights on button - And same for TV,
AC, Alarm, Music, etc...

When you leave a house you would need to push a 100 buttons to make sure everything is off and are good to go which could be little
annoying if you are lazy like me
so I defined a Facade for leaving and coming back. (Facade functions represent buttons...) So when I come and leave I just make one
call and it takes care of everything...
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
				class Alarm1
				{
				public:
					void alarmOn();

					void alarmOff();
				};

				class Ac1
				{
				public:
					void acOn();

					void acOff();
				};

				class Tv1
				{
				public:
					void tvOn();

					void tvOff();
				};
#pragma endregion Product1

#pragma region Group1
				class HouseFacade1
				{
					Alarm1 alarm;
					Ac1 ac;
					Tv1 tv;

				public:
					HouseFacade1() {}

					void goToWork();

					void comeHome();
				};
#pragma endregion Group1

#pragma endregion Example1

			}
		}
	}
}