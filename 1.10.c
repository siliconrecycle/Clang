#include <stdio.h>

/*
  ex.1-21 write a program entab replaces the spacing with the minimal
  number of space and tab.
  Outline:
          while (has character) {
	          if(is space) {
		          (count space)
			  (replace the space with n tab and m space)
		  }
		  (print char)
	  }

  Note: This program should think about the number of space bigger than TAB and
  smaller than TAB, this will have different result.
*/
#define TAB 8

int main() {
	int i, c, s;
	int n, m;

	i = 0;
	while ((c = getchar()) != EOF) {
		++i;
		if (c == ' ') {
			--i;
			for (s = 1; (c = getchar()) == ' '; ++s);

			n = (i + s) / TAB;
			if (n > 0)
				m = (i + s) % TAB;
			else
				m = (i + s) % TAB - i;
			
			for (int j = 0; j < n; ++j)
				putchar('\t');
			for (int k = 0; k < m; ++k)
				putchar('*');
			i = 1;
		} else if (c == '\n') {
			putchar(c);
			i = 0;
		}
		putchar(c);
	}
}
