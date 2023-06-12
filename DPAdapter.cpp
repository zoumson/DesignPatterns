#pragma once
#include "DPAdapter.h"

/*
* Structural PATTERN
1. Adapter


*/

namespace za
{
	namespace dp
	{
		namespace structural
		{
			namespace adp
			{

#pragma region Example1
				void DogFemaleS1::performsConversion() const
				{
					std::cout << "Dog female performs conversion." << std::endl;
				}

				void CatFemaleA1::performsConversion() const
				{
					std::cout << "Cat female performs conversion." << std::endl;
				}

				void DogNatureA1::carryOutNature(DogA1* dog)
				{
					std::cout << "On with the Dog nature!" << std::endl;
					dog->performsConversion();
				}

				ConversionAdapterA1::ConversionAdapterA1(CatA1* c) : cat(c) {};

				void ConversionAdapterA1::performsConversion() const
				{
					cat->performsConversion();
				}


#pragma endregion Example1

#pragma region Example2

				std::string TargetA2::Request() const 
				{
					return "Target: The default target's behavior.";
				}

				std::string AdapteeA2::SpecificRequest() const
				{
					return ".eetpadA eht fo roivaheb laicepS";
				}
				
				std::string AdapterA2::Request() const 
				{
					std::string to_reverse = SpecificRequest();
					std::reverse(to_reverse.begin(), to_reverse.end());
					return "Adapter: (TRANSLATED) " + to_reverse;
				}

				void ClientCodeA2(const TargetA2* target)
				{
					std::cout << target->Request();
				}

#pragma endregion Example2

#pragma region Example3

				LegacyRectangleA3::LegacyRectangleA3(int x1, int y1, int x2, int y2)
				{

				};

				void LegacyRectangleA3::oldDraw()
				{
				};

				RectangleAdapterA3::RectangleAdapterA3(int x, int y, int w, int h) : LegacyRectangleA3(x, y, x + w, y + h)
				{
					std::cout << "RectangleAdapter(x,y,x+w,x+h)" << std::endl;
				};

				void RectangleAdapterA3::draw()
				{
					std::cout << "RectangleAdapter: draw()." << std::endl;
					oldDraw();
				}

#pragma endregion Example3

#pragma region Example4
				std::string TargetA3::Request() const
				{
					return "Target: The default target's behavior.";
				}
				
				std::string AdapteeA3::SpecificRequest() const
				{
					return ".eetpadA eht fo roivaheb laicepS";
				}
	
				AdapterA3::AdapterA3(AdapteeA3* adaptee) : adaptee_(adaptee) {}

				std::string AdapterA3::Request() const 
				{
					std::string to_reverse = this->adaptee_->SpecificRequest();
					std::reverse(to_reverse.begin(), to_reverse.end());
					return "Adapter: (TRANSLATED) " + to_reverse;
				}
		
				void ClientCodeA3(const TargetA3* target)
				{
					std::cout << target->Request();
				}

#pragma endregion Example4

#pragma region Example5

				PrintA5::~PrintA5()
				{
				}

				MessageDisplayA5::MessageDisplayA5(const std::string& _message)
					: message(_message)
				{
				};

				MessageDisplayA5::~MessageDisplayA5()
				{
				}

				void MessageDisplayA5::displayWithHyphens() const
				{
					std::cout << "-- " << message << " --" << std::endl;
				}

				void MessageDisplayA5::displayWithBrackets() const
				{
					std::cout << "[[ " << message << " ]]" << std::endl;
				}

				PrintMessageDisplayA5::PrintMessageDisplayA5(const std::string& _message)
					: MessageDisplayA5(_message)
				{
				}

				PrintMessageDisplayA5::~PrintMessageDisplayA5()
				{
				}

				void PrintMessageDisplayA5::printWeak() const
				{
					displayWithHyphens();
				}

				void PrintMessageDisplayA5::printStrong() const
				{
					displayWithBrackets();
				}

#pragma endregion Example5

#pragma region Example6

				void OldClassA6::foo(int data)
				{
					std::cout << "current number: " << data << std::endl;
				}
				int OldClassA6::bar()
				{
					srand(time(0));
					int lb = 20, ub = 100;
					int num = (rand() % (ub - lb + 1)) + lb;
					return num;
				}
		
				AdapterA6::AdapterA6(IAdapteeA6* pAdaptee)
				{
					this->pAdaptee = pAdaptee;
				}
				void AdapterA6::process()
				{
					int data = pAdaptee->bar();
					pAdaptee->foo(data);

				};
				
#pragma endregion Example6
			}
		}
	}
}