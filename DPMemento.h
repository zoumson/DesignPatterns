#pragma once
#include "DPUtilities.h"

/*
12. Momentom design pattern


*/

namespace za
{
	namespace dp
	{
		namespace mem
		{
            class Canvas;

            class CanvasMemento 
            {
                friend class Canvas;
                const std::vector<std::string> shapes;
            public:
                CanvasMemento(std::vector<std::string> shapes) : shapes(shapes) {};
            };

            class Canvas 
            {
                std::vector<std::string> shapes;
                std::vector<CanvasMemento*> oldStates;
            public:
                ~Canvas();
                void addShape(const std::string& newShape);
                void undo();
                void clearAll();
                std::vector<std::string> getShapes();
            };
		}
	}
}