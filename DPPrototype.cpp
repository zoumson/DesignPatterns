#pragma once
#include "DPPrototype.h"

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

			}
		}
	}
}