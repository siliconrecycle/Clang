#include <stdio.h>
#include <string.h>

char *strncpy(char *s, const char *ct, size_t n);
char *strncat(char *s, const char *ct, size_t n);
int strncmp(const char *cs, const char *ct, size_t n);

int main(void) {
	char s[100] = "hella";
	char msg[] = "hello world";

	/* printf("msg: %s\n", strncpy(s, msg, 5)); */
	/* printf("msg: %s\n", strncat(s, msg, 5)); */
	printf("i: %d\n", strncmp(s, msg, 5));
}

int strncmp(const char *cs, const char *ct, size_t n)
{
	int i;

	for(i = 0; (i < n) && (*ct != '\0'); cs++, ct++, i++) {
		if(*cs != *ct)
			return *cs - *ct;
	}
	return 0;
}

char *strncat(char *s, const char *ct, size_t n)
{
	int i, ls;
	char *p;
	
	ls = strlen(s);
	p = s + ls;

	for(i = 0; (i <= n) && (*p++ = *ct++) != '\0'; i++)
		;
	return s;
}


char *strncpy(char *s, const char *ct, size_t n)
{
	char *p = s;
	int i;
	for(i = 0; (i <= n) && (*p++ = *ct++) != '\0'; i++)
		;
	return s;
}
