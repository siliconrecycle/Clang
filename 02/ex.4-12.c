/* prt = log --color --graph --pretty=format:'%Cred%h%Creset %Cgreen(%cr) %C(bold blue)<%an>%Creset -%C(yellow)%d%Creset %s' --abbrev-commit */

#include <stdio.h>
#include <string.h>

/* This is sloving ex.4-12 question. */

void itoa(int n, char s[]);

int main(void) {
	int v;
	char s[100], s1[100];
	
	v = 124213;
	printf("%d\n", v);

	itoa(v, s);
	printf("%s\n", s);

	v = 33234234;
	printf("%d\n", v);
	itoa(v, s1);
	printf("%s\n", s1);
}

void putcharS(char s[], char c)
{
	int l;
	l = strlen(s);
	s[l] = c;
	s[l + 1] = '\0';
}

void itoa(int n, char s[])
{
	char c;

	if (n / 10)
		itoa((n / 10), s);
	c = n % 10 + '0';
	putcharS(s, c);
}
