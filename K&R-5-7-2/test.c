#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "qsort.c"
#include "writelines.c"

int main() {
	int a = 212, b = 321, c = 123, d = 4;

	char *x[] = { "hello world", "qian", "yi", "ming" };
	int *y[] = {&a, &b, &c, &d};

	writelines((void *)x, 4);
	writelines((void *)y, 4);

//	char str1[] = "abc";
//	char str2[] = "xyz";
//
//	printf("r: %d\n", numcmp(str1, str2));
//
//	if (numcmp(str1, str2))
//		printf("str1 cmp str2\n");
//	else
//		printf("str1 not cmp str2\n");

//    double num1 = atof(str1);
//    double num2 = atof(str2);
//
//    if (num1 == num2) {
//        printf("str1 and str2 are equal.\n");
//    } else {
//        printf("str1 and str2 are not equal.\n");
//    }

    return 0;
}