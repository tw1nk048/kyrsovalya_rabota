#pragma once
#ifndef WIDGET_H
#define WIDGET_H

#include "ui_widget.h"
#include <QGraphicsScene>
#include <QResizeEvent>
#include <QWidget>

#include "line.h"
#include "scene.h"
#include "loadFile.h"
#include <movecash.h>
#include <moveitem.h>
#include <movetable.h>

namespace Ui {
class Widget;
}

class Widget : public QWidget {
  Q_OBJECT

public:
  explicit Widget(QWidget *parent = 0);
  ~Widget();

public slots:
  void slotTable(QGraphicsItem *item);
  void slotCash(QGraphicsItem *item);
  void slotItem(QGraphicsItem *item);
  void on_pushButton_clicked();

  void on_pushButton_2_clicked();

  void on_pushButton_4_clicked();

  void on_pushButton_3_clicked();

  void on_pushButton_5_clicked();

private slots:
  void on_pushButton_6_clicked();

  void on_checkBox_clicked(bool checked);

  void on_pushButton_8_clicked();

  void on_checkBox_2_clicked(bool checked);

  void on_checkBox_3_clicked(bool checked);
  void on_pushButton_9_clicked();

private:
  Ui::Widget *ui;
  bool set_remove = false;
  bool set_change = false;
  int flag = 0;
  myGraphicsScene *scene;
};

#endif // WIDGET_H
