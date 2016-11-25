#pragma once
#include <Process/LayerPresenter.hpp>
#include <Tutorial/Process/Layer/TutorialProcessLayerFactory.hpp>
#include <QPoint>

#include <Process/ZoomHelper.hpp>
#include <iscore/tools/SettableIdentifier.hpp>
#include <Process/Focus/FocusDispatcher.hpp>

namespace Tutorial
{
class TutorialView;
class TutorialPresenter final :
        public Process::LayerPresenter
{
    public:
        explicit TutorialPresenter(
                const Layer& model,
                TutorialView* view,
                const Process::ProcessPresenterContext& ctx,
                QObject* parent);

        void setWidth(qreal width) override;
        void setHeight(qreal height) override;

        void putToFront() override;
        void putBehind() override;

        void on_zoomRatioChanged(ZoomRatio) override;

        void parentGeometryChanged() override;

        const Process::LayerModel& layerModel() const override;
        const Id<Process::ProcessModel>& modelId() const override;

    private:
        const Layer& m_layer;
        TutorialView* m_view{};
};
}
