#include <stdio.h>

/* ex.1-14 Write a program to print a histogram of the frequence of different characters in its input. */

#define MAXLINES 10
#define NUM      26

int main() {
	int c;
	int nc[NUM];

	for (int i = 0; i < NUM; ++i)
		nc[i] = 0;

	while((c = getchar()) != EOF) {
		if (c > 'a' && c < 'z') {
			++nc[c - 'a'];
		}
	}

	for (int i = 0; i < NUM; ++i)
		printf("%d ", nc[i]);

	for (int i = MAXLINES - 1; i >= 0; --i) {
		for (int j = 0; j < NUM; ++j) {
			if (nc[j] - i > 0) {
				printf("* ");
			} else {
				printf("  ");
			}
		}
		printf("\n");
	}

	for (int i = 0; i < NUM ; ++i)
		printf("%c ", 'a' + i);
	printf("\n");
}
