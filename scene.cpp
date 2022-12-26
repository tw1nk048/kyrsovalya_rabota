#include "scene.h"

myGraphicsScene::myGraphicsScene(QObject *parent)
    : QGraphicsScene(parent) {}

void myGraphicsScene::mousePressEvent(QGraphicsSceneMouseEvent *event) {
  QGraphicsScene::mousePressEvent(event);

  int mouse_x = event->scenePos().x(), mouse_y = event->scenePos().y();
  flag_move = false;

  QList<QGraphicsItem *> all = items();
  for (int i = 0; i < all.size(); i++) {
    QGraphicsItem *gi = all[i];
    if (dynamic_cast<Line *>(gi) != nullptr) {
      Line *fig = dynamic_cast<Line *>(gi);
      int start_x = std::min(fig->startPoint().x(), fig->endPoint().x());
      int start_y = std::min(fig->startPoint().y(), fig->endPoint().y());

      int end_x = std::max(fig->startPoint().x(), fig->endPoint().x());
      int end_y = std::max(fig->startPoint().y(), fig->endPoint().y());

      if (end_x >= mouse_x - 3 && mouse_x >= start_x - 3 && end_y >= mouse_y - 3 &&
          mouse_y >= start_y - 3) {
        flag_move = true;
        offset = event->scenePos();
        m_activeItem = fig;
        break;
      }
    } else if (dynamic_cast<moveTable *>(gi) != nullptr){
      moveTable *fig = dynamic_cast<moveTable*>(gi);

      int start_x = fig->pos().x();
      int start_y = fig->pos().y();

      int end_x = fig->width + fig->pos().x();
      int end_y = fig->height + fig->pos().y();

      if (end_x >= mouse_x && mouse_x >= start_x && end_y >= mouse_y &&
          mouse_y >= start_y) {
        flag_move = true;
        m_activeItem = nullptr;
        break;
      }
    } else if (dynamic_cast<MoveItem *>(gi) != nullptr){
      MoveItem *fig = dynamic_cast<MoveItem*>(gi);
      int start_x = fig->pos().x();
      int start_y = fig->pos().y();

      int end_x = fig->width + fig->pos().x();
      int end_y = fig->height + fig->pos().y();

      if (end_x >= mouse_x && mouse_x >= start_x && end_y >= mouse_y &&
          mouse_y >= start_y) {
        flag_move = true;
        m_activeItem = nullptr;
        break;
      }
    } else if (dynamic_cast<moveCash *>(gi) != nullptr){
      moveCash *fig = dynamic_cast<moveCash*>(gi);
      int start_x = fig->scenePos().x();
      int start_y = fig->scenePos().y();

      int end_x = fig->width + fig->pos().x();
      int end_y = fig->height + fig->pos().y();

      if (end_x >= mouse_x && mouse_x >= start_x && end_y >= mouse_y &&
          mouse_y >= start_y) {
        flag_move = true;
        m_activeItem = nullptr;
        break;
      }
    }
  }

  if (event->button() == Qt::RightButton) {
    delete m_activeItem;
    this->update(QRectF(0, 0, this->width(), this->height()));
    return;
  }
  if (!flag_move && flag_line){
    if (event->button() == Qt::LeftButton) {
      m_activeItem = new Line(event->scenePos());
      addItem(m_activeItem);
    }
  }
}

void myGraphicsScene::mouseMoveEvent(QGraphicsSceneMouseEvent *event) {
  QGraphicsScene::mouseMoveEvent(event);

  if (m_activeItem != nullptr) {
    if (flag_move) {
      QPointF start = m_activeItem->startPoint(),
              end = m_activeItem->endPoint();
      QPointF cursor = event->scenePos();
      m_activeItem->setStartPoint(cursor - (end - start) / 2);
      m_activeItem->setEndPoint(cursor + (end - start) / 2);
    } else {
      m_activeItem->setEndPoint(event->scenePos());
    }
  }
  this->update(QRectF(0, 0, this->width(), this->height()));
}

void myGraphicsScene::mouseReleaseEvent(QGraphicsSceneMouseEvent *event) {
  QGraphicsScene::mouseReleaseEvent(event);
  m_activeItem = nullptr;
}

