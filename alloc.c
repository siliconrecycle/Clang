// hello
#include <stdio.h>

#define ALLOCSIZE 100

char allocbuf[ALLOCSIZE];
char *allocp = allocbuf;

char *alloc(int n);
void afree(char *p);
void strcpy01(char *s, char *t);

int main(void) {
	char *msg = alloc(5);
	char *tran = "hello world";
	strcpy01(msg, tran);
	printf("%s\n", msg);
	afree(msg + 2);
	printf("%s\n", msg);
}
char *alloc(int n)
{
	if(allocbuf + ALLOCSIZE - allocp >= n) {
		allocp += n;
		return allocp - n;
	} else
		return 0;
}
void afree(char *p)
{
	if((p > allocbuf) && (p < allocbuf + ALLOCSIZE))
		allocp = p;
}
void strcpy01(char *s, char *t)
{
	while(*s++ = *t++)
		;
}

