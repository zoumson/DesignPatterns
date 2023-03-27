#pragma once
#include "DPUtilities.h"

/*
* Creational Pattern
3. Builder
a. Separate construction of complex objects
b. Build a complex object one step at a time
c. Same construction process for different representations

*/

namespace za
{
	namespace dp
	{
		namespace creational
		{
			namespace bui
			{
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
			}
		}
	}
}