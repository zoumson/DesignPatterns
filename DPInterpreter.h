#pragma once
#include "DPUtilities.h"

/*
5. Observer design pattern

Define a recursive grammar that our program can use to 
convert languages it doesn't understand into some form 
that it does understand
*/

namespace za
{
	namespace dp
	{
        namespace behavioral
        {
            namespace itr
            {
                class Expression
                {
                public:
                    virtual int evaluate() = 0;
                };

                // 5 + (10 + 1)
                class OperationExpression : public Expression
                {
                    std::string operatorSymbol;
                    Expression* leftHandSide;
                    Expression* rightHandSide;
                public:
                    OperationExpression(const std::string& operatorSymbol, Expression* lhs, Expression* rhs) : operatorSymbol(operatorSymbol), leftHandSide(lhs), rightHandSide(rhs) {};
                    int evaluate() override;
                };

                class NumberExpression : public Expression
                {
                    std::string numberString;
                public:
                    NumberExpression(const std::string& numberString) : numberString(numberString) {};
                    int evaluate() override;
                };

            }
        }
	}
}