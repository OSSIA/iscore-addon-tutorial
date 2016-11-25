#pragma once
#include <Engine/Executor/ProcessElement.hpp>
namespace Tutorial
{
class ProcessModel;
class ProcessExecutor final :
        public ossia::time_process
{
    public:
        ProcessExecutor();

        void start() override;
        void stop() override;
        void pause() override;
        void resume() override;

        ossia::state_element offset(ossia::time_value) override;
        ossia::state_element state() override;
};


class ProcessExecutorComponent final :
        public Engine::Execution::ProcessComponent_T<
            Tutorial::ProcessModel,
            Tutorial::ProcessExecutor>
{
        COMPONENT_METADATA("4797971b-54cd-43e5-8514-e2e941303d1a")
    public:
        ProcessExecutorComponent(
                Engine::Execution::ConstraintElement& parentConstraint,
                ProcessModel& element,
                const Engine::Execution::Context& ctx,
                const Id<iscore::Component>& id,
                QObject* parent);
};


using ComponentFactory =
    Engine::Execution::ProcessComponentFactory_T<ProcessExecutorComponent>;

}
