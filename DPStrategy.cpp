#pragma once
#include "DPStrategy.h"

namespace za
{
	namespace dp
	{
        namespace behavioral
        {
            namespace str
            {
#pragma region Example1

                void FormalGreetingStrategyS1::greet(const std::string& name)
                {
                    std::cout << "Good morning " << name << ", how do you do?\n";
                }
                void NormalGreetingStrategyS1::greet(const std::string& name)
                {
                    std::cout << "Hi " << name << ", how are you?\n";
                }
                void InformalGreetingStrategyS1::greet(const std::string& name)
                {
                    std::cout << "Hey " << name << ", what's up?\n";
                }
                PersonS1::~PersonS1()
                {
                    delete greetingStrategy;
                };
                void PersonS1::greet(const std::string& name)
                {
                    greetingStrategy->greet(name);
                }

#pragma endregion Example2

#pragma region Example2

                CircleS2::CircleS2(double radius, std::unique_ptr<DrawCircleStrategyS2> drawer)
                    : radius_(radius)
                    , drawer_(std::move(drawer))
                {
                    std::cout << "Checking that the given radius is valid and that \
                         the given 'std::unique_ptr' is not a nullptr " << std::endl;
                }
                void CircleS2::draw( /*some arguments*/) const 
                {
                    drawer_->draw(*this /*, some arguments*/);
                }
                double CircleS2::radius() const 
                { 
                    return radius_; 
                }
                
                SquareS2::SquareS2(double side, std::unique_ptr<DrawSquareStrategyS2> drawer)
                    : side_(side)
                    , drawer_(std::move(drawer))
                {
                    std::cout << "Checking that the given side length is valid and that \
                         the given 'std::unique_ptr' is not a nullptr " << std::endl;
                }
                void SquareS2::draw( /*some arguments*/) const
                {
                    drawer_->draw(*this /*, some arguments*/);
                }
                double SquareS2::side() const
                { 
                    return side_;
                }

                void drawAllShapesS2(std::vector<std::unique_ptr<ShapeS2>> const& shapes)
                {
                    for (auto const& shape : shapes)
                    {
                        shape->draw( /*some arguments*/);
                    }
                }

                void OpenGLCircleStrategyS2::draw(CircleS2 const& circle /*, ...*/) const
                {
                    std::cout << "Implementing the logic for drawing a circle by means of OpenGL" << std::endl;
                }
                
                void OpenGLSquareStrategyS2::draw(SquareS2 const& square /*, ...*/) const
                {
                    std::cout << "Implementing the logic for drawing a square by means of OpenGL" << std::endl;
                }

#pragma endregion Example2

#pragma region Example3

                CircleS3::CircleS3(double radius, DrawStrategyS3 drawer)
                    : radius_(radius)
                    , drawer_(std::move(drawer))
                {
                    std::cout << "Checking that the given radius is valid and that \
                         the given 'std::function' instance is not empty " << std::endl;
                }
                void CircleS3::draw( /*some arguments*/) const
                {
                    drawer_(*this /*, some arguments*/);
                }
                double CircleS3::radius() const
                {
                    return radius_;
                }


                SquareS3::SquareS3(double side, DrawStrategyS3 drawer)
                    : side_(side)
                    , drawer_(std::move(drawer))
                {
                    std::cout << "Checking that the given side length is valid and that \
                         the given 'std::function' instance is not empty " << std::endl;
                }
                void SquareS3::draw( /*some arguments*/) const
                {
                    drawer_(*this /*, some arguments*/);
                }
                double SquareS3::side() const
                {
                    return side_;
                }

                void OpenGLCircleStrategyS3::operator()(CircleS3 const& circle /*, ...*/) const
                {
                    std::cout << "Implementing the logic for drawing a circle by means of OpenGL" << std::endl;
                }

                void OpenGLSquareStrategyS3::operator()(SquareS3 const& square /*, ...*/) const
                {
                    std::cout << "Implementing the logic for drawing a square by means of OpenGL" << std::endl;
                }
#pragma endregion Example3

            }
        }
	}
}