#pragma once
#include "DPMemento.h"


namespace za
{
	namespace dp
	{
		namespace mem
		{


            Canvas::~Canvas()
            {
                for (auto p : oldStates)
                {
                    delete p;
                }
                oldStates.clear();
            };
            void Canvas::addShape(const std::string& newShape) 
            {
                oldStates.push_back(new CanvasMemento(shapes));
                shapes.push_back(newShape);
            };
            void Canvas::undo()
            {
                CanvasMemento* previousState = oldStates.back();
                oldStates.pop_back();
                shapes = previousState->shapes;
                delete previousState;
            };
            void Canvas::clearAll()
            {
                shapes.clear();
            }
            std::vector<std::string> Canvas::getShapes()
            { 
                return shapes; 
            };

		}
	}
}