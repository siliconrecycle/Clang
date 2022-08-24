#include <stdio.h>

/*
  ex.1-23 write a program to check a C program for rudimentary
  syntax errors of the unmatched parentheses, brackets and braces.
  
  Outline:
        1:
          while ((c = getchar()) != EOF) {
	          if (c == '{') {
		          while ((c = getchar() != '}'));
		  }
	  }
	2:
	  while ((c == getchar()) != EOF) {
	          if (c == '{')
		          (count +1)
		  else if (c == '}')
		          (count -1)
	  }
	  if (count == 0)
	          (everything is right)
	  else
	          (syntax error)
	  
  Note: this problem should have three ways to slove.first, you can use 'digui'.
  next, you can use 'loop'.last, you can use, i forget it.
  This time, i write a simple program, this program only can slove unnest braces.
  Should notice one thing. if you only input '}' rather than '{', this will not
  say you are error.
*/

int main(void) {
	/* int c; */

	/* while ((c = getchar()) != EOF) { */
	/* 	if (c == '{') { */
	/* 		while ((c = getchar()) != '}') { */
	/* 			if (c == EOF) { */
	/* 				printf("Error!\n"); */
	/* 				return 0; */
	/* 			} */
	/* 		} */
	/* 		printf("Success!\n");		 */
	/* 	} */
	/* } */

	int n, m, c;

	n = m = 0;
	while ((c = getchar()) != EOF) {
		if (c == '{') {
			++n;
		} else if (c == '}') {
			--n;
		} else if (c == '(') {
			++m;
		} else if (c == ')') {
			--m;
		}
	}

	if (n != 0 || m != 0)
		printf("Syntax Error!\n");
	else
		printf("Success!\n");
}
