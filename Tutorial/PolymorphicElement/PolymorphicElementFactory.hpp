#pragma once
#include <iscore/plugins/customfactory/FactoryInterface.hpp>
#include <iscore/serialization/VisitorCommon.hpp>
#include <iscore_addon_tutorial_export.h>


namespace Tutorial
{
class PolymorphicElement;
class ISCORE_ADDON_TUTORIAL_EXPORT PolymorphicElementFactory :
        public iscore::AbstractFactory<PolymorphicElementFactory>
{
        ISCORE_ABSTRACT_FACTORY("a7c67e8c-9302-4f12-9deb-6d020f74d1d4")

        public:
            virtual ~PolymorphicElementFactory();

            virtual PolymorphicElement* make(
                const Id<PolymorphicElement>& id,
                QObject* parent) const = 0;

            virtual PolymorphicElement* load(
                const VisitorVariant& data,
                QObject* parent) const = 0;
};


template<typename Model_T>
class PolymorphicElementFactory_T final :
        public PolymorphicElementFactory
{
    public:
        virtual ~PolymorphicElementFactory_T() = default;

        static auto static_concreteFactoryKey()
        { return Metadata<ConcreteFactoryKey_k, Model_T>::get(); }

    private:
        UuidKey<PolymorphicElementFactory> concreteFactoryKey() const override
        { return Metadata<ConcreteFactoryKey_k, Model_T>::get(); }

        Model_T* make(
                const Id<PolymorphicElement>& id,
                QObject* parent) const final override
        {
            return new Model_T{id, parent};
        }

        Model_T* load(
                const VisitorVariant& vis,
                QObject* parent) const final override
        {
            return deserialize_dyn(vis, [&] (auto&& deserializer)
            { return new Model_T{deserializer, parent}; });
        }
};



class ISCORE_ADDON_TUTORIAL_EXPORT PolymorphicElementFactoryList final :
        public iscore::ConcreteFactoryList<PolymorphicElementFactory>
{
    public:
        using object_type = PolymorphicElement;

        PolymorphicElement* loadMissing(
                const VisitorVariant& vis,
                QObject* parent) const;
};
}
