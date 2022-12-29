#include <stdio.h>

int main(void) {
	/* // 1. integer array can't assign with pointer. */
	/* int *nums = {1, 2, 3, 4, 5}; */
	/* printf("%d\n", nums++); */

	/* // 2. char */
	/* /\* char *msg = "hello world qian"; *\/ */
	/* char *msg = {'h', 'e', 'l', 'l', 'o'}; */
	/* printf("%s\n", msg); */
	/* // printf("%s\n", *msg); */



	/* int nums[2][13] = { */
	/* 	{1, 2, 3, 4, 5}, */
	/* 	{6, 7, 8, 9, 10} */
	/* }; */
	
	/* printf("%d\n", nums[1][2]); */

	/* char *nums[3] = { */
	/* 	"hello", */
	/* 	"world", */
	/* 	"qian" */
	/* }; */

	/* char **p = nums; */
	/* printf("%s\n", *p); */

	/* /\* *(p++); *\/ */
	/* *++p; */
	/* printf("%s\n", *p); */

	/* /\* *--p; *\/ */
	/* *p--; */
	/* printf("%s\n", *p); */

	int a = 10, b = 20;
	int *p = &a;


	/* printf("%d\n", 	(*p)++); */
	/* printf("%d\n", 	*p); */


	printf("%d\n", ++*p);
	printf("%d\n", *p);
}
