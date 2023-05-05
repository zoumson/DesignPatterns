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
#pragma region Example1
#pragma region Interface11
				//Door Objects
				class Door
				{
				public:
					Door()
					{
					};
					virtual void Open() = 0;
				};
#pragma endregion Interface11
#pragma region Product11
				class GasCarDoor : public Door
				{
				public:
					GasCarDoor();
					void Open() override;
		
				};

				class ElectricCarDoor : public Door
				{
				public:
					ElectricCarDoor();
					void Open() override;
				};
#pragma endregion Product11
#pragma region Interface12
				//Engine objects
				class Engine
				{
				protected:
					char _sound[15];
				public:
					Engine();
					virtual void Run() = 0;
				};
#pragma endregion Interface12
#pragma region Product12
				class GasEngine : public Engine
				{
				public:
					GasEngine();
					void Run() override;
				};

				class ElectricEngine : public Engine
				{
				public:
					ElectricEngine();
					void Run() override;
				};
#pragma endregion Product12
#pragma region Factory1
				//Factories
				class CarFactory
				{
				public:
					enum class CAR_FACTORIES
					{
						GAS1,
						ELECTRIC1
					};
					virtual std::unique_ptr<Door> BuildDoor() = 0;
					virtual std::unique_ptr<Engine> BuildEngine() = 0;
					static std::unique_ptr<CarFactory> create(const CAR_FACTORIES& factory);
				};

				class GasCarFactory :public CarFactory
				{
				public:
					std::unique_ptr<Door> BuildDoor() override;
					std::unique_ptr<Engine> BuildEngine()override;
				};

				class ElectricCarFactory :public CarFactory
				{
				public:
					std::unique_ptr<Door> BuildDoor() override;
					std::unique_ptr<Engine> BuildEngine()override;
				};
#pragma endregion Factory1
#pragma region User1
				void buildCar(CarFactory& factory);
#pragma endregion User1

#pragma endregion Example1

#pragma region Example2

#pragma region Interface21
				class ProductA2
				{
				public:
					virtual void info() = 0;
				};

#pragma endregion Interface21

#pragma region Product21
				class ConcreteProductA21 : public ProductA2
				{
				public:
					void info() override;
				};

				class ConcreteProductA22 : public ProductA2 
				{
				public:
					void info() override;
				};

#pragma endregion Product21

#pragma region Interface22

				class ProductB2 
				{
				public:
					virtual void info() = 0;
				};

#pragma endregion Interface22

#pragma region Product22
				class ConcreteProductB21 : public ProductB2 
				{
				public:
					void info() override;
				};

				class ConcreteProductB22 : public ProductB2 
				{
				public:
					void info() override;
				};

#pragma endregion Product22


#pragma region Factory2
				class AbstractFactory2 
				{
				public:
					enum class PRODUCT2_FACTORIES
					{
						PRODUCT2_1,
						PRODUCT2_2
					};
					virtual std::unique_ptr<ProductA2> createProductA() = 0;
					virtual std::unique_ptr<ProductB2> createProductB() = 0;
					static std::unique_ptr<AbstractFactory2> create(const PRODUCT2_FACTORIES& type);
				};

				class ConcreteFactory21 : public AbstractFactory2 
				{
				public:
					std::unique_ptr<ProductA2> createProductA() override;
					std::unique_ptr<ProductB2> createProductB() override;
				};
				
				class ConcreteFactory22 : public AbstractFactory2 
				{
				public:
					std::unique_ptr<ProductA2> createProductA() override;
					std::unique_ptr<ProductB2> createProductB() override;
				};


#pragma endregion Factory2
#pragma region User2
				void buildProduct2(AbstractFactory2& factory);
#pragma endregion User2


#pragma endregion Example2

#pragma region Example3
#pragma region Interface31
				class IDumb
				{
				public:
					virtual std::string Name() = 0;
				};
#pragma endregion Interface31

#pragma region Product31

				class Asha : public IDumb
				{
				public:
					std::string Name() override;
				};

				class Primo : public IDumb
				{
				public:
					std::string Name() override;
				};

				class Genie : public IDumb
				{
				public:
					std::string Name() override;
				};

	
#pragma endregion Product31

#pragma region Interface32
				class ISmart
				{
				public:
					virtual std::string Name() = 0;
				};

#pragma endregion Interface32

#pragma region Product32
				class GalaxyS2 : public ISmart
				{
				public:
					std::string Name() override;
				};

				class Titan : public ISmart
				{
				public:
					std::string Name() override;
				};

				class Lumia : public ISmart
				{
				public:
					std::string Name() override;
				};



#pragma endregion Product32

