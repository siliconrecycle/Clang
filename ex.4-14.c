#include <stdio.h>

#define swap(t, x, y) \
	t tmp = x;\
	x = y;\
	y = tmp;

int main(void) {
	int a, b;

	a = 1, b = 2;
	printf("a: %d, b: %d\n", a, b);	

	swap(int, a, b);

	printf("a: %d, b: %d\n", a, b);	
}
