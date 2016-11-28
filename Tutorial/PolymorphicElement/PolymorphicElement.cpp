#include "PolymorphicElement.hpp"

namespace Tutorial
{

PolymorphicElement::PolymorphicElement(
        const Id<PolymorphicElement>& id,
        QObject* parent):
    Entity{id, "PolymorphicElement", parent}
{

}

PolymorphicElement::PolymorphicElement(
        const PolymorphicElement& source,
        const Id<PolymorphicElement>& id,
        QObject* parent):
    Entity{id, "PolymorphicElement", parent}
{

}

PolymorphicElement::~PolymorphicElement()
{

}

}

template<>
void Visitor<Reader<DataStream>>::readFrom_impl(
        const Tutorial::PolymorphicElement& p)
{
    // Save the parent class
    readFrom(static_cast<const iscore::Entity<Tutorial::PolymorphicElement>&>(p));

}

template<>
void Visitor<Writer<DataStream>>::writeTo(
        Tutorial::PolymorphicElement& p)
{
}

template<>
void Visitor<Reader<JSONObject>>::readFrom_impl(
        const Tutorial::PolymorphicElement& p)
{
    // Save the parent class
    readFrom(static_cast<const iscore::Entity<Tutorial::PolymorphicElement>&>(p));
}

template<>
void Visitor<Writer<JSONObject>>::writeTo(
        Tutorial::PolymorphicElement& p)
{
}
