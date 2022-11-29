#include <stdio.h>
#include "readlines.h"

#define MAXCHAR 10

void writelines(char *lineptr[], int num)
{
	while(num-- > 0)
		printf("wr: %s", *lineptr++);
}


int readlines(char *lineptr[], int maxline)
{
	char line[MAXCHAR];
	int nl;

	nl = 0;
	while(getline01(line, MAXCHAR) > 0) {
		if(nl < maxline) {
			/* copyto(lineptr, line, nl); */
			
			lineptr[nl++] = line;
			printf("rl:");
			writelines(lineptr, nl);
		} else
			return -1;
	}
	return nl;
}


int main(void) {
	char *store[100];
	int max = 10, n;
	/* char *store01[100] = {"hello ", "world"}; */

	n = readlines(store, max);


	writelines(store, n);
}
