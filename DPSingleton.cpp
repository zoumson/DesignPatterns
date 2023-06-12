#pragma once
#include "DPSingleton.h"

/*
* Creational PATTERN
5. Singleton


*/

namespace za
{
	namespace dp
	{
#pragma endregion Example1	

        namespace creational
		{
			namespace sin
			{
#pragma region Example1	

				//the static need to be in source file not in header
				LeaderS1* LeaderS1::_instance = nullptr;

#pragma endregion Example1	
#pragma region Example2	

                WifiS2::WifiS2()
                {
                    speed = 100;
                };
                void  WifiS2::setSpeed(int value)
                {
                    speed = value;
                };
                int  WifiS2::getSpeed()
                {
                    return speed;
                };
                void WifiS2::send(std::string data)
                {
                    std::cout << "Sent By Wifi: " << data << " Speed: " << speed << std::endl;
                };
                WifiS2* WifiS2::instance()
                {
                    if (!thisInstance)
                    {
                        thisInstance = new WifiS2;
                    }
                    return thisInstance;
                }
                void WifiS2::destroyInstance()
                {
                    delete thisInstance;
                    thisInstance = nullptr;
                };
                
                BluetoothS2::BluetoothS2()
                {
                    speed = 8;
                };
                void  BluetoothS2::setSpeed(int value)
                {
                    speed = value;
                };
                int  BluetoothS2::getSpeed()
                {
                    return speed;
                };
                void BluetoothS2::send(std::string data)
                {
                    std::cout << "Sent By Bluetooth: " << data << " Speed: " << speed << std::endl;
                };
                BluetoothS2* BluetoothS2::instance()
                {
                    if (!thisInstance) 
                    {
                        thisInstance = new BluetoothS2;
                    }
                    return thisInstance;
                }
                void BluetoothS2::destroyInstance()
                {
                    delete thisInstance;
                    thisInstance = nullptr;
                };

                BluetoothS2* BluetoothS2::thisInstance = nullptr;
                WifiS2* WifiS2::thisInstance = nullptr;


#pragma endregion Example2	

#pragma region Example3

                SingletonS3* SingletonS3::getInstance()
                {
                    static SingletonS3* instance = new SingletonS3();
                    //instance is created only once cuz of static qualifer
                    return instance;

                };
                SingletonS3::SingletonS3()
                {

                };
                SingletonS3::~SingletonS3()
                {
                }

#pragma endregion Example3	
			}
		}

	
	}
}