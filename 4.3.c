#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

#define MAXVAL 100
#define NUMBER '0'
#define MAXOP 100

void login(double i);

int getch(void);
void ungetch(int c);

void push(double i);
double pop(void);

int getop(char s[]);

int main(void) {
	int op, op2;
	char s[MAXOP];

	while ((op = getop(s)) != EOF) {
		switch (op) {
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
			if (op == 0.0)
				printf("error: divider is zero\n");
			else
				push(pop() / op2);
			break;
		case '\n':
			printf("\tresult: %g\n", pop());
			break;
		default:
			printf("error: unknown operator!\n");
		}
	}
}

void login(double i)
{
	printf("log in: %g\n", i);
}

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void)
{
	return (bufp > 0) ? buf[--bufp] : getchar();
	/* if (sp2 > 0) */
	/* 	return stack[--sp2]; */
	/* else { */
	/* 	return getchar(); */
	/* } */
}

void ungetch(int c)
{
	if (bufp < BUFSIZE)
		buf[bufp++] = c;
	else
		printf("error: too much char!\n");
}

int getop(char s[])
{
	int c, i;

       	while ((s[0] = c = getch()) == ' ' || c == '\t')
		;
	s[1] = '\0';
	if (!isdigit(c) && (c != '.'))
		return c;
	i = 0;
	if (isdigit(c))
		while (isdigit(s[++i] = c = getch()))
			;
	if (c == '.')
		while (isdigit(s[++i] = c = getch()))
			;
	/* for (i = 1; isdigit(c); ++i) { */
	/* 	s[i] = c; */
 	/* 	c = getch(); */
	/* } */
	/* if (c == '.') */
	/* 	s[i] = c; */
	/* for (i = 1; isdigit(c); ++i) { */
	/* 	s[i] = c; */
	/* 	c = getch(); */
	/* }	 */

       	s[i] = '\0';
	
	if (c != EOF) {
		ungetch(c);
	}
	return NUMBER;
}

double val[MAXVAL];
int sp = 0;

void push(double i)
{
	if (sp < MAXVAL)
		val[sp++] = i;
	else
		printf("error: number is too big.\n");
	
	printf("%g\n", val[sp - 1]);
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else {
		printf("error: no number!\n");
		return 0.0;
	}
}
