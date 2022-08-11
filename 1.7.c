#include <stdio.h>

/* 1.7 This is a program tell you how to write a function in one file. */

int power(int base, int n);

int main () {
	for (int i = 0; i < 10; ++i) {
		printf("2(%d) = %d\n", i, power(2, i));
		printf("-3(%d) = %d\n", i, power(-3, i));
	}
	return 0;
}

int power(int base, int n) {
	int p;
	p = 1;
	for (int i = 1; i <= n; ++i) {
		p = base * p;
	}
	return p;
}
