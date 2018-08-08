#include "TutorialProcessView.hpp"
#include <Process/Style/ScenarioStyle.hpp>
#include <QGraphicsSceneMouseEvent>
#include <QPainter>
#include <QQuickWidget>
#include <QGraphicsProxyWidget>
#include <QApplication>
#include <wobjectimpl.h>
W_OBJECT_IMPL(Tutorial::TutorialView)
namespace Tutorial
{

TutorialView::TutorialView(
        QGraphicsItem* parent):
    LayerView{parent}
{
  this->setFlag(QGraphicsItem::ItemClipsToShape, true);
  this->setFlag(QGraphicsItem::ItemClipsChildrenToShape, true);

  m_widget = new QQuickWidget(QUrl("qrc:///TutorialProcess.qml"));
  m_widget->setClearColor(QColor("#19456B"));
  m_widget->setResizeMode(QQuickWidget::ResizeMode::SizeRootObjectToView);

  m_proxy = new QGraphicsProxyWidget{this};
  m_proxy->setWidget(m_widget);

  m_proxy->update();
}


void TutorialView::heightChanged(qreal h)
{
  m_proxy->setGeometry(QRectF{0, 50, this->width(), this->height() - 100});
  m_widget->setMinimumSize((int)width(), (int)height() - 100);
  m_widget->setMaximumSize((int)width(), (int)height() - 100);
  m_widget->update();
}

void TutorialView::widthChanged(qreal w)
{
  m_proxy->setGeometry(QRectF{0, 50, this->width(), this->height() - 100});
  m_widget->setMinimumSize((int)width(), (int)height() - 100);
  m_widget->setMaximumSize((int)width(), (int)height() - 100);
  m_widget->update();
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
