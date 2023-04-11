#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	int start, tab, c;
	char s[100] = "";

	start = 0;
	tab = -1;

	while (--argc > 0 && (*++argv)[0] == '-') {
		switch (c = *++argv[0]) {
		case 'm':
			/* printf("m: %s\n", *(argv)); */
			strcpy(s, *(++argv));
			--argc;
			start = atoi(s);
			/* printf("start: %d\n", start); */
			break;
		case 'n':
			/* printf("n: %s\n", *(argv)); */
			strcpy(s, *(++argv));
			--argc;
			tab = atoi(s);
			/* printf("tab: %d\n", tab); */
			break;
		default:
			printf("unknown op!\n");
			break;
		}
	}

	entab(start, tab);
}

/* int main(int argc, char *argv[]) */
/* { */
/* 	printf("ex5-11, hello!\n"); */
/* 	printargv(argc, argv); */

/* 	int t = 0, c; */
/* 	printf("c: %c\n", (*argv)[0]); */
/* 	if ((*++argv)[0] == '\t') */
/* 		for (t = 1 ;(c = *++argv[0]) == '\t'; ++t) */
/* 			; */
/* 	printf("t: <%d>\n", t); */
/* 	entab(t); */
/* } */

/* #include "detab.c" */

/* int main(int argc, char *argv[]) */
/* { */
/* 	int i; */
/* 	for (i = 0; *++argv[0] == '\t'; ++i) */
/* 		; */
/* 	detab(i); */
/* } */
