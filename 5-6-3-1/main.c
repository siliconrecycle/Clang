#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "utils.c"
#include "stack.c"

#define MAXVAL 100
#define NUMBER '0'
#define LETTER '1'

int getop(char s[], int argc, char *argv[]);
void push(double f);
double pop(void);
void swap(void);
void clear(void);

int main(int argc, char *argv[]) {
	int type;
	double op2;
	char s[MAXVAL];
	double alph[26] = {0};
	
	/* printargv(argc, argv); */

	while ((type = getop(s, argc, argv)) != EOF) {
		switch (type) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			op2 = pop();
			push(pop() - op2);
			break;
		case '/':
			op2 = pop();
			if (op2 != 0.0)
				push(pop() / op2);
			else
				printf("error: main: '/' 's divider can't be zero!\n");				       
			break;
		case '%':
			op2 = pop();
			if (op2 != 0.0)
			  push(fmod(pop(), op2));
			else
				printf("error: main: '%' 's divider can't be zero!\n");				       
			break;			
		case '\n':
			/* printf("main: s: <%s>\n", s); */
			printf("\tresult: %g\n", pop());
			break;
		default:
			printf("default: type: %d\n", type);
			printf("error: main(): unknown operator!\n");
			break;
		}
	}
}


#include <ctype.h>
#include <string.h>

#define MAXLINE 100

int getch(void);
void ungetch(char c);

void ungets(char s[]);
void printb(void);
int getline01(char s[], int lim);

char val01[MAXLINE];
int sp01 = 0;
int nm = 0;

int getcmdline(char s[], int argc, char *argv[])
{
	printf("getcmdline: ");
	printf("argc: %d ", argc);
	char tmp[MAXLINE] = "";
	while(--argc > 0) {
		strcat(tmp, *++argv);
		strcat(tmp, (argc > 1) ? " " : "");
	}
	strcat(tmp, "\n");
	strcpy(s, tmp);
	printf("s: <%s>\n", s);
	return strlen(s);
}

int getop(char s[], int argc, char *argv[])
{
	printf("getop: ");
	printargv(argc, argv);

	int c, i;

	if (sp01 > nm) {
		/* nm = getline01(val01, MAXLINE); */
		nm = getcmdline(val01, argc, argv);
		/* printf("nm = %d, val01: <%s>\n", nm, val01); */
		sp01 = 0;
	}

	printf("getop01: nm: %d, sp01: %d, val01: <%s>\n", nm, sp01, val01);

	while ((s[0] = c = val01[sp01++]) == ' ' || c == '\t')
		;
	
	s[1] = '\0';
	if (!isdigit(c) && c != '.')
		return c;

	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = val01[sp01++]))
		       ;

	if (c  == '.')
		while (isdigit(s[++i] = c = val01[sp01++]))
		       ;
	s[i] = '\0';



	/* if(sp01 >= nm) */
	/* 	return EOF; */

	return NUMBER;
}

#include <string.h>
#define MAXBUF 1

char buf[MAXBUF];
int bufp = 0;

int getch(void)
{
	int c = getchar();
	if (bufp > 0) {
		c = buf[--bufp];
		printf("getch: %c\n", c);
	}
	return c;
	/* return (bufp > 0) ? buf[--bufp] : getchar();  */
}

void ungetch(char c)
{
	/* // examize input is eof. */
	/* if (c == EOF) { */
	/* 	printf("ungetch: eof!\n"); */
	/* 	printf("s: %c\n", c); */
	/* } */

	if (bufp < MAXBUF)
		buf[bufp++] = c;
	else
		printf("error: main: getop: ungetch: buf is full!\n");
}

void printb()
{
	printf("buf: ");
	for (int i = 0; i < MAXBUF; ++i)
		printf("%c", buf[i]);
	printf("\n");
}

/* void reverse(char s[]) */
/* { */
/* 	int n = strlen(s); */
/* 	int tmp; */
/* 	int i = 0; */
/* 	while (i < n / 2) { */
/* 		tmp = s[i]; */
/* 		s[i] = s[n - i]; */
/* 		s[n - i] = tmp; */
/* 		++i; */
/* 	} */
/* } */

void ungets(char s[])
{
	int n = strlen(s);

	printf("ungets: input: <%s>", s);
	printf("len: %d\n", n);
	
	/* for (int i = 0; i < n; ++i) { */
	/* 	if (s[i] == ' ' && i != n - 1) { */
	/* 		printf("ungets: s[%d]: <%c>\n", i, s[i]); */
	/* 		printf("ungets: too much strings!\n"); */
	/* 		return; */
	/* 	} */
	/* } */

	for (int i = n - 2; i >= 0; --i)
		ungetch(s[i]);
	printf("buf: %s\n", buf);
}
	
int getline01(char s[], int lim)
{
	int c, i;

	i = 0;
	while (lim-- > 0 && (c = getchar()) != EOF && c != '\n') { // EOF is not be included in s[].
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = '\n';
	}
	s[i] = '\0';	
	return i;
}
