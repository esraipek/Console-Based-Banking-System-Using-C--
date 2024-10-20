#ifndef MUSTERI_H
#define MUSTERI_H

#include <QString>

class Customer {
private:
    QString tckn;
    QString name;
    QString password;
    QString iban;
    double balance;

public:
    // Constructor (Yapıcı Fonksiyon)
    Customer()=default;




    Customer(const QString& tckn,const QString& name, const QString& password,const QString& iban, double balance)
        : tckn(tckn),name(name), password(password),iban(iban), balance(balance) {}

    // Getter ve Setter Fonksiyonları
    QString getTckn()const{return tckn;}
    void setTckn(const QString& tckn){this->tckn=tckn;}
    QString getName() const { return name; }
    void setName(const QString& name) { this->name = name; }
    QString getPassword()const{return password;}
    void setPassword(const QString& password){this->password=password;}
    QString getIban() const { return iban; }
    void setIban(const QString& iban) { this->iban = iban; }
    double getBalance()  { return balance; }
    void setBalance(double balance) { this->balance = balance; }


};

#endif // MUSTERI_H
