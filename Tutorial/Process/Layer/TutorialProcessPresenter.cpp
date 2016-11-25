#include <Tutorial/Process/Layer/TutorialProcessPresenter.hpp>
#include <Tutorial/Process/Layer/TutorialProcessView.hpp>


namespace Tutorial
{
TutorialPresenter::TutorialPresenter(
        const Layer& layer,
        TutorialView* view,
        const Process::ProcessPresenterContext& ctx,
        QObject* parent):
    LayerPresenter{ctx, parent},
    m_layer{layer},
    m_view{view}
{
}

void TutorialPresenter::setWidth(qreal val)
{
    m_view->setWidth(val);
}

void TutorialPresenter::setHeight(qreal val)
{
    m_view->setHeight(val);
}

void TutorialPresenter::putToFront()
{
    m_view->setVisible(true);
}

void TutorialPresenter::putBehind()
{
    m_view->setVisible(false);
}

void TutorialPresenter::on_zoomRatioChanged(ZoomRatio)
{
}

void TutorialPresenter::parentGeometryChanged()
{
}

const Process::LayerModel& TutorialPresenter::layerModel() const
{
    return m_layer;
}

const Id<Process::ProcessModel>& TutorialPresenter::modelId() const
{
    return m_layer.processModel().id();
}

}
