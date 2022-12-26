#include "movecash.h"

moveCash::moveCash(QObject *parent) :
    QObject(parent), QGraphicsItem()
{

}

moveCash::~moveCash()
{

}

QRectF moveCash::boundingRect() const
{
    return QRectF (0, 0, width, height);
}

void moveCash::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QImage image(":/cassa.png");
    QRect recrangle(0, 0, width, height);
    /*painter->setPen(Qt::white);
    painter->setBrush(Qt::green);
    painter->drawRect(-30,-30,120,60);*/
    painter->drawImage(recrangle, image);
    Q_UNUSED(option);
    Q_UNUSED(widget);
}

void moveCash::mouseMoveEvent(QGraphicsSceneMouseEvent *event)
{
    /* Устанавливаем позицию графического элемента
     * в графической сцене, транслировав координаты
     * курсора внутри графического элемента
     * в координатную систему графической сцены
     * */
    this->setPos(mapToScene(event->pos()));
}

void moveCash::mousePressEvent(QGraphicsSceneMouseEvent *event)
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

void moveCash::mouseReleaseEvent(QGraphicsSceneMouseEvent *event)
{
    /* При отпускании мышью элемента
     * заменяем на обычный курсор стрелку
     * */
    this->setCursor(QCursor(Qt::ArrowCursor));
    Q_UNUSED(event);
}

void moveCash::setLine(bool new_val) {
    is_painting = new_val;
}
