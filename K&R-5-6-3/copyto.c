#include <stdio.h>
#include <string.h>
//#include "readlines.h"

#define ALLOCSIZE 1000

static char buff[ALLOCSIZE];
static char *ptr = buff;

void copyto(char *lineptr[], char *str, int p)
{
	int len;
	len = strlen(str);

	if(buff + ALLOCSIZE - len > 0) {
		str[len-1] = '\0';
		strcpy(ptr, str);
		lineptr[p] = ptr;

		ptr += len;
	} else
		printf("error: no more pointers\n");

	/* writelines(lineptr, 5); */
}

/* int main(void) { */
/* 	char store01[100][100] = {"hello\n", "world\n", "Qian\n"}; */
/*        	char *store[100]; */
/* 	int n; */

/* 	for(n = 0; n < 3; n++) */
/* 		copyto(store, store01[n], n); */

/* 	writelines(store, n); */
/* } */
