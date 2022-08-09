#include <stdio.h>

/* ex.1-11 anything is not in `(c == ' ' || c == '\t' || c == '\n')`
 for example, `\b` is one thing which will cause bug.*/

#define IN  1
#define OUT 0

int main() {
	int c, state;
	int nc, nl, nw;
	
	nc = nl = nw = 0;
	state = OUT;
	while ((c = getchar()) != EOF) {
		++nc;
		if (c == '\n')
			++nl;
		if (c == ' ' || c == '\t' || c == '\n') {
			state = OUT;
		} else if (state == OUT) {
			state = IN;
			++nw;
		}
	}
	printf("chars: %d, lines: %d, words: %d\n", nc, nl, nw);
}
