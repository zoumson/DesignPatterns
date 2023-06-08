#pragma once
#include "DPUtilities.h"
/*
6. Strategy design pattern


*/

namespace za
{
	namespace dp
	{
        namespace behavioral
        {
            namespace str
            {

                class GreetingStrategy
                {
                public:
                    virtual ~GreetingStrategy() {};
                    virtual void greet(const std::string& name) = 0;
                };

                class FormalGreetingStrategy : public GreetingStrategy
                {
                public:
                    void greet(const std::string& name);
                };

                class NormalGreetingStrategy : public GreetingStrategy
                {
                public:
                    void greet(const std::string& name);
                };

                class InformalGreetingStrategy : public GreetingStrategy
                {
                public:
                    void greet(const std::string& name);
                };

                class Person
                {
                    GreetingStrategy* greetingStrategy;
                public:
                    Person(GreetingStrategy* greetingStrategy) : greetingStrategy(greetingStrategy) {};
                    ~Person();
                    void greet(const std::string& name);

                };
            }
        }
	}
}