/********************************************************************************
** Form generated from reading UI file 'son.ui'
**
** Created by: Qt User Interface Compiler version 6.6.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SON_H
#define UI_SON_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_son
{
public:
    QPushButton *getbackButton;
    QLabel *label_2;
    QPushButton *confirmButton;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QPushButton *signalButton;
    QLineEdit *amountEdit;

    void setupUi(QWidget *son)
    {
        if (son->objectName().isEmpty())
            son->setObjectName("son");
        son->resize(400, 300);
        getbackButton = new QPushButton(son);
        getbackButton->setObjectName("getbackButton");
        getbackButton->setGeometry(QRect(10, 20, 101, 20));
        label_2 = new QLabel(son);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(40, 130, 111, 20));
        label_2->setAlignment(Qt::AlignCenter);
        confirmButton = new QPushButton(son);
        confirmButton->setObjectName("confirmButton");
        confirmButton->setGeometry(QRect(250, 130, 51, 20));
        layoutWidget = new QWidget(son);
        layoutWidget->setObjectName("layoutWidget");
        layoutWidget->setGeometry(QRect(40, 100, 308, 24));
        horizontalLayout = new QHBoxLayout(layoutWidget);
        horizontalLayout->setObjectName("horizontalLayout");
        horizontalLayout->setContentsMargins(0, 0, 0, 0);
        label = new QLabel(layoutWidget);
        label->setObjectName("label");
        label->setAlignment(Qt::AlignCenter);

        horizontalLayout->addWidget(label);

        signalButton = new QPushButton(layoutWidget);
        signalButton->setObjectName("signalButton");
        signalButton->setMaximumSize(QSize(30, 16777215));
        signalButton->setIconSize(QSize(13, 13));

        horizontalLayout->addWidget(signalButton);

        amountEdit = new QLineEdit(layoutWidget);
        amountEdit->setObjectName("amountEdit");

        horizontalLayout->addWidget(amountEdit);


        retranslateUi(son);

        QMetaObject::connectSlotsByName(son);
    } // setupUi

    void retranslateUi(QWidget *son)
    {
        son->setWindowTitle(QCoreApplication::translate("son", "\350\202\241\347\245\250\344\271\260\345\215\226\347\225\214\351\235\242", nullptr));
        getbackButton->setText(QCoreApplication::translate("son", "\350\277\224\345\233\236\344\270\212\344\270\200\344\270\252\351\241\265\351\235\242", nullptr));
        label_2->setText(QCoreApplication::translate("son", "(+\344\270\272\345\215\226\345\207\272\357\274\214-\344\270\272\344\271\260\345\205\245)", nullptr));
        confirmButton->setText(QCoreApplication::translate("son", "\347\241\256\345\256\232", nullptr));
        label->setText(QCoreApplication::translate("son", "\350\257\267\350\276\223\345\205\245\344\275\240\350\246\201\344\271\260/\345\215\226\345\207\272\347\232\204\344\273\275\351\242\235\357\274\232", nullptr));
        signalButton->setText(QCoreApplication::translate("son", "+", nullptr));
    } // retranslateUi

};

namespace Ui {
    class son: public Ui_son {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SON_H
