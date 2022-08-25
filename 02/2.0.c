/* ex.2-1 write a program to determine the range of char, short, int and long
 variables, and signed, unsigned.*/

#include <stdio.h>
#include <limits.h>

int main(void) {
	printf("weclome 2.0!\n");
	printf("char:[%d, %d]\n", CHAR_MIN, CHAR_MAX);
	printf("short:[%d, %d]\n", SHRT_MIN, SHRT_MAX);
	printf("int:[%d, %d]\n", INT_MIN, INT_MAX);
	printf("long:[%ld, %ld]\n", LONG_MIN, LONG_MAX);

	printf("uchar:[%d, %d]\n", 0, UCHAR_MAX);
	printf("ushort:[%d, %d]\n", 0, USHRT_MAX);
	printf("uint:[%d, %ld]\n", 0, UINT_MAX);
	printf("ulong:[%ld, %lu]\n", 0, ULONG_MAX);
}
