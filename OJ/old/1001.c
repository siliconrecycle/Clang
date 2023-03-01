#include <stdio.h>
#include <math.h>

void reverse(void);

int main(void) {
	reverse();
	return 0;
}

void reverse(void)
{
	long int n;
	int r;

	if ((r = scanf("%ld", &n)) != EOF) {
	  reverse();
	}

	if (r != EOF && r != '\n')
		printf("%0.4lf\n", sqrt(n));
}
