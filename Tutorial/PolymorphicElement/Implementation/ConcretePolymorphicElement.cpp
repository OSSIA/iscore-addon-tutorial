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
template <>
void DataStreamReader::read(
        const Tutorial::ConcretePolymorphicElement& p)
{
    insertDelimiter();
}

template <>
void DataStreamWriter::write(
        Tutorial::ConcretePolymorphicElement& p)
{
    checkDelimiter();
}

template <>
void JSONObjectReader::read(
        const Tutorial::ConcretePolymorphicElement& p)
{
}

template <>
void JSONObjectWriter::write(
        Tutorial::ConcretePolymorphicElement& p)
{
}
