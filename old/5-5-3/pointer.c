#include <stdio.h>

int main(void) {
	/* int *nums = {1, 2, 3, 4, 5}; */
	/* printf("%d\n", nums++); */

	/* int nums[2][13] = { */
	/* 	{1, 2, 3, 4, 5}, */
	/* 	{6, 7, 8, 9, 10} */
	/* }; */
	
	/* printf("%d\n", nums[1][2]); */

	char *nums[3] = {
		"hello",
		"world",
		"qian"
	};

	char **p = nums;
	printf("%s\n", *p);

	/* *(p++); */
	*++p;
	printf("%s\n", *p);

	/* *--p; */
	*p--;
	printf("%s\n", *p);

	/* int a = 10, b = 20; */
	/* int *p = &a; */

	/* /\* (*p)++; *\/ */
	/* /\* printf("%d\n", *p); *\/ */

	/* ++*p; */
	/* printf("%d\n", *p); */


	/* /\* char *msg = "hello world qian"; *\/ */
	/* /\* printf("%s\n", msg); *\/ */
	/* /\* // printf("%s\n", *msg); *\/ */

}
