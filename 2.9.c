#include <stdio.h>
#include <ctype.h>

/* #define SET_ON 011 */

unsigned getbits(unsigned x, int p, int n);

int main(void) {
	int a = -20;

	printf("%#b\n", a);
	/* printf("%#d\n", a); */
	printf("%#b\n", ~a);
	/* printf("%#b\n", !a); */

	printf("%#b\n", a & ~0177);
	/* printf("%b\n", a | SET_ON); */
	/* printf("%b\n", 0b1 & 0b10); */
	/* printf("%b\n", 0b1 && 0b10); */

	/* printf("%#b\n", a >> 2); */
	/* printf("%#d\n", a >> 2); */

	/* printf("%#b\n", a << 2); */
	/* printf("%#d\n", a << 2); */

	/* int a = 0b010010011; */
	/* printf("%#b\n", a); */
	/* unsigned int r = getbits(a, 4, 3); */
	/* printf("%#b\n", r); */
	/* unsigned int r1 = getbits(a, 5, 3); */
	/* printf("%#b\n", r1); */
	/* unsigned int r2 = getbits(a, 3, 3); */
	/* printf("%#b\n", r2); */

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
