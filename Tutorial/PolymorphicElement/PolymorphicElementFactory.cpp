#include "PolymorphicElementFactory.hpp"

namespace Tutorial
{

PolymorphicElementFactory::~PolymorphicElementFactory()
{

}

PolymorphicElement* PolymorphicElementFactoryList::loadMissing(
        const VisitorVariant& vis,
        QObject* parent) const
{
    return nullptr;
}

}
