#include <stdio.h>
#include <stdlib.h>

void printd (int i);

int numcmp(char *s1, char *s2) {
	double v1, v2;
	v1 = atof(s1);
	v2 = atof(s2);
	printf("%s: %f, %s: %f\n", s1, s2, v1, v2);
	if (v1 < v2)
		return -1;
	else if (v1 > v2)
		return 1;
	else
		return 0;
}

int strcmp01(char *s, char *t) {
	for (; *s == *t; s++, t++)
		if (*s == '\0')
			return 0;
	return *s - *t;
}

void swap(void *v[], int i, int j)
{
	char *temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void qsort01(void *v[], int left, int right, int (*cmp)(void *, void *))
{
	int i, last;
	void swap(void *v[], int i, int j);

	if (left >= right)
		return;

	swap (v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if ((*cmp)(v[i], v[left]) < 0)
			swap (v, ++last, i);
	}
	swap (v, left, last);
	qsort01(v, left, last - 1, cmp);
	qsort01(v, last + 1, right, cmp);
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

