#include <stdio.h>

/* ex.1-8 count blanks, tabs, newlines. */

int main() {
	int nl, nb, nt;
	int c;

	nl = nb = nt = 0;
	while ((c = getchar()) != EOF) {
		if (c == '\n') {
			++nl;
		} else if (c == ' ') {
			++nb;
		} else if (c == '\t') {
			++nt;
		}
	}
	printf("The number of newlines: %d\n", nl);
	printf("The number of tabs: %d\n", nt);
	printf("The number of blanks: %d\n", nb);
}
