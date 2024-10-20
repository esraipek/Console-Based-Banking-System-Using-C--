#include "anasayfa.h"
#include "ui_anasayfa.h"
#include "musteri.h"
#include <QSqlError>
#include <QSqlDatabase>
#include <QMessageBox>
#


anasayfa::anasayfa(Customer* giren_customer,QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::anasayfa)

{
    ui->setupUi(this);

     QSqlDatabase mydb= QSqlDatabase::database("QSQLITE","bb_connection");
      mydb.setDatabaseName("/home/esraipek/db_kutuphanesi/yeni_datab.db");
     mydb.open();


}

void anasayfa::setcustomeriban_balance(Customer* giren_customer) {
        ui->label->setText(QString::number(giren_customer->getBalance()));
        ui->label_4->setText(giren_customer->getIban());

}





anasayfa::~anasayfa()
{
    delete ui;
   // delete giren_customer;
    mydb.close();
}




void anasayfa::on_pushButton_3_clicked()
{


    mt_page=new money_transfer(giren_customer);
    mt_page->show();
    this->close();




}
