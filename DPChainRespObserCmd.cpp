#include "DPChainRespObserCmd.h"

namespace za
{
	namespace dp
	{
            std::string SendMessageCommand::getMessage()  
            { 
                return message; 
            };
            void SendMessageCommand::execute() 
            {
                chatGroup->publish(message);
            }

            BaseHandler::~BaseHandler() 
            { 
                delete next; 
            };
            Handler* BaseHandler::setNext(Handler * nextValidator)  
            {
                next = nextValidator;
                return nextValidator;
            }
            std::string BaseHandler::handle(MessageCommand* command)  
            {
                if (this->next) 
                {
                    return this->next->handle(command);
                }
                return "Success!";
            }
 
            std::string NotEmptyValidator::handle(MessageCommand* command)  
            {
                std::cout << "Checking if empty...\n";

                if (command->getMessage().empty()) 
                {
                    return "Please enter a value";
                }

                return BaseHandler::handle(command);
            }
        
            std::string LengthValidator::handle(MessageCommand* command)  
            {
                std::cout << "Checking if length equals" << minLength << "...\n";

                if (command->getMessage().length() < minLength) 
                {
                    return "Please enter a value longer than " + std::to_string(minLength);
                }

                return BaseHandler::handle(command);
            }

            std::string PostMessageHandler::handle(MessageCommand* command) 
            {
                command->execute();
                return "Message Sent!";
            }
 
	}
}