#pragma once
#include <Process/LayerView.hpp>

namespace Tutorial
{
class TutorialView final : public Process::LayerView
{
    public:
        explicit TutorialView(QGraphicsItem* parent);

        void setText(const QString&);

    private:
        void paint_impl(QPainter*) const override;
        QString m_text;
};
}
