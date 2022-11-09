#include <stdio.h>

void login(void);
char *strcat(char *s, char *t);

int main(void) {
	char *h = "hello ";
	char *w = "Qian";
	printf("%s\n", strcat(h, w));
}

char *strcat(char *s, char *t)
{
	char msg[100];
	char *p = msg;
	int i;
	for(i = 0;*p = *s; p++, s++, i++) {
		if(*s == '\0')
			break;
	}
	
	while(*p++ = *t++) {
		printf("%c\n", *p);
	}
	printf("%s\n", msg);
	return p = &msg[0];
}
	
void login(void)
{
	printf("log in\n");
}
