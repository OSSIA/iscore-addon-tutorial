#pragma once
#include <score/plugins/customfactory/FactoryInterface.hpp>
#include <score/serialization/VisitorCommon.hpp>
#include <score_addon_tutorial_export.h>


namespace Tutorial
{
class PolymorphicEntity;

//! The factory class that creates and loads our PolymorphicEntity subclasses
class SCORE_ADDON_TUTORIAL_EXPORT PolymorphicElementFactory :
    public score::InterfaceBase
{
  //! Uniquely identifies this kind of factory.
  SCORE_INTERFACE(PolymorphicElementFactory, "a7c67e8c-9302-4f12-9deb-6d020f74d1d4")

  public:
    ~PolymorphicElementFactory() override;

  virtual PolymorphicEntity* make(
      const Id<PolymorphicEntity>& id,
      QObject* parent) const = 0;

  virtual PolymorphicEntity* load(
      const VisitorVariant& data,
      QObject* parent) const = 0;
};

/** The pattern is used throughout i-score.
 * Most of the time, we know exactly what the implementation of
 * our factory will be. So instead of having tons of copy-paste, we just
 * define a class template.
 *
 * This class accesses the Metadata template : to have this work, it is necessary
 * to define the correct metadata somewhere.
 *
 * Here, it is defined for instance in the macro POLYMORPHIC_ENTITY_METADATA.
 *
 * We cannot have the base class being itself polymorphic : there has to
 * be an actual (not template) class at some point, with a virtual destructor in
 * a .cpp file, for plug-ins to work in DLLs.
 */
template<typename Model_T>
class PolymorphicElementFactory_T final :
    public PolymorphicElementFactory
{
public:
  virtual ~PolymorphicElementFactory_T() = default;

  static auto static_concreteKey()
  { return Metadata<ConcreteKey_k, Model_T>::get(); }

private:
  UuidKey<PolymorphicElementFactory> concreteKey() const noexcept override
  { return Metadata<ConcreteKey_k, Model_T>::get(); }

  Model_T* make(
      const Id<PolymorphicEntity>& id,
      QObject* parent) const final override
  {
    return new Model_T{id, parent};
  }

  Model_T* load(
      const VisitorVariant& vis,
      QObject* parent) const final override
  {
    return score::deserialize_dyn(vis, [&] (auto&& deserializer)
    { return new Model_T{deserializer, parent}; });
  }
};


//! Finally, this is where all the factories for the PolymorphicElement subtypes will be stored.
//! They are accessible through score::ApplicationContext.
class SCORE_ADDON_TUTORIAL_EXPORT PolymorphicElementFactoryList final :
    public score::InterfaceList<PolymorphicElementFactory>
{
public:
  using object_type = PolymorphicEntity;

  //! This is used in case a plug-in was saved with a particular polymorphic class,
  //! and this class is not found when reloading.
  PolymorphicEntity* loadMissing(
      const VisitorVariant& vis,
      QObject* parent) const;
};
}
