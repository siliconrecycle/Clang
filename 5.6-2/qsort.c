#include <stdio.h>
#include <string.h>
#include "readlines.h"

void printd (int i);

/* int main (void) { */
/* 	/\* int i; *\/ */

/* 	/\* //printd (123); *\/ */
/* 	/\* int v[] = {2, 3, 1, 4, 1}; *\/ */
/* 	/\* qsort (v, 0, 4); *\/ */

/* 	/\* for (i = 0; i < 5; i++) *\/ */
/* 	/\* 	printf ("%d\n", v[i]); *\/ */

/* 	char *str[100] = {"cabcedef\n","bcdefg\n", "abcdefg\n", "bceefg\n"}; */
/* 	writelines(str, 4); */
/* 	qsort(str, 0, 3); */

/* 	/\* void swap(char *[], int, int); *\/ */
/* 	/\* swap(str, 0, 2); *\/ */

/* 	writelines(str, 4); */
/* } */

void swap(char *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void qsort(char *v[], int left, int right)
{
	int i, last;
	void swap(char *v[], int i, int j);

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

void printd (int n)
{
	if (n < 0) {
		putchar ('-');
		n = -n;
	}
	if (n / 10)
		printd (n / 10);
	putchar (n % 10 + '0');
}

