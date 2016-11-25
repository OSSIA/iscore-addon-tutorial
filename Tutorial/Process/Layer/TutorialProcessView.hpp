#pragma once
#include <Process/LayerView.hpp>

namespace Tutorial
{
class TutorialView final : public Process::LayerView
{
    public:
        explicit TutorialView(QGraphicsItem* parent);

    private:
        void paint_impl(QPainter*) const override;
};
}
