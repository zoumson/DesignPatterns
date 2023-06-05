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
					using namespace za::dp::creational::fm;
					auto example1 = [&]()
					{
						buildCoffee1(CoffeeMakerFactory1::COFFEE1_TYPES::CAPPUCCINO1);
					};
					auto example2 = [&]()
					{
						//std::unique_ptr<CarFactory2> factory1 = std::make_unique<HondaFactory2>();
						//std::unique_ptr<CarFactory2> factory2 = std::make_unique<ToyotaFactory2>();						
						//
						//
						//std::unique_ptr<Car2> car1 = factory1->createCar();
						//std::unique_ptr<Car2> car2 = factory2->createCar();

						//std::cout << car1->getDescription() << std::endl;
						//std::cout << car2->getDescription() << std::endl;

						buildCar2(CarFactory2::CAR2_TYPES::HONDA2);


					};					
					auto example3 = [&]()
					{

						buildCharacter3(CharacterFactory3::CHARACTER3_TYPES::KNIGHT3);

					};
					auto example4 = [&]()
					{
						buildProduct4(ProductFactory4::PRODUCT4_TYPES::PRODUCTB4);

					};
					auto example5 = [&]()
					{
						buildComputer5(ComputerFactory5::COMPUTER5_TYPES::DESKTOP5);
					};
					auto example6 = [&]()
					{
						buildPizza6(PizzaFactory6::PIZZA6_TYPES::HAMMUSHROOM6);
					};

					example1();
					example2();
					example3();
					example4();
					example5();
					example6();

				}
				void abstracFactory()
				{
					using namespace za::dp::creational::af;
					auto example1 = [&]()
					{
						auto carFactory = CarFactory::create(CarFactory::CAR_FACTORIES::GAS1);
						buildCar(*carFactory);
					};
					auto example2 = [&]()
					{
						auto product2Factory2 = AbstractFactory2::create(AbstractFactory2::PRODUCT2_FACTORIES::PRODUCT2_1);
						buildProduct2(*product2Factory2);

					};					
					auto example3 = [&]()
					{
						auto phoneFactory = APhoneFactory::create(APhoneFactory::PHONE_FACTORIES::SAMSUNG);
						buildPhone(*phoneFactory);

					};
					auto example4 = [&]()
					{
						auto guiFactory = GUIFactory4::create(GUIFactory4::GUI_FACTORIES::LINUX4);
						buildGUI(*guiFactory);
					};
					auto example5 = [&]()
					{
						auto themeFactory = ThemeFactory5::create(ThemeFactory5::THEME_FACTORIES::DARK5);
						buildTheme(*themeFactory);
					};
					
					example1();
					example2();
					example3();
					example4();
					example5();
				}
				void builder()
				{
					using namespace za::dp::creational::bui;

					auto example1 = [&]()
					{

						auto mealBuilder1 = MealBuilder1::create(MealBuilder1::MEAL1_BUILDERS::BURGER1);

						mealBuilder1->cookEntree();
						mealBuilder1->cookSide();
						mealBuilder1->fillDrink();
						
						auto meal1 = mealBuilder1->getMeal();
						meal1->openMealBag();
	
					};

					auto example2 = [&]()
					{
						//1. no argument, just create object itself 
						EmailBuilder2 emailBuilder2;

						//2. setting arguments of the object  one at a time 
						emailBuilder2.setSender("adama@gmail.com");
						emailBuilder2.setRecipient("adama@yahoo.com");
						emailBuilder2.setSubject("Learning Design Patterns");
						emailBuilder2.setBody("Hi Adama,\n\nJust a sending you resources to enhance your coding skills.\n\nBest regards,\n Adama");
						//3. retrieve 
						auto email2 = emailBuilder2.getEmail();
						//4. call the call operator to show the message
						email2->showEmail();
					};

					auto example3 = [&]()
					{
						auto pizzaBuilder3 = PizzaBuilder3::create(PizzaBuilder3::PIZZA3_BUILDERS::SPICY3);

						pizzaBuilder3->buildDough();
						pizzaBuilder3->buildSauce();
						pizzaBuilder3->buildTopping();

						auto pizza3 = pizzaBuilder3->getPizza();
						pizza3->open();

					};

					auto example4 = [&]()
					{
						BurgerBuilder4 burgerBuilder4;

						burgerBuilder4.setBread("Wheat");
						burgerBuilder4.setMeat("Chicken");
						burgerBuilder4.setCheese("Cheddar");
						burgerBuilder4.setVegetables("Lettuce, Tomato");

						auto burger4 = burgerBuilder4.getBurger();
						burger4->showBurger();
					};

					example1();
					example2();
					example3();
					example4();

				}
				
				
				void prototypee()
				{
					using namespace za::dp::creational::pro;
					auto example1 = [&]()
					{


						//create initial instance of a Sheep
						Sheep* sheep0 = new Sheep;
						sheep0->setHairColor("white");
						sheep0->setTail(5);
						sheep0->setWeight(90);
						sheep0->setHeight(1);
						sheep0->setAge(5);

						//create initial instance of a Cow
						Cow* cow0 = new Cow;
						cow0->setHairColor("brown");
						cow0->setTail(20);
						cow0->setWeight(790);
						cow0->setHeight(2);
						cow0->setAge(8);

						Animal* farm[3];

						//use cloning to populate the farm
						farm[0] = sheep0->clone();
						farm[1] = cow0->clone();

						//change a cow property
						farm[1]->setWeight(1000);

						//shear a Sheep and clone it
						sheep0->shearing();
						farm[2] = sheep0->clone();
					};					
					auto example2 = [&]()
					{
						RecordFactory recordFactory;

						auto record = recordFactory.create(RecordFactory::RECORD_TYPES::CAR);
						record->print();

						record = recordFactory.create(RecordFactory::RECORD_TYPES::BIKE);
						record->print();

						record = recordFactory.create(RecordFactory::RECORD_TYPES::PERSON);
						record->print();
					};
					auto example3 = [&]()
					{
						ObjectFactory3::initialize();
						Prototype3* object3;

						/* All the object were created by cloning the prototypes. */
						object3 = ObjectFactory3::getType1Value1();
						std::cout << object3->getType() << ": " << object3->getValue() << std::endl;

						object3 = ObjectFactory3::getType1Value2();
						std::cout << object3->getType() << ": " << object3->getValue() << std::endl;

						object3 = ObjectFactory3::getType2Value1();
						std::cout << object3->getType() << ": " << object3->getValue() << std::endl;

						object3 = ObjectFactory3::getType2Value2();
						std::cout << object3->getType() << ": " << object3->getValue() << std::endl;
					};
					auto example4 = [&]()
					{
						auto jane = EmployeeFactory::NewMainOfficeEmployee("Jane Doe", 125);
						auto jack = EmployeeFactory::NewAuxOfficeEmployee("jack Doe", 123);

						std::cout << *jane << std::endl << *jack << std::endl;
					};					
					auto example5 = [&]()
					{
						//Dog5* dog5 = new Dog5;
						//who_am_i(dog5);
						//delete dog5;
					};
					//example1();
					//example2();
					//example3();
					//example4();
					example5();


				}
				void singleton()
				{
					za::dp::creational::sin::Leader::getInstance()->giveSpeech();
					za::dp::creational::sin::Leader* elected = elected->getInstance();
					elected->giveSpeech();
				}
			}
			namespace structural
			{
				void adapter()
				{
					using namespace za::dp::structural::adp;

					auto example1 = [&]()
					{
						// Client code
						std::unique_ptr<DogFemaleS1> dogFemale = std::make_unique<DogFemaleS1>();

						std::unique_ptr<CatFemaleA1> catFemale = std::make_unique<CatFemaleA1>();

						DogNatureA1 dogNature;
						//	dogNature.carryOutNature (catFemale);  // Will not compile of course since the parameter must be of type Dog*.
						//ConversionAdapterA1* adaptedCat = new ConversionAdapterA1(catFemale);  // catFemale has adapted to become a Dog!
						std::unique_ptr<ConversionAdapterA1> adaptedCat = std::make_unique<ConversionAdapterA1>(catFemale.get());  // catFemale has adapted to become a Dog!

						dogNature.carryOutNature(dogFemale.get());
						dogNature.carryOutNature(adaptedCat.get());  // So now catFemale, in the form of adaptedCat, participates in the dogNature!
						// Note that catFemale is carrying out her own type of nature in dogNature though.
					};

					auto example2 = [&]()
					{
						std::cout << "Client: I can work just fine with the Target objects:\n";
						std::unique_ptr < TargetA2> target = std::make_unique < TargetA2>();

						ClientCodeA2(target.get());
						std::cout << std::endl << std::endl;

						std::unique_ptr < AdapteeA2> adaptee = std::make_unique < AdapteeA2>();
						std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
						std::cout << "Adaptee: " << adaptee->SpecificRequest();
						std::cout << std::endl << std::endl;

						std::cout << "Client: But I can work with it via the Adapter:\n";
						std::unique_ptr < AdapterA2> adapter = std::make_unique < AdapterA2>();
						ClientCodeA2(adapter.get());
						std::cout << std::endl << std::endl;
					};

					auto example3 = [&]()
					{
						int x = 20, y = 50, w = 300, h = 200;			
						std::unique_ptr<RectangleA3> r =  std::make_unique<RectangleAdapterA3>(x, y, w, h);
						r->draw();
					};
					
					auto example4 = [&]()
					{
						std::cout << "Client: I can work just fine with the Target objects:\n";
						std::unique_ptr < TargetA3> target = std::make_unique < TargetA3>();

						ClientCodeA3(target.get());
						std::cout << std::endl << std::endl;

						std::unique_ptr < AdapteeA3> adaptee = std::make_unique < AdapteeA3>();
						std::cout << "Client: The Adaptee class has a weird interface. See, I don't understand it:\n";
						std::cout << "Adaptee: " << adaptee->SpecificRequest();
						std::cout << std::endl << std::endl;

						std::cout << "Client: But I can work with it via the Adapter:\n";
						std::unique_ptr < AdapterA3> adapter = std::make_unique < AdapterA3>(adaptee.get());
						ClientCodeA3(adapter.get());
						std::cout << std::endl << std::endl;
					};					
					
					auto example5 = [&]()
					{
						std::unique_ptr<PrintA5> print(new PrintMessageDisplayA5("Nice to meet you"));
						print->printWeak();
						print->printStrong();
					};
										
					auto example6 = [&]()
					{
						std::unique_ptr<IAdapteeA6> pAdaptee(new OldClassA6());
						std::unique_ptr < ITargetA6> pTarget(new AdapterA6(pAdaptee.get()));
						pTarget->process();

					};

					//example1();
					//example2();
					//example3();
					//example4();
					//example5();
					example6();
				}
				void bridge()
				{
					using namespace za::dp::structural::bd;

					auto example1 = [&]()
					{
						std::unique_ptr<ImplementationB1> implementation = std::make_unique<ConcreteImplementationAB1>();
						//std::unique_ptr<AbstractionB1> abstraction(new AbstractionB1(implementation));
						std::unique_ptr<AbstractionB1> abstraction = std::make_unique<AbstractionB1>(implementation.get());

						ClientCodeB1(*(abstraction.get()));
						std::cout << std::endl;


						implementation = std::make_unique<ConcreteImplementationBB1>();
						abstraction = std::make_unique<ExtendedAbstractionB1>(implementation.get());

						ClientCodeB1(*(abstraction.get()));
					};

					auto example2 = [&]()
					{


						std::unique_ptr<DisplayImplB2> display_impl1(new TextDisplayImplB2("Japan"));

						std::unique_ptr<DisplayB2> d1(new DisplayB2(display_impl1.get()));
						d1->output();

						std::unique_ptr<DisplayImplB2> display_impl2(new TextDisplayImplB2("The United States of America"));
						std::unique_ptr<MultiLineDisplayB2> d2(new MultiLineDisplayB2(display_impl2.get()));
						d2->output();
						d2->outputMultiple(3);




					};

					auto example3 = [&]()
					{
						CircleShapeB3 circle1(1, 2, 3, new DrawingAPI1B3());
						CircleShapeB3 circle2(5, 7, 11, new DrawingAPI2B3());
						circle1.resizeByPercentage(2.5);
						circle2.resizeByPercentage(2.5);
						circle1.draw();
						circle2.draw();

					};

					//example1();
					//example2();
					example3();
				}

				void composite()
				{
					using namespace za::dp::structural::cmp;

					auto example1 = [&]()
					{
						// Initialize four ellipses
						const std::auto_ptr<EllipseC1> ellipse1(new EllipseC1());

						const std::auto_ptr<EllipseC1> ellipse2(new EllipseC1());

						const std::auto_ptr<EllipseC1> ellipse3(new EllipseC1());
						const std::auto_ptr<EllipseC1> ellipse4(new EllipseC1());

						// Initialize three composite graphics
						const std::auto_ptr<CompositeGraphicC1> graphic(new CompositeGraphicC1());
						const std::auto_ptr<CompositeGraphicC1> graphic1(new CompositeGraphicC1());
						const std::auto_ptr<CompositeGraphicC1> graphic2(new CompositeGraphicC1());

						// Composes the graphics
						graphic1->add(ellipse1.get());
						graphic1->add(ellipse2.get());
						graphic1->add(ellipse3.get());

						graphic2->add(ellipse4.get());

						graphic->add(graphic1.get());
						graphic->add(graphic2.get());

						// Prints the complete graphic (four times the string "Ellipse")
						graphic->print();
					};

					auto example2 = [&]()
					{
						ComponentC2* simple = new LeafC2;
						std::cout << "Client: I've got a simple component:\n";
						ClientCode1C2(simple);
						std::cout << "\n\n";
						/**
						   * as well as the complex composites.
						   */

						ComponentC2* tree = new CompositeC2;
						ComponentC2* branch1 = new CompositeC2;

						ComponentC2* leaf_1 = new LeafC2;
						ComponentC2* leaf_2 = new LeafC2;
						ComponentC2* leaf_3 = new LeafC2;

						branch1->Add(leaf_1);
						branch1->Add(leaf_2);

						ComponentC2* branch2 = new CompositeC2;
						branch2->Add(leaf_3);

						tree->Add(branch1);
						tree->Add(branch2);

						std::cout << "Client: Now I've got a composite tree:\n";
						ClientCode1C2(tree);
						std::cout << "\n\n";

						std::cout << "Client: I don't need to check the components classes even when managing the tree:\n";
						ClientCode2C2(tree, simple);
						std::cout << "\n";

						delete simple;
						delete tree;
						delete branch1;
						delete branch2;
						delete leaf_1;
						delete leaf_2;
						delete leaf_3;




					};

					auto example3 = [&]()
					{
						CompositeC3 composite;

						for (unsigned int i = 0; i < 5; i++)
						{
							composite.add(new LeafC3(i));
						}

						composite.remove(0);
						composite.operation();
					};

					//example1();
					//example2();
					example3();
				}
				void decorator()
				{
					using namespace za::dp::structural::dco;

					auto example1 = [&]()
					{
						const std::string salutation = "Greetings,";
						const std::string valediction = "Sincerly, Andy";
						std::string message1 = "This message is not decorated.";
						std::string message2 = "This message is decorated with a salutation.";
						std::string message3 = "This message is decorated with a valediction.";
						std::string message4 = "This message is decorated with a salutation and a valediction.";

						std::unique_ptr<InterfaceD1> messenger1 = std::make_unique<CoreD1>();
						std::unique_ptr<InterfaceD1> messenger2 = std::make_unique<MessengerWithSalutationD1>(std::make_unique<CoreD1>(), salutation);
						std::unique_ptr<InterfaceD1> messenger3 = std::make_unique<MessengerWithValedictionD1>(std::make_unique<CoreD1>(), valediction);
						std::unique_ptr<InterfaceD1> messenger4 = std::make_unique<MessengerWithValedictionD1>(std::make_unique<MessengerWithSalutationD1>
							(std::make_unique<CoreD1>(), salutation), valediction);

						messenger1->write(message1);
						std::cout << message1 << '\n';
						std::cout << "\n------------------------------\n\n";

						messenger2->write(message2);
						std::cout << message2 << '\n';
						std::cout << "\n------------------------------\n\n";

						messenger3->write(message3);
						std::cout << message3 << '\n';
						std::cout << "\n------------------------------\n\n";

						messenger4->write(message4);
						std::cout << message4 << '\n';
						std::cout << "\n------------------------------\n\n";
					};

					auto example2 = [&]()
					{
						/**
						* This way the client code can support both simple components...
						*/
						std::unique_ptr<ComponentD2> simple(new ConcreteComponentD2);
						std::cout << "Client: I've got a simple component:\n";
						ClientCodeD2(simple.get());
						std::cout << "\n\n";
						/**
					   * ...as well as decorated ones.
					   *
					   * Note how decorators can wrap not only simple components but the other
					   * decorators as well.
					   */
						std::unique_ptr<ComponentD2> decorator1(new ConcreteDecoratorAD2(simple.get()));
						std::unique_ptr<ComponentD2> decorator2(new ConcreteDecoratorBD2(decorator1.get()));
						std::cout << "Client: Now I've got a decorated component:\n";
						ClientCodeD2(decorator2.get());
						std::cout << "\n";

					};

					auto example3 = [&]()
					{
						//Create our Car that we want to buy
						std::unique_ptr<CarD3> b (new CarModel1D3());

						std::cout << "Base model of " << b->getDescription() << " costs $" << b->getCost() << "\n";

						////Who wants base model let's add some more features

						//release() don't call the destrucor while get() does
						b = std::make_unique<NavigationD3>(b.release());
						std::cout << b->getDescription() << " will cost you $" << b->getCost() << "\n";
						b = std::make_unique<PremiumSoundSystemD3>(b.release());
						b = std::make_unique<ManualTransmissionD3>(b.release());
						std::cout << b->getDescription() << " will cost you $" << b->getCost() << "\n";

					};
					auto example4 = [&]()
					{
						/**
						* This way the client code can support both simple components...
						*/

						std::unique_ptr<ComponentD4> simple(new ConcreteComponentD4);
						std::cout << "Client: I've got a simple component:\n";
						ClientCodeD4(simple.get());
						std::cout << "\n\n";

						/**
						* ...as well as decorated ones.
						*
						* Note how decorators can wrap not only simple components but the other
						* decorators as well.
						*
						*/

						std::unique_ptr < ComponentD4> decorator1(new ConcreteDecoratorAD4(simple.get()));
						std::unique_ptr < ComponentD4> decorator2(new ConcreteDecoratorBD4(decorator1.get()));
						std::cout << "Client: Now I've got a decorated component:\n";
						ClientCodeD4(decorator2.get());
						std::cout << "\n";
					};

					//example1();
					//example2();
					example3();
					//example4();
				}

				void facade()
				{
					using namespace za::dp::structural::fa;
					auto example1 = [&]()
					{
						HouseFacade1 hf;

						//Rather than calling 100 different on and off functions thanks to facade I only have 2 functions...
						hf.goToWork();
						hf.comeHome();
					};
					
					
					example1();



				}

			}
			
		}

	}

}





















