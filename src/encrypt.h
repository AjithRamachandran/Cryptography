#ifndef ENCRYPT_H
#define ENCRYPT_H

//#include "cryptography.h"

class Encrypt
{
public:
    static int n, t;
    long int* encryption_key(int, int);
	long int cd(long int a);
    void encrypt(char*, char*, long int, long int[]);
	int prime(int);
};

#endif // ENCRYPT_H
