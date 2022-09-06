#include <stdio.h>

int lower(int c);

int main(void) {
	int c = lower('B');
	printf("%c\n", c);
	printf("%c\n", "B");
	printf("%c\n", 'B');
}

int lower(int c)
{
	return (c > 'A' && c < 'Z') ? (c + 'a' - 'A') : -1;
}
