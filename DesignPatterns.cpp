// DesignPatterns.cpp : This file contains the 'main' function. Program execution begins and ends there.
//
#include "DPViews.h"
#include <iostream>

int main()
{
    size_t testNumber = 15;


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
		default:
			za::dp::ex::chainOfResponsability();
			break;
	}
	return 0;
}


