#pragma once
#include "DPUtilities.h"

/*
* Structural Pattern
* 3. Composite
 * Intent: Lets you compose objects into tree structures and then work with
 * these structures as if they were individual objects.
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

				class GraphicC1
				{
				public:
					virtual void print() const = 0;
					virtual ~GraphicC1() {}
				};

				class EllipseC1 : public GraphicC1
				{
				public:
					void print() const override;
				};

				class CompositeGraphicC1 : public GraphicC1
				{
				public:
					void print() const override;

					void add(GraphicC1* aGraphic);

				private:
					std::vector<GraphicC1*>  graphicList_;
				};
#pragma endregion Example1

#pragma region Example2
                /**
                 * The base Component class declares common operations for both simple and
                 * complex objects of a composition.
                 */
                class ComponentC2
                {
                    /**
                       * @var Component
                       */
                protected:
                    ComponentC2* parent_;
                    /**
                       * Optionally, the base Component can declare an interface for setting
                       * and accessing a parent of the component in a tree structure. It can also
                       * provide some default implementation for these methods.
                       */
                public:
                    virtual ~ComponentC2() {}
                    void SetParent(ComponentC2* parent);
                    ComponentC2* GetParent() const;
                    /**
                       * In some cases, it would be beneficial to define the child-management
                       * operations right in the base Component class. This way, you won't need to
                       * expose any concrete component classes to the client code, even during the
                       * object tree assembly. The downside is that these methods will be empty
                       * for the leaf-level components.
                       */
                    virtual void Add(ComponentC2* component) {};
                    virtual void Remove(ComponentC2* component) {};
                    /**
                       * You can provide a method that lets the client code figure out whether
                       * a component can bear children.
                       */
                    virtual bool IsComposite() const;
                    /**
                       * The base Component may implement some default behavior or leave it to
                       * concrete classes (by declaring the method containing the behavior as
                       * "abstract").
                       */
                    virtual std::string Operation() const = 0;
                };

                /**
                 * The Leaf class represents the end objects of a composition. A leaf can't
                 * have any children.
                 *
                 * Usually, it's the Leaf objects that do the actual work, whereas Composite
                 * objects only delegate to their sub-components.
                 */
                class LeafC2 : public ComponentC2
                {
                public:
                    std::string Operation() const override;
                };
                /**
                 * The Composite class represents the complex components that may have
                 * children. Usually, the Composite objects delegate the actual work to their
                 * children and then "sum-up" the result.
                 */
                class CompositeC2 : public ComponentC2
                {
                    /**
                       * @var \SplObjectStorage
                       */
                protected:
                    std::list<ComponentC2*> children_;

                public:
                    /**
                       * A composite object can add or remove other components (both simple or
                       * complex) to or from its child list.
                       */
                    void Add(ComponentC2* component) override;
                    /**
                       * Have in mind that this method removes the pointer to the list but doesn't frees the
                       * memory, you should do it manually or better use smart pointers.
                       */
                    void Remove(ComponentC2* component) override;
                    bool IsComposite() const override;
                    /**
                       * EN: The Composite executes its primary logic in a particular way. It
                       * traverses recursively through all its children, collecting and summing
                       * their results. Since the composite's children pass these calls to their
                       * children and so forth, the whole object tree is traversed as a result.
                       */
                    std::string Operation() const override;
                };

                /**
                 * The client code works with all of the components via the base interface.
                 */
                void ClientCode1C2(ComponentC2* component);

                /**
                 * Thanks to the fact that the child-management operations are declared in
                 * the base Component class, the client code can work with any component, simple
                 * or complex, without depending on their concrete classes.
                 */
                void ClientCode2C2(ComponentC2* component1, ComponentC2* component2);

                /**
                 * This way the client code can support the simple leaf components...
                 */
#pragma endregion Example2

#pragma region Example3

                class ComponentC3
                {
                public:
                    virtual ~ComponentC3() {};
                    virtual ComponentC3* getChild(int);
                    virtual void add(ComponentC3*);
                    virtual void remove(int);
                    virtual void operation() = 0;
                };

                /*
                 * Composite
                 * defines behavior of the components having children
                 * and store child components
                 */
                class CompositeC3 : public ComponentC3
                {
                public:
                    ~CompositeC3();

                    ComponentC3* getChild(int index) override;

                    void add(ComponentC3* component) override;
                    void remove(int index) override;
                    void operation() override;

                private:
                    std::vector<ComponentC3*> children;
                };

                /*
                 * Leaf
                 * defines the behavior for the elements in the composition,
                 * it has no children
                 */
                class LeafC3 : public ComponentC3
                {
                public:

                    LeafC3(const int i);
                    ~LeafC3() {};
                    void operation() override;


                private:
                    int id;
                };

                 

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
