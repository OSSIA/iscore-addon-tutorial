#pragma once
#include <Tutorial/PolymorphicElement/PolymorphicElementFactory.hpp>
#include <iscore/plugins/customfactory/SerializableInterface.hpp>
#include <iscore/model/Entity.hpp>

namespace Tutorial
{
class PolymorphicElement :
        public iscore::Entity<PolymorphicElement>,
        public iscore::SerializableInterface<PolymorphicElementFactory>
{
        Q_OBJECT
        ISCORE_SERIALIZE_FRIENDS(PolymorphicElement, DataStream)
        ISCORE_SERIALIZE_FRIENDS(PolymorphicElement, JSONObject)

    public:
        PolymorphicElement(
                const Id<PolymorphicElement>& id,
                QObject* parent);

        PolymorphicElement(
                const PolymorphicElement& source,
                const Id<PolymorphicElement>&,
                QObject* parent);

        template<typename Impl>
        PolymorphicElement(
                Deserializer<Impl>& vis,
                QObject* parent) :
            iscore::Entity<PolymorphicElement>{vis, parent}
        {
            vis.writeTo(*this);
        }


        ~PolymorphicElement();

        virtual void someVirtualMethod() = 0;

        virtual PolymorphicElement* clone(
                const Id<PolymorphicElement>& newId,
                QObject* parent) const = 0;

};
}

#define POLYMORPHICELEMENT_METADATA(Export, Model, Uuid, ObjectKey, PrettyName) \
    MODEL_METADATA(Export, Tutorial::PolymorphicElementFactory, Model, Uuid, ObjectKey, PrettyName)
