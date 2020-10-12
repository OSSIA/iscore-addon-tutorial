#include "TutorialProcessView.hpp"

#include <Process/Style/ScenarioStyle.hpp>

#include <QApplication>
#include <QGraphicsProxyWidget>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>

#include <wobjectimpl.h>
W_OBJECT_IMPL(Tutorial::TutorialView)
namespace Tutorial
{

TutorialView::TutorialView(QGraphicsItem* parent) : LayerView{parent}
{
  this->setFlag(QGraphicsItem::ItemClipsToShape, true);
  this->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
}

void TutorialView::heightChanged(qreal h)
{
}

void TutorialView::widthChanged(qreal w)
{
}
void TutorialView::setText(const QString& txt)
{
  m_text = txt;
  update();
}

void TutorialView::paint_impl(QPainter* painter) const
{
  auto font = score::Skin::instance().MonoFont;
  font.setPointSize(25);
  painter->setFont(font);
  painter->setPen(Qt::white);

  painter->drawText(QPointF{5., 30.}, m_text);
}

void TutorialView::mousePressEvent(QGraphicsSceneMouseEvent* event)
{
  // Necessary to get double click.
  event->accept();
}

void TutorialView::mouseDoubleClickEvent(QGraphicsSceneMouseEvent* event)
{
  doubleClicked();

  event->accept();
}
}
