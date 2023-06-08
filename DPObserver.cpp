#include "DPObserver.h"

namespace za
{
	namespace dp
	{
        namespace behavioral
        {
            namespace ob
            {

                void ChatGroup::subscribe(Subscriber* subscriber)
                {
                    this->subscribers.push_back(subscriber);
                };
                void ChatGroup::unsubscribe(Subscriber* subscriber)
                {
                    subscribers.erase(std::remove_if(subscribers.begin(), subscribers.end(),
                        [subscriber](Subscriber* s)
                        {
                            return s->getName() == subscriber->getName();
                        }), subscribers.end());
                };
                void ChatGroup::publish(const std::string& message)
                {
                    for (auto subscriber : subscribers)
                    {
                        subscriber->notify(groupName, message);
                    }
                };
                void ChatUser::notify(const std::string& publisherName, const std::string& message)
                {
                    std::cout << userName << " received a new message from " << publisherName << ": " << message << "\n";
                }
                std::string ChatUser::getName()
                {
                    return userName;
                };



            }
        }
	}
}