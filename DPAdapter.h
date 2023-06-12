#pragma once
#include "DPUtilities.h"

/*
* Structural PATTERN
* 1. Adapter
* Adapter Design PATTERN
*
* Intent: Provides a unified interface that allows objects with incompatible
* interfaces to collaborate.
*/

namespace za
{
	namespace dp
	{
		namespace structural
		{
			namespace adp
			{


#pragma region Example1
				//Normal
				class DogA1 
				{  // Abstract Target
				public:
					virtual ~DogA1() = default;
					virtual void performsConversion() const = 0;
				};

				class DogFemaleS1 : public DogA1 
				{  // Concrete Target
				public:
					void performsConversion() const override;
				};

				class CatA1 
				{  // Abstract Adaptee
				public:
					virtual ~CatA1() = default;
					virtual void performsConversion() const = 0;
				};

				class CatFemaleA1 : public CatA1 {  // Concrete Adaptee
				public:
					void performsConversion() const override;
				};

				class DogNatureA1 
				{
				public:
					void carryOutNature(DogA1* dog);
				};

				class ConversionAdapterA1 : public DogA1 
				{  // Adapter
				private:
					CatA1* cat;
				public:
					ConversionAdapterA1(CatA1* c);
					void performsConversion() const override;
				};

#pragma endregion Example1

#pragma region Example2
				//MultipleInheritance
				class TargetA2 
				{
				public:
					virtual ~TargetA2() = default;
					virtual std::string Request() const;
				};

				class AdapteeA2 
				{
				public:
					std::string SpecificRequest() const;
				};

				class AdapterA2 : public TargetA2, private AdapteeA2 
				{
				public:
					AdapterA2() {};
					std::string Request() const override;
				};

				void ClientCodeA2(const TargetA2* target); 
#pragma endregion Example2

#pragma region Example3
				//MultipleInheritance
				// Desired interface (Target)
				class RectangleA3
				{
				public:
					virtual void draw() = 0;
				};

				// Legacy component (Adaptee)
				class LegacyRectangleA3
				{
				public:
					LegacyRectangleA3(int x1, int y1, int x2, int y2);
					void oldDraw();
				private:
					int x1_;
					int y1_;
					int x2_;
					int y2_;
				};

				// Adapter wrapper
				class RectangleAdapterA3 : public RectangleA3, private LegacyRectangleA3
				{
				public:
					RectangleAdapterA3(int x, int y, int w, int h);
					void draw() override;
				};
#pragma endregion Example3

#pragma region Example4
				class TargetA3 
				{
				public:
					virtual ~TargetA3() = default;
					virtual std::string Request() const;
				};

				/**
				 * EN: The Adaptee contains some useful behavior, but its interface is
				 * incompatible with the existing client code. The Adaptee needs some adaptation
				 * before the client code can use it.
				 */
				class AdapteeA3 
				{
				public:
					std::string SpecificRequest() const;
				};

				/**
				 * The Adapter makes the Adaptee's interface compatible with the Target's
				 * interface.
				 */
				class AdapterA3 : public TargetA3 
				{
				private:
					AdapteeA3* adaptee_;

				public:
					AdapterA3(AdapteeA3* adaptee);
					std::string Request() const override;
				};

				/**
				* The client code supports all classes that follow the Target interface.
				*/
				void ClientCodeA3(const TargetA3* target);

#pragma endregion Example4

#pragma region Example5
				class PrintA5
				{


				public:

					virtual ~PrintA5();

					virtual void printWeak() const = 0;

					virtual void printStrong() const = 0;


				};
				class MessageDisplayA5
				{

				private:

					const std::string message;

				public:

					MessageDisplayA5(const std::string& message);

					virtual ~MessageDisplayA5();

					void displayWithHyphens() const;

					void displayWithBrackets() const;

					// ˅
				public:

				protected:

				private:
					MessageDisplayA5(const MessageDisplayA5&) = delete;
					MessageDisplayA5& operator=(const MessageDisplayA5&) = delete;
					MessageDisplayA5(MessageDisplayA5&&) = delete;
					MessageDisplayA5& operator=(MessageDisplayA5&&) = delete;

					// ˄
				};
				// Adapt the MessageDisplay interface to the Print interface.
				class PrintMessageDisplayA5 : public MessageDisplayA5, public PrintA5
				{

				public:

					PrintMessageDisplayA5(const std::string& message);

					~PrintMessageDisplayA5();

					void printWeak() const;

					void printStrong() const;


				private:
					PrintMessageDisplayA5(const PrintMessageDisplayA5&) = delete;
					PrintMessageDisplayA5& operator=(const PrintMessageDisplayA5&) = delete;
					PrintMessageDisplayA5(PrintMessageDisplayA5&&) = delete;
					PrintMessageDisplayA5& operator=(PrintMessageDisplayA5&&) = delete;

					// ˄
				};

#pragma endregion Example5

#pragma region Example6
				//Target Interface(New Interface)
				class ITargetA6 
				{
				public:
					virtual void process() = 0;
				};

				//Legacy Interface(Old Interface)
				class IAdapteeA6
				{
				public:
					virtual void foo(int data) = 0;
					virtual int bar() = 0;
				};

				//Legacy Concrete 
				class OldClassA6 : public IAdapteeA6
				{
					void foo(int data) override;
					int bar()  override;
				};

				//Adapter legacy to target 
				class AdapterA6: public ITargetA6
				{ 
				protected:
					IAdapteeA6* pAdaptee;

				public:

					AdapterA6(IAdapteeA6* pAdaptee);
					void process() override;

				};

#pragma endregion Example6
			}
		}
	}
}