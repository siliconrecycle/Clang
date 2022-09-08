#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void) {
	int v[] = {1, 2, 3, 4, 5, 6};

	int r = binsearch(2, v, 6);
	printf("%d\n", r);
}

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;
	/* while (low <= high) { */
	/* 	mid = (low + high) / 2; */
	/* 	if (x < v[mid]) { */
	/* 		high = mid - 1; */
	/* 	} else if (x > v[mid]) { */
	/* 		low = mid + 1; */
	/* 	} else  */
	/* 		return mid; */
	/* } */

	while (low <= high) {
		mid = (low + high) / 2;
		if (x <= v[mid]) {
			high = mid - 1;
			
		} else  {
			low = mid + 1;
		} 
	}

	return -1;
}
