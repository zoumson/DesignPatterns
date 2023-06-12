#pragma once
#include "DPUtilities.h"

/*
* Creational PATTERN
5. Singleton
only one insatnce of the class
only used for logging 
Not thread safe
sol: lazy initialization
lock the section  of creating the instance
*/

namespace za
{
	namespace dp
	{
		namespace creational
		{
			namespace sin
			{
#pragma region Example1

				class LeaderS1
				{
				private:
					static LeaderS1* _instance;
					LeaderS1()
					{
						std::cout << "New leader elected" << std::endl;
					}
				public:
					static LeaderS1* getInstance()
					{
						if (_instance == nullptr)
						{
							_instance = new LeaderS1;
						};
						return _instance;
					};					
					
					static void destroyInstance()
					{
						delete _instance;
						_instance = nullptr;
					};
					void giveSpeech()
					{
						std::cout << "Address the public" << std::endl;
					}
				};

#pragma endregion Example1	

#pragma region Example2	

                // Default Classes
                class DeviceS2
                {
                public:
                    virtual void send(std::string data) = 0;
                    virtual void setSpeed(int value) = 0;
                    virtual int getSpeed() = 0;
                };

                class WifiS2 : public DeviceS2
                {
                public:
                    int speed;
                    static WifiS2* thisInstance;
                    WifiS2();
                    void setSpeed(int value) override;
                    int getSpeed() override;
                    void send(std::string data) override;
                    // Singleton Design PATTERN
                    static WifiS2* instance();
					static void destroyInstance();
                };

                class BluetoothS2 : public DeviceS2
                {
                public:
                    int speed;
                    static BluetoothS2* thisInstance;
                    BluetoothS2();
                    void setSpeed(int value) override;
                    int getSpeed() override;
                    void send(std::string data) override;
                    // Singleton Design PATTERN
                    static BluetoothS2* instance();
					static void destroyInstance();
                };

#pragma endregion Example2		

#pragma region Example3	

				class SingletonS3
				{

				public:

					static SingletonS3* getInstance();

				private:
					static SingletonS3* localInstance;
					SingletonS3();
					~SingletonS3();

				private:
					SingletonS3(const SingletonS3&) = delete;
					SingletonS3& operator=(const SingletonS3&) = delete;
					SingletonS3(SingletonS3&&) = delete;
					SingletonS3& operator=(SingletonS3&&) = delete;

				};

#pragma endregion Example3		
			}
		}
	}
}