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


					Engine::Engine()
					{
						strcpy_s(_sound, "");
					};

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

					Door* GasCarFactory::BuildDoor()
					{
						return new GasCarDoor();
					};
					Engine* GasCarFactory::BuildEngine()
					{
						return new GasEngine();
					};

					Door* ElectricCarFactory::BuildDoor()
					{
						return new ElectricCarDoor();
					};
					Engine* ElectricCarFactory::BuildEngine()
					{
						return new ElectricEngine();
					};


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

					std::unique_ptr<APhoneFactory> APhoneFactory::CreateFactory(APhoneFactory::PHONE_FACTORIES factory)
					{
						if (factory == PHONE_FACTORIES::SAMSUNG)
						{
							return std::make_unique<SamsungFactory>();
						}
						else if (factory == PHONE_FACTORIES::HTC)
						{
							return std::make_unique<HTCFactory>();
						}
						else if (factory == PHONE_FACTORIES::NOKIA)
						{
							return std::make_unique<NokiaFactory>();
						}

						return nullptr;
					}
	
					std::unique_ptr<ISmart> SamsungFactory::GetSmart()
					{
						return std::make_unique<GalaxyS2>();
					}
					
					std::unique_ptr<IDumb> SamsungFactory::GetDumb()
					{
						return std::make_unique<Primo>();

					}	

					std::unique_ptr<ISmart> HTCFactory::GetSmart()
					{
						return std::make_unique<Titan>();
					}
					
					std::unique_ptr<IDumb> HTCFactory::GetDumb()
					{
						return std::make_unique<Genie>();

					}

					std::unique_ptr<ISmart> NokiaFactory::GetSmart()
					{
						return std::make_unique<Lumia>();
					}
					
					std::unique_ptr<IDumb> NokiaFactory::GetDumb()
					{
						return std::make_unique<Asha>();

					}

#pragma endregion Factory3

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
					void buildInterface(GUIFactory4& factory) 
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
					void client5(ThemeFactory5& factory)
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