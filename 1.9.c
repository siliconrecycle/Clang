
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

   ex.1-17 write a program to print all lines that are longer than 80 characters.

   while (has text line) {
           if (length of line > 80) {
	           (copy it)
		   (save it)
	   }
   }
   (print it)

   There is still some question, how can i save the unknown length of the lines?
   I don't know the size of array that i need to declare, because i don't know
   how many lines which its length longer than LIM.
   but i can simplely print it.
*/

#define MAX 100
#define LIM 8

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
			if (slen > LIM) {
				printf("%s", line);
			}
			slen = 0;
		} else if (len > LIM) {
			printf("%s", line);
			longest = len;
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
