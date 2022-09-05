#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, int y);
unsigned invert(unsigned x, int p, int n);
unsigned rightrot(unsigned x, int n);

int main(void) {
	int a = 0b01001011;
	/* int b = 0b01101000; */
	printf("%#b\n", a);
	/* printf("%#b\n", b); */
	/* printf("%#b\n", a ^ b); */
	/* unsigned int r2 = getbits(a, 3, 3); */
	/* printf("%#b\n", r2); */
	/* unsigned int r = getbits(a, 4, 3); */
	/* printf("%#b\n", r); */
	/* unsigned int r1 = getbits(a, 5, 3); */
	/* printf("%#b\n", r1); */
	/* int c = setbits(a, 5, 3, 0b00101000); */
	/* printf("%#b\n", c); */
	/* int c = invert(a, 5, 3); */
	/* printf("%#b\n", c); */
	int c = rightrot(a, 3);
	printf("%#b\n", c);
}

/*
  a = 01001011
  rightrot(a, 3) =>
  01001110

  a1 = a =>
  01001011
  a = (a >> 3) << 3 =>
  01001000
  
  a1 & 01 = 01001011 & 00000001 =>
  00000001 << 3 - 1 =>
  00000100 | a =>
  01001100
  
  (a1 >> 1) & 01 = 0100101 & 00000001 =>
  00000001 << 2 - 1 =>
  00000010 | a =>
  01001110

  (a1 >> 1) & 01 = 010010 & 00000001 =>
  00000000 << 1 - 1 =>
  00000000 | a =>
  01001110
 */

unsigned rightrot(unsigned x, int n)
{
	unsigned a, a1;
	a = a1 = x;
	a = (a >> n) << n;

	for (int i = 0; i < n; ++i) {
		a |= ((a1 >> i) & 01) << (n - i - 1);
	}
	return a;
}


/*
  a = 01001011
  invert(a, 5, 3) =>
  01110011

  ~(~0 << 3) << (5 + 1 - 3) =>
  ~(11111111 << 3) << (3) =>
  ~(11111000) << 3 =>
  00000111 << 3 =>
  00111000
  b = 00111000 ^
  a = 01001011 =>
      01110011
   */

unsigned invert(unsigned x, int p, int n)
{
	int a = x;
	int b = ~(~0 << n) << (p + 1 - n) ^ a;

	return b;
}

/*
  a = 01001011
  y = 00101000
  setbits(a, 5, 3, 0b00101000) =>
  01101011

  ~(~0 << 3) =>
  ~11111000 =>
  00000111 << 5 + 1 - 3 =>
  00111000 & y =
  00101000
  b = 00101000
  ~00111000 =>
   11000111 & a = 
   01001011 =>
   01000011
  c = 01000011
  b | c =
  00101000
  01000011 =>
  01101011
*/

unsigned setbits(unsigned x, int p, int n, int y)
{
	int a = x;
	int a1 = ~(~0 << n) << (p + 1 - n);
	int b = a1 & y;
	int c = ~a1 & a;
	return (b | c);
}

unsigned getbits (unsigned x, int p, int n)
{
	/*
	  getbits(a, 5, 3) =>
	  01001011 >> [3 = (5 + 1 - 3)] =>
	  00001001 & [00000111 = ~11111000  = ~(11111111 << 3) = ~(~0 << 3)] =>
	  001
	*/
	return (x >> (p + 1 - n) & ~(~0 << n));
}