#pragma region Factory3
				class APhoneFactory
				{
				public:
					enum class PHONE_FACTORIES
					{
						SAMSUNG,
						HTC,
						NOKIA
					};

					virtual std::unique_ptr<ISmart> createSmart() = 0;
					virtual std::unique_ptr<IDumb> createDumb() = 0;

					static std::unique_ptr<APhoneFactory> create(const PHONE_FACTORIES& type);
				};

				class SamsungFactory : public APhoneFactory
				{
				public:
					std::unique_ptr<ISmart> createSmart() override;
					std::unique_ptr<IDumb> createDumb() override;
				};

				class HTCFactory : public APhoneFactory
				{
				public:
					std::unique_ptr<ISmart> createSmart() override;
					std::unique_ptr<IDumb> createDumb() override;
				};

				class NokiaFactory : public APhoneFactory
				{
				public:
					std::unique_ptr<ISmart> createSmart() override;
					std::unique_ptr<IDumb> createDumb() override;
				};
#pragma endregion Factory3

#pragma region User3
				void buildPhone(APhoneFactory& factory);
#pragma endregion User3
#pragma endregion Example3

#pragma region Example4

#pragma region Interface4
				class GUIComponent4 
				{
				public:
					virtual ~GUIComponent4() = default;
					virtual void draw() const = 0;
				};
#pragma endregion Interface4

#pragma region Product4
				class Frame4 : public GUIComponent4 {};
				class Button4 : public GUIComponent4 {};
				class Label4 : public GUIComponent4 {};
#pragma endregion Product4

#pragma region Factory4
				class GUIFactory4 
				{
				public:
					enum class GUI_FACTORIES
					{
						WINDOWS4,
						LINUX4
					};
					virtual ~GUIFactory4() = default;
					virtual std::unique_ptr<Frame4> createFrame() = 0;
					virtual std::unique_ptr<Button4> createButton() = 0;
					virtual std::unique_ptr<Label4> createLabel() = 0;
					static std::unique_ptr<GUIFactory4> create(const GUI_FACTORIES& type);
				};

				/* Windows support */
				class WindowsFactory4 : public GUIFactory4 
				{
				private:
					class WindowsFrame4 : public Frame4 
					{
					public:
						void draw() const override;
					};
					class WindowsButton4 : public Button4 
					{
					public:
						void draw() const override;
					};
					class WindowsLabel4 : public Label4 
					{
					public:
						void draw() const override;
					};
				public:
					std::unique_ptr<Frame4> createFrame() override;
					std::unique_ptr<Button4> createButton() override;
					std::unique_ptr<Label4> createLabel() override;
				};

				/* Linux support */
				class LinuxFactory4 : public GUIFactory4 
				{
				private:
					class LinuxFrame4 : public Frame4 
					{
					public:
						void draw() const override;
					};
					class LinuxButton4 : public Button4 
					{
					public:
						void draw() const override;
					};
					class LinuxLabel4 : public Label4 
					{
					public:
						void draw() const override;
					};
				public:
					std::unique_ptr<Frame4> createFrame() override;
					std::unique_ptr<Button4> createButton() override;
					std::unique_ptr<Label4> createLabel() override;
				};

#pragma endregion Factory4
#pragma region User4
				/* User code */
				void buildGUI(GUIFactory4& factory);
#pragma endregion User4

#pragma endregion Example4

#pragma region Example5


#pragma region Interface51
				class Bgcolor5
				{
				public:
					virtual std::string setBg() = 0;

				};
#pragma endregion Interface51
#pragma region Product51
				class LightBgColour5 : public Bgcolor5
				{
				public:
					std::string setBg() override;

				};

				class DarkBgColour5 : public Bgcolor5
				{
				public:
					std::string setBg() override;

				};
#pragma endregion Product51

#pragma region Interface52
				class Text5
				{
				public:
					virtual std::string setTxt() = 0;
					virtual std::string interact(Bgcolor5& interactor) = 0;

				};
#pragma endregion Interface52
#pragma region Product52
				class LightText5 : public Text5
				{
				public:
					std::string setTxt() override;
					std::string interact(Bgcolor5& interactor) override;

				};

				class DarkText5 : public Text5
				{
				public:
					std::string setTxt() override;
					std::string interact(Bgcolor5& interactor) override;

				};
#pragma endregion Product52


#pragma region Factory5
				class ThemeFactory5
				{
				public:
					enum class THEME_FACTORIES
					{
						LIGHT5,
						DARK5
					};
					virtual ~ThemeFactory5() = default;
					virtual std::unique_ptr<Bgcolor5> createBg() = 0;
					virtual std::unique_ptr<Text5> createTxt() = 0;
					static std::unique_ptr<ThemeFactory5> create(const THEME_FACTORIES& type);
				};				
				
				class LightFactory5 : public ThemeFactory5
				{
				public:
					std::unique_ptr<Bgcolor5> createBg() override;
					std::unique_ptr<Text5> createTxt() override;

				};				
				class DarkFactory5 : public ThemeFactory5
				{
				public:
					std::unique_ptr<Bgcolor5> createBg() override;
					std::unique_ptr<Text5> createTxt() override;

				};

#pragma endregion Factory5
#pragma region User5
				/* User code */
				void buildTheme(ThemeFactory5& factory);
#pragma endregion User5

#pragma endregion Example5
			}
		}
	}
}