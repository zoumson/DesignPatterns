#pragma once
#include "DPUtilities.h"

/*
* Structural PATTERN
* 4. Decorator
* Intent: Lets you attach new behaviors to objects by placing these objects
* inside special wrapper objects that contain the behaviors.
*/

namespace za
{
	namespace dp
	{
		namespace structural
		{
			namespace dco
			{
#pragma region Example1
				class InterfaceD1 
				{
				public:
					virtual ~InterfaceD1() { };
					virtual void write(std::string&) = 0;
				};

				class CoreD1 : public InterfaceD1
				{
				public:
					~CoreD1();
					void write(std::string& text) override;  // Do nothing.
				};

				class DecoratorD1 : public InterfaceD1
				{
				private:
					std::unique_ptr<InterfaceD1> interface;
				public:
					DecoratorD1(std::unique_ptr<InterfaceD1> c);
					void write(std::string& text) override;
				};

				class MessengerWithSalutationD1 : public DecoratorD1 
				{
				private:
					std::string salutation;
				public:
					MessengerWithSalutationD1(std::unique_ptr<InterfaceD1> c, const std::string& str);
					~MessengerWithSalutationD1();
					void write(std::string& text) override;
				};

				class MessengerWithValedictionD1 : public DecoratorD1 
				{
				private:
					std::string valediction;
				public:
					MessengerWithValedictionD1(std::unique_ptr<InterfaceD1> c, const std::string& str);
					~MessengerWithValedictionD1();
					void write(std::string& text) override;
				};

#pragma endregion Example1

#pragma region Example2
				/**
				 * The base Component interface defines operations that can be altered by
				 * decorators.
				 */
				class ComponentD2 
				{
				public:
					virtual ~ComponentD2() {}
					virtual std::string Operation() const = 0;
				};
				/**
				 * Concrete Components provide default implementations of the operations.
				 * There might be several variations of these classes.
				 */
				class ConcreteComponentD2 : public ComponentD2 
				{
				public:
					std::string Operation() const override;
				};
				/**
				 * The base Decorator class follows the same interface as the other
				 * components. The primary purpose of this class is to define the wrapping
				 * interface for all concrete decorators. The default implementation of the
				 * wrapping code might include a field for storing a wrapped component and the
				 * means to initialize it.
				 */
				class DecoratorD2 : public ComponentD2 
				{
					/**
					   * @var Component
					   */
				protected:
					ComponentD2* component_;

				public:
					DecoratorD2(ComponentD2* component);
					/**
					   * The Decorator delegates all work to the wrapped component.
					   */
					std::string Operation() const override;
				};
				/**
				 * Concrete Decorators call the wrapped object and alter its result in some
				 * way.
				 */
				class ConcreteDecoratorAD2 : public DecoratorD2 
				{
					/**
					   * EN: Decorators may call parent implementation of the operation, instead
					   * of calling the wrapped object directly. This approach simplifies
					   * extension of decorator classes.
					   */
				public:
					ConcreteDecoratorAD2(ComponentD2* component);
					std::string Operation() const override;
				};
				/**
				 * Decorators can execute their behavior either before or after the call to
				 * a wrapped object.
				 */
				class ConcreteDecoratorBD2 : public DecoratorD2 
				{
				public:
					ConcreteDecoratorBD2(ComponentD2* component);
					std::string Operation() const override;
				};
				/**
				 * The client code works with all objects using the Component interface.
				 * This way it can stay independent of the concrete classes of components it
				 * works with.
				 */
				void ClientCodeD2(ComponentD2* component);

#pragma endregion Example2

#pragma region Example3

				class CarD3 //Our Abstract base class
				{
				protected:
					std::string _str;
				public:
					CarD3();

					virtual std::string getDescription();

					virtual double getCost() = 0;

					virtual ~CarD3();
				};

				class OptionsDecoratorD3 : public CarD3 //Decorator Base class
				{
				public:
					virtual std::string getDescription() = 0;

					virtual ~OptionsDecoratorD3();
				};

				class CarModel1D3 : public CarD3
				{
				public:
					CarModel1D3();
					double getCost() override;

					~CarModel1D3();
				};

				class NavigationD3 : public OptionsDecoratorD3
				{
					CarD3* _b;
				public:
					NavigationD3(CarD3* b);
					NavigationD3(NavigationD3& obj)
					{
						_b = obj._b;
					};
					NavigationD3& operator=(const NavigationD3& obj)
					{ 
						_b = obj._b; return *this; 
					}
					std::string getDescription() override;
					double getCost() override;
					~NavigationD3();
				};

				class PremiumSoundSystemD3 : public OptionsDecoratorD3
				{
					CarD3* _b;
				public:
					PremiumSoundSystemD3(CarD3* b);
					std::string getDescription() override;
					double getCost() override;
					~PremiumSoundSystemD3();
				};

				class ManualTransmissionD3 : public OptionsDecoratorD3
				{
					CarD3* _b;
				public:
					ManualTransmissionD3(CarD3* b);
					std::string getDescription() override;
					double getCost() override;
					~ManualTransmissionD3();
				};

				
#pragma endregion Example3

#pragma region Example4

