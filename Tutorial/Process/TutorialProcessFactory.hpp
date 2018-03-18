#pragma once
#include <Process/GenericProcessFactory.hpp>
#include <Tutorial/Process/TutorialProcessModel.hpp>

namespace Tutorial
{
using ProcessFactory =
    Process::ProcessFactory_T<
        Tutorial::ProcessModel>;
}
