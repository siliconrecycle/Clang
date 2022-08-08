#include <stdio.h>

/* This time, we will counte the number of lines. */

int main() {
	int nl;
	int c;

	nl = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n')
			++nl;
	}
	printf("The number of input lines: %d\n", nl);
}
