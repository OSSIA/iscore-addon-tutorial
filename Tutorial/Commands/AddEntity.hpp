#pragma once
#include <score/command/Command.hpp>

#include <Tutorial/Commands/TutorialCommandFactory.hpp>
#include <Tutorial/PolymorphicEntity/PolymorphicEntityFactory.hpp>
#include <Tutorial/Process/TutorialProcessModel.hpp>

namespace Tutorial
{
class AddEntity : public score::Command
{
  SCORE_COMMAND_DECL(
      Tutorial::CommandFactoryName(),
      AddEntity,
      "Add a polymorphic entity")

public:
  AddEntity(
      const Tutorial::ProcessModel& model,
      PolymorphicElementFactory::ConcreteKey key);

  void undo(const score::DocumentContext& ctx) const override;
  void redo(const score::DocumentContext& ctx) const override;

protected:
  void serializeImpl(DataStreamInput& s) const override;
  void deserializeImpl(DataStreamOutput& s) override;

private:
  Path<ProcessModel> m_model;

  //! Key to identify the instance we want to create
  PolymorphicElementFactory::ConcreteKey m_key;

  //! The identifier of the object to be created
  Id<PolymorphicEntity> m_id;
};
}
