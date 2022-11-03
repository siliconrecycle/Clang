#include <stdio.h>

#define SIZE 10

void printa(int a[], int size)
{
	int i;
	for(i = 0; i < size; ++i)
		printf("a[%d]: %d\n", i, a[i]);
}

int main(void) {
	int n, array[SIZE], getint(int *np);

	for(int i = 0; i < SIZE; i++)
		array[i] = 1;

	for(n = 0; (n < SIZE) && getint(&array[n]) != EOF; n++)
		;
	printa(array, SIZE);
}
