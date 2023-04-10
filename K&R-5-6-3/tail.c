#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "common.h"

#define NUMBER 3

int main(int argc, char *argv[]) {
	char c;
	char s[100] = "";
 	int maxlines, n;

	maxlines = NUMBER;
 	char *store[maxlines];

	while (--argc > 0 && (*++argv)[0] == '-') {
		switch (c = *++argv[0]) {
		case 'n':
			strcpy(s, *(++argv));
			--argc;
			maxlines = atoi(s);
			break;
		default:
			printf("unknown op!\n");
			break;
		}
	}


	n = readlines(store, maxlines);
	writelines(store, n);
	return 0;
}
