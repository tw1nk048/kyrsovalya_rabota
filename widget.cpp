#include "widget.h"
#include "movecash.h"
#include "movetable.h"
#include "saveFile.h"
#include "loadFile.h"
#include "ui_widget.h"
#include <QFileDialog>

/* Функция для получения рандомного числа
 * в диапазоне от минимального до максимального
 * */
static int randomBetween(int low, int high) {
  return (rand() % ((high + 1) - low) + low);
}

Widget::Widget(QWidget *parent) : QWidget(parent), ui(new Ui::Widget) {
  ui->setupUi(this);

  this->resize(740, 740); // Устанавливаем размеры окна приложения
  this->setFixedSize(740, 740);

  scene = new myGraphicsScene();
  scene->setItemIndexMethod(
      QGraphicsScene::NoIndex); // настраиваем индексацию элементов

  ui->graphicsView->setScene(scene); // Устанавливаем графическую сцену в graphicsView
  ui->graphicsView->setRenderHint(QPainter::Antialiasing); // Настраиваем рендер
  ui->graphicsView->setViewportUpdateMode(QGraphicsView::BoundingRectViewportUpdate);
  scene->setSceneRect(0, 0, 740, 740); // Устанавливаем размер сцены
}

Widget::~Widget() { delete ui; }
void Widget::slotTable(QGraphicsItem *item) {
  if (set_remove)
    scene->removeItem(item);
  if (set_change) {
    flag += 30;
    item->setRotation(flag);
  }
}
void Widget::slotCash(QGraphicsItem *item) {
  if (set_remove)
    scene->removeItem(item);
  if (set_change) {
    flag += 30;
    item->setRotation(flag);
  }
}
void Widget::slotItem(QGraphicsItem *item) {
  if (set_remove)
    scene->removeItem(item);
  if (set_change) {
    flag += 30;
    item->setRotation(flag);
  }
}

// кнопки
void Widget::on_pushButton_clicked() {
  MoveItem *item = new MoveItem(); // Создаём графический элемент стелажа
  item->setPos(randomBetween(30, 470), randomBetween(30, 470)); // Устанавливаем случайную позицию элемента
  scene->addItem(item); // Добавляем элемент на графическую сцену
  connect(item, &MoveItem::signalFromElem, this, &Widget::slotItem);
}

void Widget::on_pushButton_2_clicked() {
  moveCash *item = new moveCash(); // Создаём графический элемент кассы
  item->setPos(randomBetween(30, 470), randomBetween(30, 470)); // Устанавливаем случайную позицию элемента
  scene->addItem(item); // Добавляем элемент на графическую сцену
  connect(item, &moveCash::signalFromElem, this, &Widget::slotCash);
}

void Widget::on_pushButton_3_clicked() {
  moveTable *item = new moveTable(); // Создаём графический элемент стола
  item->setPos(randomBetween(30, 470), randomBetween(30, 470));
  scene->addItem(item);
  connect(item, &moveTable::signalFromElem, this, &Widget::slotTable);
}

void Widget::on_pushButton_4_clicked() {
  exit(0); // выход из программы
}

void Widget::on_pushButton_5_clicked() {
  // очистка сцены
  scene->clear();
}

void Widget::on_pushButton_6_clicked() {
  // сохранить png
  QImage image(scene->width(), scene->height(), QImage::Format_ARGB32_Premultiplied);
  QPainter painter(&image);
  scene->render(&painter);

  QString fileName = QFileDialog::getSaveFileName(this, "Save base",QCoreApplication::applicationDirPath(), "") +".png";
    if (!fileName.isNull()) {
        QFile file(fileName);
        if (file.open(QIODevice::WriteOnly | QIODevice::Text | QIODevice::Truncate)) {
            QTextStream iStream(&file);
        image.save(fileName);
        file.close();
        }
    }
}

void Widget::on_checkBox_clicked(bool checked) // стены
{
  scene->flag_line = checked;
}

void Widget::on_checkBox_2_clicked(bool checked) // удаление
{
  set_remove = checked;
}

void Widget::on_checkBox_3_clicked(bool checked) // вращение
{
  set_change = checked;
}

void Widget::on_pushButton_8_clicked() {
  // сохранение
  SaveFile dialog = SaveFile();
  dialog.sl_saveSceneToFile(scene);
}

void Widget::on_pushButton_9_clicked() {
  // загрузка
  LoadFile load = LoadFile();
  load.sl_loadSceneToFile(scene);
  scene->update();
}
