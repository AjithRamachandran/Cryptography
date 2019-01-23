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


long int Cryptography::n, Cryptography::tempArray[100];

void Cryptography::on_encryptTextBtn_clicked()
{
    bool shouldDisplay = true;
    QString temp = ui->firstPrimeET->toPlainText();
    int x = temp.toInt();
    temp = ui->secondPrimeET->toPlainText();
    int y = temp.toInt();
    if((prime(x) == 0) || (prime(y) == 0) || (x==y)) {
        QMessageBox::warning(this, "Error", "Numbers should be prime but not same!");
        ui->firstPrimeET->setText("");
        ui->secondPrimeET->setText("");
        ui->tobeEncryptedText->setText("");
        shouldDisplay = false;
    }
    Encrypt encryptObject;
    long int e, d;
    long int *keys;
    keys = encryptObject.encryption_key(x, y);
    e = keys[0];
    d = keys[1];
    n = keys[2];
    char message[100], out[100];
    temp = ui->tobeEncryptedText->toPlainText();
    memcpy(message, temp.toStdString().c_str(), size_t(temp.size()));
    encryptObject.encrypt(message, out, e, tempArray);
    QString output(out);
    if(shouldDisplay) {
        ui->encryptedText->setText(output);
        qDebug() << d;
    }
}

void Cryptography::on_DecrptTextBtn_clicked()
{
    QString temp = ui->privateKeyText->toPlainText();
    long int privateKey = temp.toLong();
    Decrypt decryptObject;
    temp = ui->DecryptedText->toPlainText();
    char message[100], out[100];
    memcpy(message, temp.toStdString().c_str(), temp.size());
    qDebug() << message;
    decryptObject.decrypt(privateKey, n, message, out, tempArray);
    QString output(out);
    ui->EncryptedText->setText(output);
}
