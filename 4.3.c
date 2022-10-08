#include <stdio.h>
#include <stdlib.h>

#define MAXNUM 10
#define NUMBER '0'

int getop(char s[]);
void push(double f);
double pop(void);

int main(void) {
	int op;
	char s[MAXNUM];
	double temp;

	while ((op = getop(s)) != EOF) {
		printf("op: %c\n", op);
		switch (op) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			printf("log in");
			push(pop() + pop());
			break;
		case '*':
			push(pop() * pop());
			break;
		case '-':
			temp = pop();
			push(pop() - temp);
			break;
		case '/':
			temp = pop();
			if (temp != 0.0)
				push(pop() / temp);
			else
				printf("error: zero divisor\n");
			break;
		case '\n':
			printf("result: %f\n", pop());
			break;
		default:
			printf("error: unknown command %s\n", s);
			break;
		}
	}
	return 0;
}

#define MAXVAL 100

int sp = 0;
double val[MAXVAL];

void push(double f)
{
	if (sp < MAXVAL)
		val[sp++] = f;
	else
		printf("error: stack full, can't push %g\n", f);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack empty\n");
		return 0.0;
	}
}

#include <ctype.h>

int getch(void);
void ungetch(int);

int getop(char s[])
{
	int c, i;

	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && c != '.') {
		return c;
	}
	
	if (isdigit(c)) {
		while (isdigit(s[++i] = c = getch()))
		       ;
	}
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;		
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("ungetch: too many characters\n");
	else
		buf[bufp++] = c;
}
