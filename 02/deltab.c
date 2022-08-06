#include <stdio.h>

/* This is input two arguments, one is line, the other is maxline. */
void getline01(int[], int);

void getline01(int line[], int max)
{
	char c;

	for (int i = 0; (i < max) && ((c = getchar()) != EOF && c != '\n'); i++) {
		line[i] = c;
	}
}

int main(void) {
	int store[20];
	char c;
	int n;

	getline01(store, 20);
	for (int i = 0; i < 20; i++)
		printf("%s\n", store[i]);
	/* 	if (c == '\t') { */
	/* 		for (int i = 0; i < 8 - n; i++) */
	/* 			putchar(' '); */
	/* 		n = 0; */
	/* 	} else { */
	/* 		putchar(c); */
	/* 		n += 1; */
	/* 	} */
	/* 	if (n > 8) */
	/* 		n = n % 8; */
	
	/* printf("\n"); */
}
