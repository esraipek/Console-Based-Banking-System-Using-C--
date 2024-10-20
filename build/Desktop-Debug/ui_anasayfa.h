/********************************************************************************
** Form generated from reading UI file 'anasayfa.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_ANASAYFA_H
#define UI_ANASAYFA_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_anasayfa
{
public:
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;

    void setupUi(QWidget *anasayfa)
    {
        if (anasayfa->objectName().isEmpty())
            anasayfa->setObjectName("anasayfa");
        anasayfa->resize(400, 300);
        anasayfa->setStyleSheet(QString::fromUtf8("background-color: rgb(32, 74, 135);"));
        label = new QLabel(anasayfa);
        label->setObjectName("label");
        label->setGeometry(QRect(210, 60, 161, 41));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(196, 160, 0);"));
        label_2 = new QLabel(anasayfa);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(60, 60, 81, 31));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        label_3 = new QLabel(anasayfa);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(60, 140, 81, 31));
        label_3->setStyleSheet(QString::fromUtf8("background-color: rgb(243, 243, 243);"));
        label_4 = new QLabel(anasayfa);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(210, 130, 161, 41));
        label_4->setStyleSheet(QString::fromUtf8("background-color: rgb(196, 160, 0);"));
        pushButton_2 = new QPushButton(anasayfa);
        pushButton_2->setObjectName("pushButton_2");
        pushButton_2->setGeometry(QRect(220, 210, 131, 31));
        pushButton_3 = new QPushButton(anasayfa);
        pushButton_3->setObjectName("pushButton_3");
        pushButton_3->setGeometry(QRect(30, 210, 131, 31));

        retranslateUi(anasayfa);

        QMetaObject::connectSlotsByName(anasayfa);
    } // setupUi

    void retranslateUi(QWidget *anasayfa)
    {
        anasayfa->setWindowTitle(QCoreApplication::translate("anasayfa", "Form", nullptr));
        label->setText(QCoreApplication::translate("anasayfa", "10000 ", nullptr));
        label_2->setText(QCoreApplication::translate("anasayfa", "bakiye", nullptr));
        label_3->setText(QCoreApplication::translate("anasayfa", "iban", nullptr));
        label_4->setText(QCoreApplication::translate("anasayfa", "TR1111", nullptr));
        pushButton_2->setText(QCoreApplication::translate("anasayfa", "hesap hareketleri", nullptr));
        pushButton_3->setText(QCoreApplication::translate("anasayfa", "para transferi", nullptr));
    } // retranslateUi

};

namespace Ui {
    class anasayfa: public Ui_anasayfa {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_ANASAYFA_H
