#include <stdio.h>
#include <ctype.h>
#include <string.h>

int getline01(char *line, int maxline);
int getline02(char *line, int max);

int atoi01(char *s);
int atoi02(char *s);

void itoa01(int n, char *s);
void itoa02(int n, char *s);

void reverse(char *s);

int strindex(char *source, char *searchfor);

int main(void) {
	/* char msg[100];  */
	/* getline02(msg, 10); */
	/* printf("%s\n", msg); */

	/* char num[] = "-12341"; */
	/* printf("%d\n", atoi02(num)); */

	/* char *s; */
	/* int n = 1243123; */
	/* itoa02(n, s); */
	/* printf("%s\n", s); */

	/* char s[100] = "hello world"; */
	/* reverse(s); */
	/* printf("%s\n", s); */

	char t[] = "hello";
	char s[] = "woiiwjefoirld hello";
	printf("%d\n", strindex(s, t));
}

int strindex(char *s, char *t)
{
	char *i, *j, *k;

	for(i = s; *i != '\0'; i++) {
		for(j = i, k = t; *k != '\0' && *j == *k; j++, k++)
			;
		if(k > t && *k == '\0')
			return i - s;
	}
	return -1;
}

void putcharS(char *s, char c)
{
	int l;
	l = strlen(s);
	s += l;
	*s++ = c;
	*s = '\0';
}

void itoa02(int n, char *s)
{
	char c;

	if (n / 10)
		itoa02((n / 10), s);
	c = n % 10 + '0';
	putcharS(s, c);
}

void reverse(char *s)
{
	int c;
	char *i, *j;
	
	for(i = s, j = s +  strlen(s) - 1; i <= j; i++, j--) {
		/* printf("%s\n", i); */
		c = *i;
		*i = *j;
		*j = c;
	}
}

void itoa(int n, char *s)
{
	int sign;
	char *p = s;

	if((sign = n) < 0)
		n = -n;
	do {
		*p++ = n % 10 + '0';
	} while((n /= 10) > 0);
	if(sign < 0)
		*p++ = '-';
	*p = '\0';
	reverse(s);
}
		

int atoi02(char *s)
{
	int n, sign;
	char *p = s;

	for(; isspace(*p); p++)
		;
	sign = (*p == '-') ? -1 : 1;
	if(*p == '+' || *p == '-')
		p++;
	for(n = 0; isdigit(*p); p++)
		n = 10 * n + (*p - '0');
	return sign * n;
}

int atoi(char *s)
{
	int i, n;
	char *p = s;

	n = 0;
	for(i = 0; *p >= '0' && *p <= '9'; ++i, ++p)
		n = 10 * n + (*p - '0');
	return n;
}

int getline02(char *s, int lim)
{
	int c, i;
	char *p = s;

	i = 0;
	while(--lim > 0 && (c=getchar()) != EOF && c != '\n')
		*p++ = c;
	if(c == '\n')
		*p++ = c;
	*p = '\0';
	return i;
}

int getline01(char *s, int lim)
{
	int c, i;

	char *p = s;

	for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i)
		*p++ = c;
	if(c == '\n') {
		*p++ = c;
	}
	*p = '\0';
	return i;
}
