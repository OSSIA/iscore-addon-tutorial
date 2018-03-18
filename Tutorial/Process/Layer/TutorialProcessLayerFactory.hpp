#pragma once
#include <Process/GenericProcessFactory.hpp>
#include <Tutorial/Process/Layer/TutorialProcessPresenter.hpp>
#include <Tutorial/Process/Layer/TutorialProcessView.hpp>

#include <Process/LayerModelPanelProxy.hpp>

namespace Tutorial
{
    using LayerFactory = Process::LayerFactory_T<
    Tutorial::ProcessModel,
    Tutorial::TutorialPresenter,
    Tutorial::TutorialView,
    Process::GraphicsViewLayerPanelProxy>;
}
