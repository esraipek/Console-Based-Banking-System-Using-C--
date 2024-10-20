#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


    QSqlDatabase mydb = QSqlDatabase::addDatabase("QSQLITE");
    mydb.setDatabaseName("/home/esraipek/db_kutuphanesi/yeni_datab.db");
    mydb.open();
}

MainWindow::~MainWindow()
{
    delete ui;
    mydb.close();
}

void MainWindow::on_pushButton_clicked()
{
    QString enteredTckn = ui->lineEdit->text();
    QString enteredPassword = ui->lineEdit_2->text();

    checkLogin(enteredTckn, enteredPassword);
}

void MainWindow::checkLogin(const QString& enteredTckn, const QString& enteredPassword)
{
    QSqlQuery query(mydb);


    QString queryString = "SELECT * FROM yeni_musteri WHERE tckn =:tckn AND password =:password";
    query.prepare(queryString);

    query.bindValue(":tckn", enteredTckn);
    query.bindValue(":password", enteredPassword);

    if (!query.exec()) {
        QMessageBox::critical(this, "Query Error", "Query execution failed: " + query.lastError().text());
        qDebug() << "Query Error: " << query.lastError().text();
        return;
    }

    if (query.exec()&&query.next()) {
        Customer* giren_customer=new Customer();
        giren_customer->setTckn(query.value("tckn").toString());
        giren_customer->setName(query.value("name").toString());
        giren_customer->setPassword(query.value("password").toString());
        giren_customer->setIban(query.value("iban").toString());
        giren_customer->setBalance(query.value("balance").toDouble());

        yeni_sayfa = new anasayfa(giren_customer);

        yeni_sayfa->setcustomeriban_balance(giren_customer);
        yeni_sayfa->show();
        this->close();
    } else {
        QMessageBox::warning(this, "Login Failed", "Incorrect TC or Password.");
    }
}

