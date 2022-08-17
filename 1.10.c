#include <stdio.h>

/*
  ex.1-22 write a program to flod the long long input line into two or more short lines.
  Outline:
          while (has a character) {
	          (count n)
	          if (n < len) {
		          (print it)
		  } else if (n == len && c != ' ') {
		          (print '/')
			  (print '\n')
			  (print it)
			  (n = 0)
		  } else if (n == len) {
		          (print it)
			  (n = 0)
		  }
	  }
	  	          
  note: although this program is not intelligence to know the words and just simply sperate the words
  into next line, but it can work for this question.
  it still have some place can be inproved, maybe in futuress.
*/

#define MAX 10

int main() {
	int c;

	for (int i = 0; (c = getchar()) != EOF; ++i) {
		if (i == MAX && c != ' ') {
			putchar('/');
			putchar('\n');
			putchar(c);
			i = 0;
		} else if (i == MAX) {
			putchar('\n');
			putchar(c);
			i = 0;
		} else
			putchar(c);
	}
}
