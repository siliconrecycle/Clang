#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXVAL 100
#define NUMBER '0'
#define LETTER '1'

int getop(char s[]);
void push(double f);
double pop(void);
void swap(void);
void clear(void);

int main(void) {
	int type;
	double op2;
	char s[MAXVAL];
	double alph[26] = {0};
	
	while ((type = getop(s)) != EOF) {
		switch (type) {
		/* case LETTER: */
		/* 	printf("log in: %c\n", s[0]); */
		/* 	alph[s[0] - 'a'] = pop(); */
		/* 	for (int i = 0; i < 26; i++) { */
		/* 		printf("%c %g\n", 'a' + i, alph[i]); */
		/* 	} */
		/* 	break; */


		/* case '&': */
		/* 	op2 = pop(); */
		/* 	push(pow(pop(), op2)); */
		/* 	/\* push(exp(pop())); *\/ */
		/* 	/\* push(sin(pop())); *\/ */
		/* 	break; */
		/* case '?': */
		/* 	/\* swap(); *\/ */
		/* 	clear(); */
		/* 	break; */
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
			printf("main: s: <%s>\n", s);
			printf("\tresult: %g\n", pop());
			break;
		default:
			printf("error: main(): known operator!\n");
			break;
		}
	}
}

#define MAXNUM 100

double val[MAXNUM];
int sp = 0;

void clear(void)
{
	sp = 0;
}

void swap(void)
{
	double s[2];
	s[0] = val[sp - 1];
	s[1] = val[sp - 2];
	printf("%g %g\n", s[0], s[1]);
}

void push(double f)
{
	if (sp < MAXNUM)
		val[sp++] = f;
	else
		printf("error: push: the number of val is full!\n");
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("pop: the number of val is zero!\n");
		return 0.0;
	}
}

#include <ctype.h>

#define MAXLINE 100

int getch(void);
void ungetch(char c);

void ungets(char s[]);
void printb(void);
int getline01(char s[], int lim);

char val01[MAXLINE];
int sp01 = 0;
int nm = 0;

int getop(char s[])
{
	if (sp01 >= nm) {
		nm = getline01(val01, MAXLINE);
		sp01 = 0;
	}

	while ((s[0] = val01[sp01++]) == ' ' || s[0] == '\t')
		;
	s[1] = '\0';
	if (!isdigit(s[0]) && s[0] != '.')
		return s[0];
	/* printf("getop01: nm: %d, sp01: %d, val01: <%s>\n", nm, sp01, val01); */
	
	int i = 1;
	if (isdigit(s[0]))
		while ((sp01 < nm - 1) && isdigit(s[i++] = val01[sp01++]))
		       ;

	if (s[i - 1] == '.')
		while ((sp01 < nm - 1) && isdigit(s[i++] = val01[sp01++]))
		       ;
	/* printf("getop02: s: <%s>\n", s);	 */
	/* printf("getop02: i: <%d>\n", i); */
	s[i] = '\0';

	printf("getop03: sp01: %d, nm: %d, i: %d\n", sp01, nm, i);
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
	while (lim-- > 0 && (c = getchar()) != EOF && c != '\n') {
		s[i++] = c;
	}
	if (c == '\n') {
		s[i++] = '\n';
	}
	s[i] = '\0';	
	return i;
}
