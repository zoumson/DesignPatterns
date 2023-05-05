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
#pragma region Example1
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
#pragma endregion Example1

#pragma region Example2
#pragma region Interface2
#pragma endregion Interface2
#pragma region Product2

				std::string Honda2::getDescription()
				{
					return "Honda2 Car2";
				}
				
				std::string Toyota2::getDescription()
				{
					return "Toyota2 Car2";
				}


#pragma endregion Product2
#pragma region Factory2

				std::unique_ptr<Car2> HondaFactory2::createCar()
				{
					return std::make_unique<Honda2>();
				}
				
				std::unique_ptr<Car2> ToyotaFactory2::createCar()
				{
					return std::make_unique<Toyota2>();
				}

#pragma endregion Factory2
#pragma endregion Example2

#pragma region Example3
#pragma region Interface3

#pragma endregion Interface3

#pragma region Product3
				void Wizard::printInfo()
				{
					std::cout << "This is a wizard character\n";

				}				
				
				void Knight::printInfo()
				{
					std::cout << "This is a Knight character\n";

				}		

				void Archer::printInfo()
				{
					std::cout << "This is a Archer character\n";

				}

#pragma endregion Product3

#pragma region Factory3

					std::unique_ptr<Character> WizardFactory::createCharacter()
					{
						return std::make_unique<Wizard>();
					}

					std::unique_ptr<Character> KnightFactory::createCharacter()
					{
						return std::make_unique<Knight>();
					}
															
					std::unique_ptr<Character> ArcherFactory::createCharacter()
					{
						return std::make_unique<Archer>();
					}

#pragma endregion Factory3
#pragma endregion Example3

#pragma region Example4
#pragma region Interface4
#pragma endregion Interface4
#pragma region Product4

					void ConcreteProductA4::info() 
					{
						std::cout << "This is a ConcreteProductA4.\n";
					}

					void ConcreteProductB4::info() 
					{
						std::cout << "This is a ConcreteProductB4.\n";
					}
					


#pragma endregion Product4
#pragma region Factory4

					std::unique_ptr<Product4>ConcreteFactoryA4::createProduct()
					{
						return std::make_unique< ConcreteProductA4>();
					}
					std::unique_ptr<Product4>ConcreteFactoryB4::createProduct()
					{
						return std::make_unique< ConcreteProductB4>();
					}

#pragma endregion Factory4
#pragma endregion Example4

#pragma region Example5
#pragma region Interface5

#pragma endregion Interface5

#pragma region Product5
					void Laptop5::Run()
					{
						mHibernating = false;
					}					
					
					void Laptop5::Stop()
					{
						mHibernating = true;
					}

										
					void Desktop5::Run()
					{
						mOn = false;
					}					
					
					void Desktop5::Stop()
					{
						mOn = true;
					}

#pragma endregion Product5

#pragma region Factory5
					std::unique_ptr<Computer5> ComputerFactory5::NewComputer(const std::string& description)
					{
						if (description == "laptop")
						{
							return std::make_unique<Laptop5>();
						}
						else if (description == "desktop")
						{
							return std::make_unique<Desktop5>();
						}
						
						return nullptr;

					}


#pragma endregion Factory5

#pragma endregion Example5

#pragma region Example6

#pragma region Interface6

#pragma endregion Interface6

#pragma region Product6

					int HamAndMushroomPizza6::getPrice() const
					{
						return 850;
					}
					
					int DeluxePizza6::getPrice() const
					{
						return 1050;
					}		

					int HawaiianPizza6::getPrice() const
					{
						return 1150;
					}
					
#pragma endregion Product6

#pragma region Factory6
					std::unique_ptr<Pizza6> PizzaFactory6::createPizza(PizzaType6 pizzaType6)
					{
						switch (pizzaType6) 
						{
						case PizzaType6::HamMushroom6: 
							return std::make_unique<HamAndMushroomPizza6>();

						case  PizzaType6::Deluxe6:      
							return std::make_unique<DeluxePizza6>();

						case  PizzaType6::Hawaiian6:    
							return std::make_unique<HawaiianPizza6>();
						}
						throw "Invalid Pizza Type.";
				
					}


#pragma endregion Factory6

#pragma endregion Example6
			}
		}
	}
}