#include "cryptography.h"
#include "ui_cryptography.h"
#include "encrypt.h"
#include "decrypt.h"

#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include <QMessageBox>
#include <QDebug>

#include <math.h>

Cryptography::Cryptography(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Cryptography)
{
    ui->setupUi(this);
    ui->stackedWidget->setCurrentIndex(0);
}

Cryptography::~Cryptography()
{
    delete ui;
}

int Cryptography::prime(long int pr)
{
   int i, j;
   j = int(sqrt(pr));
   for(i = 2; i <= j; i++)
   {
      if(pr % i == 0)
         return 0;
   }
   return 1;
 }

void Cryptography::navigatePages(int pageNumber)
{
    ui->stackedWidget->setCurrentIndex(pageNumber);
}

void Cryptography::on_encryptText_clicked()
{
    navigatePages(1);
}

void Cryptography::on_decryptText_clicked()
{
    navigatePages(2);
}

void Cryptography::on_homeFromEncrypt_clicked()
{
    navigatePages(0);
}

void Cryptography::on_homeFromDecrypt_clicked()
{
    navigatePages(0);
}


long int Cryptography::n;

void Cryptography::on_encryptTextBtn_clicked()
{
    QString temp = ui->firstPrimeET->toPlainText();
    int x = temp.toInt();
    temp = ui->secondPrimeET->toPlainText();
    int y = temp.toInt();
    Encrypt encryptObject;
    long int e, d;
    long int *keys;
    keys = encryptObject.encryption_key(x, y);
    e = keys[0];
    d = keys[1];
    n = keys[3];
    char message[100], out[100];
    temp = ui->tobeEncryptedText->toPlainText();
    memcpy(message, temp.toStdString().c_str(), temp.size());
    encryptObject.encrypt(message, out, e);
    QString output(out);
    qDebug() << d;
    ui->encryptedText->setText(output);
}

void Cryptography::on_DecrptTextBtn_clicked()
{
    QString temp = ui->privateKeyText->toPlainText();
    long int privateKey = temp.toLong();
    Decrypt decryptObject;
    temp = ui->DecryptedText->toPlainText();
    char message[100], out[100];
    memcpy(message, temp.toStdString().c_str(), temp.size());
    decryptObject.decrypt(privateKey, n, message, out);
    QString output(out);
    ui->EncryptedText->setText(output);
}
