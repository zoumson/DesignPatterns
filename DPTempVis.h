#pragma once
#include "DPUtilities.h"

/*
11. Iterator design pattern


*/

namespace za
{
	namespace dp
	{
        namespace tvi
        {
            class Visitor
            {
            public:
                virtual std::string handlePerson(const std::string& name, int age) = 0;
            };

            class Person
            {
                std::string name;
                int age;
            public:
                Person(const std::string& name, int age) : name(name), age(age) {};
                std::string accept(Visitor* v);
            };

            class GreetingCardTemplate : public Visitor
            {
                std::string from;
            protected:
                virtual std::string intro(const std::string& to);
                virtual std::string occasion();
                virtual std::string closing(const std::string& from);
            public:
                GreetingCardTemplate(const std::string& from) : from(from) {};
                ~GreetingCardTemplate() {};
                std::string generateCardFor(Person* person);
                std::string handlePerson(const std::string& name, int age);

            };

            class BirthdayCardTemplate : public GreetingCardTemplate
            {
            protected:
                std::string occasion() override;
            public:
                BirthdayCardTemplate(const std::string& from) : GreetingCardTemplate(from) {};
            };

            class NewYearsCardTemplate : public GreetingCardTemplate
            {
            protected:
                std::string intro(const std::string& to) override;
                std::string occasion() override;
            public:
                NewYearsCardTemplate(const std::string& from) : GreetingCardTemplate(from) {};
            };

            class GreetingCardGenerator
            {
                GreetingCardTemplate* temp;
                std::vector<Person*> people;
            public:
                void addPerson(Person* person);
                void setTemplate(GreetingCardTemplate* newTemp);
                std::vector<std::string> createGreetingCards();
            };
        }
	}
}