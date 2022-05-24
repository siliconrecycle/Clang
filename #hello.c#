#include <stdio.h>

#define MAXLINE 10

int getline01(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
	char line[MAXLINE];
	char longest[MAXLINE];
	int len, max, sum;

	max = 0;
	sum = 0;
	while ((len = getline01(line, MAXLINE)) > 0) {
		if (len == MAXLINE - 1 && line[MAXLINE] != '\n') {
			sum += len;
			continue;
		}
		sum += len;
		len = sum;
		sum = 0;
		printf("len: %d, line: %s\n", len, line);
		if (len > max) {
			max = len;
			copy(longest, line);
		}
	}

	if (max > 0) {
		printf("max: %d, line: %s\n", max, longest);
	}
	return 0;
}

int getline01(char s[], int lim)
{
	int c, i;

	for (i=0; i < lim-1 && (c=getchar()) != '\n' && c != EOF; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = c;
		++i;
	}
	s[i] = '\0';
	return i;
}

void copy(char to[], char from[])
{
	int i;

	i = 0;
	while ((to[i]=from[i]) != '\0') {
		++i;
	}
}
