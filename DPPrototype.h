#pragma once
#include "DPUtilities.h"

/*
* Creational Pattern
4. Prototype


*/

namespace za
{
	namespace dp
	{
		namespace creational
		{
			namespace pro
			{
#pragma region Example1

				// Abstract Animal class
				class Animal
				{
				protected:
					char _hairColor[10];
					int _hairLength, _tail, _weight, _height, _age;
					int _intelligence, _stubbornness, _agressiveness;

				public:
					virtual Animal* clone() = 0;

					void setHairLength(int length);

					void setHairColor(const char* color);

					void setTail(int length);

					void setWeight(int kg);

					void setHeight(int m);
					void setAge(int age);

				};

				// Derived Sheep class
				class Sheep : public Animal
				{
				public:
					Sheep();
					Sheep* clone();
					void shearing();
				};

				// Derived Cow class
				class Cow : public Animal
				{
				public:
					Cow();
					Cow* clone();
				};
#pragma endregion Example1

#pragma region Example2

#pragma region Interface2

				/** Record is the base Prototype */
				class Record
				{
				public:
					virtual ~Record() {}
					virtual void print() = 0;
					virtual std::unique_ptr<Record> clone() = 0;
				};
#pragma endregion Interface2

#pragma region Product2
				/** CarRecord is a Concrete Prototype */
				class CarRecord : public Record
				{
				private:
					std::string _carName;
					int _ID;

				public:
					CarRecord(std::string carName, int ID);

					void print() override;

					std::unique_ptr<Record> clone() override;
				};

				/** BikeRecord is the Concrete Prototype */
				class BikeRecord : public Record
				{
				private:
					std::string _bikeName;
					int _ID;

				public:
					BikeRecord(std::string bikeName, int ID);

					void print() override;

					std::unique_ptr<Record> clone() override;
				};

				/** PersonRecord is the Concrete Prototype */
				class PersonRecord : public Record
				{
				private:
					std::string _personName;
					int _age;

				public:
					PersonRecord(std::string personName, int age);

					void print() override;

					std::unique_ptr<Record> clone() override;
				};
#pragma endregion Product2

#pragma region Factory2

				/** RecordFactory is the client */
				class RecordFactory
				{


				public:
					/** Opaque record type, avoids exposing concrete implementations */
					enum RECORD_TYPES
					{
						CAR,
						BIKE,
						PERSON
					};

					RecordFactory();

					std::unique_ptr<Record> create(RECORD_TYPES recordType);
				private:
					std::unordered_map<RECORD_TYPES, std::unique_ptr<Record>, std::hash<int> > _records;

				};
#pragma endregion Factory2

#pragma endregion Example2

#pragma region Example3

#pragma region Interface3
				/* Prototype base class. */
				class Prototype3
				{
				protected:
					std::string type;
					int value;

				public:
					virtual Prototype3* clone() = 0;

					std::string getType();
					int getValue();
				};
#pragma endregion Interface3

#pragma region Product3

				class ConcretePrototype31 : public Prototype3
				{
				public:
					ConcretePrototype31(int number);

					Prototype3* clone();
				};
				class ConcretePrototype32 : public Prototype3
				{
				public:
					ConcretePrototype32(int number);

					Prototype3* clone();
				};

#pragma endregion Product3

#pragma region Factory3
				/* Factory that manages prorotype instances and produces their clones. */
				class ObjectFactory3
				{
					static Prototype3* type1value1;
					static Prototype3* type1value2;
					static Prototype3* type2value1;
					static Prototype3* type2value2;

				public:
					static void  initialize();

					static Prototype3* getType1Value1();

					static Prototype3* getType1Value2();

					static Prototype3* getType2Value1();

					static Prototype3* getType2Value2();
				};


#pragma endregion Factory3

#pragma endregion Example3

#pragma region Example4

#pragma region Material4
				struct Office 
				{				
					std::string _street;					
					std::string _city;					
					int32_t _cubical;
					
				};
#pragma endregion Material4

#pragma region Product4
				class Employee
				{

					std::string _name;
					Office* _office;

					// Private constructor, so direct instance can not be created except for `class EmployeeFactory`
					Employee(std::string n, Office* o);
					friend class EmployeeFactory;

				public:
					Employee(const Employee& rhs);
					Employee& operator=(const Employee& rhs);
					friend std::ostream& operator<<(std::ostream& os, const Employee& o);
				};
#pragma endregion Product4

#pragma region Factory4
				class EmployeeFactory 
				{
				
				static Employee	main;				
				static Employee	aux;
				
				static std::unique_ptr<Employee> NewEmployee(std::string n, int32_t c, Employee& proto);

				public:
					static std::unique_ptr<Employee> NewMainOfficeEmployee(std::string name, int32_t cubical);
					static std::unique_ptr<Employee> NewAuxOfficeEmployee(std::string name, int32_t cubical);

				};
#pragma endregion Factory4

#pragma endregion Example4

#pragma region Example5

#pragma region Interface5

				// Prototype Design Pattern
				//
				// Intent: Lets you copy existing objects without making your code dependent on
				// their classes.

				enum Type 
				{
					PROTOTYPE_1 = 0,
					PROTOTYPE_2
				};

				/**
				 * The example class that has cloning ability. We'll see how the values of field
				 * with different types will be cloned.
				 */

				class Prototype5 
				{
				protected:
					std::string prototype_name_;
					float prototype_field_;

				public:
					Prototype5() {}
					Prototype5(std::string prototype_name);
					virtual ~Prototype5() {};
					virtual Prototype5* clone() const = 0;
					virtual void method(float prototype_field);
				};
#pragma endregion Interface5

#pragma region Product5
				/**
				 * ConcretePrototype1 is a Sub-Class of Prototype and implement the Clone Method
				 * In this example all data members of Prototype Class are in the Stack. If you
				 * have pointers in your properties for ex: String* name_ ,you will need to
				 * implement the Copy-Constructor to make sure you have a deep copy from the
				 * clone method
				 */

				class ConcretePrototype51 : public Prototype5 
				{
				private:
					float concrete_prototype_field1_;

				public:
					ConcretePrototype51(std::string prototype_name, float concrete_prototype_field);
					/**
					 * Notice that Clone method return a Pointer to a new ConcretePrototype1
					 * replica. so, the client (who call the clone method) has the responsability
					 * to free that memory. I you have smart pointer knowledge you may prefer to
					 * use unique_pointer here.
					 */
					Prototype5* clone() const override;
				};

				class ConcretePrototype52 : public Prototype5 
				{
				private:
					float concrete_prototype_field2_;

				public:
					ConcretePrototype52(std::string prototype_name, float concrete_prototype_field);
					Prototype5* clone() const override;
				};
#pragma endregion Product5

#pragma region Factory5
				/**
				 * In PrototypeFactory you have two concrete prototypes, one for each concrete
				 * prototype class, so each time you want to create a bullet , you can use the
				 * existing ones and clone those.
				 */

				class PrototypeFactory5 
				{
				private:
					std::unordered_map<Type, Prototype5*, std::hash<int>> prototypes_;

				public:
					PrototypeFactory5();
					/**
					 * Be carefull of free all memory allocated. Again, if you have smart pointers
					 * knowelege will be better to use it here.
					 */

					~PrototypeFactory5();
					/**
					 * Notice here that you just need to specify the type of the prototype you
					 * want and the method will create from the object with this type.
					 */
					Prototype5* create(Type type);
				};

#pragma endregion Factory5

#pragma region User5

				void user5(PrototypeFactory5& prototype_factory);
#pragma endregion User5

#pragma endregion Example5
			}
		}
	}
}