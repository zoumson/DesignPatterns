#pragma once
#include "DPIterator.h"



namespace za
{
	namespace dp
	{
		namespace ite
		{

                int ForwardsIterator::next() 
                {
                    int current = numbers.at(currentPosition);
                    currentPosition += 1;
                    return current;
                }
                bool ForwardsIterator::isFinished()  
                {
                    return currentPosition >= numbers.size();
                }

                int BackwardsIterator::next()  
                {
                    int current = numbers.at(numbers.size() - currentPosition - 1);
                    currentPosition += 1;
                    return current;
                }
                bool BackwardsIterator::isFinished() 
                {
                    return currentPosition >= numbers.size();
                }


                NumberIterator* NumberCollection::getForwardsIterator() 
                { 
                    return new ForwardsIterator(numbers); 
                }
                NumberIterator* NumberCollection::getBackwardsIterator() 
                {
                    return new BackwardsIterator(numbers); 
                }

		}
	}
}