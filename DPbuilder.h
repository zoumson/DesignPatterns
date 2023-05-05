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

#pragma region Material1

#pragma region Material11
				// Base Entree class
				class Entree1
				{
				protected:
					char _entree[10];
				public:
					const char* getEntree();
				};

				// Derived Buger class
				class Burger1 : public Entree1
				{
				public:
					Burger1();
				};

				// Derived Hotdog class
				class Hotdog1 : public Entree1
				{
				public:
					Hotdog1();
				};
#pragma endregion Material11

#pragma region Material12
				// Base Side class
				class Side1
				{
				protected:
					char _side[10];
				public:
					char* getSide();
				};

				//Derived Fries class
				class Fries1 : public Side1
				{
				public:
					Fries1();
				};

				//Derived Salad class
				class Salad1 : public Side1
				{
				public:
					Salad1();
				};
#pragma endregion Material12

#pragma region Material13

				class Drink1
				{
				protected:
					char _drink[10];
				public:
					Drink1();
					char* getDrink();
				};
#pragma endregion Material13

#pragma endregion Material1

#pragma region Product1
				// Complex MealCombo object that contains an Entree, a Side and a Drink object
				class MealCombo1
				{
				private:
					Entree1* entree;
					Side1* side;
					Drink1* drink;
					char _bag[100];

				public:
					MealCombo1(const char* type);
					void setEntree(Entree1* e);
					void setSide(Side1* s);
					void setDrink(Drink1* d);
					const char* openMealBag();
				};
#pragma endregion Product1

#pragma region Builder1
				// Base Builder
				class MealBuilder1
				{
				protected:
					std::unique_ptr<MealCombo1> _meal;
				public:
					enum class MEAL1_BUILDERS
					{
						BURGER1,
						HOTDOG1
					};
					virtual void cookEntree() {};
					virtual void cookSide() {};
					virtual void fillDrink() {};
					std::shared_ptr <MealCombo1> getMeal();
					static std::unique_ptr< MealBuilder1> create(const MEAL1_BUILDERS& type);
				};

				//Concrete Builder for a Burger Meal which has a burger, fries and a drink
				class BurgerMeal1 : public MealBuilder1
				{
				public:
					BurgerMeal1();
					void cookEntree();
					void cookSide();
					void fillDrink();
				};


				//Concrete Builder for a Hotdog Meal which has a hotdog, salad and a drink
				class HotdogMeal1 : public MealBuilder1
				{
				public:
					HotdogMeal1();
					void cookEntree();
					void cookSide();
					void fillDrink();
				};

				static std::ostream& operator<<(std::ostream& os, const MealBuilder1::MEAL1_BUILDERS type)
				{
					switch (type)
					{
					case MealBuilder1::MEAL1_BUILDERS::BURGER1:
						return os << "Burger1";

					case MealBuilder1::MEAL1_BUILDERS::HOTDOG1:
						return os << "Hotdog1";
					}
					return os;
				}
#pragma endregion Builder1

#pragma endregion Example1

#pragma region Example2

#pragma region Product2

				class Email2
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

#pragma endregion Product2

#pragma region Builder2
				class EmailBuilder2 
				{
				public:

					EmailBuilder2();

					~EmailBuilder2();

					void setSender(const std::string& sender);

					void setRecipient(const std::string& recipient);

					void setSubject(const std::string& subject);

					void setBody(const std::string& body);

					std::shared_ptr <Email2> getEmail();

				private:
					std::unique_ptr<Email2> _email;

				};
#pragma endregion Builder2

#pragma endregion Example2

#pragma region Example3

#pragma region Product3 

				class Pizza3 
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
#pragma endregion Product3 

#pragma region Builder3
				class PizzaBuilder3 
				{
				public:
					enum class PIZZA3_BUILDERS
					{
						HAWAIIAN3,
						SPICY3
					};
					virtual ~PizzaBuilder3() = default;
					PizzaBuilder3();
					
					std::shared_ptr <Pizza3> getPizza();
					virtual void buildDough() = 0;
					virtual void buildSauce() = 0;
					virtual void buildTopping() = 0;
					static std::unique_ptr< PizzaBuilder3> create(const PIZZA3_BUILDERS& type);
				protected:
					std::unique_ptr<Pizza3> _pizza;
				};

				class HawaiianPizzaBuilder3 :public PizzaBuilder3 
				{
				public:
					~HawaiianPizzaBuilder3() override = default;
					void buildDough() override;
					void buildSauce() override;
					void buildTopping() override;
				};

				class SpicyPizzaBuilder3 :public PizzaBuilder3 
				{
				public:
					~SpicyPizzaBuilder3() override = default;
					void buildDough() override;
					void buildSauce() override;
					void buildTopping() override;
				};

				static std::ostream& operator<<(std::ostream& os, const PizzaBuilder3::PIZZA3_BUILDERS type)
				{
					switch (type)
					{
					case PizzaBuilder3::PIZZA3_BUILDERS::HAWAIIAN3:
						return os << "Hawaiian3";

					case PizzaBuilder3::PIZZA3_BUILDERS::SPICY3:
						return os << "Spicy";
					}
					return os;
				}

#pragma endregion Builder3

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

					std::shared_ptr<Burger4> getBurger();


				private:
					std::unique_ptr<Burger4> __burger;
				};

#pragma endregion Builder4

#pragma endregion Example4

			}
		}
	}
}