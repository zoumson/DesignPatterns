#pragma once
#include"DPAbstractFactory.h"

/*

*/

namespace za
{
	namespace dp
	{
		namespace creational
		{
			namespace af
			{

					GasCarDoor::GasCarDoor()
					{
						std::cout << "Making a door for a gas car." << std::endl;
					};
					void GasCarDoor::Open()
					{
						std::cout << "click" << std::endl;
					};

					ElectricCarDoor::ElectricCarDoor()
					{
						std::cout << "Making a door for an electric car" << std::endl;
					};
					void ElectricCarDoor::Open()
					{
						std::cout << "shhhhh" << std::endl;
					};


					Engine::Engine()
					{
						strcpy_s(_sound, "");
					};

					GasEngine::GasEngine()
					{
						strcpy_s(_sound, "vroom");
						std::cout << "Making a gas engine." << std::endl;
					};
					void GasEngine::Run()
					{
						std::cout << _sound << std::endl;
					};

					ElectricEngine::ElectricEngine()
					{
						strcpy_s(_sound, "SHHHH");
						std::cout << "Making an electric engine." << std::endl;
					};
					void ElectricEngine::Run()
					{
						std::cout << _sound << std::endl;
					};

					Door* GasCarFactory::BuildDoor()
					{
						return new GasCarDoor();
					};
					Engine* GasCarFactory::BuildEngine()
					{
						return new GasEngine();
					};

					Door* ElectricCarFactory::BuildDoor()
					{
						return new ElectricCarDoor();
					};
					Engine* ElectricCarFactory::BuildEngine()
					{
						return new ElectricEngine();
					};


			}
		}
	}
}