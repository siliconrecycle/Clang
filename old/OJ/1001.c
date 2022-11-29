#include <stdio.h>
#include <math.h>

void reverse(void);

int main(void) {
	reverse();
	return 0;
}

void reverse(void)
{
	
	long int n;
	
	n = 0;

	if(scanf("%ld", &n) != EOF)
		reverse();
	else
		return;
	printf("%0.4lf\n", sqrt(n));
}
