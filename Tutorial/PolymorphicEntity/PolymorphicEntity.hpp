#pragma once
#include <Tutorial/PolymorphicEntity/PolymorphicEntityFactory.hpp>
#include <score/plugins/customfactory/SerializableInterface.hpp>
#include <score/model/Entity.hpp>

namespace Tutorial
{
class PolymorphicEntity :
        public score::Entity<PolymorphicEntity>,
        public score::SerializableInterface<PolymorphicElementFactory>
{
        Q_OBJECT
        SCORE_SERIALIZE_FRIENDS

    public:
        PolymorphicEntity(
                const Id<PolymorphicEntity>& id,
                QObject* parent);

        template<typename Impl>
        PolymorphicEntity(
                Impl& vis,
                QObject* parent) :
            score::Entity<PolymorphicEntity>{vis, parent}
        {
            vis.writeTo(*this);
        }


        ~PolymorphicEntity();

        virtual int someVirtualMethod() const = 0;

};
}

#define POLYMORPHIC_ENTITY_METADATA(Export, Model, Uuid, ObjectKey, PrettyName) \
    MODEL_METADATA(Export, Tutorial::PolymorphicElementFactory, Model, Uuid, ObjectKey, PrettyName)
