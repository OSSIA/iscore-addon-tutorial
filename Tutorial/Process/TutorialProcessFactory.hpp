#pragma once
#include <Process/GenericProcessFactory.hpp>
#include <Tutorial/Process/TutorialProcessModel.hpp>

namespace Video
{
using ProcessFactory =
    Process::GenericProcessModelFactory<
        Tutorial::ProcessModel>;
}
