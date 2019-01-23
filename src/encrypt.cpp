#include "encrypt.h"

#include <math.h>
#include <string.h>

int Encrypt::n, Encrypt::t;

int Encrypt::prime(int pr)
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

long int* Encrypt::encryption_key(int x, int y) {
    long int e = 0, d = 0;
    long int* keys = new long int[3];
    n = x * y;
    t = (x - 1) * (y - 1);
   for(int i = 2; i < t; i++)
   {
	  if(t % i == 0)
		 continue;
      long int flag = prime(i);
	  if(flag == 1 && i != x && i != y)
	  {
		 e = i;
		 flag = cd(e);
		 if(flag > 0) {
			d = flag;
			break;
		 }
	  }
   }
    keys[0] = e;
    keys[1] = d;
    keys[2] = n;

    return keys;
}

long int Encrypt::cd(long int a) {
	long int k = 1;
	while(1)
	{
		k = k + t;
		if(k % a == 0)
		  return(k/a);
	}
}

void Encrypt::encrypt(char* msg, char* out, long int e) {
    char en[100];
    long int pt, ct, k, temp[50], j;
    int i=0, len;
    len = int(strlen(msg));
	while(i != len) {
        pt = msg[i];
		pt = pt - 96;
		k = 1;
		for(j = 0; j < e; j++){
			k = k * pt;
			k = k % n;
		  }
		temp[i] = k;
		ct = k + 96;
        en[i] = char(ct);
		i++;
	}
	en[i] = -1;
    for(i=0;i<strlen(en);i++) {
        out[i] = en[i];
    }
}
