#include <stdio.h>

/*
  ex.1-23 write a program to check a C program for rudimentary
  syntax errors of the unmatched parentheses, brackets and braces.
  
  Outline:
          while ((c = getchar()) != EOF) {
	          if (c == '{') {
		          while ((c = getchar() != '}'));
		  }
	  }

	  match ('{', '}') {
	          if (c == EOF) {
		         (return error)
		  } else if (c == '{') {
		         c = getchar()
			 (matched '{' and '}')
		  } else if (c == '}') {
		         (return success)
		  } else {
		         c = getchar()
		  }
	  }
*/

int main(void) {
	int c;

	while ((c1 = getchar()) != EOF) {
		if (c == '{') {
			
		}
	}
}
