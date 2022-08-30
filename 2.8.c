#include <stdio.h>

void squeeze(char s[], int c);
void strcat01(char s[], char t[]);

int main(void) {
	char s[100] = "hello world!";
	printf("%s\n", s);
	int c = 'o';
	squeeze(s, c);
	printf("%s\n", s);

	char t[] = "Yuan, 2022-08-30";
	strcat01(s, t);
	printf("%s\n", s);	
}

void strcat01(char s[], char t[])
{
	int i, j;
	i = j = 0;
	while (s[i] != '\0') {
		i++;
	}
	while ((s[i++] = t[j++]) != '\0');
}

void squeeze(char s[], int c)
{
	int i, j;
	for (i = j = 0; s[i] != '\0'; ++i) {
		if (s[i] != c) {
			s[j++] = s[i];
		}
	}
	s[j] = '\0';
}
