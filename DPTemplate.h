#pragma once
#include "DPUtilities.h"

/*
9. Template design pattern


*/

namespace za
{
	namespace dp
	{
		namespace tmp
		{
            class GreetingCardTemplate 
            {
            protected:
                virtual std::string intro(const std::string& to);
                virtual std::string occasion();
                virtual std::string closing(const std::string& from);
            public:
                std::string generate(const std::string& to, const std::string& from);
            };

            class BirthdayCardTemplate : public GreetingCardTemplate 
            {
            protected:
                std::string occasion() override;
            };

            class NewYearsCardTemplate : public GreetingCardTemplate 
            {
            protected:
                std::string intro(const std::string& to) override;
                std::string occasion() override;
            };
		}
	}
}