#pragma once
#include"DPAbstractFactory.h"

/*

*/

namespace za
{
	namespace dp
	{
		namespace creational
		{
			namespace af
			{
#pragma region Example1
#pragma region Interface11
#pragma endregion Interface11
#pragma region Product11

				GasCarDoor::GasCarDoor()
				{
					std::cout << "Making a door for a gas car." << std::endl;
				};
				void GasCarDoor::Open()
				{
					std::cout << "click" << std::endl;
				};

				ElectricCarDoor::ElectricCarDoor()
				{
					std::cout << "Making a door for an electric car" << std::endl;
				};
				void ElectricCarDoor::Open()
				{
					std::cout << "shhhhh" << std::endl;
				};
#pragma endregion Product11
#pragma region Interface12

				Engine::Engine()
				{
					strcpy_s(_sound, "");
				};

#pragma endregion Interface12
#pragma region Product12

				GasEngine::GasEngine()
				{
					strcpy_s(_sound, "vroom");
					std::cout << "Making a gas engine." << std::endl;
				};
				void GasEngine::Run()
				{
					std::cout << _sound << std::endl;
				};

				ElectricEngine::ElectricEngine()
				{
					strcpy_s(_sound, "SHHHH");
					std::cout << "Making an electric engine." << std::endl;
				};
				void ElectricEngine::Run()
				{
					std::cout << _sound << std::endl;
				};
#pragma endregion Product12
#pragma region Factory1
				//Factories

				std::unique_ptr<Door> GasCarFactory::BuildDoor()
				{
					return std::make_unique<GasCarDoor>();
				};
				std::unique_ptr<Engine> GasCarFactory::BuildEngine()
				{
					return std::make_unique<GasEngine>();
				};

				std::unique_ptr<Door> ElectricCarFactory::BuildDoor()
				{
					return std::make_unique<ElectricCarDoor>();
				};
				std::unique_ptr<Engine> ElectricCarFactory::BuildEngine()
				{
					return std::make_unique<ElectricEngine>();
				};
				std::unique_ptr<CarFactory> CarFactory::create(const CarFactory::CAR_FACTORIES& type)
				{
					switch (type)
					{
					case CarFactory::CAR_FACTORIES::GAS1:
						return std::make_unique<GasCarFactory>();

					case CarFactory::CAR_FACTORIES::ELECTRIC1:
						return std::make_unique<ElectricCarFactory>();
					}
					return nullptr;
				}
#pragma endregion Factory1
#pragma region User1
				void buildCar(CarFactory& factory)
				{
					auto myDoor = factory.BuildDoor();
					auto myEngine = factory.BuildEngine();

					myDoor->Open();
					myEngine->Run();
				}
#pragma endregion User1

#pragma endregion Example1


#pragma region Example2

#pragma region Interface21

#pragma endregion Interface21

#pragma region Product21
				void ConcreteProductA21::info()
				{
					std::cout << "This is a ConcreteProductA21.\n";
				}				
				void ConcreteProductA22::info()
				{
					std::cout << "This is a ConcreteProductA22.\n";
				}


#pragma endregion Product21

#pragma region Interface22

#pragma endregion Interface22

#pragma region Product22

				void ConcreteProductB21::info()
				{
					std::cout << "This is a ConcreteProductB21.\n";
				}
				void ConcreteProductB22::info()
				{
					std::cout << "This is a ConcreteProductB22.\n";
				}
			 
#pragma endregion Product22

		

#pragma region Factory2
				std::unique_ptr<ProductA2> ConcreteFactory21::createProductA()
				{
					return std::make_unique<ConcreteProductA21>();
				}
								
				std::unique_ptr<ProductB2> ConcreteFactory21::createProductB()
				{
					return std::make_unique<ConcreteProductB21>();
				}
								
				
				std::unique_ptr<ProductA2> ConcreteFactory22::createProductA()
				{
					return std::make_unique<ConcreteProductA22>();
				}
								
				std::unique_ptr<ProductB2> ConcreteFactory22::createProductB()
				{
					return std::make_unique<ConcreteProductB22>();
				}


