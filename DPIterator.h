#pragma once
#include "DPUtilities.h"

/*
11. Iterator design pattern


*/

namespace za
{
	namespace dp
	{
        namespace behavioral
        {
            namespace ite
            {
                class NumberIterator
                {
                public:
                    virtual ~NumberIterator() {};
                    virtual int next() = 0;
                    virtual bool isFinished() = 0;
                };

                class ForwardsIterator : public NumberIterator
                {
                    int currentPosition;
                    std::vector<int>& numbers;
                public:
                    ForwardsIterator(std::vector<int>& numbers) : currentPosition(0), numbers(numbers) {};
                    int next();
                    bool isFinished();
                };

                class BackwardsIterator : public NumberIterator
                {
                    int currentPosition;
                    std::vector<int>& numbers;
                public:
                    BackwardsIterator(std::vector<int>& numbers) : currentPosition(0), numbers(numbers) {};
                    int next();
                    bool isFinished();
                };

                class NumberCollection
                {
                    std::vector<int> numbers;
                public:
                    NumberCollection(const std::vector<int>& numbers) : numbers(numbers) {};
                    NumberIterator* getForwardsIterator();
                    NumberIterator* getBackwardsIterator();
                };

            }
        }
	}
}