#include "TutorialProcessView.hpp"
#include <Process/Style/ScenarioStyle.hpp>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QQuickWidget>
#include <QGraphicsProxyWidget>
#include <QApplication>
namespace Tutorial
{

TutorialView::TutorialView(
        QGraphicsItem* parent):
    LayerView{parent}
{
  this->setFlag(QGraphicsItem::ItemClipsToShape, true);
  this->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);
  auto widget = new QQuickWidget(QUrl("qrc:///TutorialProcess.qml"));
  widget->setClearColor(QColor("#19456B"));
  widget->setResizeMode(QQuickWidget::ResizeMode::SizeRootObjectToView);

  auto subw = new QGraphicsProxyWidget{this};
  subw->setWidget(widget);

  connect(this, &LayerView::heightChanged, this, [=] {
    subw->setGeometry(QRectF{0, 50, this->width(), this->height() - 100});
    widget->setMinimumSize((int)width(), (int)height() - 100);
    widget->setMaximumSize((int)width(), (int)height() - 100);
    widget->update();
  });
  connect(this, &LayerView::widthChanged, this, [=] {
    subw->setGeometry(QRectF{0, 50, this->width(), this->height() - 100});
    widget->setMinimumSize((int)width(), (int)height() - 100);
    widget->setMaximumSize((int)width(), (int)height() - 100);
    widget->update();
  });
  subw->update();
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