				std::unique_ptr<AbstractFactory2> AbstractFactory2::create(const AbstractFactory2::PRODUCT2_FACTORIES& type)
				{

						switch (type)
						{
						case AbstractFactory2::PRODUCT2_FACTORIES::PRODUCT2_1:
							return std::make_unique<ConcreteFactory21>();

						case AbstractFactory2::PRODUCT2_FACTORIES::PRODUCT2_2:
							return std::make_unique< ConcreteFactory22>();
						}
						return nullptr;

				};
#pragma endregion Factory2
#pragma region User2
				void buildProduct2(AbstractFactory2& factory)
				{
					auto productA = factory.createProductA();
					auto productB = factory.createProductB();
					productA->info();
					productB->info();

				}
#pragma endregion User2


#pragma endregion Example2



#pragma region Example3
#pragma region Interface31

#pragma endregion Interface31

#pragma region Product31
					std::string Asha::Name()
					{
						return "Asha";
					}
															
					std::string Primo::Name()
					{
						return "Guru";
					}
										
					std::string Genie::Name()
					{
						return "Genie";
					}
					
#pragma endregion Product31

#pragma region Interface32

#pragma endregion Interface32

#pragma region Product32
					std::string GalaxyS2::Name()
					{
						return "GalaxyS2";
					}
															
					std::string Titan::Name()
					{
						return "Titan";
					}
										
					std::string Lumia::Name()
					{
						return "Lumia";
					}

#pragma endregion Product32

#pragma region Factory3

					//std::unique_ptr<APhoneFactory> APhoneFactory::create(APhoneFactory::PHONE_FACTORIES factory)
					//{
					//	if (factory == PHONE_FACTORIES::SAMSUNG)
					//	{
					//		return std::make_unique<SamsungFactory>();
					//	}
					//	else if (factory == PHONE_FACTORIES::HTC)
					//	{
					//		return std::make_unique<HTCFactory>();
					//	}
					//	else if (factory == PHONE_FACTORIES::NOKIA)
					//	{
					//		return std::make_unique<NokiaFactory>();
					//	}

					//	return nullptr;
					//}
					//createSmart
					//createDumb
					std::unique_ptr<ISmart> SamsungFactory::createSmart()
					{
						return std::make_unique<GalaxyS2>();
					}
					
					std::unique_ptr<IDumb> SamsungFactory::createDumb()
					{
						return std::make_unique<Primo>();

					}	

					std::unique_ptr<ISmart> HTCFactory::createSmart()
					{
						return std::make_unique<Titan>();
					}
					
					std::unique_ptr<IDumb> HTCFactory::createDumb()
					{
						return std::make_unique<Genie>();

					}

					std::unique_ptr<ISmart> NokiaFactory::createSmart()
					{
						return std::make_unique<Lumia>();
					}
					
					std::unique_ptr<IDumb> NokiaFactory::createDumb()
					{
						return std::make_unique<Asha>();

					}
					std::unique_ptr<APhoneFactory> APhoneFactory::create(const APhoneFactory::PHONE_FACTORIES& type)
					{
						switch (type)
						{
						case APhoneFactory::PHONE_FACTORIES::HTC:
							return std::make_unique<HTCFactory>();						
						
						case APhoneFactory::PHONE_FACTORIES::NOKIA:
							return std::make_unique<NokiaFactory>();	

						case APhoneFactory::PHONE_FACTORIES::SAMSUNG:
							return std::make_unique<SamsungFactory>();	
						}

						return nullptr;
					}
#pragma endregion Factory3
#pragma region User3
					void buildPhone(APhoneFactory& factory)
					{

						auto myDumb = factory.createDumb();
						auto mySmart = factory.createSmart();
						std::cout << "Dumb phone " << myDumb->Name() << "\n";
						std::cout << "Smart phone " << mySmart->Name() << "\n";

					}
#pragma endregion User3
#pragma endregion Example3

#pragma region Example4

#pragma region Interface4

#pragma endregion Interface4

#pragma region Product4

#pragma endregion Product4

#pragma region Factory4

					/* Windows support */

					void WindowsFactory4::WindowsFrame4::draw() const
					{
						std::cout << "I'm a Windows-like frame" << std::endl;
					}
					void WindowsFactory4::WindowsButton4::draw() const
					{
						std::cout << "I'm a Windows-like button" << std::endl;
					}					
					void WindowsFactory4::WindowsLabel4::draw() const
					{
						std::cout << "I'm a Windows-like label" << std::endl;
					}

