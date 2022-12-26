#ifndef LOADFILE_H
#define LOADFILE_H
#include "QtWidgets/qgraphicsitem.h"
#include <QDialog>
#include "line.h"

class QGraphicsScene;
class moveTable;
class MoveItem;
class moveCash;
class line;
class QGraphicsView;
class QVBoxLayout;

class LoadFile : public QDialog
{
    Q_OBJECT
public:
    LoadFile();
    ~LoadFile();

    void sl_loadSceneToFile(QGraphicsScene *scene);
};

#endif // LOADFILE_H
