#pragma once
#include "DPUtilities.h"
/*
3. Mediator design pattern
a. Manager
b. When you need to reduce coupling and organize complex 
	dependencies between a number of tightly coupled classes

c. Instead of having each class know about the other classes, 
d. create a mediator object that manages all the relationships betweeen these classes
*/

namespace za
{
	namespace dp
	{
        namespace behavioral
        {
            namespace med
            {

                class Mediator
                {
                public:
                    virtual void mediate(const std::string& event) = 0;
                };

                class InterfaceElement
                {
                protected:
                    Mediator* mediator;
                    std::string name;
                    bool isVisible = true;
                public:
                    InterfaceElement(const std::string& name, bool isVisible, Mediator* mediator) : name(name), isVisible(isVisible), mediator(mediator) {};
                    void setVisibility(bool isVisible);
                    std::string getDescription();

                };

                class ButtonElement : public InterfaceElement
                {
                public:
                    ButtonElement(const std::string& name, bool isVisible, Mediator* mediator) : InterfaceElement(name, isVisible, mediator) {};
                    virtual ~ButtonElement() {};
                    virtual void click();
                };

                class TextBox : public InterfaceElement
                {
                    std::string textValue = "";
                public:
                    TextBox(const std::string& name, bool isVisible, Mediator* mediator) : InterfaceElement(name, isVisible, mediator) {};
                    virtual ~TextBox() {};
                    virtual void changeText(const std::string& newValue);
                };

                class CheckBox : public InterfaceElement
                {
                    bool isChecked = false;
                public:
                    CheckBox(const std::string& name, bool isVisible, Mediator* mediator) : InterfaceElement(name, isVisible, mediator) {};
                    virtual ~CheckBox() {};
                    virtual void setIsChecked(bool isChecked);
                };

                class UserInterface : public Mediator
                {
                    TextBox* nameTextBox;
                    CheckBox* isMarriedCheckbox;
                    TextBox* spousesNameTextBox;
                    ButtonElement* submitButton;
                public:
                    UserInterface();
                    ~UserInterface();
                    void mediate(const std::string& event);
                    TextBox* getNameTextBox();
                    CheckBox* getIsMarriedCheckbox();
                    TextBox* getSpousesNameTextBox();
                    ButtonElement* getSubmitButton();
                };
            }
        }
	}
}
