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
#include "getch.c"

#define TAB 8


void prints(char sym, int n)
{
	while (n-- > 0)
		printf("%c", sym);
}
			

void entab(int start, int tab)
{
	int m = 0, n = TAB;
	int i, a, s, c;


	i = a = s = 0;
	if (start > 0)
		m = start;
	if (tab > 0)
		n = tab;

	/* printf("1 % 8 = %d\n", 2%8); */
	// 1
	//             1

	while ((c = getch()) != EOF) {

		// 1. count total chars.
		++i;

		if (i > m) {
			// 2. count no space and nor enter char.
			for (; c != ' ' && c != '\n'; c = getch(), ++a)
				putchar(c);
							
			// 3. count space chars.
			for (; c == ' '; c = getch(), ++s)
				;
			
			/* printf("\ns: %d, a: %d, n: %d\n", s, a, n); */
			
			// 4. print space and tab.
			a = a % n;
			int p = (s + a) / n;
			int q = (s + a) % n;
			
			int x =  p;
			if (x > 0)
				prints('#', n * x - a);

			int y = (p > 0) ? q : q - a;
			if (y > 0)
				prints('*', y);
			s = a = 0;

			if (c == '\n') {
				s = a = i = 0;
				i = 0;
				putchar(c);
			}

			if (c != '\n')
				ungetch(c);
		} else {
			putchar(c);
		}
			
	}
}
			
	


/* void entab(int tabnumber) { */

/* 	int s, n, m; */
/* 	int tab, c; */

/* 	tab = TAB; */

/* 	if (tabnumber > 0) */
/* 		tab = tabnumber * TAB; */
/* 	else */
/* 		tabnumber = 0; */

/* 	while((c = getchar()) != EOF) { */
/* 		for(s = 0; c == ' '; ++s, c = getchar()) */
/* 			; */

/* 		/\* printf("s: %d\n", s); *\/ */

/* 		n = (s + 1) / tab; */
/* 		for (; n > 0; --n) */
/* 			for(int i = tabnumber; i > 0; --i) */
/* 				putchar('#'); */

/* 		m = s % tab; */

/* 		for (; m > 0; --m) */
/* 			putchar('*'); */

/* 		putchar(c); */
/* 		/\* printf("m: %d, n: %d\n", m, n); *\/ */
/* 	} */
			

/* 	/\* i = 0; *\/ */
/* 	/\* while ((c = getchar()) != EOF) { *\/ */
/* 	/\* 	++i; *\/ */
/* 	/\* 	if (c == ' ') { *\/ */
/* 	/\* 		--i; *\/ */
/* 	/\* 		for (s = 1; (c = getchar()) == ' '; ++s); *\/ */

/* 	/\* 		n = (i + s) / tab; *\/ */
/* 	/\* 		if (n > 0) *\/ */
/* 	/\* 			m = (i + s) % tab; *\/ */
/* 	/\* 		else *\/ */
/* 	/\* 			m = (i + s) % tab - i; *\/ */
			
/* 	/\* 		for (int j = 0; j < n; ++j) *\/ */
/* 	/\* 			putchar('\t'); *\/ */
/* 	/\* 		for (int k = 0; k < m; ++k) *\/ */
/* 	/\* 			putchar('*'); *\/ */
/* 	/\* 		i = 1; *\/ */
/* 	/\* 	} else if (c == '\n') { *\/ */
/* 	/\* 		putchar(c); *\/ */
/* 	/\* 		i = 0; *\/ */
/* 	/\* 	} *\/ */
/* 	/\* 	putchar(c); *\/ */
/* 	/\* } *\/ */
/* } */
