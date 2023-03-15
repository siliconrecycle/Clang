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


int main(void) {

	int i, c, s;
	int n, m;

	int tab = TAB;

	while((c = getchar()) != EOF) {
		for(s = 0; c == ' '; ++s, c = getchar())
			;

		n = (s + 1) / tab;
		for (; n > 0; --n)
			putchar('#');

		m = s % tab;

		for (; m > 0; --m)
			putchar('*');

		putchar(c);
		printf("m: %d, n: %d\n", m, n);
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
	return 0;
}

// detab

/* void printfspace(int tabnumber, int *p) */
/* { */
/* 	int tab, n; */

/* 	n = *p; */
/* 	*p = 0; */

/* 	tab = TAB - n; */
	
/* 	if (tabnumber > 0) */
/* 		tab = tabnumber - n; */
	
/* 	for (; tab > 0; --tab) */
/* 		putchar('*'); */

/* } */

/* int main(void) { */
/* 	int i, c, s = 0; */
/* 	int *p; */

/* 	while ((c = getchar()) != EOF) { */

/* 		if (c == '\n') { */
/* 			putchar(c); */
/* 			s = 0; */
/* 		} */

/* 		if(c != '\t' && c != '\n') { */
/* 			putchar(c); */
/* 			++s; */
/* 		} */

/* 		p = &s; */

/* 		if(c == '\t') */
/* 			printfspace(0, p); */
/* 	}		 */


/* 	/\* 	++i; *\/ */

/* 	/\* 	if (c == '\t') { *\/ */
/* 	/\* 		--i; *\/ */
/* 	/\* 		i = i % TAB; *\/ */
/* 	/\* 		for (int j = 0; j < TAB - i; ++j) { *\/ */
/* 	/\* 			putchar('*'); *\/ */
/* 	/\* 		} *\/ */
/* 	/\* 		i = 0; *\/ */
/* 	/\* 	} else if (c == '\n') { *\/ */
/* 	/\* 		putchar(c); *\/ */
/* 	/\* 		i = 0; *\/ */
/* 	/\* 	} else { *\/ */
/* 	/\* 		putchar(c); *\/ */
/* 	/\* 	} *\/ */
/* 	/\* } *\/ */
/* } */
