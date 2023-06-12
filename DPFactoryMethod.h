#pragma once
#include "DPUtilities.h"

/*
* Creational PATTERN
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
#pragma region Example1

#pragma region Interface1
				// Product from which the concrete products will inherit from 
				class Coffee1
				{

				public:

					virtual std::string make() = 0;
				};
#pragma endregion Interface1

#pragma region Product1
				// One concrete class
				class Espresso1 : public Coffee1
				{
				public:
					std::string make() override;
				};

				// Another concrete class
				class Cappuccino1 : public Coffee1
				{
				public:
					std::string make() override;
				};
#pragma endregion Product1

#pragma region Factory1
				class CoffeeMakerFactory1
				{
				public:
					enum class COFFEE1_TYPES
					{
						ESPRESSO1,
						CAPPUCCINO1
					};
					static std::unique_ptr<Coffee1> create(const COFFEE1_TYPES& type);
				};

				static std::ostream& operator<<(std::ostream& os, const CoffeeMakerFactory1::COFFEE1_TYPES type)
				{
					switch (type)
					{
					case CoffeeMakerFactory1::COFFEE1_TYPES::ESPRESSO1:
						return os << "Espresso1";

					case CoffeeMakerFactory1::COFFEE1_TYPES::CAPPUCCINO1:
						return os << "Cappuccino1";
					}
					return os;
				}
#pragma endregion Factory1

#pragma region User1
				void buildCoffee1(const CoffeeMakerFactory1::COFFEE1_TYPES& type);
#pragma endregion User1
				
#pragma endregion Example1

#pragma region Example2

#pragma region Interface2
				// Product
				class Car2
				{
				public:
					virtual std::string getDescription() = 0;
				};
#pragma endregion Interface2

#pragma region Product2
				// Concrete Products
				class Honda2 : public Car2
				{
				public:
					std::string getDescription() override;
				};

				class Toyota2 : public Car2 
				{
				public:
					std::string getDescription() override;
				};
#pragma endregion Product2

#pragma region Factory2

	
				class CarFactory2 
				{
				public:
					enum class CAR2_TYPES
					{
						HONDA2,
						TOYOTA2
					};
					static std::unique_ptr<Car2> create(const CAR2_TYPES& type);
				};

		
				static std::ostream& operator<<(std::ostream& os, const CarFactory2::CAR2_TYPES type)
				{
					switch (type)
					{
					case CarFactory2::CAR2_TYPES::HONDA2:
						return os << "Hond2";

					case CarFactory2::CAR2_TYPES::TOYOTA2:
						return os << "Toyota2";
					}
					return os;
				}
#pragma endregion Factory2

#pragma region User2
				void buildCar2(const CarFactory2::CAR2_TYPES& type);
#pragma endregion User2

#pragma endregion Example2

#pragma region Example3

#pragma region Interface3
				// Abstract Product
				class Character3 
				{
				public:
					virtual std::string printInfo() = 0;
				};


#pragma endregion Interface3

#pragma region Product3

				// Concrete Product 1
				class Wizard3 : public Character3
				{
				public:
					std::string printInfo() override;
				};


				// Concrete Product 2
				class Knight3 : public Character3
				{
				public:
					std::string printInfo() override;
				};


				// Concrete Product 3
				class Archer3 : public Character3
				{
				public:
					std::string printInfo() override;
				};



#pragma endregion Product3

#pragma region Factory3
				// Abstract Factory
				class CharacterFactory3 
				{
				public:
					enum class CHARACTER3_TYPES
					{
						WIZARD3,
						KNIGHT3,
						ARCHER3
					};
					static std::unique_ptr<Character3> create(const CHARACTER3_TYPES& type);
				};

				static std::ostream& operator<<(std::ostream& os, const CharacterFactory3::CHARACTER3_TYPES type)
				{
					switch (type)
					{
					case CharacterFactory3::CHARACTER3_TYPES::WIZARD3:
						return os << "Wizard3";

					case CharacterFactory3::CHARACTER3_TYPES::KNIGHT3:
						return os << "Knight3";

					case CharacterFactory3::CHARACTER3_TYPES::ARCHER3:
						return os << "Archer3";
					}
					return os;
				}
#pragma endregion Factory3

#pragma region User3
				void buildCharacter3(const CharacterFactory3::CHARACTER3_TYPES& type);
#pragma endregion User3

#pragma endregion Example3

#pragma region Example4

#pragma region Interface4
				class Product4 
				{
				public:
					virtual std::string info() = 0;
				};


#pragma endregion Interface4

#pragma region Product4
				class ConcreteProductA4 : public Product4 
				{
				public:
					std::string info() override;
				};				
				
				class ConcreteProductB4 : public Product4
				{
				public:
					std::string info() override;
				};
								

#pragma endregion Product4

#pragma region Factory4
				class ProductFactory4
				{
				public:
					
					enum class PRODUCT4_TYPES
					{
						PRODUCTA4,
						PRODUCTB4
					};
					static std::unique_ptr<Product4> create(const PRODUCT4_TYPES& type);
				};


				static std::ostream& operator<<(std::ostream& os, const ProductFactory4::PRODUCT4_TYPES type)
				{
					switch (type)
					{
					case ProductFactory4::PRODUCT4_TYPES::PRODUCTA4:
						return os << "ProductA4";

					case  ProductFactory4::PRODUCT4_TYPES::PRODUCTB4:
						return os << "ProductB4";
					}
					return os;
				}

#pragma endregion Factory4

#pragma region User4
				void buildProduct4(const ProductFactory4::PRODUCT4_TYPES& type);
#pragma endregion User4

#pragma endregion Example4

#pragma region Example5

#pragma region Interface5
				class Computer5
				{
				public:
					virtual std::string run() = 0;
					virtual std::string stop() = 0;

					virtual ~Computer5() {}; /* without this, you do not call Laptop or Desktop destructor in this example! */
				};
