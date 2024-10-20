/********************************************************************************
** Form generated from reading UI file 'money_transfer.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MONEY_TRANSFER_H
#define UI_MONEY_TRANSFER_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_money_transfer
{
public:
    QLabel *label;
    QLabel *label_2;
    QLineEdit *line_iban;
    QLineEdit *line_tutar;
    QPushButton *buton_gonder;

    void setupUi(QWidget *money_transfer)
    {
        if (money_transfer->objectName().isEmpty())
            money_transfer->setObjectName("money_transfer");
        money_transfer->resize(816, 475);
        money_transfer->setStyleSheet(QString::fromUtf8("background-color: rgb(239, 41, 41);\n"
"background-color: rgb(32, 74, 135);"));
        label = new QLabel(money_transfer);
        label->setObjectName("label");
        label->setGeometry(QRect(100, 60, 141, 31));
        label->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 233, 79);"));
        label_2 = new QLabel(money_transfer);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(100, 140, 141, 31));
        label_2->setStyleSheet(QString::fromUtf8("background-color: rgb(252, 233, 79);"));
        line_iban = new QLineEdit(money_transfer);
        line_iban->setObjectName("line_iban");
        line_iban->setGeometry(QRect(392, 60, 251, 41));
        line_iban->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        line_tutar = new QLineEdit(money_transfer);
        line_tutar->setObjectName("line_tutar");
        line_tutar->setGeometry(QRect(390, 130, 251, 41));
        line_tutar->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 255, 255);"));
        buton_gonder = new QPushButton(money_transfer);
        buton_gonder->setObjectName("buton_gonder");
        buton_gonder->setGeometry(QRect(450, 230, 121, 51));

        retranslateUi(money_transfer);

        QMetaObject::connectSlotsByName(money_transfer);
    } // setupUi

    void retranslateUi(QWidget *money_transfer)
    {
        money_transfer->setWindowTitle(QCoreApplication::translate("money_transfer", "Form", nullptr));
        label->setText(QCoreApplication::translate("money_transfer", "G\303\266nderilecek iban", nullptr));
        label_2->setText(QCoreApplication::translate("money_transfer", "G\303\266nderilecek tutar", nullptr));
        buton_gonder->setText(QCoreApplication::translate("money_transfer", "G\303\266nder", nullptr));
    } // retranslateUi

};

namespace Ui {
    class money_transfer: public Ui_money_transfer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MONEY_TRANSFER_H
