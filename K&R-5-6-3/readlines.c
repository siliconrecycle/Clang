#include <stdio.h>
#include <string.h>

#include "common.h"

#define MAXCHAR 100

int readlines(char *lineptr[], int maxline)
{
	char line[MAXCHAR], *ptr;
	int nl, n;

	n = maxline;
	nl = 0;

	while(getline01(line, MAXCHAR) > 0) {
		if (nl >= n) {
			for (int i = 0; i < n - 1; ++i) {
//				strcpy(lineptr[i], lineptr[i + 1]);
				lineptr[i] = lineptr[i + 1];
//				printf("%s\n", lineptr[i]);
			}
			copyto(lineptr, line, n - 1);
//			printf("%s\n", lineptr[n - 1]);
		} else {
			copyto(lineptr, line, nl++);
		}
	}
	return nl;
}

#define NUMBER 3

int main(void) {
 	int maxlines, n;

	maxlines = NUMBER;
 	char *store[maxlines];

	n = readlines(store, maxlines);
	writelines(store, n);
	return 0;
}
