#include "TutorialProcessInspector.hpp"
#include <Tutorial/Commands/AddBanana.hpp>

#include <iscore/document/DocumentContext.hpp>

#include <QFormLayout>
#include <QLabel>
#include <QPushButton>

namespace Tutorial
{

InspectorWidget::InspectorWidget(
        const Tutorial::ProcessModel& object,
        const iscore::DocumentContext& context,
        QWidget* parent):
    InspectorWidgetDelegate_T {object, parent},
    m_dispatcher{context.commandStack}
{
    auto lay = new QFormLayout{this};

    auto label = new QLabel{this};
    lay->addRow(tr("Banana count"), label);

    auto button = new QPushButton{tr("Add banana"), this};
    lay->addWidget(button);

    connect(button, &QPushButton::pressed,
            this, &Tutorial::InspectorWidget::addBanana);

    con(object, &Tutorial::ProcessModel::bananasChanged,
        this, [=] (int v) {
        label->setText(QString::number(v));
    });

    label->setText(QString::number(object.bananas()));
}

void InspectorWidget::addBanana()
{
    m_dispatcher.submitCommand<AddBanana>(process());
}

}
