#pragma once
#include "DPChainOfResponsability.h"
#include "DPCommand.h"
#include "DPMediator.h"
#include "DPObserver.h"
#include "DPChainRespObserCmd.h"
#include "DPInterpreter.h"
#include "DPState.h"
#include "DPStrategy.h"
#include "DPTemplate.h"
#include "DPVisitor.h"
#include "DPIterator.h"
#include "DPTempVis.h"
#include "DPMemento.h"
#include "DPNullObject.h"
#include "DPIterMemNOb.h"
#include "DPFactoryMethod.h"
#include"DPAbstractFactory.h"
#include "DPBuilder.h"
#include "DPPrototype.h"
#include "DPSingleton.h"
namespace za
{
	namespace dp
	{
		namespace ex
		{
			void chainOfResponsability();
			void command();
			void mediator();
			void observer();
			void chainRespObserCmd();
			void interpreter();
			void state();
			void strategy();
			void templatee();
			void visitor();
			void templateVisitor();
			void iteratorr();
			void memento();
			void nullObject();
			void iterMemNob();
			namespace creational
			{
				void factoryMethod();
				void abstracFactory();
				void builder();
				void prototypee();
				void singleton();
			}
		}

	}

}