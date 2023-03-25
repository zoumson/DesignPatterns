#pragma once
#include "DPUtilities.h"
/*
2. Command design pattern
*/

namespace za
{
	namespace dp
	{
		namespace cmd
		{
            class Command 
            {
            public:
                virtual ~Command() {};
                virtual void execute() = 0;
            };

            class Canvas 
            {
                std::vector<std::string> shapes;
            public:
                void addShape(const std::string& newShape);
                void clearAll();
                std::vector<std::string> getShapes();
            };

            class AddShapeCommand : public Command 
            {
                std::string shapeName;
                Canvas* canvas;
            public:
                AddShapeCommand(const std::string& shapeName, Canvas* canvas) : shapeName(shapeName), canvas(canvas) {};
                void execute() override;
            };

            class ClearCommand : public Command 
            {
                Canvas* canvas;
            public:
                ClearCommand(Canvas* canvas) : canvas(canvas) {};
                void execute() override;
            };

            class Button 
            {
                Command* command;
            public:
                Button(Command* command) : command(command) {}
                ~Button() 
                { 
                    delete command;
                };
                virtual void click() 
                {
                    command->execute();
                };
            };

		}
	}
}