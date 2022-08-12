#include <stdio.h>

/* This is a program that reads a set of text lines and prints the longest.
   This is the outline of the program:

   while(has text line) {
           if (this line is longer than stored line) {
	           (stored line = this line)
           }
   }
   printf(stored line)

   how can i do this (stored line = this line),and how
   can i realize (this line is longer than stored line)?
*/

#define MAX 100

int getline01(char s[], int lim);
void copy01(char dest[], char src[]);

int main() {
	int len, slen;
	char line[MAX];
	char stored[MAX];
	
	slen = 0;
	while ((len = getline01(line, MAX)) > 0) {
		if (len > slen) {
			copy01(stored, line);
			slen = len;
		}
	}
	printf("%s\n", stored);
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
