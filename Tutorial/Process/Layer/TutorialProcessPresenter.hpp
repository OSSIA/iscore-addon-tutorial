#pragma once
#include <Process/Focus/FocusDispatcher.hpp>
#include <Process/LayerPresenter.hpp>
#include <Process/ZoomHelper.hpp>

#include <score/model/Identifier.hpp>

#include <QPoint>

#include <Tutorial/Process/Layer/TutorialProcessLayer.hpp>

namespace Tutorial
{
class ProcessModel;
class TutorialView;
//! The Presenter should update the view with the data of the model
//! and create commands to react to user actions in the view.
class TutorialPresenter final : public Process::LayerPresenter
{
public:
  explicit TutorialPresenter(
      const ProcessModel& model,
      TutorialView* view,
      const Process::Context& ctx,
      QObject* parent);

  // All the following functions are automatically called
  // by i-score when something is resize in the UI.
  void setWidth(qreal width, qreal defaultwidth) override;
  void setHeight(qreal height) override;

  void putToFront() override;
  void putBehind() override;

  void on_zoomRatioChanged(ZoomRatio) override;

  void parentGeometryChanged() override;

private:
  void on_doubleClicked();

  TutorialView* m_view{};
};
}
