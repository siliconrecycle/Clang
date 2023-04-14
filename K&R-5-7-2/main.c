#include <stdio.h>
#include <string.h>

#include "qsort.c"
#include "readlines.c"
#include "writelines.c"

#define MAXLINES 1000

void qsort01(void *lineptr[], int left, int right, int (*cmp)(void *, void *));
void printargv(int argc, char *argv[]);

int main(int argc, char *argv[]) {
	char c;
	int others = 0;
	int numeric = 0;

	char *lineptr[MAXLINES];
	int nlines;

	printargv(argc, argv);
	while (--argc > 0 && (*++argv)[0] == '-')
		while (c = *++argv[0])
			switch (c) {
			case 'n':
				numeric = 1;
				break;
			default:
				printf("error: unoption item.\n");
				others  = 1;
				break;
			}

	if (others)
		printf("Usage: qsort [-n]\n");
	else {
		if((nlines = readlines(lineptr, MAXLINES)) > 0) {
			qsort01((void *)lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : strcmp01));
			writelines(lineptr, nlines);
			return 0;
		} else {
			printf("error: too many lines!\n");
			return -1;
		}
	}
}

void printargv(int argc, char *argv[])
{
	printf("argv: [");
	while(argc--)
		printf(argc > 0 ? "\"%s\", " : "\"%s\"", *argv++);
	printf("]\n");
}
