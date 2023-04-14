#include <stdio.h>

void writelines(void *lineptr[], int num)
{
	printf(">>>>>>>>>>>>>>>>>>>>>\n");
	while(num-- > 0)
		printf("%s\n", *lineptr++);
	printf("<<<<<<<<<<<<<<<<<<<<<\n");
}
