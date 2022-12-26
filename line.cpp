#include "line.h"
#include <iostream>

Line::Line(QPointF point, QObject *parent)
    : QObject(parent), QGraphicsItem() {
  this->setStartPoint(mapFromScene(point));
  this->setEndPoint(mapFromScene(point));

  connect(this, &Line::pointChanged, this, &Line::updateRomb);
}

Line::~Line() {}

QRectF Line::boundingRect() const {
  return QRectF(
      (endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) -
          5,
      (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) -
          5,
      qAbs(endPoint().x() - startPoint().x()) + 10,
      qAbs(endPoint().y() - startPoint().y()) + 10); }
void Line::updateRomb() {
  this->update(
      (endPoint().x() > startPoint().x() ? startPoint().x() : endPoint().x()) -
          5,
      (endPoint().y() > startPoint().y() ? startPoint().y() : endPoint().y()) -
          5,
      qAbs(endPoint().x() - startPoint().x()) + 10,
      qAbs(endPoint().y() - startPoint().y()) + 10);
}

void Line::setStartPoint(const QPointF point) {
  m_startPoint = mapFromScene(point);
  emit pointChanged();
}

void Line::setEndPoint(const QPointF point) {
  m_endPoint = mapFromScene(point);
  emit pointChanged();
}

QPointF Line::startPoint() const { return m_startPoint; }

QPointF Line::endPoint() const { return m_endPoint; }

void Line::paint(QPainter *painter, const QStyleOptionGraphicsItem *option,
                      QWidget *widget) {
  painter->setPen(QPen(Qt::white, 2));

  painter->drawLine(startPoint(), endPoint());

  Q_UNUSED(option)
  Q_UNUSED(widget)
}

