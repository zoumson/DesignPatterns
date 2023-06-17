#pragma once
#include "DPBridge.h"

/*
* Structural PATTERN
2. Bridge


*/

namespace za
{
	namespace dp
	{
		namespace structural
		{
			namespace bd
			{

#pragma region Example1

				std::string ConcreteImplementationAB1::OperationImplementation() const
				{
					return "ConcreteImplementationA: Here's the result on the platform A.\n";
				}
				
				std::string ConcreteImplementationBB1::OperationImplementation() const
				{
					return "ConcreteImplementationB: Here's the result on the platform B.\n";
				}


				AbstractionB1::AbstractionB1(ImplementationB1* implementation) : implementation_(implementation)
				{
				};
				std::string AbstractionB1::Operation() const
				{
					return "Abstraction: Base operation with:\n" +
						this->implementation_->OperationImplementation();
				}

				ExtendedAbstractionB1::ExtendedAbstractionB1(ImplementationB1* implementation) : AbstractionB1(implementation)
				{
				};
				std::string ExtendedAbstractionB1::Operation() const 
				{
					return "ExtendedAbstraction: Extended operation with:\n" +
						this->implementation_->OperationImplementation();
				}
				
				void ClientCodeB1(const AbstractionB1& abstraction)
				{
					std::cout << abstraction.Operation();
				}
#pragma endregion Example1

#pragma region Example2
				DisplayImplB2::~DisplayImplB2()
				{

				}

				TextDisplayImplB2::TextDisplayImplB2(const std::string& text)
					: text(text)
					, width(static_cast<int>(text.size()))
				{
				}
				TextDisplayImplB2::~TextDisplayImplB2()
				{
				}
				void TextDisplayImplB2::implOpen() const
				{
					printLine();
				}
				void TextDisplayImplB2::implWrite() const
				{	
					std::cout << ":" << text << ":" << std::endl;		// Enclose a text with ":" and display it.
				}
				void TextDisplayImplB2::implClose() const
				{
					printLine();
				}
				void TextDisplayImplB2::printLine() const
				{
					std::cout << "*";							
					// Display "*" mark at the beginning of a frame.
					for (int i = 0; i < width; ++i) 
					{		
						// Display "." for the number of "width".
						std::cout << ".";
					}
					std::cout << "*" << std::endl;					
					// Display "*" mark at the end of a frame.
				}
				
				DisplayB2::DisplayB2(const DisplayImplB2* impl)
					: impl(impl)

				{

				}
				DisplayB2::~DisplayB2()
				{	
				}
				void DisplayB2::output() const
				{
					open();
					write();
					close();
				}
				void DisplayB2::open() const
				{
					impl->implOpen();
				}
				void DisplayB2::write() const
				{
					impl->implWrite();
				}
				void DisplayB2::close() const
				{
					impl->implClose();
				}

				MultiLineDisplayB2::MultiLineDisplayB2(DisplayImplB2* impl)
					: DisplayB2(impl)
				{
				}
				MultiLineDisplayB2::~MultiLineDisplayB2()
				{
				}
				void MultiLineDisplayB2::outputMultiple(const int times) const
				{
					open();
					for (int i = 0; i < times; ++i) 
					{
						write();
					}
					close();
				}
				
#pragma endregion Example2

#pragma region Example3

				void DrawingAPI1B3::drawCircle(double x, double y, double radius)
				{
					std::cout << "API1.circle at " << x << ':' << y << ' ' << radius << std::endl;
				}

				void DrawingAPI2B3::drawCircle(double x, double y, double radius)
				{
					std::cout << "API2.circle at " << x << ':' << y << ' ' << radius << std::endl;
				}

				CircleShapeB3::CircleShapeB3(double x, double y, double radius, DrawingAPIB3* drawingAPI) :
					m_x(x), m_y(y), m_radius(radius), m_drawingAPI(drawingAPI)
				{}
				void CircleShapeB3::draw() 
				{
					m_drawingAPI->drawCircle(m_x, m_y, m_radius);
				}
				void CircleShapeB3::resizeByPercentage(double pct) 
				{
					m_radius *= pct;
				}
			
	
#pragma endregion Example3

#pragma region Example4

				CarB4::CarB4(std::unique_ptr<EngineB4> engine)
					: pimpl_{ std::move(engine) }
				{};
				EngineB4* CarB4::getEngine() 
				{ 
					return pimpl_.get(); 
				}
				EngineB4 const* CarB4::getEngine() const 
				{ 
					return pimpl_.get(); 
				}
	

				void ElectricEngineB4::start()
				{
					std::cout << "Starting the 'ElectricEngine'...\n";
				}
				void ElectricEngineB4::stop()
				{
					std::cout << "Stopping the 'ElectricEngine'...\n";
				}

				ElectricCarB4::ElectricCarB4()
					: CarB4{ std::make_unique<ElectricEngineB4>( /*engine arguments*/) }
					// ... Initialization of the other data members
				{};
				void ElectricCarB4::drive()
				{
					getEngine()->start();
					std::cout << "Driving the 'ElectricCar'...\n";
					getEngine()->stop();
				}
#pragma endregion Example4

#pragma region Example5


#pragma endregion Example5

#pragma region Example6
#pragma endregion Example6
			}
		}
	}
}