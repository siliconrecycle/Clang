#include <stdio.h>
#include "readlines.h"

#define MAXLINES 10

int main(void) {
	char *lineptr[100];
	int lines;

	if((lines = readlines(lineptr, MAXLINES)) > 0) {
		qsort(lineptr, 0, lines - 1);
		writelines(lineptr, lines);
		return 0;
	} else {
		printf("error: too many lines!\n");
		return -1;
	}
}
