/* prt = log --color --graph --pretty=format:'%Cred%h%Creset %Cgreen(%cr) %C(bold blue)<%an>%Creset -%C(yellow)%d%Creset %s' --abbrev-commit */

#include <stdio.h>

/* This is sloving ex.4-12 question. */

void itoa(int n, char s[]);

int main(void) {
	int v;
	char s[100];
	
	v = 124213;
	printf("%d\n", v);

	itoa(v, s);
	printf("%s\n", s);
}

int i = 0;

void itoa(int n, char s[])
{
	if (n / 10)
		itoa((n / 10), s);
	s[i++] = n % 10 + '0';
}
