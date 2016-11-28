#include "ConcretePolymorphicElement.hpp"

namespace Tutorial
{

ConcretePolymorphicElement::ConcretePolymorphicElement(
        const Id<PolymorphicElement>& id,
        QObject* parent):
    PolymorphicElement{id, parent}
{

}

ConcretePolymorphicElement::ConcretePolymorphicElement(
        const ConcretePolymorphicElement& source,
        const Id<PolymorphicElement>& id,
        QObject* parent):
    PolymorphicElement{source, id, parent}
{

}

void ConcretePolymorphicElement::someVirtualMethod()
{
}

}

// Here we do not need to save the parent class.
// This is because the serialization mechanism will
// be called from the point of view of the PolymorphicElement class.
template<>
void Visitor<Reader<DataStream>>::readFrom_impl(
        const Tutorial::ConcretePolymorphicElement& p)
{
    insertDelimiter();
}

template<>
void Visitor<Writer<DataStream>>::writeTo(
        Tutorial::ConcretePolymorphicElement& p)
{
    checkDelimiter();
}

template<>
void Visitor<Reader<JSONObject>>::readFrom_impl(
        const Tutorial::ConcretePolymorphicElement& p)
{
}

template<>
void Visitor<Writer<JSONObject>>::writeTo(
        Tutorial::ConcretePolymorphicElement& p)
{
}