#pragma endregion Interface5

#pragma region Product5

				class Laptop5 : public Computer5
				{
				public:
					std::string run() override;
					std::string stop() override;
					virtual ~Laptop5() {}; /* because we have virtual functions, we need virtual destructor */
				private:
					bool mHibernating; // Whether or not the machine is hibernating
				};
				class Desktop5 : public Computer5
				{
				public:
					std::string run() override;
					std::string stop() override;
					virtual ~Desktop5() {};
				private:
					bool mOn; // Whether or not the machine has been turned on
				};
#pragma endregion Product5

#pragma region Factory5
				class ComputerFactory5
				{
				public:
					enum class COMPUTER5_TYPES
					{
						LAPTOP5,
						DESKTOP5
					};
					static std::unique_ptr<Computer5> create(const COMPUTER5_TYPES& type);
				};
				static std::ostream& operator<<(std::ostream& os, const ComputerFactory5::COMPUTER5_TYPES type)
				{
					switch (type)
					{
					case ComputerFactory5::COMPUTER5_TYPES::LAPTOP5:
						return os << "Laptop5";

					case  ComputerFactory5::COMPUTER5_TYPES::DESKTOP5:
						return os << "Desktop5";
					}
					return os;
				}
#pragma endregion Factory5

#pragma region User5
				void buildComputer5(const ComputerFactory5::COMPUTER5_TYPES& type);
#pragma endregion User5

#pragma endregion Example5

#pragma region Example6

#pragma region Interface6
				class Pizza6 
				{
				public:
					virtual int getPrice() const = 0;
					virtual ~Pizza6() {};  /* without this, no destructor for derived Pizza's will be called. */
				};

#pragma endregion Interface6

#pragma region Product6

				class HamAndMushroomPizza6 : public Pizza6 
				{
				public:
					int getPrice() const override;
					virtual ~HamAndMushroomPizza6() {};
				};

				class DeluxePizza6 : public Pizza6 
				{
				public:
					int getPrice() const override;
					virtual ~DeluxePizza6() {};
				};

				class HawaiianPizza6 : public Pizza6 
				{
				public:
					int getPrice() const override;
					virtual ~HawaiianPizza6() {};
				};
#pragma endregion Product6

#pragma region Factory6
				
				class PizzaFactory6 
				{
				public:
					enum class PIZZA6_TYPES
					{
						HAMMUSHROOM6,
						DELUXE6,
						HAWAIIAN6
					};
					static std::unique_ptr<Pizza6> create(const PIZZA6_TYPES& type);
				};

				static std::ostream& operator<<(std::ostream& os, const PizzaFactory6::PIZZA6_TYPES type)
				{
					switch (type)
					{
					case PizzaFactory6::PIZZA6_TYPES::HAMMUSHROOM6:
						return os << "HamMushroom6";

					case  PizzaFactory6::PIZZA6_TYPES::DELUXE6:
						return os << "Deluxe6";

					case PizzaFactory6::PIZZA6_TYPES::HAWAIIAN6:
						return os << "Hawaiian6";
					}
					return os;					
				}

#pragma endregion Factory6

#pragma region User6
				void buildPizza6(const PizzaFactory6::PIZZA6_TYPES& type);
#pragma endregion User6

#pragma endregion Example6


			}
		}
	}
}