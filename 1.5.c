#include <stdio.h>

int main() {
	int c;

	/* putchar(33); */
	/* printf("true or false: %d\n", c = getchar() != EOF); */
	/* (c = getchar != EOF) => 1(true)
	This is very important, 1 in ascii code is a no-display symbol.
	That means, even if it is in infinit loop, it will display nothing
	in terminal.
	Of course, we also need to know in function `putchar()`, his argument
	is integer, and then be transfered to character by ascii code table.*/
	while ((c = getchar()) != EOF) { 
		putchar(c);
	}

}
