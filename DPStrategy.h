#pragma once
#include "DPUtilities.h"
/*
6. Strategy design pattern


*/

namespace za
{
	namespace dp
	{
        namespace behavioral
        {
            namespace str
            {
#pragma region Example1

                class GreetingStrategyS1
                {
                public:
                    virtual ~GreetingStrategyS1() {};
                    virtual void greet(const std::string& name) = 0;
                };

                class FormalGreetingStrategyS1 : public GreetingStrategyS1
                {
                public:
                    void greet(const std::string& name) override;
                };

                class NormalGreetingStrategyS1 : public GreetingStrategyS1
                {
                public:
                    void greet(const std::string& name) override;
                };

                class InformalGreetingStrategyS1 : public GreetingStrategyS1
                {
                public:
                    void greet(const std::string& name) override;
                };

                class PersonS1
                {
                    GreetingStrategyS1* greetingStrategy;
                public:
                    PersonS1(GreetingStrategyS1* greetingStrategy) : greetingStrategy(greetingStrategy) {};
                    ~PersonS1();
                    void greet(const std::string& name);

                };


#pragma endregion Example1

#pragma region Example2

                //template
                class ShapeS2
                {
                public:
                    virtual ~ShapeS2() = default;

                    virtual void draw( /*some arguments*/) const = 0;
                };

                template< typename T >
                class DrawStrategyS2
                {
                public:
                    virtual ~DrawStrategyS2() = default;
                    virtual void draw(T const&) const = 0;
                };

                class CircleS2 : public ShapeS2
                {
                public:
                    using DrawCircleStrategyS2 = DrawStrategyS2<CircleS2>;

                    explicit CircleS2(double radius, std::unique_ptr<DrawCircleStrategyS2> drawer);
                    void draw( /*some arguments*/) const override;

                    double radius() const;

                private:
                    double radius_;
                    std::unique_ptr<DrawCircleStrategyS2> drawer_;
                };

                class SquareS2 : public ShapeS2
                {
                public:
                    using DrawSquareStrategyS2 = DrawStrategyS2<SquareS2>;

                    explicit SquareS2(double side, std::unique_ptr<DrawSquareStrategyS2> drawer);

                    void draw( /*some arguments*/) const override;
                    double side() const;

                private:
                    double side_;
                    std::unique_ptr<DrawSquareStrategyS2> drawer_;
                };

                void drawAllShapesS2(std::vector<std::unique_ptr<ShapeS2>> const& shapes);

                class OpenGLCircleStrategyS2 : public DrawStrategyS2<CircleS2>
                {
                public:
                    explicit OpenGLCircleStrategyS2( /* Drawing related arguments */)
                    {}

                    void draw(CircleS2 const& circle /*, ...*/) const override;

                private:
                    /* Drawing related data members, e.g. colors, textures, ... */
                };

                class OpenGLSquareStrategyS2 : public DrawStrategyS2<SquareS2>
                {
                public:
                    explicit OpenGLSquareStrategyS2( /* Drawing related arguments */)
                    {}

                    void draw(SquareS2 const& square /*, ...*/) const override;

                private:
                    /* Drawing related data members, e.g. colors, textures, ... */
                };

#pragma endregion Example2


#pragma region Example3
                //functional
                class ShapeS3
                {
                public:
                    virtual ~ShapeS3() = default;

                    virtual void draw( /*some arguments*/) const = 0;
                };
                class CircleS3 : public ShapeS3
                {
                public:
                    using DrawStrategyS3 = std::function<void(CircleS3 const& /*, ...*/)>;

                    explicit CircleS3(double radius, DrawStrategyS3 drawer);
                    void draw( /*some arguments*/) const override;

                    double radius() const;

                private:
                    double radius_;
                    DrawStrategyS3 drawer_;
                };

                class SquareS3 : public ShapeS3
                {
                public:
                    using DrawStrategyS3 = std::function<void(SquareS3 const& /*, ...*/)>;

                    explicit SquareS3(double side, DrawStrategyS3 drawer);

                    void draw( /*some arguments*/) const override;
                    double side() const;

                private:
                    double side_;
                    DrawStrategyS3 drawer_;
                };
         
                class OpenGLCircleStrategyS3
                {
                public:
                    explicit OpenGLCircleStrategyS3( /* Drawing related arguments */)
                    {}

                    void operator()(CircleS3 const& circle /*, ...*/) const;

                private:
                    /* Drawing related data members, e.g. colors, textures, ... */
                };

                class OpenGLSquareStrategyS3
                {
                public:
                    explicit OpenGLSquareStrategyS3( /* Drawing related arguments */)
                    {}

                    void operator()(SquareS3 const& square /*, ...*/) const;

                private:
                    /* Drawing related data members, e.g. colors, textures, ... */
                };
#pragma endregion Example3



            }
        }
	}
}