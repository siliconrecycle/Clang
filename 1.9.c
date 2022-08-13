#include <stdio.h>

/*
  ex.1-17 Write a program to remove trailing blanks and tabs from
  the each line of input and delete the entirely blank lines.
  Outline:
           while (has next line) {
	           if (the line trailing is blanks or tabs) {
		           (replace it with newline)
			   (replaec its next char with null character)
			   (save it)
		   } else if (the line is the entirely blank line) {
		           (skip it)[this means don't save it]
		   }
	   }
	   (print saved lines)

   There still have some question is where can i stored lines.
*/

#define MAX 100

int getline01(char s[], int lim);
void copy01(char dest[], char src[]);

int main() {
	int len, slen, longest;
	char line[MAX];
	char stored[MAX][MAX];
	
	slen = longest = 0;
	while ((len = getline01(line, MAX)) > 0) {
		/* printf("%d\n", len); */
		/* printf("s: %c\n", line[len - 2]); */
		if (line[len - 2] == ' ' || line[len - 2] == '\t') {
			line[len - 2] = '\n';
			line[len - 1] = '\0';
			printf("%s", line);
		} else if (len == 1 && line[len - 1] == '\n') {
			printf("*");
		} else {
			printf("%s", line);
		}
	}
}

int getline01(char s[], int lim) {
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i] = '\n';
		++i;
	}
	s[i] = '\0';	
	return i;
}

void copy01(char dest[], char src[]) {
	int i;
	for (i = 0; src[i] != '\0'; ++i) {
		dest[i] = src[i];
	}
	dest[i] = '\0';
}
