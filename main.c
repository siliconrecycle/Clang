#include <stdio.h>

int main(void)
{
	char month[100];
	int day, year;
	char *date = "18 Jul 2022";
	sscanf(date, "%d %s %d", &day, month, &year);
	printf("%d/%s/%d\n", day, month, year);
}
