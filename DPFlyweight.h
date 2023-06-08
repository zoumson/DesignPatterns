#pragma once
#pragma once
#include "DPUtilities.h"

/*
 * Flyweight Design Pattern
 *
 * Intent: Lets you fit more objects into the available amount of RAM by sharing
 * common parts of state between multiple objects, instead of keeping all of the
 * data in each object.
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
#define NUMBER_OF_SAME_TYPE_CHARS 3;

				/* Actual flyweight objects class (declaration) */
				class FlyweightCharacterF1;

				/*
					FlyweightCharacterAbstractBuilder is a class holding the properties which are shared by
					many objects. So instead of keeping these properties in those objects we keep them externally, making
					objects flyweight. See more details in the comments of main function.
				*/
				class FlyweightCharacterAbstractBuilderF1 
				{
					FlyweightCharacterAbstractBuilderF1() {}
					~FlyweightCharacterAbstractBuilderF1() {}
				public:
					static std::vector<float> fontSizes; // lets imagine that sizes may be of floating point type
					static std::vector<std::string> fontNames; // font name may be of variable length (lets take 6 bytes is average)

					static void setFontsAndNames();
					static FlyweightCharacterF1 createFlyweightCharacter(unsigned short fontSizeIndex,
						unsigned short fontNameIndex,
						unsigned short positionInStream);
				};

				class FlyweightCharacterF1 
				{
					unsigned short fontSizeIndex; // index instead of actual font size
					unsigned short fontNameIndex; // index instead of font name
					unsigned positionInStream;

				public:

					FlyweightCharacterF1(unsigned short fontSizeIndex, unsigned short fontNameIndex, unsigned short positionInStream);
					void print();
					~FlyweightCharacterF1() {}
				};


#pragma endregion Example1

#pragma region Example2  


				struct SharedStateF2
				{
					std::string brand_;
					std::string model_;
					std::string color_;

					SharedStateF2(const std::string& brand, const std::string& model, const std::string& color);

					friend std::ostream& operator<<(std::ostream& os, const SharedStateF2& ss)
					{
						return os << "[ " << ss.brand_ << " , " << ss.model_ << " , " << ss.color_ << " ]";
					}
				};

				struct UniqueStateF2
				{
					std::string owner_;
					std::string plates_;

					UniqueStateF2(const std::string& owner, const std::string& plates);

					friend std::ostream& operator<<(std::ostream& os, const UniqueStateF2& us)
					{
						return os << "[ " << us.owner_ << " , " << us.plates_ << " ]";
					}
				};

				/**
				* The Flyweight stores a common portion of the state (also called intrinsic
				* state) that belongs to multiple real business entities. The Flyweight accepts
				* the rest of the state (extrinsic state, unique for each entity) via its
				* method parameters.
				*/
				class FlyweightF2
				{
				private:
					SharedStateF2* shared_state_;

				public:
					FlyweightF2(const SharedStateF2* shared_state);
					FlyweightF2(const FlyweightF2& other);
					~FlyweightF2();
					SharedStateF2* shared_state() const;
					void Operation(const UniqueStateF2& unique_state) const;
				};

				/**
				* The Flyweight Factory creates and manages the Flyweight objects. It
				* ensures that flyweights are shared correctly. When the client requests a
				* flyweight, the factory either returns an existing instance or creates a new
				* one, if it doesn't exist yet.
				*/
				class FlyweightFactoryF2
				{
					/**
					 * @var Flyweight[]
					 */
				private:
					std::unordered_map<std::string, FlyweightF2> flyweights_;
					/**
					 * Returns a Flyweight's string hash for a given state.
					 */
					std::string GetKey(const SharedStateF2& ss) const;

				public:
					FlyweightFactoryF2(std::initializer_list<SharedStateF2> share_states);

					/**
					 * Returns an existing Flyweight with a given state or creates a new
					 * one.
					 */
					FlyweightF2 GetFlyweight(const SharedStateF2& shared_state);
					void ListFlyweights() const;
				};

				// ...
				void AddCarToPoliceDatabaseF2(
					FlyweightFactoryF2& ff, const std::string& plates, const std::string& owner,
					const std::string& brand, const std::string& model, const std::string& color)
					;


#pragma endregion Example2

#pragma region Example3  

				//class ObjectF3 
				//{
				//public:
				//	ObjectF3(int valueOne);
				//	~ObjectF3();
				//	void report(int valueTwo);
				//private:
				//	int m_value_one;
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
