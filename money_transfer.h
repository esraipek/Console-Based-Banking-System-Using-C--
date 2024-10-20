#ifndef MONEY_TRANSFER_H
#define MONEY_TRANSFER_H

#include <QWidget>

#include "musteri.h"
#include <QtSql>
#include <QDebug>
#include <QFileInfo>

namespace Ui {
class money_transfer;
}

class money_transfer : public QWidget
{
    Q_OBJECT

public:
    explicit money_transfer(Customer* giren_customer ,QWidget *parent = nullptr);
    ~money_transfer();
    void setcustomeriban_balance(Customer* giren_customer);




private slots:
    void on_buton_gonder_clicked();

private:
    Ui::money_transfer *ui;

    QSqlDatabase mydb;
    Customer* giren_customer;
};

#endif // MONEY_TRANSFER_H