				/**
				*The base Component interface defines operations that can be altered by
				* decorators.
				*/
				class ComponentD4
				{
				public:
					virtual ~ComponentD4() {};
					virtual std::string Operation() const = 0;
				};

				/**
				 * Concrete Components provide default implementations of the operations.
				 * There might be several variations of these classes.
				 */
				class ConcreteComponentD4 : public ComponentD4
				{
				public:
					std::string Operation() const override;
				};

				/**
				 * The base Decorator class follows the same interface as the other
				 * components. The primary purpose of this class is to define the wrapping
				 * interface for all concrete decorators. The default implementation of the
				 * wrapping code might include a field for storing a wrapped component and the
				 * means to initialize it.
				 */
				class DecoratorD4 : public ComponentD4
				{
					/**
					* @var Component
					*/
				protected:
					ComponentD4* component_;

				public:
					DecoratorD4(ComponentD4* component);
					/**
					* The Decorator delegates all work to the wrapped component.
					*/
					std::string Operation() const override;
				};

				/**
				 * Concrete Decorators call the wrapped object and alter its result in some
				 * way.
				 */
				class ConcreteDecoratorAD4 : public DecoratorD4
				{
					/**
					* Decorators may call parent implementation of the operation, instead
					* of calling the wrapped object directly. This approach simplifies
					* extension of decorator classes.
					*/
				public:
					ConcreteDecoratorAD4(ComponentD4* component);
					std::string Operation() const override;
				};

				/**
				 * Decorators can execute their behavior either before or after the call to
				 * a wrapped object.
				 */
				class ConcreteDecoratorBD4 : public DecoratorD4
				{
				public:
					ConcreteDecoratorBD4(ComponentD4* component);

					std::string Operation() const override;
				};

				/**
				 * The client code works with all objects using the Component interface.
				 * This way it can stay independent of the concrete classes of components it
				 * works with.
				 */
				void ClientCodeD4(ComponentD4* component);
#pragma endregion Example4

#pragma region Example5

				struct MoneyD5
				{
					uint64_t value{};
				};
				template<class T>
				concept cond = std::is_arithmetic_v<T>;
				template< cond T > 
				//template< typename T > /*requires std::is_arithmetic_v<T>*/
				MoneyD5 operator*(MoneyD5 money, T factor) 
				{
					return MoneyD5{ static_cast<uint64_t>(money.value * factor) };
				};

				constexpr MoneyD5 operator+(MoneyD5 lhs, MoneyD5 rhs) noexcept
				{
					return MoneyD5{ lhs.value + rhs.value };
				}

				static std::ostream& operator<<(std::ostream& os, MoneyD5 money)
				{
					return os << money.value;
				}

				class ItemD5
				{
				public:
					virtual ~ItemD5() = default;
					virtual MoneyD5 price() const = 0;
				};

				class DecoratedItemD5 : public ItemD5
				{
				public:
					explicit DecoratedItemD5(std::unique_ptr<ItemD5> item)
						: item_(std::move(item))
					{
						if (!item_) {
							throw std::invalid_argument("Invalid item");
						}
					}

				protected:
					ItemD5& item() { return *item_; }
					ItemD5 const& item() const { return *item_; }

				private:
					std::unique_ptr<ItemD5> item_;
				};

				class CppBookD5 : public ItemD5
				{
				public:
					CppBookD5(std::string title, MoneyD5 price)
						: title_{ std::move(title) }
						, price_{ price }
					{}

					std::string const& title() const { return title_; }
					MoneyD5 price() const override { return price_; }

				private:
					std::string title_{};
					MoneyD5 price_{};
				};

				class ConferenceTicketD5 : public ItemD5
				{
				public:
					ConferenceTicketD5(std::string name, MoneyD5 price)
						: name_{ std::move(name) }
						, price_{ price }
					{}

					std::string const& name() const { return name_; }
					MoneyD5 price() const override { return price_; }

				private:
					std::string name_{};
					MoneyD5 price_{};
				};

				class DiscountedD5 : public DecoratedItemD5
				{
				public:
					DiscountedD5(double discount, std::unique_ptr<ItemD5> item)
						: DecoratedItemD5(std::move(item))
						, factor_(1.0 - discount)
					{
						if (!std::isfinite(discount) || discount < 0.0 || discount > 1.0) {
							throw std::invalid_argument("Invalid discount");
						}
					}

					MoneyD5 price() const override
					{
						return item().price() * factor_;
					}

				private:
					double factor_;
				};

				class TaxedD5 : public DecoratedItemD5
				{
				public:
					TaxedD5(double taxRate, std::unique_ptr<ItemD5> item)
						: DecoratedItemD5(std::move(item))
						, factor_(1.0 + taxRate)
					{
						if (!std::isfinite(taxRate) || taxRate < 0.0) {
							throw std::invalid_argument("Invalid tax");
						}
					}

					MoneyD5 price() const override
					{
						return item().price() * factor_;
					}

				private:
					double factor_;
				};


#pragma endregion Example5
			}
		}
	}
}