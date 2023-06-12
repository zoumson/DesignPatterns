#pragma once
#include "DPComposite.h"

/*
* Structural PATTERN
* 3. Composite
*/

namespace za
{
	namespace dp
	{
		namespace structural
		{
			namespace cmp
			{

#pragma region Example1

				//void EllipseC1::print() const
				//{
				//	std::cout << "Ellipse " << std::endl;
				//}
				//
				//void CompositeGraphicC1::print() const
				//{
				//	for (GraphicC1* a : graphicList_) 
				//	{
				//		a->print();
				//	}
				//}

				//void CompositeGraphicC1::add(GraphicC1* aGraphic)
				//{
				//	graphicList_.push_back(aGraphic);
				//}

#pragma endregion Example1

#pragma region Example2
                void ComponentC2::SetParent(ComponentC2* parent)
                {
                    this->parent_ = parent;
                }
                ComponentC2* ComponentC2::GetParent() const
                {
                    return this->parent_;
                }
                bool ComponentC2::IsComposite() const 
                {
                    return false;
                }
                
                std::string LeafC2::Operation() const 
                {
                    return "Leaf";
                }
               
                void CompositeC2::Add(ComponentC2* component)
                {
                    this->children_.push_back(component);
                    component->SetParent(this);
                }
                void CompositeC2::Remove(ComponentC2* component)
                {
                    children_.remove(component);
                    component->SetParent(nullptr);
                }
                bool CompositeC2::IsComposite() const 
                {
                    return true;
                }
                std::string CompositeC2::Operation() const 
                {
                    std::string result;
                    for (const ComponentC2* c : children_) 
                    {
                        if (c == children_.back()) 
                        {
                            result += c->Operation();
                        }
                        else 
                        {
                            result += c->Operation() + "+";
                        }
                    }
                    return "Branch(" + result + ")";
                }
                
                void ClientCode1C2(ComponentC2* component)
                {
                    std::cout << "RESULT: " << component->Operation();
                }
                void ClientCode2C2(ComponentC2* component1, ComponentC2* component2)
                {
                    if (component1->IsComposite()) 
                    {
                        component1->Add(component2);
                    }
                    std::cout << "RESULT: " << component1->Operation();
                }

#pragma endregion Example2

#pragma region Example3

                ComponentC3* ComponentC3::getChild(int)
                {
                    return 0;
                }
                void ComponentC3::add(ComponentC3*) {};
                void ComponentC3::remove(int idx) {};

                CompositeC3::~CompositeC3()
                {
                    for (unsigned int i = 0; i < children.size(); i++)
                    {
                        delete children[i];
                    }
                };
                ComponentC3* CompositeC3::getChild(int index)
                {
                    return children[index];
                }
                void CompositeC3::add(ComponentC3* component)
                {
                    children.push_back(component);
                }
                void CompositeC3::remove(int index)
                {
                    ComponentC3* child = children[index];
                    children.erase(children.begin() + index);
                    delete child;
                }
                void  CompositeC3::operation()
                {
                    for (unsigned int i = 0; i < children.size(); i++)
                    {
                        children[i]->operation();
                    }
                }

                LeafC3::LeafC3(const int i) : id(i) {};
                void LeafC3::operation()
                {
                    std::cout << "Leaf " << id << " operation" << std::endl;
                }
               
#pragma endregion Example3

#pragma region Example4

#pragma endregion Example4

#pragma region Example5


#pragma endregion Example5

#pragma region Example6
#pragma endregion Example6
			}
		}
	}
}
