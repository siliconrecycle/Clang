#include <stdio.h>

#define SIZE 10

void printa(double a[], int size)
{
	int i;
	for(i = 0; i < size; ++i)
		printf("a[%d]: %g\n", i, a[i]);
}

int main(void) {
	int n, getfloat(double *np);
	double array[SIZE];

	for(int i = 0; i < SIZE; i++)
		array[i] = 1;

	for(n = 0; (n < SIZE) && getfloat(&array[n]) != EOF; n++)
		;
	printa(array, SIZE);
}
