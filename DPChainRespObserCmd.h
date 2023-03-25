//#include "DPCommand.h"
//#include "DPChainOfResponsability.h"
#pragma once
#include "DPObserver.h"


/*
Chain of responsability
Command
Observer
*/

namespace za
{
	namespace dp
	{
        class MessageCommand 
        {
        public:
            virtual ~MessageCommand() {};
            virtual void execute() = 0;
            virtual std::string getMessage() = 0;
        };

        class SendMessageCommand : public MessageCommand 
        {
            ob::ChatGroup* chatGroup;
            std::string message;
        public:
            SendMessageCommand(ob::ChatGroup* chatGroup, std::string message) : chatGroup(chatGroup), message(message) {};
            std::string getMessage() override;
            void execute() override;
        };

        class Handler 
        {
        public:
            virtual Handler* setNext(Handler* nextValidator) = 0;
            virtual ~Handler() {};
            virtual std::string handle(MessageCommand* command) = 0;
        };

        class BaseHandler : public Handler 
        {
        protected:
            Handler* next = nullptr;
        public:
            ~BaseHandler();
            Handler* setNext(Handler* nextValidator) override;
            virtual std::string handle(MessageCommand* command) override;
        };

        class NotEmptyValidator : public BaseHandler 
        {
        public:
            std::string handle(MessageCommand* command) override;
        };

        class LengthValidator : public BaseHandler 
        {
            int minLength;
        public:
            LengthValidator(int minLength) : minLength(minLength) {};
            std::string handle(MessageCommand* command) override;
        };

        class PostMessageHandler : public BaseHandler 
        {
        public:
            std::string handle(MessageCommand* command);
        };
	}
}
