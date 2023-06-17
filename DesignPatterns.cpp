// DesignPatterns.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "DPViews.h"
#include <iostream>
using namespace za::dp::ex;
void runPattern(const PATTERN& pat);

int main()
{
	const PATTERN pat = PATTERN::B_CHAIN_OF_RESPONSABILITY;
	runPattern(pat);
	return 0;
}

void runPattern(const PATTERN& pat)
{
	std::cout << "[start]\n\n";
	switch (pat)
	{

#pragma region behavioral
	case PATTERN::B_CHAIN_OF_RESPONSABILITY:
		behavioral::chainOfResponsability();
		break;

	case PATTERN::B_COMMAND:
		behavioral::command();
		break;

	case PATTERN::B_MEDIATOR:
		behavioral::mediator();
		break;

	case PATTERN::B_OBSERVER:
		behavioral::observer();
		break;

	case PATTERN::B_INTERPRETER:
		behavioral::interpreter();
		break;

	case PATTERN::B_STATE:
		behavioral::state();
		break;

	case PATTERN::B_STRATEGY:
		behavioral::strategy();
		break;

	case PATTERN::B_TEMPLATE:
		behavioral::templatee();
		break;

	case PATTERN::B_VISITOR:
		behavioral::visitor();
		break;

	case PATTERN::B_ITERATOR:
		behavioral::iteratorr();
		break;

	case PATTERN::B_MEMENTO:
		behavioral::memento();
		break;

	case PATTERN::B_NULL_OBJECT:
		behavioral::nullObject();
		break;

#pragma endregion behavioral

#pragma region creational

	case PATTERN::C_FACTORY_METHOD:
		creational::factoryMethod();
		break;

	case PATTERN::C_ABSTRACT_FACTORY:
		creational::abstracFactory();
		break;

	case PATTERN::C_BUILDER:
		creational::builder();
		break;

	case PATTERN::C_PROTOTYPE:
		creational::prototypee();
		break;

	case PATTERN::C_SINGLETON:
		creational::singleton();
		break;

#pragma endregion creational

#pragma region structural

	case PATTERN::S_ADAPTER:
		structural::adapter();
		break;

	case PATTERN::S_BRIDGE:
		structural::bridge();
		break;

	case PATTERN::S_COMPOSITE:
		structural::composite();
		break;

	case PATTERN::S_DECORATOR:
		structural::decorator();
		break;

	case PATTERN::S_FLYWEIGHT:
		structural::flyweight();
		break;
	case PATTERN::S_FACADE:
		structural::facade();
		break;
			
	case PATTERN::S_PROXY:
		structural::proxy();
		break;

#pragma endregion structural

	default:

		break;
	}
	std::cout << "\n\n[end]\n";
}




/*
* 1. Design PATTERN Definition
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