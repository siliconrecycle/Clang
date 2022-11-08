#include <stdio.h>

int strlen01(char *);

int main(void) {
	char *msg = "hello world";
	
	int l =  strlen01(msg);
	printf("len: %d\n", l);
}

int strlen01(char *s)
{
	char *p = s;
	while(*p !='\0')
		p++;
		;
	return p - s;
	/* int i; */
	/* for(i = 0; *s++ != '\0'; i++) */
	/* 	; */
	/* return i; */
}
