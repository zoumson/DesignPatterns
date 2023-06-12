#pragma once
#include "DPDecorator.h"

/*
* Structural PATTERN
* 4. Decorator
* Intent: Lets you attach new behaviors to objects by placing these objects
* inside special wrapper objects that contain the behaviors.
*/

namespace za
{
	namespace dp
	{
		namespace structural
		{
			namespace dco
			{
#pragma region Example1

				CoreD1::~CoreD1()
				{
					std::cout << "Core destructor called.\n";
				};
				void CoreD1::write(std::string& text)
				{
					
				};
				DecoratorD1::DecoratorD1(std::unique_ptr<InterfaceD1> c)
				{
					interface = std::move(c);
				};
				void DecoratorD1::write(std::string& text)
				{
					interface->write(text);
				};
			
				MessengerWithSalutationD1::MessengerWithSalutationD1(std::unique_ptr<InterfaceD1> c, const std::string& str)
				: DecoratorD1(std::move(c)), salutation(str) 
				{
				};						
				MessengerWithSalutationD1::~MessengerWithSalutationD1()
				{
					std::cout << "Messenger destructor called.\n";
				};
				void MessengerWithSalutationD1::write(std::string& text)
				{
					text = salutation + "\n\n" + text;
					DecoratorD1::write(text);
				};
						
				MessengerWithValedictionD1::MessengerWithValedictionD1(std::unique_ptr<InterfaceD1> c, const std::string& str)
				: DecoratorD1(std::move(c)), valediction(str)
				{
				};							
				MessengerWithValedictionD1::~MessengerWithValedictionD1()
				{
					std::cout << "MessengerWithValediction  destructor called.\n";
				};
				void MessengerWithValedictionD1::write(std::string& text)
				{
					DecoratorD1::write(text);
					text += "\n\n" + valediction;
				};
			
#pragma endregion Example1

#pragma region Example2

				std::string ConcreteComponentD2::Operation() const
				{
					return "ConcreteComponent";
				};

				DecoratorD2::DecoratorD2(ComponentD2* component) : component_(component)
				{

				};
				std::string DecoratorD2::Operation() const
				{
					return this->component_->Operation();
				};
				
				ConcreteDecoratorAD2::ConcreteDecoratorAD2(ComponentD2* component) : DecoratorD2(component)
				{
				};
				std::string ConcreteDecoratorAD2::Operation() const
				{
					return "ConcreteDecoratorA(" + DecoratorD2::Operation() + ")";
				};
								
				ConcreteDecoratorBD2::ConcreteDecoratorBD2(ComponentD2* component) : DecoratorD2(component)
				{
				};
				std::string ConcreteDecoratorBD2::Operation() const
				{
					return "ConcreteDecoratorB(" + DecoratorD2::Operation() + ")";
				};
				
				void ClientCodeD2(ComponentD2* component)
				{
					std::cout << "RESULT: " << component->Operation();
				}

#pragma endregion Example2

#pragma region Example3

				CarD3::CarD3()
				{
					_str = "Unknown Car";
				};
				std::string CarD3::getDescription()
				{
					return _str;
				}
				CarD3::~CarD3()
				{
					std::cout << "~Car()\n";
				};

				OptionsDecoratorD3::~OptionsDecoratorD3()
				{
					std::cout << "~OptionsDecorator()\n";
				};
				CarModel1D3::CarModel1D3()
				{
					_str = "CarModel1";
				};
				double CarModel1D3::getCost()
				{
					return 31000.23;
				};
				CarModel1D3::~CarModel1D3()
				{
					std::cout << "~CarModel1()\n";
				};
				
				NavigationD3::NavigationD3(CarD3* b)
				{
					_b = b;
				};			
				std::string NavigationD3::getDescription()
				{
					return _b->getDescription() + ", Navigation";
				};
				double NavigationD3::getCost()
				{
					return 300.56 + _b->getCost();
				};
				NavigationD3::~NavigationD3()
				{
					std::cout << "~Navigation()\n";
					delete _b;
				};
				
				PremiumSoundSystemD3::PremiumSoundSystemD3(CarD3* b)
				{
					_b = b;
				}
				std::string PremiumSoundSystemD3::getDescription()
				{
					return _b->getDescription() + ", PremiumSoundSystem";
				};
				double PremiumSoundSystemD3::getCost()
				{
					return 0.30 + _b->getCost();
				};
				PremiumSoundSystemD3::~PremiumSoundSystemD3()
				{
					std::cout << "~PremiumSoundSystem()\n";
					delete _b;
				};		

				ManualTransmissionD3::ManualTransmissionD3(CarD3* b)
				{
					_b = b;
				}
				std::string ManualTransmissionD3::getDescription()
				{
					return _b->getDescription() + ", ManualTransmission";
				};
				double ManualTransmissionD3::getCost()
				{
					return 0.30 + _b->getCost();
				};
				ManualTransmissionD3::~ManualTransmissionD3()
				{
					std::cout << "~ManualTransmission()\n";
					delete _b;
				};
				
#pragma endregion Example3

#pragma region Example4

				std::string ConcreteComponentD4::Operation() const
				{
					return "ConcreteComponent";
				};

				DecoratorD4::DecoratorD4(ComponentD4* component) : component_(component)
				{

				};
				std::string DecoratorD4::Operation() const
				{
					return this->component_->Operation();
				};

				ConcreteDecoratorAD4::ConcreteDecoratorAD4(ComponentD4* component) : DecoratorD4(component)
				{

				};
				std::string ConcreteDecoratorAD4::Operation() const
				{
					return "ConcreteDecoratorA(" + DecoratorD4::Operation() + ")";
				};

				ConcreteDecoratorBD4::ConcreteDecoratorBD4(ComponentD4* component) : DecoratorD4(component)
				{

				};
				std::string ConcreteDecoratorBD4::Operation() const
				{
					return "ConcreteDecoratorB(" + DecoratorD4::Operation() + ")";
				};

				void ClientCodeD4(ComponentD4* component)
				{
					std::cout << "RESULT: " << component->Operation();
				};

#pragma endregion Example4
			}
		}
	}
}