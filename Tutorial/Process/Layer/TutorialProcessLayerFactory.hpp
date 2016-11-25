#pragma once
#include <Tutorial/Process/TutorialProcessModel.hpp>
#include <Process/ProcessMetadata.hpp>
#include <Process/LayerModel.hpp>

namespace Tutorial
{
using Layer = Process::LayerModel_T<ProcessModel>;
}

LAYER_METADATA(
        ,
        Tutorial::Layer,
        "d5dc8583-3f7f-49ae-9664-fadda04f42fa",
        "TutorialLayer",
        "TutorialLayer"
        )
