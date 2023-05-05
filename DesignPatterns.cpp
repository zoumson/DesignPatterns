// DesignPatterns.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "DPViews.h"
#include <iostream>

int main()
{
    size_t testNumber = 16;


	switch (testNumber)
	{
		case 1:
			za::dp::ex::chainOfResponsability();
			break;		
		case 2:
			za::dp::ex::command();
			break;		
		case 3:
			za::dp::ex::mediator();
			break;	
		case 4:
			za::dp::ex::observer();
			break;		
		case 5:
			za::dp::ex::chainRespObserCmd();
			break;		
		case 6:
			za::dp::ex::interpreter();
			break;		
		case 7:
			za::dp::ex::state();
			break;		
		case 8:
			za::dp::ex::strategy();
			break;		
		case 9:
			za::dp::ex::templatee();
			break;		
		case 10:
			za::dp::ex::visitor();
			break;			
		case 11:
			za::dp::ex::templateVisitor();
			break;		
		case 12:
			za::dp::ex::iteratorr();
			break;		
		case 13:
			za::dp::ex::memento();
			break;		
		case 14:
			za::dp::ex::nullObject();
			break;		
		case 15:
			za::dp::ex::iterMemNob();
			break;		
		case 16:
			za::dp::ex::creational::factoryMethod();
			break;		
		case 17:
			za::dp::ex::creational::abstracFactory();
			break;		
		case 18:
			za::dp::ex::creational::builder();
			break;		
		case 19:
			za::dp::ex::creational::prototypee();
			break;		
		case 20:
			za::dp::ex::creational::singleton();
			break;
		default:
			za::dp::ex::chainOfResponsability();
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