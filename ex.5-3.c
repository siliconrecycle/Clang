#include <stdio.h>

void login(void);

char *strcat(char *s, char *t);
void strcat01(char s[], char t[]);

int main(void) {
	char h[20] = "hello ";
	char *w = "Qian bcde";
	/* strcat01(h, w); */
	/* printf("%s\n", w); */

	printf("%s\n", strcat(h, w));

	/* char *r = w; */
	/* printf("%s\n", r); */
}

char *strcat(char *s, char *t)
{
	char *p = s;
	while(*s++ != '\0')
		;
	s--;
	while((*s++ = *t++) != '\0')
		;
	return p;
}
	
void login(void)
{
	printf("log in\n");
}

void strcat01(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while(s[i] != '\0')
		i++;
	while((s[i++] = t[j++]) != '\0')
		;
}
