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

void printfspace(int tabnumber, int *p)
{
	int tab, n;

	n = *p;
	*p = 0;

	tab = TAB - n;
	
	if (tabnumber > 0)
		tab = tabnumber - n;
	
	for (; tab > 0; --tab)
		putchar('*');

}

void detab(int tab) {
	int i, c, s = 0;
	int *p;

	while ((c = getchar()) != EOF) {

		if (c == '\n') {
			putchar(c);
			s = 0;
		}

		if(c != '\t' && c != '\n') {
			putchar(c);
			++s;
		}

		p = &s;
		
		/* for (i = 0; i < tab && c == '\t'; ++i, c = getchar()) */
		/* 	; */
		if (c = '\t')
			printfspace(tab * TAB, p);
	}
}
