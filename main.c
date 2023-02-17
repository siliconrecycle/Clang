#include <stdio.h>
#include "detab.c"

int main(int argc, char *argv[])
{
	int i;
	for (i = 0; *++argv[0] == '\t'; ++i)
		;
	detab(i);
}
