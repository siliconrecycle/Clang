#include <stdio.h>

void swap(int *a, int *b);
void strcpy01(char *t, char *s);
int strlen01(char *);
int strcmp01(char *t, char *s);

int main(void) {
	/* int a = 3, b = 4; */
	/* swap(&a, &b); */
	/* printf("a: %d, b: %d\n", a, b); */

	char msg[] = "hello world";
	char *pmsg;

	strcpy01(pmsg, msg);
	/* printf("%s\n", pmsg); */
	
	int c = strlen01(msg);
	/* printf("%d\n", c); */

	int d = strcmp01(pmsg, msg);
	printf("%d\n", d);
}
	
void swap(int *a, int *b)
{
	int tmp = *a;
	*a = *b;
	/* a = b; */
	*b = tmp;
}
void strcpy01(char *t, char *s)
{
	while(*t++ = *s++)
		;
}
int strlen01(char *s)
{
	char *p = s;
	while(*p != '\0')
		p++;
	return p - s;
}
int strcmp01(char *t, char *s)
{
	for(; *t == *s; s++, t++)
		/* if(*t == '\0'); */
		if(*t)
			return 0;
	return *s - *t;
}

#define ALLOCSIZE 100

static char allocbuf[ALLOCSIZE];
static char *allocp =  allocbuf;

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
