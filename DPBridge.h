#pragma once
#include "DPUtilities.h"

/*
* Structural Pattern
2. Bridge
 * EN: Bridge Design Pattern
 *
 * Intent: Lets you split a large class or a set of closely related classes into
 * two separate hierarchies—abstraction and implementation—which can be
 * developed independently of each other.
 *
 *               A
 *            /     \                        A         N
 *          Aa      Ab        ===>        /     \     / \
 *         / \     /  \                 Aa(N) Ab(N)  1   2
 *       Aa1 Aa2  Ab1 Ab2
 *
*/

namespace za
{
	namespace dp
	{
		namespace structural
		{
			namespace bd
			{

#pragma region Example1
				/*
				* The Implementation defines the interface for all implementation classes.
				* It doesn't have to match the Abstraction's interface. In fact, the two
				* interfaces can be entirely different. Typically the Implementation interface
				* provides only primitive operations, while the Abstraction defines higher-
				* level operations based on those primitives.
				*/

				class ImplementationB1 
				{
				public:
					virtual ~ImplementationB1() {}
					virtual std::string OperationImplementation() const = 0;
				};

				/*
				* Each Concrete Implementation corresponds to a specific platform and
				* implements the Implementation interface using that platform's API.
				*/
				class ConcreteImplementationAB1 : public ImplementationB1 
				{
				public:
					std::string OperationImplementation() const override;
				};
				class ConcreteImplementationBB1 : public ImplementationB1 
				{
				public:
					std::string OperationImplementation() const override;
				};

				/*
				* The Abstraction defines the interface for the "control" part of the two
				* class hierarchies. It maintains a reference to an object of the
				* Implementation hierarchy and delegates all of the real work to this object.
				*/

				class AbstractionB1 
				{
					/**
					   * @var Implementation
					   */
				protected:
					ImplementationB1* implementation_;

				public:
					AbstractionB1(ImplementationB1* implementation);

					virtual ~AbstractionB1() {};

					virtual std::string Operation() const;
				};

				/*
				* You can extend the Abstraction without changing the Implementation
				* classes.
				*/
				class ExtendedAbstractionB1 : public AbstractionB1 
				{
				public:
					ExtendedAbstractionB1(ImplementationB1* implementation);
					std::string Operation() const override;
				};
				/*
				* Except for the initialization phase, where an Abstraction object gets
				* linked with a specific Implementation object, the client code should only
				* depend on the Abstraction class. This way the client code can support any
				* abstraction-implementation combination.
				* The client code should be able to work with any pre-configured
				* abstraction-implementation combination.
				*/
				void ClientCodeB1(const AbstractionB1& abstraction);

#pragma endregion Example1

#pragma region Example2

				class DisplayImplB2
				{

				public:

					virtual ~DisplayImplB2();

					virtual void implOpen() const = 0;

					virtual void implWrite() const = 0;

					virtual void implClose() const = 0;

				};

				class TextDisplayImplB2 : public DisplayImplB2
				{


				private:

					// A string to display
					const std::string text;

					// A number of characters in bytes
					const int width;

				public:

					TextDisplayImplB2(const std::string& text);

					~TextDisplayImplB2();

					void implOpen() const;

					void implWrite() const;

					void implClose() const;

				private:

					void printLine() const;


				private:
					TextDisplayImplB2(const TextDisplayImplB2&) = delete;
					TextDisplayImplB2& operator=(const TextDisplayImplB2&) = delete;
					TextDisplayImplB2(TextDisplayImplB2&&) = delete;
					TextDisplayImplB2& operator=(TextDisplayImplB2&&) = delete;

					// ˄
				};

				class DisplayB2
				{

				private:

					const DisplayImplB2* impl;

				public:

					DisplayB2(const DisplayImplB2* impl);

					virtual ~DisplayB2();

					void output() const;

				protected:

					void open() const;

					void write() const;

					void close() const;


				private:
					DisplayB2(const DisplayB2&) = delete;
					DisplayB2& operator=(const DisplayB2&) = delete;
					DisplayB2(DisplayB2&&) = delete;
					DisplayB2& operator=(DisplayB2&&) = delete;

				};

				class MultiLineDisplayB2 : public DisplayB2
				{

				public:

					MultiLineDisplayB2(DisplayImplB2* impl);

					~MultiLineDisplayB2();

					// Repeat display for the specified number of times
					void outputMultiple(const int times) const;


				private:
					MultiLineDisplayB2(const MultiLineDisplayB2&) = delete;
					MultiLineDisplayB2& operator=(const MultiLineDisplayB2&) = delete;
					MultiLineDisplayB2(MultiLineDisplayB2&&) = delete;
					MultiLineDisplayB2& operator=(MultiLineDisplayB2&&) = delete;
				};

#pragma endregion Example2

#pragma region Example3

				/* Implementor*/
				class DrawingAPIB3 
				{
				public:
					virtual void drawCircle(double x, double y, double radius) = 0;
					virtual ~DrawingAPIB3() {}
				};

				/* Concrete ImplementorA*/
				class DrawingAPI1B3 : public DrawingAPIB3 
				{
				public:
					void drawCircle(double x, double y, double radius)override;
				};

				/* Concrete ImplementorB*/
				class DrawingAPI2B3 : public DrawingAPIB3 
				{
				public:
					void drawCircle(double x, double y, double radius)override;
				};

				/* Abstraction*/
				class ShapeB3 
				{
				public:
					virtual ~ShapeB3() {}
					virtual void draw() = 0;
					virtual void resizeByPercentage(double pct) = 0;
				};

				/* Refined Abstraction*/
				class CircleShapeB3 : public ShapeB3 
				{
				public:
					CircleShapeB3(double x, double y, double radius, DrawingAPIB3* drawingAPI);
					void draw() override;
					void resizeByPercentage(double pct) override;
				private:
					double m_x, m_y, m_radius;
					DrawingAPIB3* m_drawingAPI;
				};


#pragma endregion Example3

#pragma region Example4

#pragma endregion Example4

#pragma region Example5


#pragma endregion Example5

#pragma region Example6
#pragma endregion Example6
			}
		}
	}
}