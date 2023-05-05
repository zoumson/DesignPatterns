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

#pragma region Interface1
#pragma endregion Interface1

#pragma region Product1
				std::string Espresso1::make()
				{
					return (std::string("\n\nMaking a cup of espresso\n"
							"Grind and brew one scoop of espresso beans\n"));
				}				
				
				std::string Cappuccino1::make()
				{
					return (std::string("\n\nMaking a cup of cappuccino\n"
							"Grind and brew one scoop of espresso beans.\n"
							"Heat and foam milk.\n"));
				}

#pragma endregion Product1

#pragma region Factory1

				std::unique_ptr<Coffee1> CoffeeMakerFactory1::create(const CoffeeMakerFactory1::COFFEE1_TYPES& type)
				{
					switch (type)
					{
					case CoffeeMakerFactory1::COFFEE1_TYPES::ESPRESSO1:
						return std::make_unique< Espresso1>();

					case CoffeeMakerFactory1::COFFEE1_TYPES::CAPPUCCINO1:
						return std::make_unique< Cappuccino1>();
					}
					return nullptr;
				}

#pragma endregion Factory1

#pragma region User1
				void buildCoffee1(const CoffeeMakerFactory1::COFFEE1_TYPES& type)
				{
					auto coffee1 = CoffeeMakerFactory1::create(type);

					std::cout << std::endl << "You had asked for coffee " << type << coffee1->make() << std::endl;
				}
#pragma endregion User1

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


				std::unique_ptr<Car2> CarFactory2::create(const CarFactory2::CAR2_TYPES& type)
				{

					switch (type)
					{
					case CarFactory2::CAR2_TYPES::HONDA2:
						return std::make_unique<Honda2>();

					case CarFactory2::CAR2_TYPES::TOYOTA2:
						return std::make_unique<Toyota2>();
					}
					return nullptr;

				}

#pragma endregion Factory2

#pragma region User2
				void buildCar2(const CarFactory2::CAR2_TYPES& type)
				{
					auto car2 = CarFactory2::create(type);
					std::cout << "Car " << type << " description is " << car2->getDescription() << std::endl;

				}
#pragma endregion User2

#pragma endregion Example2

#pragma region Example3

#pragma region Interface3

#pragma endregion Interface3

#pragma region Product3
				std::string Wizard3::printInfo()
				{
					return "wizard3";

				}				
				
				std::string Knight3::printInfo()
				{
					return "Knight3";
				}		

				std::string Archer3::printInfo()
				{
					return "Archer3";
				}

#pragma endregion Product3

#pragma region Factory3

					std::unique_ptr<Character3> CharacterFactory3::create(const CharacterFactory3::CHARACTER3_TYPES& type)
					{
						switch (type)
						{
						case CharacterFactory3::CHARACTER3_TYPES::WIZARD3:
							return std::make_unique<Wizard3>();

						case CharacterFactory3::CHARACTER3_TYPES::KNIGHT3:
							return std::make_unique<Knight3>();

						case CharacterFactory3::CHARACTER3_TYPES::ARCHER3:
							return std::make_unique<Archer3>();
						}
						return nullptr;
					}
#pragma endregion Factory3

#pragma region User3

					void buildCharacter3(const CharacterFactory3::CHARACTER3_TYPES& type)
					{
						auto character3 = CharacterFactory3::create(type);
						std::cout << "Character type " << type << " is " << character3->printInfo() << std::endl;
					}
#pragma endregion User3

#pragma endregion Example3

#pragma region Example4

#pragma region Interface4
#pragma endregion Interface4

#pragma region Product4

					std::string ConcreteProductA4::info() 
					{
						return "ConcreteProductA4";
					}

					std::string ConcreteProductB4::info()
					{
						return "ConcreteProductB4";
					}
					


#pragma endregion Product4

#pragma region Factory4

					std::unique_ptr<Product4> ProductFactory4::create(const ProductFactory4::PRODUCT4_TYPES& type)
					{
						switch (type)
						{
						case  ProductFactory4::PRODUCT4_TYPES::PRODUCTA4:
							return std::make_unique<ConcreteProductA4>();

						case  ProductFactory4::PRODUCT4_TYPES::PRODUCTB4:
							return std::make_unique<ConcreteProductB4>();
						}
						return nullptr;

					}
#pragma endregion Factory4

#pragma region User4

					void buildProduct4(const ProductFactory4::PRODUCT4_TYPES& type)
					{
						auto product4 = ProductFactory4::create(type);
						std::cout << "Product type " << type << " is " << product4->info() << std::endl;
					}
#pragma endregion User4

#pragma endregion Example4

#pragma region Example5

#pragma region Interface5

#pragma endregion Interface5

#pragma region Product5
					std::string Laptop5::run()
					{
						mHibernating = false;
						return "not hibernating";
					}					
					
					std::string Laptop5::stop()
					{
						mHibernating = true;
						return "hibernating";
					}

										
					std::string Desktop5::run()
					{
						mOn = true;
						return "on";
					}					
					
					std::string Desktop5::stop()
					{
						mOn = false;
						return "off";
					}

#pragma endregion Product5

#pragma region Factory5
					std::unique_ptr<Computer5> ComputerFactory5::create(const ComputerFactory5::COMPUTER5_TYPES& type)
					{
						switch (type)
						{
						case  ComputerFactory5::COMPUTER5_TYPES::LAPTOP5:
							return std::make_unique<Laptop5>();

						case  ComputerFactory5::COMPUTER5_TYPES::DESKTOP5:
							return std::make_unique<Desktop5>();
						}
						return nullptr;

					}


#pragma endregion Factory5

#pragma region User5

					void buildComputer5(const ComputerFactory5::COMPUTER5_TYPES& type)
					{
						auto computer5 = ComputerFactory5::create(type);
						std::cout << "Computer type " << type << " is " << computer5->run() << std::endl;
						std::cout << "Computer type " << type << " is " << computer5->stop() << std::endl;
					}
#pragma endregion User5

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
					std::unique_ptr<Pizza6> PizzaFactory6::create(const PizzaFactory6::PIZZA6_TYPES& type)
					{
						switch (type) 
						{
						case  PizzaFactory6::PIZZA6_TYPES::HAMMUSHROOM6:
							return std::make_unique<HamAndMushroomPizza6>();

						case  PizzaFactory6::PIZZA6_TYPES::DELUXE6:
							return std::make_unique<DeluxePizza6>();

						case  PizzaFactory6::PIZZA6_TYPES::HAWAIIAN6:
							return std::make_unique<HawaiianPizza6>();
						}
						return nullptr;
				
					}


#pragma endregion Factory6

#pragma region User6
					void buildPizza6(const PizzaFactory6::PIZZA6_TYPES& type)
					{
						auto pizza6 = PizzaFactory6::create(type);
						std::cout << "Price of pizza " << type << " is " << pizza6->getPrice() << std::endl;
					}
#pragma endregion User6

#pragma endregion Example6
			}
		}
	}
}