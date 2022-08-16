#include <stdio.h>

/*
  ex.1-22 write a program to flod the long long input line into two or more short lines.
  Outline:
          while (has a character) {
	          (count n)
	          if (n < len) {
		          (print it)
		  } else if (n = len && c != ' ') {
		          (print '/')
			  (print '\n')
			  (print it)
			  (n = 0)
		  } 
	  }
	  	          
  note: although this program is not intelligence to know the words and just simply sperate the words
  into next line, but it can work for this question.
  it still have some place can be inproved, maybe in futuress.
*/

#define MAX 10

int getline01(char line[], int lim);

int main() {
	int len;
	char line[MAX];
	
	for (int i = 0; i < MAX; ++i)
		line[i] = 0;

	while ((len = getline01(line, MAX)) > 0) {
		if (len > MAX - 2 && line[MAX - 2] != ' ') 
			printf("%s/\n", line);
		else
			printf("%s", line);
	}
}

int getline01(char line[], int lim)
{
	int c, i;
	
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i] = c;
		++i;
	}
	line[i] = '\0';
	return i;
}
