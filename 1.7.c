#include <stdio.h>

/* ex.1-15 use function syntax to rewrite template conversion program. */

#define UPPER 300
#define LOW   0
#define STEP  20

float FahrToCel(float fahr);

int main () {
	for (float i = LOW; i <= UPPER; i += STEP) {
		printf("%3.0f %6.1f\n", i, FahrToCel(i));
	}
	return 0;
}

float FahrToCel(float fahr) {
	return (5.0/9.0) * (fahr - 32.0);
}
