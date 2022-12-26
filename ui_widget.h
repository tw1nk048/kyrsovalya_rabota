/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 6.4.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QGraphicsView>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QPushButton *pushButton_5;
    QCheckBox *checkBox_2;
    QPushButton *pushButton_6;
    QPushButton *pushButton_9;
    QCheckBox *checkBox;
    QPushButton *pushButton;
    QPushButton *pushButton_3;
    QGraphicsView *graphicsView;
    QPushButton *pushButton_8;
    QPushButton *pushButton_2;
    QPushButton *pushButton_4;
    QCheckBox *checkBox_3;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName("Widget");
        Widget->resize(685, 343);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName("gridLayout");
        pushButton_5 = new QPushButton(Widget);
        pushButton_5->setObjectName("pushButton_5");

        gridLayout->addWidget(pushButton_5, 8, 0, 1, 1);

        checkBox_2 = new QCheckBox(Widget);
        checkBox_2->setObjectName("checkBox_2");

        gridLayout->addWidget(checkBox_2, 1, 1, 1, 1);

        pushButton_6 = new QPushButton(Widget);
        pushButton_6->setObjectName("pushButton_6");
        pushButton_6->setEnabled(true);

        gridLayout->addWidget(pushButton_6, 5, 0, 1, 1);

        pushButton_9 = new QPushButton(Widget);
        pushButton_9->setObjectName("pushButton_9");

        gridLayout->addWidget(pushButton_9, 5, 2, 1, 1);

        checkBox = new QCheckBox(Widget);
        checkBox->setObjectName("checkBox");

        gridLayout->addWidget(checkBox, 1, 0, 1, 1);

        pushButton = new QPushButton(Widget);
        pushButton->setObjectName("pushButton");

        gridLayout->addWidget(pushButton, 0, 2, 1, 1);

        pushButton_3 = new QPushButton(Widget);
        pushButton_3->setObjectName("pushButton_3");

        gridLayout->addWidget(pushButton_3, 0, 0, 1, 1);

        graphicsView = new QGraphicsView(Widget);
        graphicsView->setObjectName("graphicsView");

        gridLayout->addWidget(graphicsView, 4, 0, 1, 3);

        pushButton_8 = new QPushButton(Widget);
        pushButton_8->setObjectName("pushButton_8");

        gridLayout->addWidget(pushButton_8, 5, 1, 1, 1);

        pushButton_2 = new QPushButton(Widget);
        pushButton_2->setObjectName("pushButton_2");

        gridLayout->addWidget(pushButton_2, 0, 1, 1, 1);

        pushButton_4 = new QPushButton(Widget);
        pushButton_4->setObjectName("pushButton_4");

        gridLayout->addWidget(pushButton_4, 8, 2, 1, 1);

        checkBox_3 = new QCheckBox(Widget);
        checkBox_3->setObjectName("checkBox_3");

        gridLayout->addWidget(checkBox_3, 1, 2, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QCoreApplication::translate("Widget", "Widget", nullptr));
        pushButton_5->setText(QCoreApplication::translate("Widget", "\320\236\321\207\320\270\321\201\321\202\320\272\320\260", nullptr));
        checkBox_2->setText(QCoreApplication::translate("Widget", "\320\243\320\264\320\260\320\273\320\265\320\275\320\270\320\265", nullptr));
        pushButton_6->setText(QCoreApplication::translate("Widget", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 png", nullptr));
        pushButton_9->setText(QCoreApplication::translate("Widget", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\201 json", nullptr));
        checkBox->setText(QCoreApplication::translate("Widget", "\320\241\321\202\320\265\320\275\321\213", nullptr));
        pushButton->setText(QCoreApplication::translate("Widget", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\321\202\320\265\320\273\320\260\320\266", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Widget", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\205\320\276\320\273\320\276\320\264\320\270\320\273\321\214\320\275\320\270\320\272 \320\264\320\273\321\217 \321\202\320\276\320\262\320\260\321\200\320\276\320\262", nullptr));
        pushButton_8->setText(QCoreApplication::translate("Widget", "\320\241\320\276\321\205\321\200\320\260\320\275\320\270\321\202\321\214 json", nullptr));
        pushButton_2->setText(QCoreApplication::translate("Widget", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \320\272\320\260\321\201\321\201\321\203", nullptr));
        pushButton_4->setText(QCoreApplication::translate("Widget", "\320\222\321\213\321\205\320\276\320\264", nullptr));
        checkBox_3->setText(QCoreApplication::translate("Widget", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
