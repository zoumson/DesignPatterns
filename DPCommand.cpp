#include "DPCommand.h"


namespace za
{
	namespace dp
	{
		namespace cmd
		{

                void Canvas::addShape(const std::string& newShape) 
                {
                    shapes.push_back(newShape);
                };
                void Canvas::clearAll()
                {
                    shapes.clear();
                };
                std::vector<std::string> Canvas::getShapes() 
                { 
                    return shapes; 
                };

                void AddShapeCommand::execute() 
                {
                    canvas->addShape(shapeName);
                }

                void ClearCommand::execute() 
                {
                    canvas->clearAll();
                }

		}
	}
}