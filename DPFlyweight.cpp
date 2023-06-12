#pragma once
#include "DPFlyweight.h"

/*
* Structural PATTERN
* FlyWeight
*/

namespace za
{
    namespace dp
    {
        namespace structural
        {
            namespace fly
            {

#pragma region Example1

				std::vector<float> FlyweightCharacterAbstractBuilderF1::fontSizes(3);
				std::vector<std::string> FlyweightCharacterAbstractBuilderF1::fontNames(3);
				void FlyweightCharacterAbstractBuilderF1::setFontsAndNames() 
				{
					fontSizes[0] = 1.0;
					fontSizes[1] = 1.5;
					fontSizes[2] = 2.0;

					fontNames[0] = "first_font";
					fontNames[1] = "second_font";
					fontNames[2] = "third_font";
				}
				FlyweightCharacterF1::FlyweightCharacterF1(unsigned short fontSizeIndex, unsigned short fontNameIndex, unsigned short positionInStream) :
					fontSizeIndex(fontSizeIndex), fontNameIndex(fontNameIndex), positionInStream(positionInStream) {};

				void FlyweightCharacterF1::print() 
				{
					std::cout << "Font Size: " << FlyweightCharacterAbstractBuilderF1::fontSizes[fontSizeIndex]
						<< ", font Name: " << FlyweightCharacterAbstractBuilderF1::fontNames[fontNameIndex]
						<< ", character stream position: " << positionInStream << std::endl;
				}

				FlyweightCharacterF1 FlyweightCharacterAbstractBuilderF1::createFlyweightCharacter(unsigned short fontSizeIndex, unsigned short fontNameIndex, unsigned short positionInStream) 
				{
					FlyweightCharacterF1 fc(fontSizeIndex, fontNameIndex, positionInStream);

					return fc;
				}
				
#pragma endregion Example1

#pragma region Example2     

				SharedStateF2::SharedStateF2(const std::string& brand, const std::string& model, const std::string& color)
					: brand_(brand), model_(model), color_(color)
				{
				};
				
				UniqueStateF2::UniqueStateF2(const std::string& owner, const std::string& plates)
					: owner_(owner), plates_(plates)
				{
				};
				
				FlyweightF2::FlyweightF2(const SharedStateF2* shared_state) : shared_state_(new SharedStateF2(*shared_state))
				{
				};
				FlyweightF2::FlyweightF2(const FlyweightF2& other) : shared_state_(new SharedStateF2(*other.shared_state_))
				{
				};
				
				FlyweightF2::~FlyweightF2()
				{
					delete shared_state_;
				};
				SharedStateF2* FlyweightF2::shared_state() const
				{
					return shared_state_;
				};
				
				void FlyweightF2::Operation(const UniqueStateF2& unique_state) const
				{
					std::cout << "Flyweight: Displaying shared (" << *shared_state_ << ") and unique (" << unique_state << ") state.\n";
				};
				
				std::string FlyweightFactoryF2::GetKey(const SharedStateF2& ss) const
				{
					return ss.brand_ + "_" + ss.model_ + "_" + ss.color_;
				};
				FlyweightFactoryF2::FlyweightFactoryF2(std::initializer_list<SharedStateF2> share_states)
				{
					for (const SharedStateF2& ss : share_states)
					{
						this->flyweights_.insert(std::make_pair<std::string, FlyweightF2>(this->GetKey(ss), FlyweightF2(&ss)));
					}
				};

				FlyweightF2 FlyweightFactoryF2::GetFlyweight(const SharedStateF2& shared_state)
				{
					std::string key = this->GetKey(shared_state);
					if (this->flyweights_.find(key) == this->flyweights_.end())
					{
						std::cout << "FlyweightFactory: Can't find a flyweight, creating new one.\n";
						this->flyweights_.insert(std::make_pair(key, FlyweightF2(&shared_state)));
					}
					else
					{
						std::cout << "FlyweightFactory: Reusing existing flyweight.\n";
					}
					return this->flyweights_.at(key);
				};
				void FlyweightFactoryF2::ListFlyweights() const
				{
					size_t count = this->flyweights_.size();
					std::cout << "\nFlyweightFactory: I have " << count << " flyweights:\n";
					for (std::pair<std::string, FlyweightF2> pair : this->flyweights_)
					{
						std::cout << pair.first << "\n";
					}
				};
				
				void AddCarToPoliceDatabaseF2(
					FlyweightFactoryF2& ff, const std::string& plates, const std::string& owner,
					const std::string& brand, const std::string& model, const std::string& color)
				{
					std::cout << "\nClient: Adding a car to database.\n";
					const FlyweightF2& flyweight = ff.GetFlyweight({ brand, model, color });
					// The client code either stores or calculates extrinsic state and
					// passes it to the flyweight's methods.

					flyweight.Operation({ owner, plates });
				}
#pragma endregion Example2

#pragma region Example3 

				//class ObjectF3
				//{
				//public:
				//	ObjectF3(int valueOne);
				//	~ObjectF3();
				//	void report(int valueTwo);
				//private:
				//	int mValueOne;
				//};

				//class FlyWeightF3
				//{
				//public:
				//	static int X, Y;
				//	static ObjectF3* getRecord(int in);
				//	static void cleanUp();
				//private:
				//	static ObjectF3* myArray[];
				//};
#pragma endregion Example3

#pragma region Example4
#pragma endregion Example4

#pragma region Example5
#pragma endregion Example5

#pragma region Example6
#pragma endregion Example6
            }
        }
    }
}