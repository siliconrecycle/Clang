#include <stdio.h>

/* This is just a simple temperature transformation program. */

int main() {
	float lower, upper;
	float fahr, celsius, step;

	lower = 0, upper = 120;
	step = 10;

	celsius = lower;

	printf("Celsius  Fahr\n");
	while (celsius <= upper) {
		fahr = (9.0/5.0) * celsius + 32;
		printf("%5.0f %7.1f\n", celsius, fahr);
		celsius += step;
	}
}
