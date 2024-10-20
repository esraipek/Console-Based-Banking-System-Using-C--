#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "anasayfa.h"
#include <QMessageBox>
#include "musteri.h"


#include <QtSql>
#include <QDebug>
#include <QFileInfo>



QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::MainWindow *ui;
    anasayfa *yeni_sayfa;
    QSqlDatabase mydb;
    void checkLogin(const QString& enteredTckn, const QString& enteredPassword);

    //void loadCustomers(); // Veritabanından müşteri çekme
    //bunlar prototip işlevlerini cpp dosyasında yazıyorum.

    //Customer *musteri;//customer=konteynır sınıfı.



    //Qlist i sqlite ı bağlayınca silmeyi unutma.

    //customers listesi oluşturdum
   // QList <Customer*> customer_list;

};
#endif // MAINWINDOW_H
