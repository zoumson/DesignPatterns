//#pragma once
//#include "DPTempVis.h"
//
///*
//Template, Visitor design pattern
//
//
//*/
//
//namespace za
//{
//	namespace dp
//	{
//        namespace tvi
//        {
//            std::string Person::accept(Visitor* v)
//            {
//                return v->handlePerson(name, age);
//            };
//
//
//            std::string GreetingCardTemplate::intro(const std::string& to)
//            {
//                return "Dear " + to + ",\n";
//            };
//            std::string GreetingCardTemplate::occasion()
//            {
//                return "Just writing to say hi! Hope all is well with you.\n";
//            };
//            std::string GreetingCardTemplate::closing(const std::string& from)
//            {
//                return "Sincerely,\n" + from + "\n";
//            };
//
//            std::string GreetingCardTemplate::generateCardFor(Person* person)
//            {
//                return person->accept(this);
//            };
//            std::string GreetingCardTemplate::handlePerson(const std::string& name, int age)
//            {
//                return intro(name) + occasion() + closing(from);
//            };
//
//            std::string BirthdayCardTemplate::occasion()
//            {
//                return "Happy birthday!! Hope you have a wonderful day and lots of cake.\n";
//            };
//
//
//            std::string NewYearsCardTemplate::intro(const std::string& to)
//            {
//                return to + "!!!\n";
//            };
//            std::string NewYearsCardTemplate::occasion()
//            {
//                return "Happy New Years!!!! See you at the gym tomorrow!\n";
//            };
//
//            void GreetingCardGenerator::addPerson(Person* person)
//            {
//                people.push_back(person);
//            };
//            void GreetingCardGenerator::setTemplate(GreetingCardTemplate* newTemp)
//            {
//                temp = newTemp;
//            };
//            std::vector<std::string> GreetingCardGenerator::createGreetingCards()
//            {
//                std::vector<std::string> cards;
//                for (auto person : people)
//                {
//                    cards.push_back(temp->generateCardFor(person));
//                }
//                return cards;
//            };
//        }
//	}
//}