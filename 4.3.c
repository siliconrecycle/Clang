#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAXVAL 100
#define NUMBER '0'

int getop(char s[]);
void push(double f);
double pop(void);
void swap(void);
void clear(void);

int main(void) {
	int type;
	double op2;
	char s[MAXVAL];

	while ((type = getop(s)) != EOF) {
		switch (type) {
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

int getop(char s[])
{
	int c;
	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
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

	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define MAXBUF 10

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
