#include <stdio.h>

/* ex.4-13 void reverse(char s[]) */

void reverse(char s[], int left, int right);

int main(void) {
	char s[] = "hello";
	printf("%s\n", s);
	
	reverse(s, 0, 4);
	printf("%s\n", s);
}

void swap (char v[], int i, int j)
{
	int temp;
	temp = v[i];
	v[i] = v[j];
	v[j] = temp;
}
void reverse(char s[], int left, int right)
{
	if (left >= right)
		return;
	swap(s, left, right);
	reverse(s, ++left, --right);
}
