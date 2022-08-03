#include <stdio.h>

int main(void) {
	int store[20];
	char c;
	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			for(int i = 0; i < 8; i++)
				putchar(' ');
		} else {
			putchar(c);
		}
	}
}
