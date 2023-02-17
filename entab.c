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

#include <stdio.h>

#define TAB 8

void entab(int tabnumber) {

	int s, n, m;
	int tab, c;

	tab = TAB;

	if (tabnumber > 0)
		tab = tabnumber * TAB;
	else
		tabnumber = 0;

	while((c = getchar()) != EOF) {
		for(s = 0; c == ' '; ++s, c = getchar())
			;

		/* printf("s: %d\n", s); */

		n = (s + 1) / tab;
		for (; n > 0; --n)
			for(int i = tabnumber; i > 0; --i)
				putchar('#');

		m = s % tab;

		for (; m > 0; --m)
			putchar('*');

		putchar(c);
		/* printf("m: %d, n: %d\n", m, n); */
	}
			

	/* i = 0; */
	/* while ((c = getchar()) != EOF) { */
	/* 	++i; */
	/* 	if (c == ' ') { */
	/* 		--i; */
	/* 		for (s = 1; (c = getchar()) == ' '; ++s); */

	/* 		n = (i + s) / tab; */
	/* 		if (n > 0) */
	/* 			m = (i + s) % tab; */
	/* 		else */
	/* 			m = (i + s) % tab - i; */
			
	/* 		for (int j = 0; j < n; ++j) */
	/* 			putchar('\t'); */
	/* 		for (int k = 0; k < m; ++k) */
	/* 			putchar('*'); */
	/* 		i = 1; */
	/* 	} else if (c == '\n') { */
	/* 		putchar(c); */
	/* 		i = 0; */
	/* 	} */
	/* 	putchar(c); */
	/* } */
}
