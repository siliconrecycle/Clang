#include <stdio.h>

void printargv(int argc, char *argv[])
{
	printf("argv: [");
	while(argc--)
		printf(argc > 0 ? "\"%s\", " : "\"%s\"", *argv++);
	printf("]\n");
}
