#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void printfS(char v[]);
void reverse(char s[]);

int main(void)
{
	printf("%d\n", INT_MIN);
	printf("%d\n", INT_MAX);

	int i = -2147483648;
	char s[100];

	itoa(i, s);
	/* reverse(s); */
	printfS(s);
}

void itoa(int in, char s[])
{
	int i, sign;
	long int n;

	n = in;

	if ((sign = n) < 0) {
		n = -n;
	}

	printf("n: %ld\n", -n);
	i = 0;
	do {
		s[i++] = n % 10 + '0';
	} while ((n /= 10) > 0);
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
