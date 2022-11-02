#include <stdio.h>

#define SIZE 10

int main(void) {
	if(1)
		printf("hello\n");

	int n, array[SIZE], getint(int *);

	for(int i = 0; i < SIZE; i++)
		array[i] = 0;

	for(n = 0; (n < SIZE) && getint(&array[n]) != EOF; n++)
		;

	for(int i = 0; i < SIZE; i++)
		printf("array[%d]: %d\n", i,  array[i]);
}
