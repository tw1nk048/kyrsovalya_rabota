#ifndef MOVETABLE_H
#define MOVETABLE_H

#include <QObject>
#include <QGraphicsItem>
#include <QPainter>
#include <QGraphicsSceneMouseEvent>
#include <QDebug>
#include <QCursor>

class moveTable : public QObject, public QGraphicsItem
{
    Q_OBJECT
public:
    explicit moveTable(QObject *parent = 0);
    ~moveTable();
    void setLine(bool new_val);
    int width = 160;
    int height = 100;
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

#endif // MOVETABLE_H
