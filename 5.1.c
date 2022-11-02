#include <stdio.h>

#define swap01(t, a, b) \
	t tmp;\
	tmp = a;\
	a = b;\
	b = tmp;

void swap(int *a, int *b);

int main(void) {
	int a, b;
	a = 10;
	b = 1;
	printf("a:%d, b:%d\n", a, b);

	swap(&a, &b);
	printf("a:%d, b:%d\n", a, b);
}

void swap(int *a, int *b)
{
	int tmp;
	tmp = *a;
	*a = *b;
	*b = tmp;
}
