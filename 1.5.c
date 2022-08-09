#include <stdio.h>

#define IN  1
#define OUT 0

/* ex.1-12 write a program which prints it input one world per line */

int main() {
	int c, state;

	state = OUT;
	while ((c = getchar()) != EOF) {
		if (c == ' ' || c == '\n' || c == '\t') {
			state = OUT;
			putchar('\n');
		} else if (state == OUT) {
			state = IN;
			putchar(c);
		} else if (state == IN) {
			putchar(c);
		}
	}
}
