#pragma once
#include "DPUtilities.h"

/*
10. Visitor design pattern


*/

namespace za
{
	namespace dp
	{
        namespace behavioral
        {
            namespace vis
            {
#pragma region Example1

                class VisitorV1
                {
                public:
                    virtual void handlePerson(const std::string& name, int age) = 0;
                    virtual void handleLandmark(const std::string& name, const std::string& cityName) = 0;
                    virtual void handleCar(const std::string& make, const std::string& model) = 0;
                };

                class DatabaseVisitorV1 : public VisitorV1
                {
                public:
                    void handlePerson(const std::string& name, int age) override;
                    void handleLandmark(const std::string& name, const std::string& cityName) override;
                    void handleCar(const std::string& make, const std::string& model) override;
                };

                class TextFileVisitorV1 : public VisitorV1
                {
                public:
                    void handlePerson(const std::string& name, int age) override;
                    void handleLandmark(const std::string& name, const std::string& cityName) override;
                    void handleCar(const std::string& make, const std::string& model) override;
                };

                class PersonV1
                {
                    std::string name;
                    int age;
                public:
                    PersonV1(const std::string& name, int age) : name(name), age(age) {};
                    void accept(VisitorV1* v);
                };

                class LandmarkV1
                {
                    std::string name;
                    std::string cityName;
                public:
                    LandmarkV1(const std::string& name, const std::string& cityName) : name(name), cityName(cityName) {};
                    void accept(VisitorV1* v);
                };

                class CarV1
                {
                    std::string make;
                    std::string model;
                public:
                    CarV1(const std::string& make, const std::string& model) : make(make), model(model) {};
                    void accept(VisitorV1* v);
                };

#pragma endregion Example1

#pragma region Example2
                // Variant visitor
                struct PointV2
                {
                    double x;
                    double y;
                };

                class CircleV2
                {
                public:
                    explicit CircleV2(double radius);

                    double radius() const;
                    PointV2  center() const;

                private:
                    double radius_;
                    PointV2 center_{};
                };
                class SquareV2
                {
                public:
                    explicit SquareV2(double side);

                    double side() const;
                    PointV2  center() const;

                private:
                    double side_;
                    PointV2 center_{};
                };

                class DrawV2
                {
                public:
                    void operator()(CircleV2 const& c) const;
                    void operator()(SquareV2 const& s) const;
                };
               
                using ShapeV2 = std::variant<CircleV2, SquareV2>;
                using ShapesV2 = std::vector<ShapeV2>;
                void drawAllShapesV2(ShapesV2 const& shapes);

#pragma endregion Example2

#pragma region Example3
                //Cyclic Visitor
                class CircleV3;
                class SquareV3;

                class ShapeVisitorV3
                {
                public:
                    virtual ~ShapeVisitorV3() = default;

                    virtual void visit(CircleV3 const& /*, ...*/) const = 0;
                    virtual void visit(SquareV3 const& /*, ...*/) const = 0;
                    // Possibly more visit() functions, one for each concrete shape
                };
                class ShapeV3
                {
                public:
                    virtual ~ShapeV3() = default;
                    virtual void accept(ShapeVisitorV3 const& v) = 0;
                };

                class CircleV3 : public ShapeV3
                {
                public:
                    explicit CircleV3(double radius);
                    void accept(ShapeVisitorV3 const& v);
                    double radius() const;

                private:
                    double radius_;
                };

                class SquareV3 : public ShapeV3
                {
                public:
                    explicit SquareV3(double side);

                    void accept(ShapeVisitorV3 const& v) override;

                    double side() const;

                private:
                    double side_;
                };

                class DrawV3 : public ShapeVisitorV3
                {
                public:
                    void visit(CircleV3 const& c /*, ...*/) const override;

                    void visit(SquareV3 const& s /*, ...*/) const override;
                };

                void drawAllShapesV3(std::vector<std::unique_ptr<ShapeV3>> const& shapes);
#pragma endregion Example3

#pragma region Example4

                //Acyclic Visitor
                class AbstractVisitorV4
                {
                public:
                    virtual ~AbstractVisitorV4() = default;
                };

                template< typename T >
                class VisitorV4
                {
                protected:
                    virtual ~VisitorV4() = default;

                public:
                    virtual void visit(T const&) const = 0;
                };

                class ShapeV4
                {
                public:
                    virtual ~ShapeV4() = default;

                    virtual void accept(AbstractVisitorV4 const& v) = 0;
                };
                class CircleV4 : public ShapeV4
                {
                public:
                    explicit CircleV4(double radius);
                    void accept(AbstractVisitorV4 const& v) override;
                    double radius() const;

                private:
                    double radius_;
                };
                class SquareV4 : public ShapeV4
                {
                public:
                    explicit SquareV4(double side);

                    void accept(AbstractVisitorV4 const& v) override;

                    double side() const;

                private:
                    double side_;
                };

                class DrawV4 : public AbstractVisitorV4
                    , public VisitorV4<CircleV4>
                    , public VisitorV4<SquareV4>
                {
                public:
                    void visit(CircleV4 const& c) const override;
                    void visit(SquareV4 const& s) const override;
                };

                void drawAllShapes(std::vector< std::unique_ptr<ShapeV4> > const& shapes);
#pragma endregion Example4
            }
        }
	}
}
