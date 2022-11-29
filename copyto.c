#include <stdio.h>

void copyto(char *lineptr[], char *str, int p)
{
	lineptr[p] = str;
}

/* int main(void) { */
/* 	/\* char *store[100] = {"hello", "world"}; *\/ */
/* 	/\* printf("%s\n", store[1]); *\/ */

/*        	char *store[100]; */
/* 	copyto(store, "hello", 0); */
/* 	printf("%s\n", store[0]); */
/* } */
