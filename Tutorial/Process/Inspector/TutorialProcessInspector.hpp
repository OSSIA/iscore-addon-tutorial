#pragma once
#include <Tutorial/Process/TutorialProcessModel.hpp>
#include <Process/Inspector/ProcessInspectorWidgetDelegate.hpp>
#include <Process/Inspector/ProcessInspectorWidgetDelegateFactory.hpp>
#include <iscore/command/Dispatchers/CommandDispatcher.hpp>

namespace Tutorial
{
class ProcessModel;
class InspectorWidget final :
        public Process::InspectorWidgetDelegate_T<Tutorial::ProcessModel>
{
    public:
        explicit InspectorWidget(
                const Tutorial::ProcessModel& object,
                const iscore::DocumentContext& context,
                QWidget* parent);

    private:
        void addBanana();

        CommandDispatcher<> m_dispatcher;
};


class InspectorFactory final :
        public Process::InspectorWidgetDelegateFactory_T<ProcessModel, InspectorWidget>
{
        ISCORE_CONCRETE_FACTORY("41b2ea17-9bec-4688-b5e0-d7fbabfd1038")
};
}
