#include <stdio.h>

/*
  ex.1-19 Write a function to reverse the characters of a string, use it
  to write a program that reverse it input a line at a time.
  Outline:
          while(has a line) {
		          (reverse)
			  (print it)
	  }
	  char[] reverse(line, len)
	          
*/

#define MAX 100

int getline01(char s[], int lim);
void copy01(char dest[], char src[]);
void reverse(char line[], int len);

int main() {
	int len, slen, longest;
	char line[MAX];
	char stored[MAX];
	
	slen = longest = 0;
	while ((len = getline01(line, MAX)) > 0) {
		reverse(line, len);
	}
}

void reverse(char line[], int len) {
	char r[MAX];
	for (int i = 0; i < len; ++i) {
		r[i] = line[len - i - 2];
	}
	printf("%s", r);
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
