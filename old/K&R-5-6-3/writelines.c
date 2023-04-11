#include <stdio.h>

void writelines(char *lineptr[], int num)
{
	printf(">>>>>>>>>>>>>>>>>>>>>>\n");
	while(num-- > 0)
		printf("%s\n", *lineptr++);
	printf("<<<<<<<<<<<<<<<<<<<<<\n");
}
