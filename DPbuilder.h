#pragma once
#include "DPUtilities.h"

/*
* Creational Pattern
3. Builder
a. Separate construction of complex objects
b. Build a complex object one step at a time
c. Same construction process for different representations
d. Create an instance without setting arguments
e. Do not call/expose constructor with all arguments
f. Setter to set argument one at a time
g. Set optional argument when enabled
h. Get the object/instance once build is done

*/

namespace za
{
	namespace dp
	{
		namespace creational
		{
			namespace bui
			{
#pragma region Example1
#pragma region Entrees
				// Base Entree class
				class Entree
				{
				protected:
					char _entree[10];
				public:
					const char* getEntree();
				};

				// Derived Buger class
				class Burger : public Entree
				{
				public:
					Burger();
				};

				// Derived Hotdog class
				class Hotdog : public Entree
				{
				public:
					Hotdog();
				};
#pragma endregion Entrees

#pragma region Sides
				// Base Side class
				class Side
				{
				protected:
					char _side[10];
				public:
					char* getSide();
				};

				//Derived Fries class
				class Fries : public Side
				{
				public:
					Fries();
				};

				//Derived Salad class
				class Salad : public Side
				{
				public:
					Salad();
				};
#pragma endregion Sides

				class Drink
				{
				protected:
					char _drink[10];
				public:
					Drink();
					char* getDrink();
				};

				// Complex MealCombo object that contains an Entree, a Side and a Drink object
				class MealCombo
				{
				private:
					Entree* entree;
					Side* side;
					Drink* drink;
					char _bag[100];

				public:
					MealCombo(const char* type);
					void setEntree(Entree* e);
					void setSide(Side* s);
					void setDrink(Drink* d);
					const char* openMealBag();
				};

#pragma region Builders
				// Base Builder
				class MealBuilder
				{
				protected:
					MealCombo* _meal;
				public:
					virtual void cookEntree() {};
					virtual void cookSide() {};
					virtual void fillDrink() {};
					MealCombo* getMeal();
				};

				//Concrete Builder for a Burger Meal which has a burger, fries and a drink
				class BurgerMeal : public MealBuilder
				{
				public:
					BurgerMeal();
					void cookEntree();
					void cookSide();
					void fillDrink();
				};


				//Concrete Builder for a Hotdog Meal which has a hotdog, salad and a drink
				class HotdogMeal : public MealBuilder
				{
				public:
					HotdogMeal();
					void cookEntree();
					void cookSide();
					void fillDrink();
				};
#pragma endregion Builders
#pragma endregion Example1
#pragma region Example2
#pragma region Email

				class Email
				{

				public:
					void setSender(const std::string& sender);
					void setRecipient(const std::string& recipient);
					void setSubject(const std::string& subject);
					void setBody(const std::string& body);
					void showEmail();


				private:
					std::string _sender;
					std::string _recipient;
					std::string _subject;
					std::string _body;

				};

#pragma endregion Email
#pragma region EmailBuilder
				class EmailBuilder 
				{
				public:

					EmailBuilder();

					~EmailBuilder();

					void setSender(const std::string& sender);

					void setRecipient(const std::string& recipient);

					void setSubject(const std::string& subject);

					void setBody(const std::string& body);

					Email* getEmail();

				private:
					std::unique_ptr<Email> _email;
					//Email* _email;
					//Email* _email;
				};
#pragma endregion EmailBuilder

#pragma endregion Example2

#pragma region Example3

#pragma region Product 

				class Pizza 
				{
				public:
					void setDough(const std::string& dough);
					void setSauce(const std::string& sauce);
					void setTopping(const std::string& topping);
					void open() const;
				private:
					std::string _dough;
					std::string _sauce;
					std::string _topping;
				};
#pragma endregion Product 

#pragma region Builders
				class PizzaBuilder 
				{
				public:
					virtual ~PizzaBuilder() = default;
					void createNewPizza();
					Pizza* getPizza();
					virtual void buildDough() = 0;
					virtual void buildSauce() = 0;
					virtual void buildTopping() = 0;
				protected:
					std::unique_ptr<Pizza> _pizza;
				};

				class HawaiianPizzaBuilder :public PizzaBuilder 
				{
				public:
					~HawaiianPizzaBuilder() override = default;
					void buildDough() override;
					void buildSauce() override;
					void buildTopping() override;
				};

				class SpicyPizzaBuilder :public PizzaBuilder 
				{
				public:
					~SpicyPizzaBuilder() override = default;
					void buildDough() override;
					void buildSauce() override;
					void buildTopping() override;
				};
#pragma endregion Builders

#pragma region Manager
				class Cook 
				{
				public:
					void openPizza() const;
					void createPizza(PizzaBuilder* pizzaBuilder);
				private:
					PizzaBuilder* _pizzaBuilder;
				};
#pragma endregion Manager

#pragma endregion Example3
#pragma region Example4
#pragma region Product4 
				class Burger4 
				{
				public:
					void setBread(const std::string& bread);

					void setMeat(const std::string& meat);

					void setCheese(const std::string& cheese);

					void setVegetables(const std::string& vegetables);

					void showBurger();

				private:
					std::string __bread;
					std::string __meat;
					std::string __cheese;
					std::string __vegetables;
				};

#pragma endregion Product4 

#pragma region Builder4
				class BurgerBuilder4 
				{
				public:
					BurgerBuilder4();

					~BurgerBuilder4();

					void setBread(const std::string& bread);

					void setMeat(const std::string& meat);

					void setCheese(const std::string& cheese);

					void setVegetables(const std::string& vegetables);

					Burger4* getBurger();

				private:
					std::unique_ptr<Burger4> __burger;
					//Burger* _burger;
				};

#pragma endregion Builder4
#pragma endregion Example4
#pragma region Example5
#pragma region Product5

				class Computer 
				{
				public:
					void setCPU(std::string cpu);
					void setMotherboard(std::string motherboard);
					void setRAM(int ram);
					void setStorage(int storage);
					void setHasWifi(bool hasWifi);
					void setHasBluetooth(bool hasBluetooth);
					void setHasTouchscreen(bool hasTouchscreen);
					void showFeatures();
				private:
					std::string _cpu;
					std::string _motherboard;
					int _ram;
					int _storage;
					bool _hasWifi;
					bool _hasBluetooth;
					bool _hasTouchscreen;
					
				};
#pragma endregion Product5
#pragma region Builder5
				class ComputerBuilder 
				{
				public:
					void createNewComputer();
					void addCPU(std::string cpu);
					void addMotherboard(std::string motherboard);
					void addRAM(int ram);
					void addStorage(int storage);
					void addWifi();
					void addBluetooth();
					void addTouchscreen();
					Computer* getComputer();
				private:
					Computer* m_computer;

					std::unique_ptr<Computer> _computer;
				};

#pragma endregion Builder5

#pragma endregion Example5

			}
		}
	}
}