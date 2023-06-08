#include "DPInterpreter.h"



namespace za
{
	namespace dp
	{
        namespace behavioral
        {
            namespace itr
            {



                int OperationExpression::evaluate()
                {
                    if (operatorSymbol == "plus")
                    {
                        return leftHandSide->evaluate() + rightHandSide->evaluate();
                    }
                    else if (operatorSymbol == "minus")
                    {
                        return leftHandSide->evaluate() - rightHandSide->evaluate();
                    }
                    else
                    {
                        std::cout << "Unrecognized operator: " << operatorSymbol;
                        return 0;
                    }
                }

                int NumberExpression::evaluate()
                {
                    return std::stoi(numberString);
                }

            }
        }
	}
}