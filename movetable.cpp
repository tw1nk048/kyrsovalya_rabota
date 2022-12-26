#include "movetable.h"
#include <iostream>

moveTable::moveTable(QObject *parent) :
    QObject(parent), QGraphicsItem()
{
}

moveTable::~moveTable()
{

}

QRectF moveTable::boundingRect() const
{
    return QRectF (0, 0, width, height);
}

void moveTable::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QImage image(":/holod.png");
    QRect recrangle(0, 0, width, height);
    /*painter->setPen(Qt::white);
    painter->setBrush(Qt::green);
    painter->drawRect(-30,-30,120,60);*/
    painter->drawImage(recrangle, image);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void moveTable::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
  this->setPos(mapToScene(event->pos()));
}

void moveTable::mousePressEvent(QGraphicsSceneMouseEvent *event)
{
    if(event->button() & Qt::RightButton){
        emit signalFromElem(this);
    }
    /* При нажатии мышью на графический элемент
     * заменяем курсор на руку, которая держит этот элемента
     * */
    this->setCursor(QCursor(Qt::ClosedHandCursor));
    Q_UNUSED(event);
}

void moveTable::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

void moveTable::setLine(bool new_val) {
    is_painting = new_val;
}

