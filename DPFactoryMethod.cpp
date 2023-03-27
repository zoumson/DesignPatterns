#pragma once
#include "DPFactoryMethod.h"

/*

*/

namespace za
{
	namespace dp
	{
		namespace creational
		{
			namespace fm
			{

				char* Coffee::getType()
				{
					return _type;
				};


				Espresso::Espresso() : Coffee()
					{
						strcpy_s(_type, "Espresso");
						std::cout << std::endl << "Making a cup of espresso" << std::endl;
						std::cout << "Grind and brew one scoop of espresso beans." << std::endl;
					};

				Cappuccino::Cappuccino() : Coffee()
					{
						strcpy_s(_type, "Cappuccino");
						std::cout << std::endl << "Making a cup of cappuccino" << std::endl;
						std::cout << "Grind and brew one scoop of espresso beans." << std::endl;
						std::cout << "Heat and foam milk." << std::endl;
					};

				Coffee* CoffeeMakerFactory::GetCoffee()
					{
						int choice;

						std::cout << "Select type of coffee to make: " << std::endl;
						std::cout << "1: Espresso" << std::endl;
						std::cout << "2: Cappuccino" << std::endl;
						std::cout << "Selection: ";
						std::cin >> choice;

						switch (choice)
						{
						case 1:
							return new Espresso;
						case 2:
							return new Cappuccino;
						default:
							std::cout << "Invalid Selection" << std::endl;
							return nullptr;
						}
					};


			}
		}
	}
}