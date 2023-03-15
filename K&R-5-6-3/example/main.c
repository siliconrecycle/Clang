#include <stdio.h>
#include "common.h"

//void qsort(char *lineptr[], int left, int right);
//int readlines(char *lineptr[], int maxline);
//void writelines(char *lineptr[], int num);

//int getline01(char *line, int max);
//void copyto(char *lineptr[], char *str, int p);

#define MAXLINES 1000

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
