#include <stdio.h>

int rightrot(int x, int n);

int main(void) {
	int x = 0b10110110;
	int n = 3;
	int r = rightrot(x, n);
	printf("%#b\n", r);
	printf("%#b\n", x);
}

/*
  x = 10110110
  rightrot(x, 3) =>
  10110011
  
  x = 10110110
  (x >> 3 - 3) & 01 =>
  0 << 3 - 1 =>
  000

  (x >> 3 - 2) & 01 =>
  1 << 3 - 2 =>
  010 | 000 =>
  010

  (x >> 3 - 1) & 01 =
  1 << 3 - 3 =>
  001 | 010 =>
  011

  x & (~0 << 3) =>
  10110000 | 011 =>
  10110011
 */

int rightrot(int x, int n)
{
	int b = 0;
	for (int i = 0; i < n; ++i) {
		b |= (x >> n - i) & 01;
	}
	return x & (~0 << 3) | b;
}
