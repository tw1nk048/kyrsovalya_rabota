#ifndef MOVECASH_H
#define MOVECASH_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

class moveCash : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit moveCash(QObject *parent = 0);
    ~moveCash();
    void setLine(bool new_val);
    int width = 150;
    int height = 60;
signals:
    void signalFromElem(QGraphicsItem *pressElem); // сигнал для удаления
private:
    bool is_painting; // для кнопки
    QRectF boundingRect() const;
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget);
    void mouseMoveEvent(QGraphicsSceneMouseEvent *event);
    void mousePressEvent(QGraphicsSceneMouseEvent *event);
    void mouseReleaseEvent(QGraphicsSceneMouseEvent *event);
};

#endif // MOVECASH_H
