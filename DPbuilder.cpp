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



#pragma region Example1
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
#pragma endregion Example1
#pragma region Example2


#pragma region Email
					void Email::setSender(const std::string& sender)
					{
						_sender = sender;
					}
										
					
					void Email::setRecipient(const std::string& recipient)
					{
						_recipient = recipient;
					}
															
					
					void Email::setSubject(const std::string& subject)
					{
						_subject = subject;
					}

										
					void Email::setBody(const std::string& body)
					{
						_body = body;
					}

															
					void Email::showEmail()
					{
						std::cout << "Sender: " << _sender << std::endl;
						std::cout << "Recipient: " << _recipient << std::endl;
						std::cout << "Subject: " << _subject << std::endl;
						std::cout << "Body: " << _body << std::endl;
					}


#pragma endregion Email

#pragma region EmailBuilder


					EmailBuilder::EmailBuilder()
					{
						//_email = new Email();
						_email = std::make_unique<Email>();
					}

					EmailBuilder::~EmailBuilder()
					{
						//using unique ptr
						//delete _email;
					}

					void EmailBuilder::setSender(const std::string& sender)
					{
						_email->setSender(sender);
					}

					void EmailBuilder::setRecipient(const std::string& recipient)
					{
						_email->setRecipient(recipient);
					}


					void EmailBuilder::setSubject(const std::string& subject)
					{
						_email->setSubject(subject);
					}

					void EmailBuilder::setBody(const std::string& body)
					{
						_email->setBody(body);
					}

					Email* EmailBuilder::getEmail()
					{
						//return _email;
						return _email.get();
					}
#pragma endregion EmailBuilder

#pragma endregion Example2

#pragma region Example3
#pragma region Product 

					void Pizza::setDough(const std::string& dough)
					{
						_dough = dough;
					}
					void Pizza::setSauce(const std::string& sauce)
					{
						_sauce = sauce;
					}
					void Pizza::setTopping(const std::string& topping)
					{
						_topping = topping;
					}
					void Pizza::open() const 
					{
						std::cout << "The Pizza have " <<
							_dough << " dough, " <<
							_sauce << " sauce, " <<
							_topping << " topping." <<
							std::endl;
					}
#pragma endregion Product 

#pragma region Builders
					void PizzaBuilder::createNewPizza() 
					{
						_pizza = std::make_unique<Pizza>();
					}
					Pizza* PizzaBuilder::getPizza() 
					{
						return _pizza.release();
					}

					void HawaiianPizzaBuilder::buildDough()  
					{
						_pizza->setDough("Hawaiian dough");
					}
					void HawaiianPizzaBuilder::buildSauce()  
					{
						_pizza->setSauce("Hawaiian sauce");
					}
					void HawaiianPizzaBuilder::buildTopping()  
					{
						_pizza->setTopping("Hawaiian topping");
					}

					void SpicyPizzaBuilder::buildDough()
					{
						_pizza->setDough("Spicy dough");
					}
					void SpicyPizzaBuilder::buildSauce()
					{
						_pizza->setSauce("Spicy sauce");
					}
					void SpicyPizzaBuilder::buildTopping()
					{
						_pizza->setTopping("Spicy topping");
					}


#pragma endregion Builders

#pragma region Manager
					void Cook::openPizza() const 
					{
						_pizzaBuilder->getPizza()->open();
					}
					void Cook::createPizza(PizzaBuilder* pizzaBuilder)
					{
						_pizzaBuilder = pizzaBuilder;
						_pizzaBuilder->createNewPizza();
						_pizzaBuilder->buildDough();
						_pizzaBuilder->buildSauce();
						_pizzaBuilder->buildTopping();
					}
#pragma endregion Manager

#pragma endregion Example3


#pragma region Example4
#pragma region Product4 
					void Burger4::setBread(const std::string& bread) 
					{
						__bread = bread;
					}

					void Burger4::setMeat(const std::string& meat)
					{
						__meat = meat;
					}

					void Burger4::setCheese(const std::string& cheese)
					{
						__cheese = cheese;
					}

					void Burger4::setVegetables(const std::string& vegetables)
					{
						__vegetables = vegetables;
					}

					void Burger4::showBurger()
					{
						std::cout << "Burger: " << __bread << " with " << __meat
							<< " and " << __cheese << " with " << __vegetables << std::endl;
					}

#pragma endregion Product4

#pragma region Builder
					BurgerBuilder4::BurgerBuilder4()
					{
						__burger = std::make_unique<Burger4>();
					}

					BurgerBuilder4::~BurgerBuilder4()
					{
						//delete _burger;
					}

					void BurgerBuilder4::setBread(const std::string& bread)
					{
						__burger->setBread(bread);
					}

					void BurgerBuilder4::setMeat(const std::string& meat)
					{
						__burger->setMeat(meat);
					}

					void BurgerBuilder4::setCheese(const std::string& cheese)
					{
						__burger->setCheese(cheese);
					}

					void BurgerBuilder4::setVegetables(const std::string& vegetables)
					{
						__burger->setVegetables(vegetables);
					}

					Burger4* BurgerBuilder4::getBurger()
					{

						return __burger.get();
						//return _burger;
					}


#pragma endregion Builder4
#pragma endregion Example4

			}
		}
	}
}