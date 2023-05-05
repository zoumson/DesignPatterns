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
#pragma region Example1
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
					std::string getDescription();
				};

				class Toyota2 : public Car2 
				{
				public:
					std::string getDescription();
				};
#pragma endregion Product2
#pragma region Factory2

				// Abstract Factory
				class CarFactory2 
				{
				public:
					//virtual Car2* createCar() = 0;
					virtual std::unique_ptr<Car2> createCar() = 0;
				};

				// Concrete Factories
				class HondaFactory2 : public CarFactory2 
				{
				public:
					std::unique_ptr<Car2> createCar() override;
					//Car2* createCar();
				};

				class ToyotaFactory2 : public CarFactory2 
				{
				public:
					std::unique_ptr<Car2> createCar() override;
					//Car2* createCar();
				};


#pragma endregion Factory2
#pragma endregion Example2

#pragma region Example3
#pragma region Interface3
				// Abstract Product
				class Character 
				{
				public:
					virtual void printInfo() = 0;
				};


#pragma endregion Interface3

#pragma region Product3

				// Concrete Product 1
				class Wizard : public Character 
				{
				public:
					void printInfo() override;
				};


				// Concrete Product 2
				class Knight : public Character 
				{
				public:
					void printInfo() override;
				};


				// Concrete Product 3
				class Archer : public Character 
				{
				public:
					void printInfo() override;
				};



#pragma endregion Product3

#pragma region Factory3
				// Abstract Factory
				class CharacterFactory 
				{
				public:
					virtual std::unique_ptr<Character> createCharacter() = 0;
				};

				// Concrete Factory 1
				class WizardFactory : public CharacterFactory 
				{
				public:
					std::unique_ptr<Character> createCharacter() override;
				};


				// Concrete Factory 2
				class KnightFactory : public CharacterFactory 
				{
				public:
					std::unique_ptr<Character> createCharacter() override;
				};


				// Concrete Factory 3
				class ArcherFactory : public CharacterFactory 
				{
				public:
					std::unique_ptr<Character> createCharacter() override;
				};
#pragma endregion Factory3
#pragma endregion Example3

#pragma region Example4
#pragma region Interface4
				class Product4 
				{
				public:
					virtual void info() = 0;
				};


#pragma endregion Interface4
#pragma region Product4
				class ConcreteProductA4 : public Product4 
				{
				public:
					void info() override;
				};				
				
				class ConcreteProductB4 : public Product4
				{
				public:
					void info() override;
				};
								

#pragma endregion Product4
#pragma region Factory4
				class Factory4 
				{
				public:
					virtual std::unique_ptr<Product4>createProduct() = 0;
				};

				class ConcreteFactoryA4 : public Factory4 
				{
				public:
					std::unique_ptr<Product4>createProduct() override;
				};
				class ConcreteFactoryB4 : public Factory4
				{
				public:
					std::unique_ptr<Product4>createProduct() override;
				};


#pragma endregion Factory4
#pragma endregion Example4

#pragma region Example5
#pragma region Interface5
				class Computer5
				{
				public:
					virtual void Run() = 0;
					virtual void Stop() = 0;

					virtual ~Computer5() {}; /* without this, you do not call Laptop or Desktop destructor in this example! */
				};
#pragma endregion Interface5

#pragma region Product5
				class Laptop5 : public Computer5
				{
				public:
					void Run() override;
					void Stop() override;
					virtual ~Laptop5() {}; /* because we have virtual functions, we need virtual destructor */
				private:
					bool mHibernating; // Whether or not the machine is hibernating
				};
				class Desktop5 : public Computer5
				{
				public:
					void Run() override;
					void Stop() override;
					virtual ~Desktop5() {};
				private:
					bool mOn; // Whether or not the machine has been turned on
				};
#pragma endregion Product5

#pragma region Factory5
				class ComputerFactory5
				{
				public:
					static std::unique_ptr<Computer5> NewComputer(const std::string& description);
				};

#pragma endregion Factory5

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
					enum class PizzaType6 
					{
						HamMushroom6,
						Deluxe6,
						Hawaiian6
					};
					static std::unique_ptr<Pizza6> createPizza(PizzaType6 pizzaType6);
				};

				static std::ostream& operator<<(std::ostream& os, const PizzaFactory6::PizzaType6 pizzaType6)
				{
					switch (pizzaType6)
					{
					case PizzaFactory6::PizzaType6::HamMushroom6:
						return os << "HamMushroom6";

					case  PizzaFactory6::PizzaType6::Deluxe6:
						return os << "Deluxe6";

					case  PizzaFactory6::PizzaType6::Hawaiian6:
						return os << "Hawaiian6";
					}
					//return os;					
				}

#pragma endregion Factory6

#pragma endregion Example6


			}
		}
	}
}