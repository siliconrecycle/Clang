#include <stdio.h>
#include <string.h>

char *month_of_name(int n);

int main(void) {
	int m = 3;
	char *msg = "March";
	if(strcmp(msg, month_of_name(m)) == 0)
		printf("true!\n");
	else
		printf("false!\n");
}

char *month_of_name(int n)
{
	char *monthes[13] = {
		"Illegal Number",
		"January", "February", "March",
		"April", "May", "June", "July",
		"Auguest", "September", "October",
		"November", "December"
	};
	
	return (n < 1) || (n > 12) ? monthes[0] : monthes[n];
}
