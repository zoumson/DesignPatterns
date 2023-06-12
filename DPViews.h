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
#include "DPAdapter.h"
#include "DPFacade.h"
#include "DPBridge.h"
#include "DPComposite.h"
#include "DPDecorator.h"
#include "DPFlyweight.h"
#include "DPProxy.h"


namespace za
{
	namespace dp
	{
		namespace ex
		{
			enum class PATTERN
			{
				B_CHAIN_OF_RESPONSABILITY,
				B_COMMAND,
				B_MEDIATOR,
				B_OBSERVER,
				B_INTERPRETER,
				B_STATE,
				B_STRATEGY,
				B_TEMPLATE,
				B_VISITOR,
				B_ITERATOR,
				B_MEMENTO,
				B_NULL_OBJECT,


				C_FACTORY_METHOD = 20,
				C_ABSTRACT_FACTORY,
				C_BUILDER,
				C_PROTOTYPE,
				C_SINGLETON,

				S_ADAPTER = 30,
				S_BRIDGE,
				S_COMPOSITE,
				S_DECORATOR,
				S_FLYWEIGHT,
				S_FACADE,
				S_PROXY,



			};
#pragma region behavioral

			namespace behavioral
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
			}

#pragma endregion behavioral

#pragma region creational

			namespace creational
			{
				void factoryMethod();
				void abstracFactory();
				void builder();
				void prototypee();
				void singleton();
			}

#pragma endregion creational

#pragma region structural

			namespace structural
			{
				void adapter();
				void bridge();
				void composite();
				void decorator();
				void facade();
				void flyweight();
				void proxy();
			}

#pragma endregion structural
		}

	}

}