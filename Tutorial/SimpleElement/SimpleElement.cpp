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

template<>
void Visitor<Reader<DataStream>>::readFrom(const Tutorial::SimpleElement& e)
{
    readFrom(static_cast<const IdentifiedObject<Tutorial::SimpleElement>&>(e));
    insertDelimiter();
}

template<>
void Visitor<Writer<DataStream>>::writeTo(Tutorial::SimpleElement& e)
{
    checkDelimiter();
}

template<>
void Visitor<Reader<JSONObject>>::readFrom(const Tutorial::SimpleElement& e)
{
    readFrom(static_cast<const IdentifiedObject<Tutorial::SimpleElement>&>(e));
}

template<>
void Visitor<Writer<JSONObject>>::writeTo(Tutorial::SimpleElement& e)
{

}
