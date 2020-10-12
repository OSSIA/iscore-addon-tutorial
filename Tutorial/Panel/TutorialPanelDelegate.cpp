#include "TutorialPanelDelegate.hpp"

#include <QApplication>
#include <QBrush>
#include <QColor>
#include <QFormLayout>
#include <QLabel>
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
                                         QString{},
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

}
