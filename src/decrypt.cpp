#include "decrypt.h"
#include "cryptography.h"

#include <string.h>

void Decrypt::decrypt(long int d, long int n, char* en, char* out, long int temp[100]) {
    long int pt, ct, k;
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
       de[i] = char(pt);
       i++;
    }
    for(size_t i=0; i<strlen(de); i++) {
        out[i] = de[i];
    }
}
