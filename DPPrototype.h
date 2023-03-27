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
			}
		}
	}
}