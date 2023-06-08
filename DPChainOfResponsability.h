#pragma once
#include "DPUtilities.h"

/* 
The chain of responsability 
- Implement a serie of nested handlers
- Check piece of criteria sequentially
- User authentification, check username, password and so on
- Naive: series of if statement
- Disadvantage: not reusable
*/



namespace za
{
	namespace dp
	{
		namespace behavioral
		{
			namespace cr
			{
				// handler interface
				// all virtual methods
				class StringValidator
				{
				public:
					virtual  ~StringValidator() {};
					virtual  StringValidator* setNext(StringValidator* nextValidator) = 0;
					virtual  std::string validate(std::string) = 0;
				};
				// base class for all handlers
				class BaseValidator : public StringValidator
				{
				protected:
					StringValidator* next = nullptr;
				public:
					virtual  ~BaseValidator() { delete next; };

					StringValidator* setNext(StringValidator* nextValidator) override
					{
						next = nextValidator;
						return nextValidator;
					}
					virtual  std::string validate(std::string testString) override
					{
						if (this->next)
						{
							return this->next->validate(testString);
						}

						return "Sucess";
					}
				};

				//Concrete handlers
				// Class 1
				class NotEmptyValidator : public BaseValidator
				{
				public:
					NotEmptyValidator() {};
					std::string validate(std::string testString) override;
				};

				// Class 2
				class LengthValidator : public BaseValidator
				{
					int minLength;
				public:
					LengthValidator(int _minLength) : minLength(_minLength) {};

					std::string validate(std::string testString) override;
				};
				// Class 2
				class RegexValidator : public BaseValidator
				{
					std::string patternName;
					std::string regexString;
				public:
					RegexValidator(std::string _patternName, std::string _regexString) : patternName(_patternName), regexString(_regexString) {};

					std::string validate(std::string testString) override;
				};


				// Class 3
				class HistoryValidator : public BaseValidator
				{
					std::vector<std::string> historyItems;
				public:
					HistoryValidator(std::vector<std::string> _historyItems) : historyItems(_historyItems) {};

					std::string validate(std::string testString) override;
				};
			}
		}
	}
}
