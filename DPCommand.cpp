#include "DPCommand.h"


namespace za
{
	namespace dp
	{
        namespace behavioral
        {
            namespace cmd
            {

#pragma region Example1

                void CanvasC1::addShape(const std::string& newShape)
                {
                    shapes.push_back(newShape);
                };
                void CanvasC1::clearAll()
                {
                    shapes.clear();
                };
                std::vector<std::string> CanvasC1::getShapes()
                {
                    return shapes;
                };

                void AddShapeCommandC1::execute()
                {
                    canvas->addShape(shapeName);
                }

                void ClearCommandC1::execute()
                {
                    canvas->clearAll();
                }

#pragma endregion Example1

#pragma region Example2

                AddC2::AddC2(int operand) : operand_(operand) {};
                int AddC2::execute(int i) const 
                {
                    return i + operand_;
                }
                int AddC2::undo(int i) const 
                {
                    return i - operand_;
                }
               
                SubtractC2::SubtractC2(int operand) : operand_(operand) {};
                int SubtractC2::execute(int i) const
                {
                    return i - operand_;
                }
                int SubtractC2::undo(int i) const
                {
                    return i + operand_;
                }
  
                void CalculatorC2::compute(std::unique_ptr<CalculatorCommandC2> command)
                {
                    current_ = command->execute(current_);
                    stack_.push(std::move(command));
                }

                void CalculatorC2::undoLast()
                {
                    if (stack_.empty()) 
                    {
                        return;
                    }

                    auto command = std::move(stack_.top());

                    stack_.pop();
                    current_ = command->undo(current_);
                }

                int CalculatorC2::result() const
                {
                    return current_;
                }

                void CalculatorC2::clear()
                {
                    current_ = 0;
                    CommandStackC2{}.swap(stack_);  // Clearing the stack
                }




#pragma endregion Example2
            }


        }
	}
}