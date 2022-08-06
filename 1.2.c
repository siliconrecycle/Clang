#include <stdio.h>

/* This is just a simple temperature transformation program. */

int main() {
	float lower, upper;
	float fahr, celsius, step;

	lower = 0, upper = 300;
	step = 30;

	fahr = lower;

	printf("Fahr Celsius\n");
	while (fahr <= upper) {
		celsius = (5.0/9.0) * (fahr - 32);
		printf("%3.0f %6.1f\n", fahr, celsius);
		/* printf("%3.1f %6.1f\n", fahr, celsius); */
		/* printf("%3.1f%6.1f\n", fahr, celsius); */
		fahr += step;
	}
}
