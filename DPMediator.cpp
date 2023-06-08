#include "DPMediator.h"

namespace za
{
	namespace dp
	{	
        namespace behavioral
        {
            namespace med
            {

                void InterfaceElement::setVisibility(bool isVisible)
                {
                    this->isVisible = isVisible;
                };
                std::string InterfaceElement::getDescription()
                {
                    return isVisible
                        ? name + " is visible"
                        : name + " is NOT visible";
                }

                void ButtonElement::click()
                {
                    mediator->mediate(name + " clicked");
                };

                void TextBox::changeText(const std::string& newValue)
                {
                    textValue = newValue;
                    if (newValue.empty())
                    {
                        mediator->mediate(name + " empty");
                    }
                    else
                    {
                        mediator->mediate(name + " not empty");
                    }
                };

                void CheckBox::setIsChecked(bool isChecked)
                {
                    this->isChecked = isChecked;

                    if (isChecked)
                    {
                        mediator->mediate(name + " is checked");
                    }
                    else
                    {
                        mediator->mediate(name + " is unchecked");
                    }
                }

                UserInterface::UserInterface()
                {
                    nameTextBox = new TextBox("Name textbox", true, this);
                    isMarriedCheckbox = new CheckBox("Is married checkbox", true, this);
                    spousesNameTextBox = new TextBox("Spouse's name textbox", false, this);
                    submitButton = new ButtonElement("Submit button", false, this);
                };
                UserInterface::~UserInterface()
                {
                    delete nameTextBox;
                    delete isMarriedCheckbox;
                    delete spousesNameTextBox;
                    delete submitButton;
                };
                void UserInterface::mediate(const std::string& event)
                {
                    std::cout << "Mediating event: " << event << "...\n";

                    if (event == "Name textbox is empty")
                    {
                        submitButton->setVisibility(false);
                    }
                    else if (event == "Name textbox is not empty")
                    {
                        submitButton->setVisibility(true);
                    }
                    else if (event == "Is married checkbox is checked")
                    {
                        spousesNameTextBox->setVisibility(true);
                    }
                    else if (event == "Is married checkbox is unchecked")
                    {
                        spousesNameTextBox->setVisibility(false);
                    }
                    else if (event == "Submit button clicked")
                    {
                        std::cout << "Submitted!\n";
                    }
                    else
                    {
                        std::cout << "Unrecognized event!";
                    }
                }
                TextBox* UserInterface::getNameTextBox()
                {
                    return nameTextBox;
                };
                CheckBox* UserInterface::getIsMarriedCheckbox()
                {
                    return isMarriedCheckbox;
                };
                TextBox* UserInterface::getSpousesNameTextBox()
                {
                    return spousesNameTextBox;
                };
                ButtonElement* UserInterface::getSubmitButton()
                {
                    return submitButton;
                };




            }
        }
	}
}