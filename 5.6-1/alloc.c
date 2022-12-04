#include <stdio.h>

#define ALLOCSIZE 10000

static char allocbuf[ALLOCSIZE];
static char *allocp = allocbuf;

char *alloc(int n)
{
	if(allocbuf + ALLOCSIZE - allocp > 0) {
		allocp += n;
		return allocp - n;
	} else
		return 0;
}
