#pragma once
#include "DPBuilder.h"

/*
* Creational Pattern
3. Builder

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

					const char* Entree::getEntree()
					{
						return _entree;
					};

					Burger::Burger()
					{
						std::cout << "\n Grill burger patty, add tomatoes and place them in a bun";
						strcpy_s(_entree, "hamburger");
					};

					Hotdog::Hotdog()
					{
						std::cout << "\n Cook sausage and place it in a bun";
						strcpy_s(_entree, "hotdog");
					};

#pragma endregion Entrees

#pragma region Sides
					char* Side::getSide()
					{
						return _side;
					};

					Fries::Fries()
					{
						std::cout << "\n Fry and season potatoes";
						strcpy_s(_side, "fries");
					};

					Salad::Salad()
					{
						std::cout << "\n Toss greens and dressing together";
						strcpy_s(_side, "salad");
					};

#pragma endregion Sides


					Drink::Drink()
					{
						std::cout << "\n Fill cup with soda" << std::endl;
						strcpy_s(_drink, "soda");
					};
					char* Drink::getDrink()
					{
						return _drink;
					};

					MealCombo::MealCombo(const char* type)
					{
						sprintf_s(_bag, "\n %s meal combo:", type);
					};
					void MealCombo::setEntree(Entree* e)
					{
						entree = e;
					};
					void MealCombo::setSide(Side* s)
					{
						side = s;
					};
					void MealCombo::setDrink(Drink* d)
					{
						drink = d;
					};
					const char* MealCombo::openMealBag()
					{
						sprintf_s(_bag, "%s %s, %s, %s", _bag, entree->getEntree(), side->getSide(), drink->getDrink());
						return _bag;
					};

#pragma region Builders

					MealCombo* MealBuilder::getMeal()
					{
						return _meal;
					};

					BurgerMeal::BurgerMeal()
					{
						_meal = new MealCombo("Burger");
					};
					void BurgerMeal::cookEntree()
					{
						Burger* burger = new Burger;
						_meal->setEntree(burger);
					};
					void BurgerMeal::cookSide()
					{
						Fries* fries = new Fries;
						_meal->setSide(fries);
					};
					void BurgerMeal::fillDrink()
					{
						Drink* drink = new Drink;
						_meal->setDrink(drink);
					};

					HotdogMeal::HotdogMeal()
					{
						_meal = new MealCombo("Hotdog");
					};
					void HotdogMeal::cookEntree()
					{
						Hotdog* hotdog = new Hotdog;
						_meal->setEntree(hotdog);
					}
					void HotdogMeal::cookSide()
					{
						Salad* caesar = new Salad;
						_meal->setSide(caesar);
					};
					void HotdogMeal::fillDrink()
					{
						Drink* drink = new Drink;
						_meal->setDrink(drink);
					};
#pragma endregion Builders
			}
		}
	}
}