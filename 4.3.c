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
		case LETTER:
			printf("log in: %c\n", s[0]);
			alph[s[0] - 'a'] = pop();
			for (int i = 0; i < 26; i++) {
				printf("%c %g\n", 'a' + i, alph[i]);
			}
			break;
		case '&':
			op2 = pop();
			push(pow(pop(), op2));
			/* push(exp(pop())); */
			/* push(sin(pop())); */
			break;
		case '?':
			/* swap(); */
			clear();
			break;
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

int getch(void);
void ungetch(char c);

void ungets(char s[]);
void printb(void);

int getop(char s[])
{
	int c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';

	if (isalpha(c))
		return LETTER;

	if (!isdigit(c) && c != '.')
		return c;
	
	int i = 1;
	if (isdigit(c))
		while (isdigit(s[i++] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[i++] = c = getch()))
			;
	s[i] = '\0';

	/* printf("getop: s: %s\n", s); */
	/* ungets(s); */
	/* printf("s: %s\n", s); */


	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#include <string.h>
#define MAXBUF 1

char buf[MAXBUF];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(char c)
{
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
	
