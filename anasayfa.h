#ifndef ANASAYFA_H
#define ANASAYFA_H

#include <QWidget>
#include "musteri.h"

#include <QtSql>
#include <QDebug>
#include <QFileInfo>

#include "money_transfer.h"

namespace Ui {
class anasayfa;
}

class anasayfa : public QWidget
{
    Q_OBJECT

public:
    explicit anasayfa(Customer* giren_customer ,QWidget *parent = nullptr);
    ~anasayfa();



    void setcustomeriban_balance(Customer* giren_customer);





private slots:

    void on_pushButton_3_clicked();

private:
    Ui::anasayfa *ui;

    QSqlDatabase mydb;
    Customer* giren_customer;


    money_transfer *mt_page;


};

#endif // ANASAYFA_H
