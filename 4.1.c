#include <stdio.h>
#define MAXLINE 1000

int getline01(char s[], int lim);
int strindex(char s[], char t[]);

char pattern[] = "ould";

int main(void) {
	char s[MAXLINE];
	int found = 0;

	while (getline01(s, MAXLINE) > 0) {
		int t = strindex(s, pattern);
		printf("t: %d\n", t);
		if (strindex(s, pattern) >= 0) {
			printf("%s", s);
			found++;
		}
	}
	return found;
}

int strindex(char s[], char t[])
{
	int i, j, k;
	for (i = 0; s[i] != '\0'; ++i) {
		for (j = i, k = 0; t[k] != '\0' && t[k] == s[j]; ++j, ++k)
			;
		printf("k: %d\n", k);
		if (k > 0 && t[k] != '\0')
			return i;
	}
	return -1;
}
			
	

int getline01(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i++] = '\n';
	}
	s[i] = '\0';	
	return i;
}
