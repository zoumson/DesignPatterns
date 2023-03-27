#include "DPViews.h"
namespace za
{
	namespace dp
	{
		namespace ex
		{
			void chainOfResponsability()
			{
				za::dp::cr::StringValidator* emailValidator = new za::dp::cr::BaseValidator;
				emailValidator
					->setNext(new za::dp::cr::NotEmptyValidator)
					->setNext(new za::dp::cr::RegexValidator("email address",
						"^\\w+([-+.']\\w+)*@\\w+([-.]\\w+)*\\.\\w+([-.]\\w+)*$"));

				std::cout << "------------Checking Emails------------" << std::endl;
				std::cout << "Input: \n" << emailValidator->validate("") << "\n\n";
				std::cout << "Input: shaun\n" << emailValidator->validate("shaun") << "\n\n";
				std::cout << "Input: shaun@test.com\n" << emailValidator->validate("haun@test.com") << "\n\n";
				delete emailValidator;
			}						
			void command()
			{
				za::dp::cmd::Canvas* canvas = new za::dp::cmd::Canvas;

				za::dp::cmd::Button* addTriangleButton = new za::dp::cmd::Button(new za::dp::cmd::AddShapeCommand("triangle", canvas));
				za::dp::cmd::Button* addSquareButton = new za::dp::cmd::Button(new za::dp::cmd::AddShapeCommand("square", canvas));
				za::dp::cmd::Button* clearButton = new za::dp::cmd::Button(new za::dp::cmd::ClearCommand(canvas));

				addTriangleButton->click();

				std::cout << "Current canvas state: " << za::dp::com::vectorToString(canvas->getShapes()) << "\n";

				addSquareButton->click();
				addSquareButton->click();
				addTriangleButton->click();

				std::cout << "Current canvas state: " << za::dp::com::vectorToString(canvas->getShapes()) << "\n";

				clearButton->click();

				std::cout << "Current canvas state: " << za::dp::com::vectorToString(canvas->getShapes()) << "\n";

				delete canvas;
			}			
			void mediator()
			{
				za::dp::med::UserInterface* ui = new za::dp::med::UserInterface;

				za::dp::med::InterfaceElement* elements[] = 
				{
					ui->getNameTextBox(),
					ui->getIsMarriedCheckbox(),
					ui->getSpousesNameTextBox(),
					ui->getSubmitButton(),
				};

				for (auto element : elements) 
				{
					std::cout << element->getDescription() << "\n\n";
				}

				ui->getIsMarriedCheckbox()->setIsChecked(true);

				for (auto element : elements) 
				{
					std::cout << element->getDescription() << "\n";
				}

				delete ui;
			}
			void observer()
			{
				za::dp::ob::ChatUser* user1 = new za::dp::ob::ChatUser("Jim");
				za::dp::ob::ChatUser* user2 = new za::dp::ob::ChatUser("Barb");
				za::dp::ob::ChatUser* user3 = new za::dp::ob::ChatUser("Hannah");

				za::dp::ob::ChatGroup* group1 = new za::dp::ob::ChatGroup("Gardening group");
				za::dp::ob::ChatGroup* group2 = new za::dp::ob::ChatGroup("Dog-lovers group");

				group1->subscribe(user1);
				group1->subscribe(user2);

				group2->subscribe(user2);
				group2->subscribe(user3);

				group1->publish("Special sale on gardening supplies!");
				group2->publish("It's national dog day everyone!");

				delete user1;
				delete user2;
				delete user3;
				delete group1;
				delete group2;
			}
			void chainRespObserCmd()
			{
				za::dp::ob::ChatUser* user1 = new za::dp::ob::ChatUser("Jim");
				za::dp::ob::ChatUser* user2 = new za::dp::ob::ChatUser("Barb");
				za::dp::ob::ChatUser* user3 = new za::dp::ob::ChatUser("Hannah");

				za::dp::ob::ChatGroup* group1 = new za::dp::ob::ChatGroup("Gardening group");
				za::dp::ob::ChatGroup* group2 = new za::dp::ob::ChatGroup("Dog-lovers group");

				group1->subscribe(user1);
				group1->subscribe(user2);

				group2->subscribe(user2);
				group2->subscribe(user3);

				za::dp::Handler* sendMessageChain = new za::dp::BaseHandler;

				sendMessageChain
					->setNext(new NotEmptyValidator)
					->setNext(new LengthValidator(2))
					->setNext(new PostMessageHandler);

				SendMessageCommand* emptyMessage = new SendMessageCommand(group1, "");
				SendMessageCommand* tooShortMessage = new SendMessageCommand(group1, "H");
				SendMessageCommand* sayHelloToGroup1 = new SendMessageCommand(group1, "Hello everyone in group 1!");
				SendMessageCommand* sayHelloToGroup2 = new SendMessageCommand(group2, "Hello everyone in group 2!");

				std::cout << "Sending empty message:\n" << sendMessageChain->handle(emptyMessage) << "\n\n";
				std::cout << "Sending short message:\n" << sendMessageChain->handle(tooShortMessage) << "\n\n";
				std::cout << "Sending message to group 1:\n" << sendMessageChain->handle(sayHelloToGroup1) << "\n\n";
				std::cout << "Sending message to group 2:\n" << sendMessageChain->handle(sayHelloToGroup2) << "\n\n";

				delete user1;
				delete user2;
				delete user3;
				delete group1;
				delete group2;
				delete emptyMessage;
				delete tooShortMessage;
				delete sayHelloToGroup1;
				delete sayHelloToGroup2;
				delete sendMessageChain;

			}
			void interpreter()
			{
				za::dp::itr::NumberExpression* five = new za::dp::itr::NumberExpression("5");
				za::dp::itr::NumberExpression* seven = new za::dp::itr::NumberExpression("7");
				za::dp::itr::OperationExpression* fivePlusSeven = new za::dp::itr::OperationExpression("plus", five, seven);

				za::dp::itr::NumberExpression* thirteen = new za::dp::itr::NumberExpression("13");
				za::dp::itr::OperationExpression* complexOp = new za::dp::itr::OperationExpression("minus", thirteen, fivePlusSeven);

				std::cout << "Five plus seven is: " << fivePlusSeven->evaluate() << "\n";

				std::cout << "13 - (5 + 7) = " << complexOp->evaluate() << "\n";

				delete five;
				delete seven;
				delete fivePlusSeven;
			}
			void state()
			{
				za::dp::sta::DeliveredState* deliveredState = new za::dp::sta::DeliveredState(nullptr);
				za::dp::sta::InTransitState* inTransitState = new za::dp::sta::InTransitState(deliveredState);
				za::dp::sta::PurchasedState* purchasedState = new za::dp::sta::PurchasedState(inTransitState);

				za::dp::sta::Purchase* purchase = new za::dp::sta::Purchase("Shoes", purchasedState);

				std::cout << purchase->getDescription() << "\n";

				purchase->goToNextState();
				std::cout << purchase->getDescription() << "\n";

				purchase->goToNextState();
				std::cout << purchase->getDescription() << "\n";

				delete deliveredState;
				delete inTransitState;
				delete purchasedState;
				delete purchase;
			}
			void strategy()
			{
				za::dp::str::Person businessPerson(new za::dp::str::FormalGreetingStrategy());
				za::dp::str::Person normalPerson(new za::dp::str::NormalGreetingStrategy());
				za::dp::str::Person coolPerson(new za::dp::str::InformalGreetingStrategy());
				za::dp::str::Person politician(new za::dp::str::FormalGreetingStrategy());

				std::cout << "The businessperson says: ";
				businessPerson.greet("Shaun");

				std::cout << "The normal person says: ";
				normalPerson.greet("Shaun");

				std::cout << "The cool person says: ";
				coolPerson.greet("Shaun");

				std::cout << "The politician says: ";
				politician.greet("Shaun");



			}
			void templatee()
			{
				za::dp::tmp::GreetingCardTemplate gct;
				za::dp::tmp::BirthdayCardTemplate bct;
				za::dp::tmp::NewYearsCardTemplate nyct;

				std::cout << "Here's a regular greeting card:\n\n" << gct.generate("Bob", "Jane") << "\n";
				std::cout << "Here's a birthday card:\n\n" << bct.generate("Bob", "Jane") << "\n";
				std::cout << "Here's a new year's card:\n\n" << nyct.generate("Bob", "Jane") << "\n";
			}
			void visitor()
			{
				za::dp::vis::Person person("John", 40);
				za::dp::vis::Landmark landmark("Eiffel Tower", "Paris");
				za::dp::vis::Car car("Chevrolet", "Camaro");

				za::dp::vis::DatabaseVisitor* dbv = new za::dp::vis::DatabaseVisitor;
				za::dp::vis::TextFileVisitor* tfv = new za::dp::vis::TextFileVisitor;

				person.accept(dbv);
				landmark.accept(dbv);
				car.accept(dbv);

				person.accept(tfv);
				landmark.accept(tfv);
				car.accept(tfv);

				delete dbv;
				delete tfv;
			}
			void templateVisitor()
			{
				za::dp::tvi::Person* person1 = new za::dp::tvi::Person("John", 40);
				za::dp::tvi::Person* person2 = new za::dp::tvi::Person("Joan", 80);
				za::dp::tvi::Person* person3 = new za::dp::tvi::Person("Brenda", 25);

				za::dp::tvi::GreetingCardGenerator* generator = new za::dp::tvi::GreetingCardGenerator;
				generator->addPerson(person1);
				generator->addPerson(person2);
				generator->addPerson(person3);

				generator->setTemplate(new za::dp::tvi::BirthdayCardTemplate("Bob"));
				for (auto card : generator->createGreetingCards()) 
				{
					std::cout << card << "\n";
				}

				generator->setTemplate(new za::dp::tvi::NewYearsCardTemplate("Penelope"));
				for (auto card : generator->createGreetingCards()) 
				{
					std::cout << card << "\n";
				}

				delete person1;
				delete person2;
				delete person3;
			}
			void iteratorr()
			{
				std::vector<int> numbers = { 1, 2, 3, 4, 5, 6, 7 };
				za::dp::ite::NumberCollection nc(numbers);

				za::dp::ite::NumberIterator* fi = nc.getForwardsIterator();
				za::dp::ite::NumberIterator* bi = nc.getBackwardsIterator();

				while (!fi->isFinished()) 
				{
					std::cout << fi->next() << ", ";
				}

				std::cout << "\n";

				std::cout << "Iterating through the numbers backwards:\n";

				while (!bi->isFinished()) {
					std::cout << bi->next() << ", ";
				}

				std::cout << "\n";

				delete fi;
				delete bi;

			}
			void memento()
			{
				za::dp::mem::Canvas* canvas = new za::dp::mem::Canvas;

				canvas->addShape("rhombus");
				canvas->addShape("triangle");
				canvas->addShape("square");
				canvas->addShape("circle");

				for (auto shape : canvas->getShapes()) 
				{
					std::cout << shape << ", ";
				};

				std::cout << "\n";

				canvas->undo();

				for (auto shape : canvas->getShapes()) 
				{
					std::cout << shape << ", ";
				};

				std::cout << "\n";

				canvas->addShape("rhombus");
				canvas->addShape("triangle");
				canvas->addShape("square");
				canvas->addShape("circle");
				canvas->undo();

				for (auto shape : canvas->getShapes()) 
				{
					std::cout << shape << ", ";
				};

				std::cout << "\n";

				delete canvas;

			}
			void nullObject()
			{
				za::dp::nob::SomeTask task1(new za::dp::nob::ConsoleLogger);
				za::dp::nob::SomeTask task2(new za::dp::nob::FileLogger("logs.txt"));
				za::dp::nob::SomeTask task3(new za::dp::nob::ApiLogger("loggingsite.com/api/logs"));
				za::dp::nob::SomeTask task4;

				task1.execute();
				task2.execute();
				task3.execute();
				task4.execute();
			}
			void iterMemNob()
			{
				za::dp::mio::NullHistory* history = new za::dp::mio::NullHistory;
				za::dp::mio::Canvas* canvas = new za::dp::mio::Canvas(history);

				canvas->addShape("rhombus");
				canvas->addShape("triangle");
				canvas->addShape("square");
				canvas->addShape("circle");

				std::cout << "Null canvas current shapes:\n";

				for (auto shape : canvas->getShapes()) 
				{
					std::cout << shape << ", ";
				};

				std::cout << "\n";

				std::cout << "Trying to undo...\n";
				canvas->undo();
				canvas->undo();
				canvas->undo();

				std::cout << "Null canvas shapes after undo:\n";

				for (auto shape : canvas->getShapes()) 
				{
					std::cout << shape << ", ";
				};

				std::cout << "\n";
			}

