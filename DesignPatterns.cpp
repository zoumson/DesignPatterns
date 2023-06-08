// DesignPatterns.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "DPViews.h"
#include <iostream>

int main()
{
    size_t testNumber = 10;

	using namespace za::dp::ex;

	switch (testNumber)
	{

#pragma region behavioral
		case 1:
			behavioral::chainOfResponsability();
			break;		
		case 2:
			behavioral::command();
			break;		
		case 3:
			behavioral::mediator();
			break;	
		case 4:
			behavioral::observer();
			break;		
		case 5:
			behavioral::interpreter();
			break;		
		case 6:
			behavioral::state();
			break;		
		case 7:
			behavioral::strategy();
			break;		
		case 8:
			behavioral::templatee();
			break;		
		case 9:
			behavioral::visitor();
			break;		
		case 10:
			behavioral::iteratorr();
			break;			
		case 11:
			behavioral::memento();
			break;		
		case 12:
			behavioral::nullObject();
			break;		

#pragma endregion behavioral

#pragma region creational

		case 13:
			creational::factoryMethod();
			break;		
		case 14:
			creational::abstracFactory();
			break;		
		case 15:
			creational::builder();
			break;		
		case 16:
			creational::prototypee();
			break;		
		case 17:
			creational::singleton();
			break;		

#pragma endregion creational

#pragma region structural
		case 18:
			structural::adapter();
			break;			
		case 19:
			structural::bridge();
			break;			
		case 20:
			structural::composite();
			break;		
		case 21:
			structural::decorator();
			break;		
		case 22:
			structural::flyweight();
			break;		
		case 23:
			structural::facade();
			break;

#pragma endregion structural

		default:
			
			break;
	}
	return 0;
}


/*
* 1. Design Pattern Definition
* A design pattern is a common, 
* repeatable solution for creating software
* programs
* 
* 2. Software Challenges
* a. Flexibility
* b. Maintenance
* c. Extension
* 
* 3. Implement Solutions
* a. Add new features
* b. Remove features
* c. Replace features
* d. Apply program in different situations
* 
* 4. Example: Building house
* a. Basic one storatge room
* b. Adding another level, room?
* c. Redesign the kitchen
* 
* 5. Origins of the Design Patterns
* Gang of Four wrote Design Patterns: 
* Elements of Reusable Object-Oriented Software
* Original 23 patterns
* Three classifications: c
* a. creational: object instantiation
* - Factory Mehtod
* - Abstract Factory
* - Builder
* - Prototype
* - Singleton
* b. structural: class relationships and hierarchies
* c. behavioral: object intercommunication
* 6. Class Explosion
* a. Composition
* Property referenced by another class
* b. Inheritance
* Class extends another
* 7. Concrete vs. abstract
* a. Virtual
* Keyword indicating a method must be overriden 
* usually used in the base class, overide used in derived classes
* ex: virtual void f()
* {
* }
* 
* same as
* virtual void f() = 0
* b. Baseclass: Abstract class
* c. Derived class: Concrete class
* 8. Unified Modeling Language (UML)
* Aggregation relationship: one element has or contain another element
* Diamond points to the container, arrow points to the element
* 
*/