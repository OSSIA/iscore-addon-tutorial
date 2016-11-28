#include "SimpleEntity.hpp"

namespace Tutorial
{

SimpleEntity::SimpleEntity(const Id<SimpleEntity>& id, QObject* parent):
    Entity{id, "SimpleEntity", parent}
{

}

SimpleEntity::~SimpleEntity()
{

}

}

template<>
void Visitor<Reader<DataStream>>::readFrom(const Tutorial::SimpleEntity& e)
{
    readFrom(static_cast<const iscore::Entity<Tutorial::SimpleEntity>&>(e));

    insertDelimiter();
}

template<>
void Visitor<Writer<DataStream>>::writeTo(Tutorial::SimpleEntity& e)
{
    checkDelimiter();
}

template<>
void Visitor<Reader<JSONObject>>::readFrom(const Tutorial::SimpleEntity& e)
{
    readFrom(static_cast<const iscore::Entity<Tutorial::SimpleEntity>&>(e));
}

template<>
void Visitor<Writer<JSONObject>>::writeTo(Tutorial::SimpleEntity& e)
{

}
