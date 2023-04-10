#include <stdio.h>
#include <string.h>

#include "common.h"

#define MAXCHAR 100

int readlines(char *lineptr[], int maxline)
{
//	printf("hello world!\n");
	char line[MAXCHAR], *p;
	int nl, len;

	nl = 0;
	while((len = getline01(line, MAXCHAR)) > 0) {
		if(nl < maxline && (p = alloc(len)) != NULL) {
//			copyto(lineptr, line, nl++);

			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nl++] = p;

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
