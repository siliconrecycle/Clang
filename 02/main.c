#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

int main(void) {
	int op;
	char s[MAXNUM];
	double temp;

	while ((op = getop(s)) != EOF) {
		/* printf("op: %c\n", op); */
		switch (op) {
		case NUMBER:
			push(atof(s));
			break;
		case '+':
			/* printf("log in"); */
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
