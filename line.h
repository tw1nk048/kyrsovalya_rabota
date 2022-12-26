#pragma once

#include <QDebug>
#include <QGraphicsItem>
#include <QGraphicsSceneMouseEvent>
#include <QObject>
#include <QGraphicsScene>
#include <QPainter>
#include <QCursor>
#include <qgraphicsitem.h>

class Line : public QObject, public QGraphicsItem {
  Q_OBJECT
  // Свойство стартовой точки, относительно которой отрисовываем фигуру
  Q_PROPERTY(QPointF startPoint READ startPoint WRITE setStartPoint NOTIFY pointChanged)
  // Свойство конечно точки, до куда отрисовываем фигуру
  Q_PROPERTY(QPointF endPoint READ endPoint WRITE setEndPoint NOTIFY pointChanged)

public:
  explicit Line(QPointF point, QObject *parent = 0);
  ~Line();

  QPointF startPoint() const; // Стартовая точка
  QPointF endPoint() const;   // Конечная точка
  Line* clone();

  void setStartPoint(const QPointF point); // Установка стартовой точки
  void setEndPoint(const QPointF point); // Установка конечной точки

  // virtual Line* clone() = 0;

signals:
  void pointChanged(); // Сигнал об изменении точки

private:
  QPointF m_startPoint; // Стартовая точка
  QPointF m_endPoint;   // Конечная точка

  QRectF boundingRect() const; // Область, в которой содержится фигура
  void paint(QPainter *painter, const QStyleOptionGraphicsItem *option,QWidget *widget);

public slots:
  void updateRomb(); // Слот обновления области, в которой содержится фигура
};
