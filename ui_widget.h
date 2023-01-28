/********************************************************************************
** Form generated from reading UI file 'widget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_WIDGET_H
#define UI_WIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>
#include <qcustomplot.h>

QT_BEGIN_NAMESPACE

class Ui_Widget
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_3;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QComboBox *COM;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QComboBox *BautRate;
    QPushButton *openSerial_btn;
    QLabel *label_3;
    QPlainTextEdit *plainTextEdit;
    QVBoxLayout *verticalLayout_3;
    QPushButton *plot_btn;
    QCustomPlot *plot;

    void setupUi(QWidget *Widget)
    {
        if (Widget->objectName().isEmpty())
            Widget->setObjectName(QStringLiteral("Widget"));
        Widget->resize(1177, 621);
        gridLayout = new QGridLayout(Widget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(Widget);
        label->setObjectName(QStringLiteral("label"));
        label->setMinimumSize(QSize(45, 21));
        label->setMaximumSize(QSize(45, 21));

        horizontalLayout->addWidget(label);

        COM = new QComboBox(Widget);
        COM->setObjectName(QStringLiteral("COM"));
        COM->setMinimumSize(QSize(87, 21));
        COM->setMaximumSize(QSize(87, 21));

        horizontalLayout->addWidget(COM);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label_2 = new QLabel(Widget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMinimumSize(QSize(45, 21));
        label_2->setMaximumSize(QSize(45, 21));

        horizontalLayout_2->addWidget(label_2);

        BautRate = new QComboBox(Widget);
        BautRate->setObjectName(QStringLiteral("BautRate"));
        BautRate->setMinimumSize(QSize(87, 21));
        BautRate->setMaximumSize(QSize(87, 21));

        horizontalLayout_2->addWidget(BautRate);


        verticalLayout->addLayout(horizontalLayout_2);


        horizontalLayout_3->addLayout(verticalLayout);

        openSerial_btn = new QPushButton(Widget);
        openSerial_btn->setObjectName(QStringLiteral("openSerial_btn"));
        openSerial_btn->setMinimumSize(QSize(171, 51));
        openSerial_btn->setMaximumSize(QSize(171, 51));

        horizontalLayout_3->addWidget(openSerial_btn);


        verticalLayout_2->addLayout(horizontalLayout_3);

        label_3 = new QLabel(Widget);
        label_3->setObjectName(QStringLiteral("label_3"));

        verticalLayout_2->addWidget(label_3);

        plainTextEdit = new QPlainTextEdit(Widget);
        plainTextEdit->setObjectName(QStringLiteral("plainTextEdit"));
        QSizePolicy sizePolicy(QSizePolicy::Preferred, QSizePolicy::Preferred);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(plainTextEdit->sizePolicy().hasHeightForWidth());
        plainTextEdit->setSizePolicy(sizePolicy);
        plainTextEdit->setMinimumSize(QSize(321, 511));
        plainTextEdit->setMaximumSize(QSize(321, 511));

        verticalLayout_2->addWidget(plainTextEdit);


        gridLayout->addLayout(verticalLayout_2, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QStringLiteral("verticalLayout_3"));
        plot_btn = new QPushButton(Widget);
        plot_btn->setObjectName(QStringLiteral("plot_btn"));

        verticalLayout_3->addWidget(plot_btn);

        plot = new QCustomPlot(Widget);
        plot->setObjectName(QStringLiteral("plot"));
        plot->setMinimumSize(QSize(821, 511));
        plot->setMaximumSize(QSize(821, 511));

        verticalLayout_3->addWidget(plot);


        gridLayout->addLayout(verticalLayout_3, 0, 1, 1, 1);


        retranslateUi(Widget);

        QMetaObject::connectSlotsByName(Widget);
    } // setupUi

    void retranslateUi(QWidget *Widget)
    {
        Widget->setWindowTitle(QApplication::translate("Widget", "Widget", Q_NULLPTR));
        label->setText(QApplication::translate("Widget", "\344\270\262\345\217\243\345\217\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("Widget", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        BautRate->clear();
        BautRate->insertItems(0, QStringList()
         << QApplication::translate("Widget", "9600", Q_NULLPTR)
         << QApplication::translate("Widget", "19200", Q_NULLPTR)
         << QApplication::translate("Widget", "38400", Q_NULLPTR)
         << QApplication::translate("Widget", "57600", Q_NULLPTR)
         << QApplication::translate("Widget", "115200", Q_NULLPTR)
         << QApplication::translate("Widget", "230400", Q_NULLPTR)
         << QApplication::translate("Widget", "460800", Q_NULLPTR)
        );
        openSerial_btn->setText(QApplication::translate("Widget", "\346\211\223\345\274\200\344\270\262\345\217\243", Q_NULLPTR));
        label_3->setText(QApplication::translate("Widget", "\350\241\200\347\263\226\346\265\223\345\272\246\357\274\232", Q_NULLPTR));
        plot_btn->setText(QApplication::translate("Widget", "\345\256\236\346\227\266\346\233\262\347\272\277", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Widget: public Ui_Widget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_WIDGET_H
