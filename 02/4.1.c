#include <stdio.h>
#include <string.h>

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
			printf("s: %s", s);
			found++;
		}
	}
	return found;
}

int strindex(char s[], char t[])
{
	int i, j, k;
	int n, m;
	n = strlen(s) - 1;
	m = strlen(t) - 1;
	for (i = n; i >= 0; --i) {
		for (j = i, k = m; k >= 0 && t[k] == s[j]; --k, --j)
			;
		printf("i: %d\n", i);
		if (k < 0)
			return n - i;
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
