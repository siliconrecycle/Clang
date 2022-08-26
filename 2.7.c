#include <stdio.h>
#include <ctype.h>
#include <string.h>

int htoi(char s[]); 

int main(void) {
	/* printf("%d\n", isdigit('1')); */
	
	/* int c = "2098"; */

	/* if (isdigit(c)) */
	/* 	printf("%c\n", c); */
	/* else */
	/* 	printf("no-zero\n"); */

	char c[] = "F";
	int n = htoi(c);
	printf("%d\n", n);
	return 0;
}

int htoi(char c[]) {
	int i, n;

	n = 0;
	for (i = 0; i < strlen(c); ++i) {
		if (isdigit(c[i]))
			n = 16 * n + (c[i] - '0');
		else if (c[i] >= 'a' && c[i] <= 'f') 
			n = 16 * n + (c[i] - 'a');
		else if (c[i] >= 'A' && c[i] <= 'F')
			n = 16 * n + (c[i] - 'A') + 10 ;
		else
			printf("input error!\n");
	}
	return n;
}
