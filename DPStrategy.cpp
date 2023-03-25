#pragma once
#include "DPStrategy.h"

namespace za
{
	namespace dp
	{
		namespace str
		{
                void FormalGreetingStrategy::greet(const std::string& name) 
                {
                    std::cout << "Good morning " << name << ", how do you do?\n";
                }
                void NormalGreetingStrategy::greet(const std::string& name) 
                {
                    std::cout << "Hi " << name << ", how are you?\n";
                }
                void InformalGreetingStrategy::greet(const std::string& name) 
                {
                    std::cout << "Hey " << name << ", what's up?\n";
                }
                Person::~Person() 
                { 
                    delete greetingStrategy; 
                };
                void Person::greet(const std::string& name) 
                {
                    greetingStrategy->greet(name);
                }
		}
	}
}