#include <stdio.h>

/*
  ex.1-23 write a program to check a C program for rudimentary
  syntax errors of the unmatched parentheses, brackets and braces.
  
  Outline:
          while (has a character) {
	          (matched or not)
	  }
*/

int main(void) {
	int c1, c2;

	while ((c1 = getchar()) != EOF) {
		if (c1 == '/' && (c2 = getchar()) == '*') {
			while ( !((c1 = getchar()) == '*'
				  && (c2 = getchar()) == '/')) {
				;
			}
			c1 = getchar();
		} else {
			putchar(c1);
		}
	}
}
