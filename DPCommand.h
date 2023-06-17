#pragma once
#include "DPUtilities.h"
/*
2. Command design pattern
*/

namespace za
{
	namespace dp
	{
        namespace behavioral
        {
            namespace cmd
            {
#pragma region Example1
                class CommandC1
                {
                public:
                    virtual ~CommandC1() {};
                    virtual void execute() = 0;
                };

                class CanvasC1
                {
                    std::vector<std::string> shapes;
                public:
                    void addShape(const std::string& newShape);
                    void clearAll();
                    std::vector<std::string> getShapes();
                };

                class AddShapeCommandC1 : public CommandC1
                {
                    std::string shapeName;
                    CanvasC1* canvas;
                public:
                    AddShapeCommandC1(const std::string& shapeName, CanvasC1* canvas) : shapeName(shapeName), canvas(canvas) {};
                    void execute() override;
                };

                class ClearCommandC1 : public CommandC1
                {
                    CanvasC1* canvas;
                public:
                    ClearCommandC1(CanvasC1* canvas) : canvas(canvas) {};
                    void execute() override;
                };

                class ButtonC1
                {
                    CommandC1* command;
                public:
                    ButtonC1(CommandC1* command) : command(command) {}
                    ~ButtonC1()
                    {
                        delete command;
                    };
                    virtual void click()
                    {
                        command->execute();
                    };
                };
#pragma region Example1

#pragma region Example2

                class CalculatorCommandC2
                {
                public:
                    virtual ~CalculatorCommandC2() = default;

                    virtual int execute(int i) const = 0;
                    virtual int undo(int i) const = 0;
                };

                class AddC2 : public CalculatorCommandC2
                {
                public:
                    explicit AddC2(int operand);

                    int execute(int i) const override;
                    int undo(int i) const override;

                private:
                    int operand_{};
                };

                class SubtractC2 : public CalculatorCommandC2
                {
                public:
                    explicit SubtractC2(int operand);

                    int execute(int i) const override;
                    int undo(int i) const override;

                private:
                    int operand_{};
                };
                
                class CalculatorC2
                {
                public:
                    void compute(std::unique_ptr<CalculatorCommandC2> command);
                    void undoLast();

                    int result() const;
                    void clear();

                private:
                    using CommandStackC2 = std::stack<std::unique_ptr<CalculatorCommandC2>>;

                    int current_{};
                    CommandStackC2 stack_;
                };

#pragma endregion Example2



            }
		}
	}
}