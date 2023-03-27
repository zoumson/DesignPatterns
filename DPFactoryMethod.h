#pragma once
#include "DPUtilities.h"

/*
* Creational Pattern
1. Factory Method
-Coffe machine
-Used to create different type of coffe
-Create object at runtime
-Lets the subclasses instantiate the object instead of the main


*/

namespace za
{
	namespace dp
	{
		namespace creational
		{
			namespace fm
			{
				// Product from which the concrete products will inherit from 
				class Coffee
				{
				protected:
					char _type[15];
				public:
					Coffee()
					{
					};
					char* getType();
				};

				// One concrete class
				class Espresso : public Coffee
				{
				public:
					Espresso();
				};

				// Another concrete class
				class Cappuccino : public Coffee
				{
				public:
					Cappuccino();
				};

				class CoffeeMakerFactory
				{
				private:
					Coffee* _coffee;
				public:
					Coffee* GetCoffee();
				};

			}
		}
	}
}