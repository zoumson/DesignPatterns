#pragma once
#include "DPUtilities.h"
/*
6. Sate design pattern

When your program has a lot of different events that different
objects need to react to, in other words,
when we only want objects that care about certain events to be notified of their occurrence


Write our programs in terms of publisers and observers,
where publisers simply publish events and observers can choose wheter not to listen
*/

namespace za
{
	namespace dp
	{
		namespace sta
		{
            class State 
            {
            public:
                virtual std::string getDescription() = 0;
                virtual State* getNextState() = 0;
            };

            class PurchasedState : public State 
            {
                State* nextState = nullptr;
            public:
                PurchasedState(State* nextState) : nextState(nextState) {};
                std::string getDescription() override;
                State* getNextState() override;
            };

            class InTransitState : public State 
            {
                State* nextState = nullptr;
            public:
                InTransitState(State* nextState) : nextState(nextState) {};
                std::string getDescription() override;
                State* getNextState() override;
            };

            class DeliveredState : public State 
            {
                State* nextState = nullptr;
            public:
                DeliveredState(State* nextState) : nextState(nextState) {};
                std::string getDescription() override;
                State* getNextState() override;
            };

            class Purchase 
            {
                std::string productName;
                State* currentState;
            public:
                Purchase(const std::string& productName, State* initialState)
                    : productName(productName), currentState(initialState) {};
                std::string getDescription();
                void goToNextState();               
            };

		}
	}
}