#include <score/command/Dispatchers/CommandDispatcher.hpp>

#include <Tutorial/Commands/AddEntity.hpp>
#include <Tutorial/Process/Layer/TutorialProcessPresenter.hpp>
#include <Tutorial/Process/Layer/TutorialProcessView.hpp>
#include <score/tools/Bind.hpp>

namespace Tutorial
{
TutorialPresenter::TutorialPresenter(
    const ProcessModel& layer,
    TutorialView* view,
    const Process::Context& ctx,
    QObject* parent)
    : LayerPresenter{layer, view,  ctx, parent}, m_view{view}
{
  const Tutorial::ProcessModel& p = layer;

  // From model to view :
  con(p, &ProcessModel::bananasChanged, this, [=](int b) {
    m_view->setText("bananas: " + QString::number(b));
  });
  m_view->setText("bananas: " + QString::number(p.bananas()));

  // From view to model :
  connect(
      view,
      &TutorialView::doubleClicked,
      this,
      &TutorialPresenter::on_doubleClicked);
}

void TutorialPresenter::setWidth(qreal val, qreal defaultwidth)
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

void TutorialPresenter::on_zoomRatioChanged(ZoomRatio) {}

void TutorialPresenter::parentGeometryChanged() {}


void TutorialPresenter::on_doubleClicked()
{
  const PolymorphicElementFactoryList& entity_list
      = m_context    // Layer context
            .context // Document context
            .app     // Application context
            .interfaces<PolymorphicElementFactoryList>();

  // If there are some factories available
  if (!entity_list.empty())
  {
    // Here we take the first one but of course
    // there are plenty of other ways : for instance
    // putting them all in a widget and displaying the list.

    auto factory_it = entity_list.begin(); // iterator<std::pair<key, value>>;

    //! This key will allow us to refer to this specific factory in the future.
    //! Objects inheriting from score::SerializableInterface also have a method
    //! that gives this key.
    auto factory_key = factory_it->concreteKey();

    CommandDispatcher<> disp{m_context.context.commandStack};

    disp.submit<AddEntity>(
        static_cast<const ProcessModel&>(m_process),    // The object on which it is applied
        factory_key // The factory that we used.
    );
  }
}

}
