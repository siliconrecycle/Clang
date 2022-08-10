#include <stdio.h>

/* This is a program which can count digital, white sapce, and others. */

int main() {
	int c;
	int ndigit[10];
	int nw, no;

	nw = no = 0;
	for (int i = 0; i < 10; ++i)
		ndigit[i] = 0;

	while ((c = getchar()) != EOF) {
		if (c > '0' && c < '9') {
			++ndigit[c - '0'];
		} else if (c == ' ' || c == '\t' || c == '\n') {
			++nw;
		} else {
			++no;
		}
	}

	printf("digital = ");
	for (int i = 0; i < 10; ++i)
		printf("%d ", ndigit[i]);
	printf("\nwhite space = %d\nother = %d\n", nw, no);
}
