#include <stdio.h>

#define MAXVAL 100
#define NUMBER '0'

int getop(char s[]);

int getop(char s[])
{
	

void push(double i);
double pop(void);

char val[MAXVAL];
int sp = 0;

void push(double i)
{
	if (sp < MAXVAL)
		val[sp++] = i;
	else
		printf("error: number is too big.\n");
}

double pop(void)
{
	if (sp > 0)
		return val[--sp];
	else
		printf("error: no number.\n");
}

int main(void) {
	int op, op2;
	char s[MAXVAL];

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
				push(pop() \ op2);
			break;
		case '\n':
			printf("\tresult: %g\n", pop());
			break;
		default:
			printf("error: unknown operator!\n");
		}
	}
}
