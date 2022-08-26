#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define HELLO "hello world!"
#define fraction 1.234L

const char msg[] = "Warning: ";

void leap(int year);
void getline01(char line[], int lim);

int main(void) {
	printf("%s\n", HELLO);
	printf("%LF\n", fraction);
	printf("%s\n", msg);

	printf("%d\n", strlen(msg));

	for (int i = 2022; i < 2030; ++i)
		leap(i);
	
	int lim;
	char p[lim];

	lim = 20;
	getline01(p, 20);
	printf("%s\n", p);
	
	return 0;
}

void getline01(char line[], int lim)
{
	int i, c; 
	for(i = 0; i < lim - 1 ; ++i) {
		if ((c=getchar()) == EOF)
			break;
		else if (c == '\n')
			break;
		line[i] = c;
	}
	if (c == '\n') {
		line[i] = '\n';
		++i;
	}
	line[i] = '\0';
	return ;
}

void leap(int year)
{
	if ((year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		printf("%d is a leap year\n", year);
	else
		printf("%d is not a leap year\n", year);
}
