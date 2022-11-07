#include <stdio.h>



void printd (int i);
void qsort(int v[], int left, int right);

int main (void) {
	int i;

	//printd (123);
	int v[] = {2, 3, 1, 4, 1};
	qsort (v, 1, 4);

	for (i = 0; i < 5; i++)
		printf ("%d\n", v[i]);
}

void swap (int v[], int i, int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}

void qsort(int v[], int left, int right)
{
	int i, last;
	void swap (int v[], int i, int j);

	if (left >= right)
		return;

	swap (v, left, (left + right) / 2);
	last = left;
	for (i = left + 1; i <= right; i++) {
		if (v[i] < v[left])
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

