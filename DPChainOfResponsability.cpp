#include "DPChainOfResponsability.h"

namespace za
{
	namespace dp
	{
		namespace behavioral
		{
			namespace cr
			{
				//Concrete handlers
				// Class 1
				std::string NotEmptyValidator::validate(std::string testString)
				{
					std::cout << "Checking if empty..." << std::endl;
					if (testString.empty())
					{
						return "Please enter a value";
					}
					return BaseValidator::validate(testString);
				}
				// Class 2
				std::string LengthValidator::validate(std::string testString)
				{
					std::cout << "Checking string length..." << std::endl;
					if (testString.length() < minLength)
					{
						return "Please enter a value longer than " + std::to_string(minLength);
					}
					return BaseValidator::validate(testString);
				}
				// Class 2
				std::string RegexValidator::validate(std::string testString)
				{
					std::cout << "Checking regex match..." << std::endl;
					if (!std::regex_match(testString, std::regex(regexString)))
					{
						return "The value entered does not match the proper format for a " + patternName;
					}
					return BaseValidator::validate(testString);
				}
				// Class 3
				std::string HistoryValidator::validate(std::string testString)
				{
					std::cout << "Checking if string has been used before..." << std::endl;
					if (za::dp::com::inArray(testString, historyItems))
					{
						return "Please enter a value here that you haven't entered before";
					}
					return BaseValidator::validate(testString);
				}
			}
		}
	}
}