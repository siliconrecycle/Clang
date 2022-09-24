#include <stdio.h>
#include <string.h>

void itoa(int n, char s[]);
void printfS(char v[]);
void reverse(char s[]);

int main(void)
{
	int i = -2425;
	char s[100];
	/* char s[100] = "hello world"; */

	itoa(i, s);
	/* reverse(s); */
	printfS(s);
}

void itoa(int n, char s[])
{
	int i, sign;

	/* if ((sign = n) < 0) { */
	/* 	n = -n; */
	/* } */

	if (n < 0) {
		n = -n;
		sign = -1;
	}

	i = 0;
	s[i++] = '0' + n % 10;
	while ((n = n / 10) > 0) {
		s[i++] = '0' + n % 10;
	}
	/* do { */
	/* 	s[i++] = n % 10 + '0'; */
	/* } while ((n =/ 10) > 0); */
	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';		/* i forget this. */
	reverse(s);
}

void reverse(char s[])
{
	int i, j;
	/* Caution!!! Not s[i] != '\0', should be i < j. */
	for (i = 0, j = strlen(s) - 1; i < j; ++i, --j) {
		char temp = s[i];
		s[i] = s[j];
		s[j] = temp;
	}
}

void printfS(char v[])
{
	int n = strlen(v);
	for (int i = 0; i < n; ++i)
		printf("%c ", v[i]);
	printf("\n");
}
