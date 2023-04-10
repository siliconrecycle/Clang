#include <stdio.h>
<<<<<<< HEAD
#include <string.h>
#include <stdlib.h>

#include "common.h"

#define NUMBER 3

int main(int argc, char *argv[]) {
	char c;
	char s[100] = "";
 	int maxlines, n;

	maxlines = NUMBER;
 	char *store[maxlines];

	while (--argc > 0 && (*++argv)[0] == '-') {
		switch (c = *++argv[0]) {
		case 'n':
			strcpy(s, *(++argv));
			--argc;
			maxlines = atoi(s);
			break;
		default:
			printf("unknown op!\n");
			break;
		}
	}


	n = readlines(store, maxlines);
	writelines(store, n);
	return 0;
=======
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
>>>>>>> ae03475 (5-6-3 finshed)
}
