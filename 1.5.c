#include <stdio.h>

/* In this time, we will write a program which can count the
   number of characters.
   This is 1.5.2, i will write this program in two ways.*/
int main() {
	long nc;

	/* nc = 0; */
	/* while (getchar() != EOF) { */
	/* 	++nc; */
	/* } */

	for (nc = 0; getchar() != EOF; ++nc)
		;
	printf("The number of input character: %ld\n", nc);
}
