#include "loadFile.h"
#include "QtWidgets/qapplication.h"
#include "QtWidgets/qgraphicsitem.h"
#include "widget.h"
#include <QFileDialog>

#include <QDir>
#include <QFile>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QList>
#include <QMessageBox>
#include <QPushButton>
#include <QVBoxLayout>
#include <QXmlStreamWriter>
#include <QJsonArray>
#include <QJsonDocument>
#include <QJsonObject>

LoadFile::LoadFile() {}

LoadFile::~LoadFile() {}

void LoadFile::sl_loadSceneToFile(QGraphicsScene *scene) {
  std::cout << "LOAD\n";
  QString fileName = QFileDialog::getOpenFileName(
      this, "Load base", QCoreApplication::applicationDirPath(),
      "");
  if (!fileName.isNull()) {
    QFile file(fileName);
    if (file.open(QIODevice::ReadOnly)) {
      QByteArray bytes = file.readAll();
      file.close();

      QJsonParseError jsonError;
      QJsonDocument document = QJsonDocument::fromJson(bytes, &jsonError);
      if (document.isArray()) {
        QJsonArray jsonArr = document.array();
        scene->clear();
        int start_x, start_y, end_x, end_y;
        Line *figure;
        MoveItem *move_item;
        moveTable *move_table;
        moveCash *move_cash;

        for (int i = 0; i < jsonArr.count(); ++i) {
          QJsonObject jsonObj = jsonArr.at(i).toObject();
          int type = jsonObj.take("type").toInt();

          switch (type) {
            case 0:
              // Line
              start_x = jsonObj.take("startXCoordinates").toInt();
              start_y = jsonObj.take("startYCoordinates").toInt();
              end_x = jsonObj.take("endXCoordinates").toInt();
              end_y = jsonObj.take("endYCoordinates").toInt();
              figure = new Line(QPointF(start_x, start_y));
              figure->setEndPoint(QPointF(end_x, end_y));
              scene->addItem(figure);
              break;
            case 1:
              // MoveItem
              start_x = jsonObj.take("xCoordinates").toInt();
              start_y = jsonObj.take("yCoordinates").toInt();
              move_item = new MoveItem();        // Создаём графический элемент стелажа
              move_item->setPos(start_x, start_y);
              scene->addItem(move_item);   // Добавляем элемент на графическую сцену
              break;
            case 2:
              // moveTable
              start_x = jsonObj.take("xCoordinates").toInt();
              start_y = jsonObj.take("yCoordinates").toInt();
              move_table = new moveTable();        // Создаём графический элемент стелажа
              move_table->setPos(start_x, start_y);
              scene->addItem(move_table);   // Добавляем элемент на графическую сцену
              break;
            case 3:
              // moveCash
              start_x = jsonObj.take("xCoordinates").toInt();
              start_y = jsonObj.take("yCoordinates").toInt();
              move_cash = new moveCash();        // Создаём графический элемент стелажа
              move_cash->setPos(start_x, start_y);
              move_cash->update();
              scene->addItem(move_cash);   // Добавляем элемент на графическую сцену
              break;
          }
        }
      }
    }
  }
}
