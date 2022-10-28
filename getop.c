#include <stdio.h>
#include <ctype.h>
#include "calc.h"

static int first = 1;

int getop(char s[])
{
	int c = ' ', i;
	static int store;

	if (first == 1) {
		store == -1;
		first -= 1;
	}
	
	if (store > 0) {
		c = store;
	}

	while ((s[0] = c) == ' ' || c == '\t') {
		c = getch();
	}
	s[1] = '\0';
	if (!isdigit(c) && c != '.') {
		return c;
	}
	
	if (isdigit(c)) {
		while (isdigit(s[++i] = c = getch()))
		       ;
	}
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		store = c;
	return NUMBER;		
}
