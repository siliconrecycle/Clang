#include <stdio.h>
#include <string.h>

int strend(char *s, char *t);

int main(void) {
	char s[] = "hello world01";
	char t[] = "world";

	int i = strend(s, t);
	/* printf("%s\n", s); */

	printf("i: %d\n", i);

}

int strend(char *s, char *t)
{
	int ls, lt, diff, i;

	ls = strlen(s);
	lt = strlen(t);
	/* printf("ls: %d, lt: %d\n", ls, lt); */

	diff = ls - lt;

	/* printf("s[%d]: %c\n", diff, *(s + diff)); */

	while(*t != '\0') {
		if(*(s + diff) != *t)
			return 0;
		s++;
		t++;
	}
	return 1;
}


