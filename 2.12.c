#include <stdio.h>
#include <math.h>

int power(int n, int x);

int main(void) {
	int n;
	n = 2;
	/* printf("%d %d\n", ++n, power(2, n)); */

	++n;
	printf("%d %d\n", n, power(2, n));
}

int power(int n, int x )
{
	for (int i = 0; i < x; ++i)
		n *=n;
	return n;
}
