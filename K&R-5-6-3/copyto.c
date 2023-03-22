#include <stdio.h>
#include <string.h>

#include "common.h"

void copyto(char *lineptr[], char *str, int p)
{
	char *ptr;
	int len;
	len = strlen(str);

	if((ptr = alloc(len)) != 0) {
		str[len-1] = '\0';
		strcpy(ptr, str);
		lineptr[p] = ptr;

		ptr += len;
	} else
		printf("error: no more pointers\n");

	/* writelines(lineptr, 5); */
}

//int main(void) {
//	char store01[100][100] = {"hello\n", "world\n", "Qian\n"};
//	char *store[100];
// 	int n;
//
// 	for(n = 0; n < 3; n++)
// 		copyto(store, store01[n], n);
//
//	writelines(store, n);
//}
