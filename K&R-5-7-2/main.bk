#include <stdio.h>
#include <string.h>

#include "readlines.c"
#include "qsort.c"

#include "writelines.c"

#define MAXLINES 1000
char *lineptr[MAXLINES];

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort01(void *lineptr[], int left, int right, int (*cmp)(void *, void *));
int numcmp(char *a, char *b);

void printfarg(int argc, char *argv[]) {
	printf("prtarg: ");
	while (--argc > 0)
		printf("%s%s", *++argv, (argc > 1) ? " " : "");
	printf("\n");
}

int main(int argc, char *argv[]) {
	int nlines;
	int c, numeric = 0, other = 0;

//	printfarg(argc, argv);
//	printf("argc: %d\n", argc);

	while(--argc > 0 && (*++argv)[0] == '-') {
		while(c = *++argv[0])
			switch (c) {
			case 'n':
				numeric = 1;
				break;
			default:
				printf("error: unoption item.\n");
				other = 1;
				break;
			}
	}

//	printf("argc: %d\n", argc);
	if(other)
		printf("Usage: qsort [-n]\n");
	else {

		if((nlines = readlines(lineptr, MAXLINES)) >= 0) {
//			qsort01((void **)lineptr, 0, nlines - 1, (int (*)(void *, void *))(numeric ? numcmp : strcmp01));
//			qsort01((void **)lineptr, 0, nlines - 1, (numeric ? numcmp : strcmp01));
			qsort01(lineptr, 0, nlines - 1, (numeric ? numcmp : strcmp01));
			writelines(lineptr, nlines);
			return 0;
		} else {
			printf("error: too many lines!\n");
			return -1;
		}
	}
}
