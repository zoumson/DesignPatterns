#pragma once
#include "DPVisitor.h"




namespace za
{
	namespace dp
	{
        namespace behavioral
        {
            namespace vis
            {

                void DatabaseVisitor::handlePerson(const std::string& name, int age)
                {
                    std::cout << "Writing person to database: " << name << ", " << age << "\n";
                };
                void DatabaseVisitor::handleLandmark(const std::string& name, const std::string& cityName)
                {
                    std::cout << "Writing landmark to database: " << name << ", " << cityName << "\n";
                };
                void DatabaseVisitor::handleCar(const std::string& make, const std::string& model)
                {
                    std::cout << "Writing car to database: " << make << ", " << model << "\n";
                };

                void TextFileVisitor::handlePerson(const std::string& name, int age)
                {
                    std::cout << "Writing person to file: " << name << ", " << age << "\n";
                };
                void TextFileVisitor::handleLandmark(const std::string& name, const std::string& cityName)
                {
                    std::cout << "Writing landmark to file: " << name << ", " << cityName << "\n";
                };
                void TextFileVisitor::handleCar(const std::string& make, const std::string& model)
                {
                    std::cout << "Writing car to file: " << make << ", " << model << "\n";
                };

                void Person::accept(Visitor* v)
                {
                    v->handlePerson(name, age);
                };

                void Landmark::accept(Visitor* v)
                {
                    v->handleLandmark(name, cityName);
                };

                void Car::accept(Visitor* v)
                {
                    v->handleCar(make, model);
                };

            }
        }
	}
}