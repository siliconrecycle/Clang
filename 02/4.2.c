#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

/* double atof(char s[]); */

int atoi(char s[]);

int main(void) {
	/* char f[] = "-1.234"; */
	char f[] = "-123.4e-6";
	double atof(char s[]);
	printf("%e\n", atof(f));
	
	/* char i[] = "123123.1231"; */
	/* printf("%d\n", atoi(i)); */

	/* double sum, atof(char []); */
	/* /\* double sum; *\/ */
	/* char line[MAXLINE]; */
	/* int getline01(char [], int); */
	/* sum = 0; */
	/* while (getline01(line, MAXLINE) > 0) { */
	/* 	printf("sum: %f\n", sum += atof(line)); */
	/* } */
	/* return 0; */
}

int atoi(char s[])
{
	double atof(char []);
	/* return (int)atof(s); */
	return atof(s);
}

/* double atof(char s[]) */
/* { */
/* 	int i, sign; */
/* 	double val, power; */
/* 	for (i = 0; isspace(s[i]); ++i) */
/* 		; */
/* 	sign = (s[i] == '-') ? -1 : 1; */
/* 	if (s[i] == '-' || s[i] == '+') */
/* 		++i; */
/* 	for (val = 0; isdigit(s[i]); ++i) */
/* 		val = 10 * val + (s[i] - '0'); */
/* 	if (s[i] == '.') */
/* 		++i; */
/* 	for (power = 1.0; isdigit(s[i]); ++i) { */
/* 		val = 10 * val + (s[i] - '0'); */
/* 		power *= 10; */
/* 	} */
/* 	return sign * val / power; */
/* } */
		
