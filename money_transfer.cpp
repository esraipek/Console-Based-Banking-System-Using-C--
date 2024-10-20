#include "money_transfer.h"
#include "ui_money_transfer.h"
#include "musteri.h"
#include <QSqlError>
#include <QSqlDatabase>
#include <QMessageBox>

money_transfer::money_transfer( Customer* giren_customer, QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::money_transfer)
  , giren_customer(giren_customer)  // Sınıf üyesini başlat
{
    ui->setupUi(this);

   // Veritabanı bağlantısını sağla
    mydb = QSqlDatabase::addDatabase("QSQLITE","cc_connection");
    mydb.setDatabaseName("/home/esraipek/db_kutuphanesi/yeni_datab.db");
    mydb.open();

}

money_transfer::~money_transfer()
{
    delete ui;
    mydb.close();
}
void money_transfer::on_buton_gonder_clicked()
{

    QString gonderilen_iban = ui->line_iban->text();
    double gonderilen_tutar = ui->line_tutar->text().toDouble();

    QString gonderici_iban = giren_customer->getIban();
    qDebug() << "gonderici_iban:" << gonderici_iban;

    double gonderici_balance = giren_customer->getBalance();
    qDebug() << "gonderici_balance:" << gonderici_balance;

    QSqlQuery query(mydb);
    QString queryString = "SELECT balance FROM yeni_musteri WHERE iban = :iban";
    query.prepare(queryString);
    query.bindValue(":iban", gonderilen_iban);

    if (!query.exec()) {
        QMessageBox::critical(this, "Query Error", "sorgu yapılamadı " + query.lastError().text());
        qDebug() << "Query Error: " << query.lastError().text();
        return;
    }

    if (!query.next()) {
        QMessageBox::warning(this, "IBAN Not Found", "Iban bulunamadı.");
        return;
    }

    double alici_balance = query.value("balance").toDouble();

    if (gonderilen_tutar <= gonderici_balance && gonderilen_tutar <= 10000 && gonderilen_tutar >= 0) {
        QSqlQuery update_alici_query(mydb);
        update_alici_query.prepare("UPDATE yeni_musteri SET balance = balance + :gonderilen_tutar WHERE iban = :gonderilen_iban");
        update_alici_query.bindValue(":gonderilen_tutar", gonderilen_tutar);
        update_alici_query.bindValue(":gonderilen_iban", gonderilen_iban);

        if (!update_alici_query.exec()) {
            QMessageBox::critical(this, "Query Error", "alıcı balance i güncellenemedi " + update_alici_query.lastError().text());
            qDebug() << "Query Error: " << update_alici_query.lastError().text();
            return;
        }

        QSqlQuery update_gonderen_query(mydb);
        update_gonderen_query.prepare("UPDATE yeni_musteri SET balance = balance - :gonderilen_tutar WHERE iban = :gonderici_iban");
        update_gonderen_query.bindValue(":gonderilen_tutar", gonderilen_tutar);
        update_gonderen_query.bindValue(":gonderici_iban", gonderici_iban);

        if (!update_gonderen_query.exec()) {
            QMessageBox::critical(this, "Query Error", "gonderici bakiyesi güncellenemedi.: " + update_gonderen_query.lastError().text());
            qDebug() << "Query Error: " << update_gonderen_query.lastError().text();
            return;
        }

        giren_customer->setBalance(gonderici_balance - gonderilen_tutar);

        QMessageBox::information(this, "Transfer Successful", "transfer başarılı");
    } else {
        QMessageBox::warning(this, "Transfer Failed", "gönderilen tutar bakiyenizden daha az ve tek seferde 10.000 tlden daha az olmalı.");
    }
}
