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

#pragma region Material1

#pragma region Material11

					const char* Entree1::getEntree()
					{
						return _entree;
					};

					Burger1::Burger1()
					{
						std::cout << "\n Grill burger patty, add tomatoes and place them in a bun";
						strcpy_s(_entree, "hamburger");
					};

					Hotdog1::Hotdog1()
					{
						std::cout << "\n Cook sausage and place it in a bun";
						strcpy_s(_entree, "hotdog");
					};

#pragma endregion Material11

#pragma region Material12
					char* Side1::getSide()
					{
						return _side;
					};

					Fries1::Fries1()
					{
						std::cout << "\n Fry and season potatoes";
						strcpy_s(_side, "fries");
					};

					Salad1::Salad1()
					{
						std::cout << "\n Toss greens and dressing together";
						strcpy_s(_side, "salad");
					};

#pragma endregion Material12

#pragma region Material13


					Drink1::Drink1()
					{
						std::cout << "\n Fill cup with soda" << std::endl;
						strcpy_s(_drink, "soda");
					};
					char* Drink1::getDrink()
					{
						return _drink;
					};
#pragma endregion Material13

#pragma endregion Material1

#pragma region Product1

					MealCombo1::MealCombo1(const char* type)
					{
						sprintf_s(_bag, "\n %s meal combo:", type);
					};
					void MealCombo1::setEntree(Entree1* e)
					{
						entree = e;
					};
					void MealCombo1::setSide(Side1* s)
					{
						side = s;
					};
					void MealCombo1::setDrink(Drink1* d)
					{
						drink = d;
					};
					const char* MealCombo1::openMealBag()
					{
						sprintf_s(_bag, "%s %s, %s, %s", _bag, entree->getEntree(), side->getSide(), drink->getDrink());
						std::cout << "\n" << _bag << "\n";
						return _bag;
					};
#pragma endregion Product1

#pragma region Builder1

					BurgerMeal1::BurgerMeal1()
					{
						_meal = std::make_unique<MealCombo1>("Burger");
					};
					void BurgerMeal1::cookEntree()
					{
						Burger1* burger = new Burger1;
						_meal->setEntree(burger);
					};
					void BurgerMeal1::cookSide()
					{
						Fries1* fries = new Fries1;
						_meal->setSide(fries);
					};
					void BurgerMeal1::fillDrink()
					{
						Drink1* drink = new Drink1;
						_meal->setDrink(drink);
					};

					HotdogMeal1::HotdogMeal1()
					{
						_meal = std::make_unique<MealCombo1>("Hotdog");
					};
					void HotdogMeal1::cookEntree()
					{
						Hotdog1* hotdog = new Hotdog1;
						_meal->setEntree(hotdog);
					}
					void HotdogMeal1::cookSide()
					{
						Salad1* caesar = new Salad1;
						_meal->setSide(caesar);
					};
					void HotdogMeal1::fillDrink()
					{
						Drink1* drink = new Drink1;
						_meal->setDrink(drink);
					};

					std::shared_ptr<MealCombo1> MealBuilder1::getMeal()
					{
						return std::move(_meal);
					};
					std::unique_ptr< MealBuilder1> MealBuilder1::create(const MealBuilder1::MEAL1_BUILDERS& type)
					{
						switch (type)
						{
						case MealBuilder1::MEAL1_BUILDERS::BURGER1:
							return std::make_unique<BurgerMeal1>();

						case MealBuilder1::MEAL1_BUILDERS::HOTDOG1:
							return std::make_unique<HotdogMeal1>();
						}
						return nullptr;
					}
#pragma endregion Builder1

#pragma endregion Example1

#pragma region Example2

#pragma region Product2
					void Email2::setSender(const std::string& sender)
					{
						_sender = sender;
					}
										
					
					void Email2::setRecipient(const std::string& recipient)
					{
						_recipient = recipient;
					}
															
					
					void Email2::setSubject(const std::string& subject)
					{
						_subject = subject;
					}

										
					void Email2::setBody(const std::string& body)
					{
						_body = body;
					}

															
					void Email2::showEmail()
					{
						std::cout << "Sender: " << _sender << std::endl;
						std::cout << "Recipient: " << _recipient << std::endl;
						std::cout << "Subject: " << _subject << std::endl;
						std::cout << "Body: " << _body << std::endl;
					}


#pragma endregion Product2

#pragma region Builder2


					EmailBuilder2::EmailBuilder2()
					{
						//_email = new Email();
						_email = std::make_unique<Email2>();
					}

					EmailBuilder2::~EmailBuilder2()
					{
						//using unique ptr
						//delete _email;
					}


					void EmailBuilder2::setSender(const std::string& sender)
					{
						_email->setSender(sender);
					}

					void EmailBuilder2::setRecipient(const std::string& recipient)
					{
						_email->setRecipient(recipient);
					}

					void EmailBuilder2::setSubject(const std::string& subject)
					{
						_email->setSubject(subject);
					}

					void EmailBuilder2::setBody(const std::string& body)
					{
						_email->setBody(body);
					}


					std::shared_ptr<Email2> EmailBuilder2::getEmail()
					{
						return std::move(_email);
					}
#pragma endregion Builder2

#pragma endregion Example2

#pragma region Example3

#pragma region Product3 

					void Pizza3::setDough(const std::string& dough)
					{
						_dough = dough;
					}
					void Pizza3::setSauce(const std::string& sauce)
					{
						_sauce = sauce;
					}
					void Pizza3::setTopping(const std::string& topping)
					{
						_topping = topping;
					}
					void Pizza3::open() const 
					{
						std::cout << "The Pizza have " <<
							_dough << " dough, " <<
							_sauce << " sauce, " <<
							_topping << " topping." <<
							std::endl;
					}
#pragma endregion Product3 

#pragma region Builder3

					PizzaBuilder3::PizzaBuilder3()
					{
						_pizza = std::make_unique<Pizza3>();
					}
					std::unique_ptr< PizzaBuilder3> PizzaBuilder3::create(const PizzaBuilder3::PIZZA3_BUILDERS& type)
					{

						switch (type)
						{
						case PizzaBuilder3::PIZZA3_BUILDERS::HAWAIIAN3:
							return std::make_unique<HawaiianPizzaBuilder3>();

						case PizzaBuilder3::PIZZA3_BUILDERS::SPICY3:
							return std::make_unique<SpicyPizzaBuilder3>();
						}
						return nullptr;

					}
					std::shared_ptr<Pizza3> PizzaBuilder3::getPizza() 
					{
						return std::move(_pizza);
					}

					void HawaiianPizzaBuilder3::buildDough()  
					{
						_pizza->setDough("Hawaiian dough");
					}
					void HawaiianPizzaBuilder3::buildSauce()  
					{
						_pizza->setSauce("Hawaiian sauce");
					}
					void HawaiianPizzaBuilder3::buildTopping()  
					{
						_pizza->setTopping("Hawaiian topping");
					}

					void SpicyPizzaBuilder3::buildDough()
					{
						_pizza->setDough("Spicy dough");
					}
					void SpicyPizzaBuilder3::buildSauce()
					{
						_pizza->setSauce("Spicy sauce");
					}
					void SpicyPizzaBuilder3::buildTopping()
					{
						_pizza->setTopping("Spicy topping");
					}


#pragma endregion Builder3

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

					std::shared_ptr<Burger4> BurgerBuilder4::getBurger()
					{

						//return __burger.get();
						return std::move(__burger);
						//return _burger;
					}


#pragma endregion Builder4

#pragma endregion Example4

			}
		}
	}
}