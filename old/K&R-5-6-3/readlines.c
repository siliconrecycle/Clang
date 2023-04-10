#include <stdio.h>
#include <string.h>

#include "common.h"

#define MAXCHAR 100

int readlines(char *lineptr[], int maxline)
{
	char line[MAXCHAR], *ptr;
	int nl, n;

	n = maxline;
	nl = 0;

	while(getline01(line, MAXCHAR) > 0) {
		if (nl >= n) {
			for (int i = 0; i < n - 1; ++i) {
//				strcpy(lineptr[i], lineptr[i + 1]);
<<<<<<< HEAD
//				copyto(lineptr, lineptr[i + 1], i);
				lineptr[i] = lineptr[i + 1];
//				printf("ptr: %s\n", lineptr[i]);
=======
				copyto(lineptr, lineptr[i + 1], i);
//				lineptr[i] = lineptr[i + 1];
				printf("ptr: %s\n", lineptr[i]);
>>>>>>> ae03475 (5-6-3 finshed)
			}
			copyto(lineptr, line, n - 1);
//			printf("%s\n", lineptr[n - 1]);
		} else {
<<<<<<< HEAD
//			printf("main: s: %s, nl: %d\n", line, nl + 1);
=======
>>>>>>> ae03475 (5-6-3 finshed)
			copyto(lineptr, line, nl++);
		}
	}
	return nl;
}

<<<<<<< HEAD
//#include <stdlib.h>
//
//#define NUMBER 3
//
//int main(int argc, char *argv[]) {
//	char c;
//	char s[100] = "";
// 	int maxlines, n;
//
//	maxlines = NUMBER;
// 	char *store[maxlines];
//
//	while (--argc > 0 && (*++argv)[0] == '-') {
//		switch (c = *++argv[0]) {
//		case 'n':
//			strcpy(s, *(++argv));
//			--argc;
//			maxlines = atoi(s);
//			break;
//		default:
//			printf("unknown op!\n");
//			break;
//		}
//	}
//
//
//	n = readlines(store, maxlines);
//	writelines(store, n);
//	return 0;
//}
=======
#define NUMBER 3

int main(void) {
 	int maxlines, n;

	maxlines = NUMBER;
 	char *store[maxlines];

	n = readlines(store, maxlines);
	writelines(store, n);
	return 0;
}
>>>>>>> ae03475 (5-6-3 finshed)
