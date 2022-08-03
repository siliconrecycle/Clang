#include <stdio.h>

int main(void) {
	int store[20];
	char c;
	int n;

	while ((c = getchar()) != EOF) {
		if (c == '\t') {
			for (int i = 0; i < 8 - n; i++)
				putchar('*');
			n = 0;
		} else if (c != '\n' && c != '\r') {
			putchar('0');
			n += 1;
		}
		if (n > 8)
			n = n % 8;
	}
}
