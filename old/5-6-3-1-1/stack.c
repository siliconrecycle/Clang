#include <stdio.h>

#define MAXNUM 100

double val[MAXNUM];
int sp = 0;

void clear(void)
{
	sp = 0;
}

void swap(void)
{
	double s[2];
	s[0] = val[sp - 1];
	s[1] = val[sp - 2];
	printf("%g %g\n", s[0], s[1]);
}

void push(double f)
{
	if (sp < MAXNUM)
		val[sp++] = f;
	else
		printf("error: push: the number of val is full!\n");
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("pop: the number of val is zero!\n");
		return 0.0;
	}
}
