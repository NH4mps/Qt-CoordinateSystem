#include "reversedtext.h"

ReversedText::ReversedText(QString text, QGraphicsItem *parent)
    :QGraphicsTextItem(text, parent)
{}

void ReversedText::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->save();
    painter->translate(0,boundingRect().height());
    painter->scale(1,-1);
    QGraphicsTextItem::paint(painter, option, widget);
    painter->restore();
}
