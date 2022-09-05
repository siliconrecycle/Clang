#include <stdio.h>

int bitcount(unsigned i);

int main(void) {
	printf("%#b\n", 10);
	int c = bitcount(10);
	printf("%d\n", c);
	return 0;
	
	/* char msg[] = "abcdefg"; */
	/* int a, b; */
	/* a = 1; */
	/* b = 2; */
	/* printf("%c\n", msg[a + b]); */
	/* msg[a + b] += 1; */
	/* printf("%c\n", msg[a + b]); */

	/* unsigned x = 10; */
	/* printf("%#b\n", x); */
	/* printf("%#b\n", (x - 1)); */
	/* x &= (x - 1); */
	/* printf("%#b\n", x); */
	/* return 0; */
}

int bitcount(unsigned x)
{
	/* int b; */
	/* for (b = 0; x != 0; x >>= 1) */
	/* 	if (x & 01 == 1) */
	/* 		++b; */
  	/* return b;	 */

	/* This is very interesting, x &= (x - 1) will remove the one's bit by minus one to change the place of one. */
	int b;
	for (b = 0; x != 0; x &= (x - 1))
		++b;
  	return b;	

}
