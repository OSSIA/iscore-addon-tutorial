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
    const Tutorial::ProcessModel& p = layer.processModel();

    con(p, &ProcessModel::bananasChanged,
            this, [=] (int b) {
        m_view->setText("bananas: " + QString::number(b));
    });
    m_view->setText("bananas: " + QString::number(p.bananas()));
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
    m_view->setOpacity(1);
}

void TutorialPresenter::putBehind()
{
    m_view->setOpacity(0.2);
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
