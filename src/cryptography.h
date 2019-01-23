#ifndef CRYPTOGRAPHY_H
#define CRYPTOGRAPHY_H

#include <QMainWindow>

namespace Ui {
class Cryptography;
}

class Cryptography : public QMainWindow
{
    Q_OBJECT

public:
    explicit Cryptography(QWidget *parent = nullptr);
    ~Cryptography();

private slots:

    void navigatePages(int pageNumber);

    void on_encryptText_clicked();

    void on_decryptText_clicked();

    void on_homeFromEncrypt_clicked();

    void on_homeFromDecrypt_clicked();

    int prime(long int);

    void on_encryptTextBtn_clicked();

    void on_DecrptTextBtn_clicked();

private:
    static long int n;
    static long int tempArray[100];
    Ui::Cryptography *ui;
};

#endif // CRYPTOGRAPHY_H
