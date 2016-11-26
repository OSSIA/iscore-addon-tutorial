#include "TutorialProcessView.hpp"
#include <QPainter>
namespace Tutorial
{

TutorialView::TutorialView(
        QGraphicsItem* parent):
    LayerView{parent}
{

}

void TutorialView::paint_impl(QPainter* painter) const
{
    painter->drawText(QPointF{0, 0}, "Hello world");
}
}
