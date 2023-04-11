#include <stdio.h>
#include <string.h>

#include "common.h"

void copyto(char *lineptr[], char *str, int p)
{
	char *ptr;
	int len;
	len = strlen(str);

//	printf("log in copyto.c: ");
//	printf("s: %s, p: %d\n", str, p);

	if((ptr = alloc(len)) != NULL) {
//		str[len-1] = '\0';
		strcpy(ptr, str);
		ptr[len - 1] = '\0';
//		printf("ptr: %s, p: %d\n", ptr, p);
		lineptr[p] = ptr;
	} else
		printf("error: no more pointers\n");

	/* writelines(lineptr, 5); */
}

//int main(void) {
//	char *store01[] = {"hello\n", "world\n", "Qian\n"};
////	char *store[100];
// 	int n;
//
//	writelines(store01, 3);
//
// 	for(n = 0; n < 2; n++)
// 		copyto(store01, store01[n + 1], n);
//
//	writelines(store01, 3);
//}