					std::unique_ptr<Frame4> WindowsFactory4::createFrame()
					{
						return std::make_unique<WindowsFrame4>();
					}					
					std::unique_ptr<Button4> WindowsFactory4::createButton()
					{
						return std::make_unique<WindowsButton4>();
					}										
					std::unique_ptr<Label4> WindowsFactory4::createLabel()
					{
						return std::make_unique<WindowsLabel4>();
					}

					/* Linux support */
					void LinuxFactory4::LinuxFrame4::draw() const
					{
						std::cout << "I'm a Linux-like frame" << std::endl;
					}
					void LinuxFactory4::LinuxButton4::draw() const
					{
						std::cout << "I'm a Linux-like button" << std::endl;
					}
					void LinuxFactory4::LinuxLabel4::draw() const
					{
						std::cout << "I'm a Linux-like label" << std::endl;
					}

					std::unique_ptr<Frame4> LinuxFactory4::createFrame()
					{
						return std::make_unique<LinuxFrame4>();
					}
					std::unique_ptr<Button4> LinuxFactory4::createButton()
					{
						return std::make_unique<LinuxButton4>();
					}
					std::unique_ptr<Label4> LinuxFactory4::createLabel()
					{
						return std::make_unique<LinuxLabel4>();
					}

					//static std::unique_ptr<GUIFactory4> create(const GUI_FACTORIES& type);
					std::unique_ptr<GUIFactory4> GUIFactory4::create(const GUIFactory4::GUI_FACTORIES& type)
					{
						switch (type)
						{
						case GUIFactory4::GUI_FACTORIES::WINDOWS4:
							return std::make_unique< WindowsFactory4>();						
						
						case GUIFactory4::GUI_FACTORIES::LINUX4:
							return std::make_unique< LinuxFactory4>();
						}

						return nullptr;

					}

#pragma endregion Factory4
#pragma region User4
					/* User code */
					void buildGUI(GUIFactory4& factory)
					{
						auto frame = factory.createFrame();
						auto button = factory.createButton();
						auto label = factory.createLabel();

						frame->draw();
						button->draw();
						label->draw();
					}
#pragma endregion User4

#pragma endregion Example4


#pragma region Example5


#pragma region Interface51
#pragma endregion Interface51
#pragma region Product51
					std::string LightBgColour5::setBg()
					{
						return "light";
					}					
					
					std::string DarkBgColour5::setBg()
					{
						return "dark";
					}

#pragma endregion Product51

#pragma region Interface52
#pragma endregion Interface52
#pragma region Product52

					std::string LightText5::setTxt()
					{
						return "text - light";
					}
					std::string LightText5::interact(Bgcolor5& interactor)
					{
						std::string result = interactor.setBg();
						return ("text-light interacted with " + result);
					}
					
					std::string DarkText5::setTxt()
					{
						return "text - dark";
					}
					std::string DarkText5::interact(Bgcolor5& interactor)
					{
						std::string result = interactor.setBg();
						return ("text-dark interacted with " + result);
					}

#pragma endregion Product52


#pragma region Factory5

					std::unique_ptr<Bgcolor5> LightFactory5::createBg()
					{
						return std::make_unique<LightBgColour5>();
					}
										
					std::unique_ptr<Text5> LightFactory5::createTxt()
					{
						return std::make_unique<LightText5>();
					}
					

					std::unique_ptr<Bgcolor5> DarkFactory5::createBg()
					{
						return std::make_unique<DarkBgColour5>();
					}
										
					std::unique_ptr<Text5> DarkFactory5::createTxt()
					{
						return std::make_unique<DarkText5>();
					}

					std::unique_ptr<ThemeFactory5> ThemeFactory5::create(const ThemeFactory5::THEME_FACTORIES& type)
					{
						switch (type)
						{
						case ThemeFactory5::THEME_FACTORIES::LIGHT5:
							return std::make_unique<LightFactory5>();						
						
						case ThemeFactory5::THEME_FACTORIES::DARK5:
							return std::make_unique< DarkFactory5>();
						}
						return nullptr;
					}

#pragma endregion Factory5
#pragma region User5
					/* User code */
					void buildTheme(ThemeFactory5& factory)
					{
						auto bg = factory.createBg();
						auto txt = factory.createTxt();
						
						std::cout << bg->setBg() << " " << txt->setTxt() << "\n";
						std::cout << txt->interact(*bg) << "\n";

					}
#pragma endregion User5

#pragma endregion Example5

			}
		}
	}
}