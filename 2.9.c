#include <stdio.h>

unsigned getbits(unsigned x, int p, int n);
unsigned setbits(unsigned x, int p, int n, int y);

int main(void) {
	int a = 0b01001011;
	printf("%#b\n", a);
	/* unsigned int r2 = getbits(a, 3, 3); */
	/* printf("%#b\n", r2); */
	/* unsigned int r = getbits(a, 4, 3); */
	/* printf("%#b\n", r); */
	/* unsigned int r1 = getbits(a, 5, 3); */
	/* printf("%#b\n", r1); */
	int c = setbits(a, 5, 3, 0b00101000);
	printf("%#b\n", c);
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
