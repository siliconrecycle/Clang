#include <stdio.h>
#include <string.h>
#include <limits.h>

void itoa(int n, char s[]);
void itob(int n, char s[], int b);
void itoc(int in, char s[], int w);
void printfS(char v[]);
void reverse(char s[]);

int main(void)
{
	printf("%d\n", INT_MIN);
	printf("%d\n", INT_MAX);

	int i = -2147483648;
	char s[100];

	/* itoa(i, s); */
	/* reverse(s); */
	/* itob(i, s, 16); */
	itoc(i, s, 5);
	printfS(s);
}

void itoc(int in, char s[], int w)
{
	int i, sign;
	long int n;

	n = in;
	if ((sign = n) < 0) {
		n = -n;
	}

	i = 0;
	do {
		s[i++] = n % 10 + '0';
		for (int m = 0; m < w; ++m)
			s[i++] = ' ';
	} while ((n /= 10) > 0);
	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';		/* i forget this. */
	reverse(s);
}

void itob(int in, char s[], int b)
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
		switch (b) {
		case 2:
			s[i++] = n % 2 + '0';
			break;
		case 8:
			s[i++] = n % 8 + '0';
			break;
		case 16:
			if (n % 16 > 9) {
				s[i++] = (n % 16 - 9) + 'A';
			} else {
				s[i++] = n % 16 + '0';
			}
			break;
		default:
			printf("error base!");
			break;
		}
	} while ((n /= b) > 0);
	if (sign < 0) {
		s[i++] = '-';
	}
	s[i] = '\0';		/* i forget this. */
	reverse(s);
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
		printf("%c", v[i]);
	printf("\n");
}
