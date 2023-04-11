#include <stdio.h>
#include <string.h>

#define MAXLINE 1000

int getline01(char s[], int lim);
int strindex(char s[], char t[]);

/* char pattern[] = "ould"; */

void printargv(int argc, char *argv[])
{
	printf("argv: [");
	while(argc--)
		printf(argc > 0 ? "\"%s\", " : "\"%s\"", *argv++);
	printf("]\n");
}

int main(int argc, char *argv[]) {
	char s[MAXLINE], c;
	int found = 0;
	int except = 0, number = 0;
	long lineno = 0;

	printargv(argc, argv);
	/* printf("char: %c\n", (*++argv)[0]); */
	/* printf("str: %s", *argv); */
	while(--argc > 0 && (*++argv)[0] == '-')
		while(c = *++argv[0])
			switch (c) {
			case 'p':
				except = 1;
				break;
			case 'n':
				number = 1;
				break;
			default:
				printf("error: unoption item.\n");
				argc = 0;
				found  = -1;
				break;
			}

	if(argc != 1)
		printf("Usage: find -x -n pattern\n");
	else
		while (getline01(s, MAXLINE) > 0) {
			lineno++;
			if ((strstr(s, argv[0]) != NULL) != except) {
				if (number)
					printf("%ld:", lineno);
				printf("%s", s);
				found++;
			}

			/* if (strstr(s, argv[0]) != NULL && !p) { */
			/* 	if (n)  */
			/* 		printf("%d match: %s", ++i, s); */
			/* 	else */
			/* 		printf("match: %s", s); */
			/* 	found++; */
			/* } */
			/* if (strstr(s, argv[0]) == NULL && p) { */
			/* 	if (n)  */
			/* 		printf("%d unmatch: %s", ++i, s); */
			/* 	else */
			/* 		printf("unmatch: %s", s); */
			/* } */
		}
	return found;
}


/* int main(void) { */
/* 	char s[MAXLINE]; */
/* 	int found = 0; */

/* 	while (getline01(s, MAXLINE) > 0) { */
/* 		int t = strindex(s, pattern); */
/* 		/\* printf("t: %d\n", t); *\/ */

/* 		if (strindex(s, pattern) >= 0) { */
/* 			printf("s: %s", s); */
/* 			found++; */
/* 		} */
/* 	} */
/* 	return found; */
/* } */

int strindex(char s[], char t[])
{
	int i, j, k;
	int n, m;
	n = strlen(s) - 1;
	m = strlen(t) - 1;
	for (i = n; i >= 0; --i) {
		for (j = i, k = m; k >= 0 && t[k] == s[j]; --k, --j)
			;
		/* printf("i: %d\n", i); */
		if (k < 0)
			return n - i;
	}
	return -1;
}
			
	

int getline01(char s[], int lim)
{
	int c, i;
	for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
		s[i] = c;
	}
	if (c == '\n') {
		s[i++] = '\n';
	}
	s[i] = '\0';	
	return i;
}