			namespace creational
			{
				void factoryMethod()
				{
					za::dp::creational::fm::CoffeeMakerFactory coffeeMachine;
					za::dp::creational::fm::Coffee* cup;
					cup = coffeeMachine.GetCoffee();

					std::cout << std::endl << "You had asked for a(n)" << cup->getType() << std::endl;
				}
				void abstracFactory()
				{
					za::dp::creational::af::CarFactory* CarPlant;
					int choice;

					std::cout << "Select a car type: " << std::endl;
					std::cout << "1: Gasoline" << std::endl;
					std::cout << "2: Electric" << std::endl;
					std::cout << "Selection: ";
					std::cin >> choice;
					std::cout << std::endl;

					switch (choice)
					{
					case 1:
						CarPlant = new za::dp::creational::af::GasCarFactory;
						break;
					case 2:
						CarPlant = new za::dp::creational::af::ElectricCarFactory;
						break;
					default:
						std::cout << "Invalid Selection" << std::endl;
						CarPlant = nullptr;
						break;
					}

					if (CarPlant != nullptr)
					{
						za::dp::creational::af::Door* myDoor = CarPlant->BuildDoor();
						za::dp::creational::af::Engine* myEngine = CarPlant->BuildEngine();

						myDoor->Open();
						myEngine->Run();
					}
				}
				void builder()
				{
					za::dp::creational::bui::MealBuilder * cook = new za::dp::creational::bui::MealBuilder;
					za::dp::creational::bui::MealCombo* meal;
					int choice;

					// Prompt user for their meal choice
					std::cout << "Select a meal: " << std::endl;
					std::cout << "1: Hamburger Meal" << std::endl;
					std::cout << "2: Hotdog Meal" << std::endl;
					std::cout << "Selection: ";
					std::cin >> choice;
					std::cout << std::endl;

					// Instantiate the appropriate builder based on user input
					switch (choice)
					{
					case 1:
						cook = new za::dp::creational::bui::BurgerMeal;
						break;
					case 2:
						cook = new za::dp::creational::bui::HotdogMeal;
						break;
					default:
						std::cout << "Invalid Selection" << std::endl;
						cook = nullptr;
						break;
					}

					std::cout << "Making selected meal" << std::endl;

					// Build the complex object
					cook->cookEntree();
					cook->cookSide();
					cook->fillDrink();
					meal = cook->getMeal();
					std::cout << meal->openMealBag() << std::endl;
				}
				void prototypee()
				{
					//create initial instance of a Sheep
					za::dp::creational::pro::Sheep* sheep0 = new za::dp::creational::pro::Sheep;
					sheep0->setHairColor("white");
					sheep0->setTail(5);
					sheep0->setWeight(90);
					sheep0->setHeight(1);
					sheep0->setAge(5);

					//create initial instance of a Cow
					za::dp::creational::pro::Cow* cow0 = new za::dp::creational::pro::Cow;
					cow0->setHairColor("brown");
					cow0->setTail(20);
					cow0->setWeight(790);
					cow0->setHeight(2);
					cow0->setAge(8);

					za::dp::creational::pro::Animal* farm[3];

					//use cloning to populate the farm
					farm[0] = sheep0->clone();
					farm[1] = cow0->clone();

					//change a cow property
					farm[1]->setWeight(1000);

					//shear a Sheep and clone it
					sheep0->shearing();
					farm[2] = sheep0->clone();

				}
				void singleton()
				{
					za::dp::creational::sin::Leader::getInstance()->giveSpeech();
					za::dp::creational::sin::Leader* elected = elected->getInstance();
					elected->giveSpeech();
				}
			}

			
		}

	}

}
