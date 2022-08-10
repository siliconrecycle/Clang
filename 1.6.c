#include <stdio.h>

/* ex.1-13 write a program to print a histogram of the length of words in
 its input.First, we need a program to count the length of word.*/

#define OUT 0
#define IN  1

int main() {
	int c, state, n;
	int nw[10];

	state = OUT;
	n = 0;
	for (int i = 0; i < 10; ++i)
		nw[i] = 0;
	
	while ((c = getchar()) != EOF && n < 10) {
		if (c == ' ' || c == '\t' || c == '\n') {
			state = OUT;
			++n;
		} else if (state == OUT || state == IN) {
			state = IN;
			++nw[n];
		}
	}
	for (int i = 0; i < 10; ++i)
		printf("%d ", nw[i]);
	printf("\n");

	/* horizontal histogram */
	for (int i = 0; i < 10; ++i) {
		printf("%d ", i);
		for (int j = 0; j < nw[i]; ++j)
			printf("*");
		printf("\n");
	}
	printf("\n");
	
	/* vertical histogram */
	for (int i = 9; i >= 0; --i) {
		for (int j = 0; j < 10; ++j) {
			if (nw[j] - i > 0) {
				printf("*\t");
			} else {
				printf("\t");
			}
		}
		printf("\n");
	}
	for (int i = 0; i < 10; ++i)
		printf("%d\t", i);
	printf("\n");
}
