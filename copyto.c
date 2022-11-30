#include <stdio.h>
#include <string.h>
#include "readlines.h"

void copyto(char *lineptr[], char *str, int p)
{
	/* char str01[100]; */
	/* strcpy(str01, str);  */
	/* lineptr[p] = str01; */
	
	lineptr[p] = str;
}

int main(void) {
	char *store01[100] = {"hello", "world"};
       	char *store[100];
	int n;

	for(n = 0; n < 2; n++)
		copyto(store, store01[n], n);

	writelines(store, n);
}
