#pragma once
#include <Process/LayerView.hpp>

class QQuickWidget;
class QGraphicsProxyWidget;
namespace Tutorial
{
//! The View should only handle painting, and forwarding of
//! input events to the presenter. It will create a PolymorphicEntity on double click.
class TutorialView final
    : public Process::LayerView
{
  W_OBJECT(TutorialView)
public:
  explicit TutorialView(QGraphicsItem* parent);

  void setText(const QString&);

  void doubleClicked() W_SIGNAL(doubleClicked);

private:
  void paint_impl(QPainter*) const override;
  void mousePressEvent(QGraphicsSceneMouseEvent* event) override;
  void mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event) override;

  void heightChanged(qreal h) override;
  void widthChanged(qreal w) override;
  QString m_text;
  QQuickWidget* m_widget{};
  QGraphicsProxyWidget* m_proxy{};

};
}
