#include "DPObserver.h"

namespace za
{
	namespace dp
	{
        namespace behavioral
        {
            namespace ob
            {

#pragma region Example1

                void ChatGroupO1::subscribe(SubscriberO1* subscriber)
                {
                    this->subscribers.push_back(subscriber);
                };
                void ChatGroupO1::unsubscribe(SubscriberO1* subscriber)
                {
                    subscribers.erase(std::remove_if(subscribers.begin(), subscribers.end(),
                        [subscriber](SubscriberO1* s)
                        {
                            return s->getName() == subscriber->getName();
                        }), subscribers.end());
                };
                void ChatGroupO1::publish(const std::string& message)
                {
                    for (auto subscriber : subscribers)
                    {
                        subscriber->notify(groupName, message);
                    }
                };
                void ChatUserO1::notify(const std::string& publisherName, const std::string& message)
                {
                    std::cout << userName << " received a new message from " << publisherName << ": " << message << std::endl;
                }
                std::string ChatUserO1::getName()
                {
                    return userName;
                };

#pragma endregion Example1

#pragma region Example2
				/*
				void PersonO2::forename(std::string newForename)
				{
					forename_ = std::move(newForename);
					notify(StateChange::forenameChanged);
				}
				void PersonO2::surname(std::string newSurname)
				{
					surname_ = std::move(newSurname);
					notify(StateChange::surnameChanged);
				}
				void PersonO2::address(std::string newAddress)
				{
					address_ = std::move(newAddress);
					notify(StateChange::addressChanged);
				}
				std::string const& PersonO2::forename() const
				{
					return forename_;
				}
				std::string const& PersonO2::surname() const
				{
					return surname_;
				}
				std::string const& PersonO2::address() const
				{
					return address_;
				}
				bool PersonO2::attach(PersonObserverO2* observer)
				{
					auto [pos, success] = observers_.insert(observer);
					return success;
				}
				bool PersonO2::detach(PersonObserverO2* observer)
				{
					return (observers_.erase(observer) > 0U);
				}
				void PersonO2::notify(StateChange property)
				{
					// This formulation makes sure detach() operations
					// can be detected during the iteration
					for (auto iter = std::begin(observers_); iter != std::end(observers_); )
					{
						auto const pos = iter++;
						(*pos)->update(*this, property);
					}
				}

				void NameObserverO2::update(PersonO2 const& person, PersonO2::StateChange property)
				{
					if (property == PersonO2::StateChange::forenameChanged ||
						property == PersonO2::StateChange::surnameChanged)
					{
						std::cout << "Respond to changed name" << std::endl;
					}
				}

				void AddressObserverO2::update(PersonO2 const& person, PersonO2::StateChange property)
				{
					if (property == PersonO2::StateChange::addressChanged)
					{
						std::cout << "Respond to changed address" << std::endl;
					}
				}

				*/
#pragma endregion Example2

#pragma region Example3

				PersonO3::PersonO3(std::string forename, std::string surname)
					: forename_{ std::move(forename) }
					, surname_{ std::move(surname) }
				{};
				void PersonO3::forename(std::string newForename)
				{
					forename_ = std::move(newForename);
					notify(StateChange::forenameChanged);
				}
				void PersonO3::surname(std::string newSurname)
				{
					surname_ = std::move(newSurname);
					notify(StateChange::surnameChanged);
				}
				void PersonO3::address(std::string newAddress)
				{
					address_ = std::move(newAddress);
					notify(StateChange::addressChanged);
				}
				std::string const& PersonO3::forename() const
				{
					return forename_;
				}
				std::string const& PersonO3::surname() const
				{
					return surname_;
				}
				std::string const& PersonO3::address() const
				{
					return address_;
				}
				bool PersonO3::attach(PersonObserverO3* observer)
				{
					auto [pos, success] = observers_.insert(observer);
					return success;
				}
				bool PersonO3::detach(PersonObserverO3* observer)
				{
					return (observers_.erase(observer) > 0U);
				}
				void PersonO3::notify(StateChange property)
				{
					// This formulation makes sure detach() operations
					// can be detected during the iteration
					for (auto iter = std::begin(observers_); iter != std::end(observers_); )
					{
						auto const pos = iter++;
						(*pos)->update(*this, property);
					}
				}

				void propertyChangedO3(PersonO3 const& person, PersonO3::StateChange property) 
				{
					if (property == PersonO3::StateChange::forenameChanged ||
						property == PersonO3::StateChange::surnameChanged)
					{
						std::cout << "Respond to changed name" << std::endl;
					}
				}


#pragma endregion Example3


            }
        }
	}
}