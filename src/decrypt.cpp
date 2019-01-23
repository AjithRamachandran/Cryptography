#include "decrypt.h"

#include <string.h>

void Decrypt::decrypt(int d, long int n, char* en, char* out) {
    long int pt, ct, k, temp[100];
    char de[100];
    int i = 0;
    while(en[i] != -1)
    {
       ct = temp[i];
       k = 1;
       for(int j = 0; j < d; j++)
       {
          k = k * ct;
          k = k % n;
       }
       pt = k + 96;
       de[i] = pt;
       i++;
    }
    de[i] = -1;
    for(i=0;i<strlen(de);i++) {
        out[i] = de[i];
    }
}
