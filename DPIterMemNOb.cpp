#include "DPIterMemNOb.h"


namespace za
{
	namespace dp
	{
		namespace mio
		{


                CanvasMemento* ForwardsIterator::next() 
                {
                    CanvasMemento* current = history.at(currentPosition);
                    currentPosition += 1;
                    return current;
                };
                bool ForwardsIterator::isFinished()  
                {
                    return currentPosition >= history.size();
                }


                CanvasHistory::~CanvasHistory()
                {
                    for (auto p : oldStates)
                    {
                        delete p;
                    }
                    oldStates.clear();
                };
                void CanvasHistory::addState(CanvasMemento* newState) 
                {
                    oldStates.push_back(newState);
                };
                CanvasMemento* CanvasHistory::undo()
                {
                    oldStates.pop_back();
                    CanvasMemento* previousState = oldStates.back();
                    return previousState;
                };
                ForwardsIterator* CanvasHistory::getForwardsIterator()
                {
                    return new ForwardsIterator(oldStates);
                }

                NullHistory::NullHistory() 
                { 
                    state = new CanvasMemento({}); 
                };
                void NullHistory::addState(CanvasMemento* newState) 
                {
                    state = newState;
                };
                CanvasMemento* NullHistory::undo() 
                {
                    return state;
                };


                void Canvas::addShape(const std::string& newShape) 
                {
                    shapes.push_back(newShape);
                    history->addState(new CanvasMemento(shapes));
                };
                void Canvas::undo() 
                {
                    CanvasMemento* previousState = history->undo();
                    shapes = previousState->shapes;
                }
                void Canvas::clearAll() 
                {
                    shapes.clear();
                    history->addState(new CanvasMemento(shapes));
                };
                std::vector<std::string> Canvas::getShapes() 
                { 
                    return shapes; 
                };

                void ReplayCanvas::replay() 
                {
                    while (!historyIterator->isFinished()) 
                    {
                        CanvasMemento* nextState = historyIterator->next();
                        shapes = nextState->shapes;
                        std::cout << "The shapes are now: ";
                        for (auto shape : shapes) 
                        {
                            std::cout << shape << ", ";
                        }
                        std::cout << "\n";
                    }
                };

		}
	}
}