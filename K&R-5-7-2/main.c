#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

void printargv(int argc, char *argv[])
{
	printf("argv: [");
	while(argc--)
		printf(argc > 0 ? "\"%s\", " : "\"%s\"", *argv++);
	printf("]\n");
}

int main(int argc, char *argv[]) {
	int nmcmp = 0;

	printargv(argc, argv);
	/* printf("char: %c\n", (*++argv)[0]); */
	/* printf("str: %s", *argv); */
	while(--argc > 0 && (*++argv)[0] == '-')
		while(c = *++argv[0])
			switch (c) {
			case 'n':
				nmcmp = 1;
				break;
			default:
				printf("error: unoption item.\n");
				argc = 0;
				found  = -1;
				break;
			}

	if(argc != 1)
		printf("Usage: qsort [-n]\n");
	else {
		char *lineptr[100];
		int lines;

		if((lines = readlines(lineptr, MAXLINES)) > 0) {
			qsort(lineptr, 0, lines - 1);
			writelines(lineptr, lines);
			return 0;
		} else {
			printf("error: too many lines!\n");
			return -1;
		}
	}
}
