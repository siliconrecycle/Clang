#include <stdio.h>

int getline01(char *line, int max)
{
	char str[max], c;
	int n;

	for(n = 0; (c = getchar()) != EOF; n++) {
		if(n < max && c != '\n') {
			line[n] = c;
		} else if(c == '\n') {
			line[n] = c;
			line[++n] = '\0';
			return n;
		} else {
			line[n] = '\0';
			return n;
		}
	}
	return -1;
}

/* int main(void) { */
/* 	char msg[100]; */
/* 	int nread; */
/* 	while((nread = getline01(msg, 10)) > 0) */
/* 		printf("num: %d, %s\n", nread, msg); */
/* } */
