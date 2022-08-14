#include <stdio.h>

/*
  ex.1-20 write a program deltab replaces the tab with the proper
  number of space.
  Outline:
          while (has tab) {
	          (print TAB - len space)
		  (print char)
	  }

  Note: think about the newline to sperate the line and make the counter count from
  zero.
*/
#define TAB 8

int main() {
	int i, c;

	i = 0;
	while ((c = getchar()) != EOF) {
		++i;

		if (c == '\t') {
			--i;
			i = i % TAB;
			for (int j = 0; j < TAB - i; ++j) {
				putchar('*');
			}
			i = 0;
		} else if (c == '\n') {
			putchar(c);
			i = 0;
		} else {
			putchar(c);
		}
	}
}
