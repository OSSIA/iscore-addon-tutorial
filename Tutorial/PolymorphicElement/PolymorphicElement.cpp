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

template <>
void DataStreamReader::read(
        const Tutorial::PolymorphicElement& p)
{
}

template <>
void DataStreamWriter::write(
        Tutorial::PolymorphicElement& p)
{
}

template <>
void JSONObjectReader::read(
        const Tutorial::PolymorphicElement& p)
{;
}

template <>
void JSONObjectWriter::write(
        Tutorial::PolymorphicElement& p)
{
}
