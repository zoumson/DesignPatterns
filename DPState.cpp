#pragma once
#include "DPState.h"

namespace za
{
	namespace dp
	{
        namespace behavioral
        {
            namespace sta
            {

                std::string PurchasedState::getDescription()
                {
                    return "Current State: PURCHASED - Will be shipping soon\n";
                }

                State* PurchasedState::getNextState()
                {
                    return nextState;
                };

                std::string InTransitState::getDescription()
                {
                    return "Current State: IN_TRANSIT - Your item is on the way\n";
                }
                State* InTransitState::getNextState()
                {
                    return nextState;
                };

                std::string DeliveredState::getDescription()
                {
                    return "Current State: DELIVERED - Your item has arrived\n";
                }
                State* DeliveredState::getNextState()
                {
                    return nextState;
                };

                std::string Purchase::getDescription()
                {
                    return currentState->getDescription();
                }
                void Purchase::goToNextState()
                {
                    if (currentState->getNextState())
                    {
                        currentState = currentState->getNextState();
                    }
                    else
                    {
                        std::cout << "No more states!";
                    }
                };

            }
        }
	}
}