#include <ctype.h>
#include <stdio.h>

int getch(void);
void ungetch(int c);

int getint(int *np)
{
	int c, sign;
	while(isspace(c = getch()))
	      ;

	if(!isdigit(c) && c != '-' && c != '+') {
		ungetch(c);
		return 0;
	}

	sign = (c == '-') ? -1 : 1;
	if(c == '-' || c == '+')
		c = getch();

	if(!isdigit(c)) {
		ungetch(c);
		return 0;
	}
	
	for(*np = 0; isdigit(c); c = getch())
		*np = 10 * *np + (c - '0');
	*np *= sign;
	
	if(c != EOF)
		ungetch(c);

	return c;
}
