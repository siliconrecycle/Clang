/* ex.2-4 write an alternative version of squeeze(s1, s2) that delete each character in s1 that matches any character in s2.*/

#include <stdio.h>

void squeeze(char s1[], char s2[]);
/* void strcat01(char s[], char t[]); */

int main(void) {
	char s1[] = "hello world!";
	char s2[] = "ow";
	printf("%s\n", s1);

	squeeze(s1, s2);
	printf("%s\n", s1);

	/* char t[] = "Yuan, 2022-08-30"; */
	/* strcat01(s, t); */
	/* printf("%s\n", s);	 */
}

/* void strcat01(char s[], char t[]) */
/* { */
/* 	int i, j; */
/* 	i = j = 0; */
/* 	while (s[i] != '\0') { */
/* 		i++; */
/* 	} */
/* 	while ((s[i++] = t[j++]) != '\0'); */
/* } */

void squeeze(char s1[], char s2[])
{
	int i, j;
	for (int t = 0; s2[t] != '\0'; ++t) {
		for (i = j = 0; s1[i] != '\0'; ++i) {
			if (s1[i] != s2[t]) {
				s1[j++] = s1[i];
			}
		}
		s1[j] = '\0';
	}
}
