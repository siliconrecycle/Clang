#include <stdio.h>
#include "entab.c"

void printargv(int argc, char *argv[])
{
	printf("argv: [");
	while(argc--)
		printf(argc > 0 ? "\"%s\", " : "\"%s\"", *argv++);
	printf("]\n");
}

int main(int argc, char *argv[])
{
	printf("ex5-11, hello!\n");
	printargv(argc, argv);

	int t = 0, c;
	printf("c: %c\n", (*argv)[0]);
	if ((*++argv)[0] == '\t')
		for (t = 1 ;(c = *++argv[0]) == '\t'; ++t)
			;
	printf("t: <%d>\n", t);
	entab(t);
}

/* #include "detab.c" */

/* int main(int argc, char *argv[]) */
/* { */
/* 	int i; */
/* 	for (i = 0; *++argv[0] == '\t'; ++i) */
/* 		; */
/* 	detab(i); */
/* } */
