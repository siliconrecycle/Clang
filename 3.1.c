#include <stdio.h>

int binsearch(int x, int v[], int n);

int main(void) {
	int v[] = {1, 3, 9, 12, 35, 60};

	for (int i = 0; i < 61; ++i) {
		int r = binsearch(i, v, 6);
		printf("i: %d, r: %d\n", i, r);
	}
}

/*
  {1, 3, 9, 12, 35, 60}
   0  1  2  3   4   5
   (9, 6)

   low = 0, high = 5
   (0 < 5)
   mid = (low + high) / 2 = 2
   (9 = 9) =>
   high = 2 - 1 = 1

   low = 0, high = 1
   (low < high)
   mid = 0
   (9 > 1) =>
   low = 0 + 1 = 1

   low = 1, high = 1
   (low <= high)
   mid = 1
   (9 > 3) =>
   low = 1 + 1 = 2
   
   low = 2, high = 1
   (low > high)

   low = 2
 */

int binsearch(int x, int v[], int n)
{
	int low, high, mid;

	low = 0;
	high = n - 1;

	while (low <= high) {
		mid = (low + high) / 2;
		if (x <= v[mid]) {
			high = mid - 1;
		} else {
			low = mid + 1;
		}
	}
	
	if (v[low] != x)
		return -1;
	return low;
}


/* /\* */
/*   {1, 3, 9, 12, 35, 60} */
/*    0  1  2  3   4   5 */
/*    (9, 6) */

/*    low = 0, high = 5 */
/*    (low <= high) */
/*    mid = 2 */
/*    (9 = 9) => */
/*    low = 3 */
   
/*    low = 3, high = 5 */
/*    (low <= high) */
/*    mid = 4 */
/*    (9 < 35) => */
/*    high = 3 */

/*    low = 3, high = 3 */
/*    (low <= high) */
/*    mid = 3 */
/*    (9 < 12) */
/*    high = 2 */

/*    low = 3, high = 2 */
/*    (low <= high) false */
/*  *\/ */

/* int binsearch(int x, int v[], int n) */
/* { */
/* 	int low, high, mid; */

/* 	low = 0; */
/* 	high = n - 1; */

/* 	while (low <= high) { */
/* 		mid = (low + high) / 2; */
/* 		if (x >= v[mid]) { */
/* 			left = mid + 1; */
/* 		} else { */
/* 			high = mid - 1; */
/* 		} */
/* 	} */
	
/* 	if (v[low] != x) */
/* 		return -1; */
/* 	return low; */
/* } */

