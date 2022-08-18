#include <stdio.h>

/*
  ex.1-23 write a program to remove comment from the C program.
  Outline:
          while (has a character) {
	          if (the first two characters are '/' and '*') {
		          (skip middle character with loop
			   until the last two character are '*'
			   and '/')
			   while (the first character is not '*', the
			   last character is not '/');
			   (print char)
		   }
	  }
  note: this program in some aspect is simily to remove some blank into one blank.
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
