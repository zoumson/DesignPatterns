#pragma once
#include "DPUtilities.h"

/*
* Creational Pattern
2. Abstract Factory 

*/

namespace za
{
	namespace dp
	{
		namespace creational
		{
			namespace af
			{
				//Door Objects
				class Door
				{
				public:
					Door()
					{
					};
					virtual void Open() = 0;
				};

				class GasCarDoor : public Door
				{
				public:
					GasCarDoor();
					void Open();
		
				};

				class ElectricCarDoor : public Door
				{
				public:
					ElectricCarDoor();
					void Open();
				};

				//Engine objects
				class Engine
				{
				protected:
					char _sound[15];
				public:
					Engine();
					virtual void Run() = 0;
				};

				class GasEngine : public Engine
				{
				public:
					GasEngine();
					void Run();
				};

				class ElectricEngine : public Engine
				{
				public:
					ElectricEngine();
					void Run();
				};

				//Factories
				class CarFactory
				{
				public:
					virtual Door* BuildDoor() = 0;
					virtual Engine* BuildEngine() = 0;
				};

				class GasCarFactory :public CarFactory
				{
				public:
					Door* BuildDoor();
					Engine* BuildEngine();
				};

				class ElectricCarFactory :public CarFactory
				{
				public:
					Door* BuildDoor();
					Engine* BuildEngine();
				};


			}
		}
	}
}