#include <stdio.h>
#include <ctype.h>

int main(void) {
	long a = 2147483647;
	long n = a + 1;
	double b = 0.111201230123;

	printf("%G\n", b);
}
