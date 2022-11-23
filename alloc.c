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

void strcpy01(char *t, char *s)
{
	while(*t++ = *s++)
		;
}

int strcmp01(char *s, char *t)
{
	for(; *s == *t; s++, t++)
		if(*t == '\0')
		/* if(*t) */
			return 0;
	return *s - *t;
}

