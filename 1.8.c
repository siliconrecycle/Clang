
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

   ex.1-16 revise the main routine of the program, so it can print the
   length of the arbitrary input lines, and as much as possible text.
*/

#define MAX 10

int getline01(char s[], int lim);
void copy01(char dest[], char src[]);

int main() {
	int len, slen, longest;
	char line[MAX];
	char stored[MAX];
	
	slen = longest = 0;
	while ((len = getline01(line, MAX)) > 0) {
		if (len == MAX - 1 && line[MAX - 1] == '\0') {
			slen = slen + len; 
		} else if (slen > 0) {
			slen = len + slen;
			if (slen > longest) {
				longest = slen;
				copy01(stored, line);
			}
			slen = 0;
		} else if (len > longest) {
			copy01(stored, line);
			longest = len;
		} 
	}
	if (longest > 0)
		printf("\n%slongest: %d\n", stored, longest);
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
