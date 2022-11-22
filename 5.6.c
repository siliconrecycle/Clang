#include <stdio.h>
#include <string.h>
#include "getline01.c"
#include "alloc.c"

#define MAXLINES 10

int readlines(char *lineptr[], int linemax);
void qsort(char *lineptr[], int left, int right);
void writelines(char *lineptr[], int linenumber);

int main(void)
{
	int nlines;
	char *lineptr[MAXLINES];


	if((nlines = readlines(lineptr, MAXLINES)) > 0) {
		qsort(lineptr, 0, nlines);
		writelines(lineptr, nlines);
		return 0;
	} else {
		printf("error: too many lines!\n");
		return 1;
	}

}

#define MAXCHAR 100

int getline01(char *line, int lim);
char *alloc(int);
/* void strcpy01(char *t, char *s); */

int readlines(char *lineptr[], int linemax)
{
	int len, nlines;
	char *p, line[MAXCHAR];

	nlines = 0;
	while((len = getline01(line, MAXCHAR)) > 0) {

		if(nlines >= MAXLINES || (p = alloc(len)) == NULL) {
			return -1;
		} else {
			/* printf("log in"); */
			line[len - 1] = '\0';
			strcpy(p, line);
			lineptr[nlines++] = p;
		}

		/* if(nlines < MAXLINES) { */
		/* 	line[len-1] = '\0'; */
		/* 	strcpy(p, line); */
		/* 	lineptr[nlines++] = p; */
		/* 	printf("log in\n"); */
		/* } else { */
		/* 	return -1; */
		/* } */

	}
	return nlines;
}

/* int strcmp01(char *t, char *s); */

void swap (char *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap (char *v[], int i, int j);

	if (left >= right)
		return;

	swap (v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if (strcmp(v[i], v[left]) < 0)
			swap (v, ++last, i);
	}
	swap (v, left, last);
	qsort (v, left, last - 1);
	qsort (v, last + 1, right);
}


void writelines(char *lineptr[], int linenum)
{
	while(linenum--) {
		printf("%s", *lineptr++);
	}
}
