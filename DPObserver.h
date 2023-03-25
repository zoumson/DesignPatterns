#pragma once
#include "DPUtilities.h"
/*
4. Observer design pattern

When your program has a lot of different events that different 
objects need to react to, in other words, 
when we only want objects that care about certain events to be notified of their occurrence


Write our programs in terms of publisers and observers, 
where publisers simply publish events and observers can choose wheter not to listen 
*/

namespace za
{
	namespace dp
	{
		namespace ob
		{
			class Subscriber 
			 {
				public:
					virtual void notify(const std::string& publisherName, const std::string& message) = 0;
					virtual std::string getName() = 0;
			};

			class Publisher 
			{
				public:
					virtual void subscribe(Subscriber* subscriber) = 0;
					virtual void unsubscribe(Subscriber* subscriber) = 0;
					virtual void publish(const std::string& message) = 0;
			};

			class ChatGroup : public Publisher 
			{
				std::string groupName;
				std::vector<Subscriber*> subscribers;
			public:
				ChatGroup(const std::string& name) : groupName(name) {};
				void subscribe(Subscriber* subscriber) override;
				void unsubscribe(Subscriber* subscriber) override;
				void publish(const std::string& message) override;
			};

			class ChatUser : public Subscriber 
			{
				std::string userName;
			public:
				ChatUser(const std::string& userName) : userName(userName) {};
				void notify(const std::string& publisherName, const std::string& message) override;
				std::string getName() override;
			};


		}
	}
}
