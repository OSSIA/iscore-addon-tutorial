#include "SimpleElement.hpp"
#include <iscore/serialization/DataStreamVisitor.hpp>
#include <iscore/serialization/JSONVisitor.hpp>
namespace Tutorial
{

SimpleElement::SimpleElement(const Id<SimpleElement>& id, QObject* parent):
    IdentifiedObject{id, "SimpleElement", parent}
{

}

SimpleElement::~SimpleElement()
{

}

}

template <>
void DataStreamReader::read(const Tutorial::SimpleElement& e)
{
    insertDelimiter();
}

template <>
void DataStreamWriter::write(Tutorial::SimpleElement& e)
{
    checkDelimiter();
}

template <>
void JSONObjectReader::read(const Tutorial::SimpleElement& e)
{
}

template <>
void JSONObjectWriter::write(Tutorial::SimpleElement& e)
{

}
