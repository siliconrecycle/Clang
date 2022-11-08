#include <stdio.h>

void strcpy01(char *s, char *t);
int strcmp(char *s, char *t);

int main(void) {
	char *msg;
	char *tran = "hello world";
	int b = strcmp(msg, tran);
	printf("str: %s, b: %d\n", msg, b);

	strcpy01(msg, tran);
	b = strcmp(msg, tran);
	printf("str: %s, b: %d\n", msg, b);
}

int strcmp(char *s, char *t)
{
	/* int i; */
	/* for(i = 0; s[i] == t[i]; i++) */
	/* 	if(s[i] == '\0') */
	/* 		return 0; */
	/* return t[i] - s[i]; */

	for(; *s == *t; s++, t++)
		if(*s == '\0')
			return 0;
	return *t - *s;
}
void strcpy01(char *s, char *t)
{
	// 1.
	while(*s++ = *t++)
		;
	// 2.
	/* int i; */
	/* for(i = 0; (s[i] = t[i]) != '\0'; i++) */
	/* 	; */
	// 3.
	/* int i; */
	/* for(i = 0; (*s++ = *t++) != '\0'; i++) */
	/* 	; */
}

