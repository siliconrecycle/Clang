/* ex.2-5 write a program any(s1, s2), which returns the first location in a string s1 where any character from the string s2 occurs, or -1 if s1 contains no character in s2.*/

#include <stdio.h>

int any(char s1[], char s2[]);

int main(void) {
	char s1[] = "hello world!";
	char s2[] = "ewo";
	printf("%s\n", s1);
	printf("%s\n", s2);

	int c =	any(s1, s2);
	printf("%d\n", c);
}

int any(char s1[], char s2[])
{
	int i, j;
	
	for (i = 0; s1[i] != '\0'; ++i) {
		for (j = 0; s2[j] != '\0'; ++j) {
			if (s2[j] == s1[i]) {
				return i;
			}
		}
	}	
	return -1;	
}
