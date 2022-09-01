#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, int y);

int main(void) {
	int a = 0b010010011;
	/* printf("%#b\n", a); */
	/* unsigned int r2 = getbits(a, 3, 3); */
	/* printf("%#b\n", r2); */
	/* unsigned int r = getbits(a, 4, 3); */
	/* printf("%#b\n", r); */
	/* unsigned int r1 = getbits(a, 5, 3); */
	/* printf("%#b\n", r1); */
	setbits(a, 5, 3, 1);
}

unsigned setbits(unsigned x, int p, int n, int y)
{
	/*
	 setbits(a, 5, 3, 1)
	 11111111 >> (5 + 1 -3) =>
	 11111 << 3 =>
	 11111000
	 ~000 << 3
	 01001010 | 00111000
	 01111010
	*/

	int r = (~000 << 3);
	printf("%#b\n", r);
}

unsigned getbits (unsigned x, int p, int n)
{
	/*
	  getbits(a, 5, 3) =>
	  010010011 >> [3 = (5 + 1 - 3)] =>
	  010010 & [0111 = ~1000  = ~(1 << 3) = ~(~0 << 3)] =>
	  010
	*/
	return (x >> (p + 1 - n) & ~(~0 << n));
}
