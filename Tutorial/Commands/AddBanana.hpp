#pragma once
#include <iscore/command/SerializableCommand.hpp>
#include <Tutorial/Process/TutorialProcessModel.hpp>
#include <Tutorial/Commands/TutorialCommandFactory.hpp>

namespace Tutorial
{
class AddBanana : public iscore::SerializableCommand
{
        ISCORE_COMMAND_DECL(Tutorial::CommandFactoryName(), AddBanana, "Add a banana")
    public:
        AddBanana(const Tutorial::ProcessModel& model);

        void undo() const override;
        void redo() const override;

    protected:
        void serializeImpl(DataStreamInput & s) const override;
        void deserializeImpl(DataStreamOutput & s) override;

    private:
        Path<ProcessModel> m_model;
};
}
