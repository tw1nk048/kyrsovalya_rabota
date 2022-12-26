#include <iostream>
#include "saveFile.h"
#include "QtWidgets/qapplication.h"
#include "QtWidgets/qgraphicsitem.h"
#include "widget.h"
#include "line.h"
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

SaveFile::SaveFile(QWidget *parent) : QDialog(parent) { resize(270, 200); }

SaveFile::~SaveFile() {}

void SaveFile::sl_saveSceneToFile(QGraphicsScene *scene) {
  QJsonArray figures;

  foreach (QGraphicsItem *item, scene->items()) {
    QJsonObject jsonFigure;
    if (dynamic_cast<MoveItem *>(item) != nullptr) {
      MoveItem *moveitem = (MoveItem *)item;
      jsonFigure["xCoordinates"] = moveitem->x();
      jsonFigure["yCoordinates"] = moveitem->y();
      jsonFigure["type"] = 1;
    } else if (dynamic_cast<moveTable *>(item) != nullptr) {
      moveTable *table = (moveTable *)item;
      jsonFigure["xCoordinates"] = table->x();
      jsonFigure["yCoordinates"] = table->y();
      jsonFigure["type"] = 2;
    } else if (dynamic_cast<moveCash *>(item) != nullptr) {
      moveCash *cash = (moveCash *)item;
      jsonFigure["xCoordinates"] = cash->x();
      jsonFigure["yCoordinates"] = cash->y();
      jsonFigure["type"] = 3;
    } else {
      Line *line = (Line *)item;
      jsonFigure["startXCoordinates"] = line->startPoint().x();
      jsonFigure["startYCoordinates"] = line->startPoint().y();
      jsonFigure["endXCoordinates"] = line->endPoint().x();
      jsonFigure["endYCoordinates"] = line->endPoint().y();
      jsonFigure["type"] = 0;
    }
    figures.append(jsonFigure);
  }

  QJsonDocument document(figures);
  QByteArray bytes = document.toJson(QJsonDocument::Indented);

  QString fileName = QFileDialog::getSaveFileName(
      this, "Save base", QCoreApplication::applicationDirPath(),
      "") + ".json";
  if (!fileName.isNull()) {
    QFile file(fileName);
    if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
      QTextStream iStream(&file);
      iStream << bytes;
      file.close();
    } else {
      std::cout << "file open failed" << std::endl;
    }
  }
}
