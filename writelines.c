#include <stdio.h>

void writelines(char *lineptr[], int num)
{
	printf("writeline:\n");
	while(num-- > 0)
		printf("%s", *lineptr++);
	printf("\nend.\n");
}
