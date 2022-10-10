#include <stdio.h>
#include <stdlib.h>

#define NUMBER '0'
#define MAXVAL 100

int getop(char []);
void push(double);
double pop(void);

int main(void) {
	int type;
	double op;
	char s[MAXVAL];
	while ((type = getop(s)) != EOF) {
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
			op = pop();
			push(pop() - op);
			break;
		case '/':
			op = pop();
			if (op == 0.0)
				printf("error: it is not a divider!\n");
			else
				push(pop() / op);
			break;
		case '\n':
			printf("\tresult: %g\n", pop());
			break;
		default:
			printf("error: unknown operator!\n");
			break;
		}
	}
	return 0;
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
	if (!isdigit(c) && c != '.')
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	s[i] = '\0';
	if (c != EOF)
		ungetch(c);
	return NUMBER;
}

#define BUFSIZE 10

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
}
	
void ungetch(int c)
{
	if (bufp >= BUFSIZE)
		printf("error: too much characters in buf!\n");
	else
		buf[bufp++] = c;
}

#define MAXOP 100
	
double val[MAXOP];
int sp = 0;

void push(double f)
{
	if (sp >= MAXOP)
		printf("error: too much operators!\n");
	else
		val[sp++] = f;
}

double pop(void)
{
	/* return (sp > 0) ? val[--sp] : 0.0; */
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: stack is empty!\n");
		return 0.0;
	}
}
