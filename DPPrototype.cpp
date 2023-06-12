#pragma once
#include "DPPrototype.h"

/*
* Creational PATTERN
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
					void Animal::setHairLength(int length)
					{
						_hairLength = length;
					};

					void Animal::setHairColor(const char* color)
					{
						strcpy_s(_hairColor, color);
					};

					void Animal::setTail(int length)
					{
						_tail = length;
					};

					void Animal::setWeight(int kg)
					{
						_weight = kg;
					};

					void Animal::setHeight(int m)
					{
						_height = m;
					};

					void Animal::setAge(int age)
					{
						_age = age;
					};

					Sheep::Sheep()
					{
						_hairLength = 5;
						_stubbornness = 3;
						_agressiveness = 2;
						_intelligence = 7;
					};
					Sheep* Sheep::clone()
					{
						return new Sheep(*this);
					}
					void Sheep::shearing()
					{
						_hairLength -= 2;
					}


					Cow::Cow()
					{
						_stubbornness = 6;
						_agressiveness = 5;
						_intelligence = 8;
					};
					Cow* Cow::clone()
					{
						return new Cow(*this);
					};

#pragma endregion Example1

#pragma region Example2

#pragma region Interface2


#pragma endregion Interface2

#pragma region Product2

					CarRecord::CarRecord(std::string carName, int ID) : _carName(carName), _ID(ID) {}					
					void CarRecord::print()
					{
						std::cout << "Car Record" << std::endl
							<< "Name  : " << _carName << std::endl
							<< "Number: " << _ID << std::endl << std::endl;
					}									
					std::unique_ptr<Record> CarRecord::clone()
					{
						return std::make_unique<CarRecord>(*this);
					}

					BikeRecord::BikeRecord(std::string bikeName, int ID) : _bikeName(bikeName), _ID(ID) {}
					void BikeRecord::print()
					{
						std::cout << "Bike Record" << std::endl
							<< "Name  : " << _bikeName << std::endl
							<< "Number: " << _ID << std::endl << std::endl;
					}
					std::unique_ptr<Record> BikeRecord::clone()
					{
						return std::make_unique<BikeRecord>(*this);
					}
					
					PersonRecord::PersonRecord(std::string personName, int age) : _personName(personName), _age(age) {}
					void PersonRecord::print()
					{
						std::cout << "Person Record" << std::endl
							<< "Name : " << _personName << std::endl
							<< "Age  : " << _age << std::endl << std::endl;
					}
					std::unique_ptr<Record> PersonRecord::clone()
					{
						return std::make_unique<PersonRecord>(*this);
					}



#pragma endregion Product2

#pragma region Factory2

					RecordFactory::RecordFactory()
					{
						_records[RECORD_TYPES::CAR] = std::make_unique<CarRecord>("Ferrari", 5050);
						_records[RECORD_TYPES::BIKE] = std::make_unique<BikeRecord>("Yamaha", 2525);
						_records[RECORD_TYPES::PERSON] = std::make_unique<PersonRecord>("Tom", 25);
					}

					std::unique_ptr<Record> RecordFactory::create(RecordFactory::RECORD_TYPES  type)
					{
						return _records[type]->clone();
					}


#pragma endregion Factory2

#pragma endregion Example2

#pragma region Example3

#pragma region Interface3
					std::string Prototype3::getType()
					{
						return type;
					}

					int Prototype3::getValue()
					{
						return value;
					}

#pragma endregion Interface3

#pragma region Product3

					ConcretePrototype31::ConcretePrototype31(int number)
					{
						type = "Type1";
						value = number;
					}
					Prototype3* ConcretePrototype31::clone()
					{
						return new ConcretePrototype31(*this);
					}
					
					ConcretePrototype32::ConcretePrototype32(int number)
					{
						type = "Type2";
						value = number;
					}
					Prototype3* ConcretePrototype32::clone()
					{
						return new ConcretePrototype32(*this);
					}
#pragma endregion Product3

#pragma region Factory3
					

					void ObjectFactory3::initialize()
					{
						type1value1 = new ConcretePrototype31(1);
						type1value2 = new ConcretePrototype31(2);
						type2value1 = new ConcretePrototype32(1);
						type2value2 = new ConcretePrototype32(2);
					}

					Prototype3* ObjectFactory3::getType1Value1()
					{
						return type1value1->clone();
					}

					Prototype3* ObjectFactory3::getType1Value2()
					{
						return type1value2->clone();
					}

					Prototype3* ObjectFactory3::getType2Value1()
					{
						return type2value1->clone();
					}

					Prototype3* ObjectFactory3::getType2Value2()
					{
						return type2value2->clone();
					}

					//static values need to be initialize in cpp 
					Prototype3* ObjectFactory3::type1value1 = 0;
					Prototype3* ObjectFactory3::type1value2 = 0;
					Prototype3* ObjectFactory3::type2value1 = 0;
					Prototype3* ObjectFactory3::type2value2 = 0;

#pragma endregion Factory3

#pragma endregion Example3

#pragma region Example4

#pragma region Material4

#pragma endregion Material4

#pragma region Product4

					Employee::Employee(std::string n, Office* o) : _name(n), _office(o) {}
					Employee::Employee(const Employee& rhs) : _name{ rhs._name }, _office{ new Office{*rhs._office} }{}
					Employee& Employee::operator=(const Employee& rhs)
					{
						if (this == &rhs) 
						{
							return *this;
						}


							_name = rhs._name;
							_office = new Office{ *rhs._office };
							return *this;
					}
					std::ostream& operator<<(std::ostream& os, const Employee& o) 
					{
							return (os << o._name << " works at "
							<< o._office->_street << " " << o._office->_city << " seats @" << o._office->_cubical);

					}

#pragma endregion Product4

#pragma region Factory4

					std::unique_ptr<Employee> EmployeeFactory::NewEmployee(std::string n, int32_t c, Employee& proto)
					{
						
						auto e = std::make_unique<Employee>(proto);
						
						e->_name = n;
						
						e->_office->_cubical = c;
						
						return e;
						
					}

					std::unique_ptr<Employee> EmployeeFactory::NewMainOfficeEmployee(std::string name, int32_t cubical) 
					{
							return NewEmployee(name, cubical, main);
					}

					std::unique_ptr<Employee> EmployeeFactory::NewAuxOfficeEmployee(std::string name, int32_t cubical)
					{
						return NewEmployee(name, cubical, aux);
					}
					// Static Member Initialization 
					Employee EmployeeFactory::main{ "", new Office{"123 East Dr", "London", 123} };
					Employee EmployeeFactory::aux{ "", new Office{"RMZ Ecoworld ORR", "London", 123} };
#pragma endregion Factory4

#pragma endregion Example4
//
//#pragma region Example5
//
//#pragma region Interface5
//
//
//					/**
//					 * The example class that has cloning ability. We'll see how the values of field
//					 * with different types will be cloned.
//					 */
//
//					class Prototype5
//					{
//					protected:
//						std::string prototype_name_;
//						float prototype_field_;
//
//					public:
//						Prototype5() {}
//						Prototype5(std::string prototype_name);
//						virtual ~Prototype5() {};
//						virtual Prototype5* clone() const = 0;
//						virtual void method(float prototype_field);
//					};
//#pragma endregion Interface5
//
//#pragma region Product5
//					/**
//					 * ConcretePrototype1 is a Sub-Class of Prototype and implement the Clone Method
//					 * In this example all data members of Prototype Class are in the Stack. If you
//					 * have pointers in your properties for ex: String* name_ ,you will need to
//					 * implement the Copy-Constructor to make sure you have a deep copy from the
//					 * clone method
//					 */
//
//					class ConcretePrototype51 : public Prototype5
//					{
//					private:
//						float concrete_prototype_field1_;
//
//					public:
//						ConcretePrototype51(std::string prototype_name, float concrete_prototype_field);
//						/**
//						 * Notice that Clone method return a Pointer to a new ConcretePrototype1
//						 * replica. so, the client (who call the clone method) has the responsability
//						 * to free that memory. I you have smart pointer knowledge you may prefer to
//						 * use unique_pointer here.
//						 */
//						Prototype5* clone() const override;
//					};
//
//					class ConcretePrototype52 : public Prototype5
//					{
//					private:
//						float concrete_prototype_field2_;
//
//					public:
//						ConcretePrototype52(std::string prototype_name, float concrete_prototype_field);
//						Prototype5* clone() const override;
//					};
//#pragma endregion Product5
//
//#pragma region Factory5
//					/**
//					 * In PrototypeFactory you have two concrete prototypes, one for each concrete
//					 * prototype class, so each time you want to create a bullet , you can use the
//					 * existing ones and clone those.
//					 */
//
//					class PrototypeFactory5
//					{
//					private:
//						std::unordered_map<Type, Prototype5*, std::hash<int>> prototypes_;
//
//					public:
//						PrototypeFactory5();
//						/**
//						 * Be carefull of free all memory allocated. Again, if you have smart pointers
//						 * knowelege will be better to use it here.
//						 */
//
//						~PrototypeFactory5();
//						/**
//						 * Notice here that you just need to specify the type of the prototype you
//						 * want and the method will create from the object with this type.
//						 */
//						Prototype5* create(Type type);
//					};
//
//#pragma endregion Factory5
//
//#pragma region User5
//
//					void user5(PrototypeFactory5& prototype_factory);
//#pragma endregion User5
//
//#pragma endregion Example5
			}
		}
	}
}