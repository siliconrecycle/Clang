#include <stdio.h>
#include "common.h"

#define MAXCHAR 100

int readlines(char *lineptr[], int maxline)
{
//	printf("hello world!\n");
	char line[MAXCHAR];
	int nl;

	nl = 0;
	while(getline01(line, MAXCHAR) > 0) {
		if(nl < maxline) {
			copyto(lineptr, line, nl++);

			/* lineptr[nl++] = line; */
			/* printf("rl:"); */
			/* writelines(lineptr, nl); */
		} else
			return -1;
	}
	return nl;
}


/* int main(void) { */
/* 	char *store[100]; */
/* 	int max = 10, n; */
/* 	/\* char *store01[100] = {"hello ", "world"}; *\/ */

/* 	n = readlines(store, max); */

/* 	writelines(store, n); */
/* } */
