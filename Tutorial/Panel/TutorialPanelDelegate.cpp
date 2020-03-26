#include "TutorialPanelDelegate.hpp"

#include <QApplication>
#include <QBrush>
#include <QColor>
#include <QFormLayout>
#include <QLabel>
#include <QQmlComponent>
#include <QQmlContext>
#include <QQmlEngine>
#include <QQuickItem>
#include <QQuickView>
#include <QQuickWidget>
#include <QQuickWindow>
namespace Tutorial
{

PanelDelegate::PanelDelegate(const score::GUIApplicationContext& ctx)
    : score::PanelDelegate{ctx}
{
  m_widget = new QWidget;
  auto lay = new QFormLayout{m_widget};

  lay->addWidget(new QLabel{tr("This is a panel.")});
}

QWidget* PanelDelegate::widget()
{
  return m_widget;
}

const score::PanelStatus& PanelDelegate::defaultPanelStatus() const
{
  static const score::PanelStatus status{true, false,
                                         Qt::RightDockWidgetArea,
                                         10,
                                         QObject::tr("Tutorial"),
                                         QObject::tr("Ctrl+T")};

  return status;
}

void PanelDelegate::on_modelChanged(
    score::MaybeDocument oldm,
    score::MaybeDocument newm)
{
}

void PanelDelegate::setNewSelection(const Selection& s) {}

std::unique_ptr<score::PanelDelegate>
PanelDelegateFactory::make(const score::GUIApplicationContext& ctx)
{
  return std::make_unique<PanelDelegate>(ctx);
}

QMLPanelDelegate::QMLPanelDelegate(const score::GUIApplicationContext& ctx)
    : score::PanelDelegate{ctx}
{
  QQuickView* view = new QQuickView(QUrl("qrc:///TutorialPanel.qml"));
  auto w = QWidget::createWindowContainer(view);
  view->setClearBeforeRendering(true);
  view->setColor(qApp->palette().background().color());
  view->setResizeMode(QQuickView::ResizeMode::SizeRootObjectToView);
  m_widget = w;
}

QWidget* QMLPanelDelegate::widget()
{
  return m_widget;
}

const score::PanelStatus& QMLPanelDelegate::defaultPanelStatus() const
{
  static const score::PanelStatus status{true, false,
                                         Qt::RightDockWidgetArea,
                                         100,
                                         QObject::tr("Tutorial QML"),
                                         QObject::tr("Ctrl+U")};

  return status;
}

void QMLPanelDelegate::on_modelChanged(
    score::MaybeDocument oldm,
    score::MaybeDocument newm)
{
}

void QMLPanelDelegate::setNewSelection(const Selection& s) {}

std::unique_ptr<score::PanelDelegate>
QMLPanelDelegateFactory::make(const score::GUIApplicationContext& ctx)
{
  return std::make_unique<QMLPanelDelegate>(ctx);
}

}
