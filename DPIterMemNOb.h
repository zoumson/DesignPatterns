#pragma once
#include "DPUtilities.h"

/*
14. iterator, memento, null object

*/

namespace za
{
	namespace dp
	{
		namespace mio
		{
            class Canvas;
            class ReplayCanvas;

            class CanvasMemento 
            {
                friend class Canvas;
                friend class ReplayCanvas;
                const std::vector<std::string> shapes;
            public:
                CanvasMemento(std::vector<std::string> shapes) : shapes(shapes) {};
            };

            class CanvasIterator 
            {
            public:
                virtual ~CanvasIterator() {};
                virtual CanvasMemento* next() = 0;
                virtual bool isFinished() = 0;
            };

            class ForwardsIterator : public CanvasIterator 
            {
                int currentPosition;
                std::vector<CanvasMemento*>& history;
            public:
                ForwardsIterator(std::vector<CanvasMemento*>& history) : currentPosition(0), history(history) {};
                CanvasMemento* next() override;
                bool isFinished() override;
            };

            class History 
            {
            public:
                virtual void addState(CanvasMemento* newState) = 0;
                virtual CanvasMemento* undo() = 0;
            };

            class CanvasHistory : public History 
            {
                std::vector<CanvasMemento*> oldStates;
            public:
                ~CanvasHistory();
                void addState(CanvasMemento* newState) override;
                CanvasMemento* undo() override;
                ForwardsIterator* getForwardsIterator();
            };

            class NullHistory : public History 
            {
                CanvasMemento* state;
            public:
                NullHistory();
                void addState(CanvasMemento* newState);
                CanvasMemento* undo();
            };

            class Canvas 
            {
                std::vector<std::string> shapes;
                History* history;
            public:
                Canvas(History* history) : history(history) {};
                void addShape(const std::string& newShape);

                void undo();
                void clearAll();
                std::vector<std::string> getShapes();
            };

            class ReplayCanvas 
            {
                std::vector<std::string> shapes;
                ForwardsIterator* historyIterator;
            public:
                ReplayCanvas(CanvasHistory* history);
                void replay();
            };
		}
	}
}