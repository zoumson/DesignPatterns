#pragma once
#include "DPVisitor.h"




namespace za
{
	namespace dp
	{
        namespace behavioral
        {
            namespace vis
            {
#pragma region Example1

                void DatabaseVisitorV1::handlePerson(const std::string& name, int age)
                {
                    std::cout << "Writing person to database: " << name << ", " << age << "\n";
                };
                void DatabaseVisitorV1::handleLandmark(const std::string& name, const std::string& cityName)
                {
                    std::cout << "Writing landmark to database: " << name << ", " << cityName << "\n";
                };
                void DatabaseVisitorV1::handleCar(const std::string& make, const std::string& model)
                {
                    std::cout << "Writing car to database: " << make << ", " << model << "\n";
                };

                void TextFileVisitorV1::handlePerson(const std::string& name, int age)
                {
                    std::cout << "Writing person to file: " << name << ", " << age << "\n";
                };
                void TextFileVisitorV1::handleLandmark(const std::string& name, const std::string& cityName)
                {
                    std::cout << "Writing landmark to file: " << name << ", " << cityName << "\n";
                };
                void TextFileVisitorV1::handleCar(const std::string& make, const std::string& model)
                {
                    std::cout << "Writing car to file: " << make << ", " << model << "\n";
                };

                void PersonV1::accept(VisitorV1* v)
                {
                    v->handlePerson(name, age);
                };

                void LandmarkV1::accept(VisitorV1* v)
                {
                    v->handleLandmark(name, cityName);
                };

                void CarV1::accept(VisitorV1* v)
                {
                    v->handleCar(make, model);
                };

#pragma endregion Example1

#pragma region Example2
                CircleV2::CircleV2(double radius)
                    : radius_(radius)
                {
                    std::cout << "Checking that the given radius is valid" << std::endl;
                }
                double CircleV2::radius() const { return radius_; }
                PointV2  CircleV2::center() const { return center_; }

                SquareV2::SquareV2(double side)
                    : side_(side)
                {
                    std::cout << "Checking that the given side length is valid" << std::endl;
                }

                double SquareV2::side() const { return side_; }
                PointV2  SquareV2::center() const { return center_; }

                void DrawV2::operator()(CircleV2 const& c) const
                {
                    std::cout << "Implementing the logic for drawing a circle" << std::endl;
                }
                void DrawV2::operator()(SquareV2 const& s) const
                {
                    std::cout << "Implementing the logic for drawing a square" << std::endl;
                }

                void drawAllShapesV2(ShapesV2 const& shapes)
                {
                    for (auto const& shape : shapes)
                    {
                        std::visit(DrawV2{}, shape);
                    }
                }


#pragma endregion Example2

#pragma region Example3
                //Cyclic Visitor
                CircleV3::CircleV3(double radius)
                    : radius_(radius)
                {
                    std::cout << "Checking that the given radius is valid" << std::endl;
                };
                void CircleV3::accept(ShapeVisitorV3 const& v)
                {
                    v.visit(*this);
                };
                double CircleV3::radius() const
                {
                    return radius_;
                };

                SquareV3::SquareV3(double side)
                    : side_(side)
                {
                    std::cout << "Checking that the given side length is valid" << std::endl;
                };
                void SquareV3::accept(ShapeVisitorV3 const& v)
                {
                    v.visit(*this);
                };
                double SquareV3::side() const 
                { 
                    return side_; 
                }
                
                void DrawV3::visit(CircleV3 const& c /*, ...*/) const
                {
                    std::cout << "Implementing the logic for drawing a circle" << std::endl;
                }
                void DrawV3::visit(SquareV3 const& s /*, ...*/) const
                {
                    std::cout << "Implementing the logic for drawing a square" << std::endl;
                };

                void drawAllShapesV3(std::vector<std::unique_ptr<ShapeV3>> const& shapes)
                {
                    for (auto const& shape : shapes)
                    {
                        shape->accept(DrawV3{});
                    }
                };
#pragma endregion Example3

            }
        }
	}
}