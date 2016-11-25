#include "TutorialProcessExecutor.hpp"

namespace Tutorial
{

ProcessExecutor::ProcessExecutor()
{
}


void ProcessExecutor::start()
{
}

void ProcessExecutor::stop()
{
}

void ProcessExecutor::pause()
{
}

void ProcessExecutor::resume()
{
}

ossia::state_element ProcessExecutor::offset(
        ossia::time_value off)
{
    return {};
}

ossia::state_element ProcessExecutor::state()
{
    return {};
}



ProcessExecutorComponent::ProcessExecutorComponent(
        Engine::Execution::ConstraintElement& parentConstraint,
        ProcessModel& element,
        const Engine::Execution::Context& ctx,
        const Id<iscore::Component>& id,
        QObject* parent):
    Engine::Execution::ProcessComponent_T{
          parentConstraint, element, ctx, id, "TutorialExecutorComponent", parent}
{

}

}
