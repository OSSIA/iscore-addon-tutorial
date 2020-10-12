#include "PolymorphicEntity.hpp"

#include <wobjectimpl.h>

W_OBJECT_IMPL(Tutorial::PolymorphicEntity)
namespace Tutorial
{

PolymorphicEntity::PolymorphicEntity(
    const Id<PolymorphicEntity>& id,
    QObject* parent)
    : Entity{id, "PolymorphicElement", parent}
{
}

PolymorphicEntity::~PolymorphicEntity() {}

}

template <>
void DataStreamReader::read(const Tutorial::PolymorphicEntity& p)
{
}

template <>
void DataStreamWriter::write(Tutorial::PolymorphicEntity& p)
{
}

template <>
void JSONReader::read(const Tutorial::PolymorphicEntity& p)
{
  ;
}

template <>
void JSONWriter::write(Tutorial::PolymorphicEntity& p)
{
}
