#pragma once
#include <Tutorial/PolymorphicElement/PolymorphicElement.hpp>

namespace Tutorial
{
class ConcretePolymorphicElement;
}

POLYMORPHICELEMENT_METADATA(
        ,
        Tutorial::ConcretePolymorphicElement,
        "e1c02c4c-a4c4-4779-9204-8a00f35e7985",
        "Concrete",
        "Concrete")

namespace Tutorial
{
class ConcretePolymorphicElement final : public PolymorphicElement
{
        Q_OBJECT
        ISCORE_SERIALIZE_FRIENDS
        MODEL_METADATA_IMPL(ConcretePolymorphicElement)

    public:
        ConcretePolymorphicElement(
                const Id<PolymorphicElement>& id,
                QObject* parent);

        ConcretePolymorphicElement(
                const ConcretePolymorphicElement& source,
                const Id<PolymorphicElement>&,
                QObject* parent);

        template<typename Impl>
        ConcretePolymorphicElement(
                Impl& vis,
                QObject* parent) :
            PolymorphicElement{vis, parent}
        {
            vis.writeTo(*this);
        }


        void someVirtualMethod() override;
};

// Thanks to the generic factory we wrote earlier, the definition
// for this particular class's factory is a single line.
using ConcretePolymorphicElementFactory =
    PolymorphicElementFactory_T<ConcretePolymorphicElement>;
}
