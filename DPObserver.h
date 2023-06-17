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
		namespace behavioral
		{
			namespace ob
			{
#pragma region Example1

				class SubscriberO1
				{
				public:
					virtual void notify(const std::string& publisherName, const std::string& message) = 0;
					virtual std::string getName() = 0;
				};

				class PublisherO1
				{
				public:
					virtual void subscribe(SubscriberO1* subscriber) = 0;
					virtual void unsubscribe(SubscriberO1* subscriber) = 0;
					virtual void publish(const std::string& message) = 0;
				};

				class ChatGroupO1 : public PublisherO1
				{
					std::string groupName;
					std::vector<SubscriberO1*> subscribers;
				public:
					ChatGroupO1(const std::string& name) : groupName(name) {};
					void subscribe(SubscriberO1* subscriber) override;
					void unsubscribe(SubscriberO1* subscriber) override;
					void publish(const std::string& message) override;
				};

				class ChatUserO1 : public SubscriberO1
				{
					std::string userName;
				public:
					ChatUserO1(const std::string& userName) : userName(userName) {};
					void notify(const std::string& publisherName, const std::string& message) override;
					std::string getName() override;
				};

#pragma endregion Example1

#pragma region Example2

				//Classic Observer
				template< typename SubjectO2, typename StateTag >
				class ObserverO2
				{
				public:
					virtual ~ObserverO2() = default;
					virtual void update(SubjectO2 const& subject, StateTag property) = 0;
				};

				class PersonO2
				{
				public:
					enum class StateChange
					{
						forenameChanged,
						surnameChanged,
						addressChanged
					};

					using PersonObserverO2 = ObserverO2<PersonO2, StateChange>;

					explicit PersonO2(std::string forename, std::string surname)
						: forename_{ std::move(forename) }
						, surname_{ std::move(surname) }
					{};

					void notify(StateChange property)
					{
						// This formulation makes sure detach() operations
						// can be detected during the iteration
						for (auto iter = std::begin(observers_); iter != std::end(observers_); )
						{
							auto const pos = iter++;
							(*pos)->update(*this, property);
						}
					}
					void forename(std::string newForename)
					{
						forename_ = std::move(newForename);
						notify(StateChange::forenameChanged);
					};
					void surname(std::string newSurname)
					{
						surname_ = std::move(newSurname);
						notify(StateChange::surnameChanged);
					};
					void address(std::string newAddress)
					{
						address_ = std::move(newAddress);
						notify(StateChange::addressChanged);
					};
					std::string const& forename() const
					{
						return forename_;
					}
					std::string const& surname() const
					{
						return surname_;
					}
					std::string const& address() const
					{
						return address_;
					}
					bool attach(PersonObserverO2* observer)
					{
						auto [pos, success] = observers_.insert(observer);
						return success;
					}
					bool detach(PersonObserverO2* observer)
					{
						return (observers_.erase(observer) > 0U);
					}

				private:
					std::string forename_;
					std::string surname_;
					std::string address_;

					std::set<PersonObserverO2*> observers_;
				};

				class NameObserverO2 : public ObserverO2<PersonO2, PersonO2::StateChange>
				{
				public:
					void update(PersonO2 const& person, PersonO2::StateChange property) override
					{
						if (property == PersonO2::StateChange::forenameChanged ||
							property == PersonO2::StateChange::surnameChanged)
						{
							std::cout << "Respond to changed name" << std::endl;
						}
					}
				};

				class AddressObserverO2 : public ObserverO2<PersonO2, PersonO2::StateChange>
				{
				public:
					void update(PersonO2 const& person, PersonO2::StateChange property) override
					{
						if (property == PersonO2::StateChange::addressChanged)
						{
							std::cout << "Respond to changed address" << std::endl;
						}
					}
				};


#pragma endregion Example2

#pragma region Example3

				template< typename Subject, typename StateTag >
				class ObserverO3
				{
				public:
					using OnUpdate = std::function<void(Subject const&, StateTag)>;

					// No virtual destructor necessary

					explicit ObserverO3(OnUpdate onUpdate)
						: onUpdate_{ std::move(onUpdate) }
					{
						std::cout << "std::function instance" << std::endl;
					}

					// Non-virtual update function
					void update(Subject const& subject, StateTag property)
					{
						onUpdate_(subject, property);
					}

				private:
					OnUpdate onUpdate_;
				};

				class PersonO3
				{
				public:
					enum class StateChange
					{
						forenameChanged,
						surnameChanged,
						addressChanged
					};

					using PersonObserverO3 = ObserverO3<PersonO3, StateChange>;

					explicit PersonO3(std::string forename, std::string surname);

					bool attach(PersonObserverO3* observer);
					bool detach(PersonObserverO3* observer);

					void notify(StateChange property);

					void forename(std::string newForename);
					void surname(std::string newSurname);
					void address(std::string newAddress);

					std::string const& forename() const;
					std::string const& surname() const;
					std::string const& address() const;

				private:
					std::string forename_;
					std::string surname_;
					std::string address_;

					std::set<PersonObserverO3*> observers_;
				};

				void propertyChangedO3(PersonO3 const& person, PersonO3::StateChange property);

#pragma endregion Example3

			}
		}
	}
}
