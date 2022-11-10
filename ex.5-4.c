#include <stdio.h>

int strend(char *s, char *t);

int main(void) {
	char s[] = "hello world";
	char t[] = "world";
	int i = strend(s, t);
	printf("i: %d\n", i);
	
	/* char *s = "hello world"; */
	/* printf("%c\n", *(s - 23)); */
}

int strend(char *s, char *t)
{
	int i;

	while(*s++)
		;
	while(*t++)
		;
	while(*(--s) == *(--t))
		;
	/* printf("t: <%c>\n", *(t + 1)); */
	return (*(t+1) == 'w') ? 1 : 0;
}
