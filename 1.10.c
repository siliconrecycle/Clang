#include <stdio.h>

/*
  1.10 use external variable to revise the longest-line program.
*/

#define MAX 100

char line[MAX];
char stored[MAX];

int getline01(void);
void copy01(void);

int main() {
	int len, slen;
	/* extern char stored[]; */
	
	slen = 0;
	while ((len = getline01()) > 0) {
		if(len > slen) {
			slen = len;
			copy01();
		}
	}

	if (slen > 0)
		printf("%s", stored);
}

int getline01(void) {
	int c, i;
	/* extern char line[MAX]; */

	for (i = 0; i < MAX - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		line[i] = c;
	}
	if (c == '\n') {
		line[i] = '\n';
		++i;
	}
	line[i] = '\0';	
	return i;
}

void copy01(void) {
	int i;
	/* extern char line[MAX]; */
	/* extern char stored[MAX]; */

	for (i = 0; line[i] != '\0'; ++i) {
		stored[i] = line[i];
	}
	stored[i] = '\0';
}
