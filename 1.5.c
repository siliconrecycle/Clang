#include <stdio.h>

/* ex.1-9 copy input to output, and replacing one or more blanks by a single
 blank.*/

int main() {
	int c;

	while ((c = getchar()) != EOF) {
		putchar(c);
		while (c == ' ')
			c = getchar();
	}
}
