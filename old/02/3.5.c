#include <stdio.h>
#include <string.h>

void shellsort(int v[], int n, int m);
void printfV(int v[], int n);
void printfS(char v[]);
void expand(char s1[], char s2[]);

int main(void) {
	/* int v[] = {7, 5, 3, 2, 3, 8, 7, 1, 2, 9}; */
	/* printfV(v, 10); */
	/* shellsort(v, 10, 0); */
	/* printfV(v, 10); */
	/* shellsort(v, 10, 1); */
	/* printfV(v, 10); */

	char s1[] = "a-z";
	char a[] = "-a-z";
	char b[] = "a-z-";
	char c[] = "-a-z\n"
		"1-\t7"
		"\nB-G-";
	/* printf("%s\n", b); */
	/* char s2[100]; */
	/* expand(c, s2); */
	/* printf("%s\n", s2); */
	printfS(c);
}

void printfS(char v[])
{
	int n = strlen(v);
	for (int i = 0; i < n; ++i)
		printf("%c", v[i]);
	printf("\n");
}

void expand(char s1[], char s2[])
{
	int i, j;

	printf("%s\n", s1);
	for(i = 0, j = 0; s1[i] != '\0'; ++i, ++j) {
		/*while countes '-', i not equal 0 and the last is not terminate operater. */
		if (s1[i] == '-' && i != 0 && s1[i + 1] != '\0') {
			--j;
			++i;
			while (s2[j] != s1[i]) {
				++j;
				s2[j] = s2[j-1] + 1;
			}
		}
		s2[j] = s1[i];
	}
	s2[j] = '\0';
}

void printfV(int v[], int n)
{
	for (int i = 0; i < 10; ++i)
		printf("%d ", v[i]);
	printf("\n");
}

/*
  {7, 5, 3, 2, 3, 8, 7, 1, 2, 9}
   0  1  2  3  4  5  6  7  8  9

  {1, 2, 2, 3, 3, 5, 7, 7, 8, 9}
   0  1  2  3  4  5  6  7  8  9

  n = 10

  for(gap = n/2; gap > 0; gap /= 2)
      gap = 5
      for(i = 5; 5 < 10; i++)
      end for
  {7, 5, 1, 2, 3, 8, 7, 3, 2, 9}
   0  1  2  3  4  5  6  7  8  9
      gap = 2
      for(i = gap; i < n; i++) =>
      for(i = 2; i < 10; i++)
          for(j = 0; 0 >= 0 && v[0] > v[2]; j-=2) =>
	  for(j = 0; true && 7 > 1; j-=2)
	      v[0] = 1, v[2] = 7
  {1, 5, 7, 2, 3, 8, 7, 3, 2, 9}
   0  1  2  3  4  5  6  7  8  9
              (j = -2 >= 0 &&) => fasle
	  end for
	  i = 3 => (j = 1 >= 0 && v[1] > v[3]) =>
	  (true && 5 > 2)
	      v[1] = 2, v[3] = 5
  {1, 2, 7, 5, 3, 8, 7, 3, 2, 9}
   0  1  2  3  4  5  6  7  8  9
              (j = 1 - 2 = -1 >= 0 &&) => false
	  end for
	  i = 4 => (j = 2 >= 0 && v[2] > v[4]) =>
	  (true && 7 > 3)
	      v[2] = 3, v[4] = 7
  {1, 2, 3, 5, 7, 8, 7, 3, 2, 9}
   0  1  2  3  4  5  6  7  8  9
              (j = 2 - 2 = 0 >= 0 && v[0] > v[2]) => false
	  end for
          i = 5 => (j = 3 >= 0 && v[3] > v[5]) => false
	  i = 6 => (j = 4 >= 0 && v[4] > v[6]) => false
	  i = 7 => (j = 5 >= 0 && v[5] > v[7]) =>
	  (true && 8 > 3)
	      v[5] = 3, v[7] = 8
  {1, 2, 3, 5, 7, 3, 7, 8, 2, 9}
   0  1  2  3  4  5  6  7  8  9
              (j = 5 - 2 = 3 >= 0 && v[3] > v[5]) =>
	      (true && 5 > 3)
	           v[3] = 3, v[5] = 5
  {1, 2, 3, 3, 7, 5, 7, 8, 2, 9}
   0  1  2  3  4  5  6  7  8  9
              (j = 3 - 2 = 1 >= 0 && v[1] > v[3]) =>
	      (true && 2 > 3) => false
	  i = 8 => (j = 6 >= 0 && v[6] > v[8]) =>
	  (true && 7 > 2)
	      v[6] = 2, v[8] = 7
  {1, 2, 3, 3, 7, 5, 2, 8, 7, 9}
   0  1  2  3  4  5  6  7  8  9
              (j = 4 >= 0 && v[4] > v[6]) =>
	      (j = 4 >= 0 && 7 > 2)
	          v[4] = 2, v[6] = 7
  {1, 2, 3, 3, 2, 5, 7, 8, 7, 9}
   0  1  2  3  4  5  6  7  8  9
              (j = 2 >= 0 && v[2] > v[4]) =>
	      (true && 3 > 2)
	          v[2] = 2, v[4] = 3
  {1, 2, 3, 3, 2, 5, 7, 8, 7, 9}
   0  1  2  3  4  5  6  7  8  9
              (j = 0 >= 0 && v[0] > v[2]) =>
	      (true && 1 > 3) => false
	  i = 9 => (j = 7 >= 0 && v[7] > v[9]) =>
	  (true && 8 > 9) => false
       end for
  {1, 2, 3, 3, 2, 5, 7, 8, 7, 9}
   0  1  2  3  4  5  6  7  8  9
      gap = 1
      for(i = 1; 1 < 10; i++)
          i = 1 => (j = 0 >= 0 && v[0] > v[1]) => false
	  i = 2 => (j = 1 >= 0 && v[1] > v[2]) => fasle
	  i = 3 => (j = 2 >= 0 && v[2] > v[3]) => false
	  i = 4 => (j = 3 >= 0 && v[3] > v[4]) =>
	           (true && 3 > 2)
		       v[3] = 2, v[4] = 3
  {1, 2, 3, 2, 3, 5, 7, 8, 7, 9}
   0  1  2  3  4  5  6  7  8  9
                   (j = 2 >= 0 && v[2] > v[3]) =>
		   (true && 3 > 2)
		       v[2] = 2, v[3] = 3
  {1, 2, 2, 3, 3, 5, 7, 8, 7, 9}
   0  1  2  3  4  5  6  7  8  9
                   (j = 0 >= 0 && v[0] > v[1]) =>
		   (true && 1 > 2) => false
	  i = 5 => (j = 4 >= 0 && v[4] > v[5]) =>
	           (true && 3 > 5) => false
	  i = 6 => (j = 5 >= 0 && v[5] > v[6]) => false
	  i = 7 => (j = 6 >= 0 && v[6] > v[7]) => false
	  i = 8 => (j = 7 >= 0 && v[7] > v[8]) =>
	           (true && 8 > 7)
		       v[7] = 7, v[8] = 8
  {1, 2, 2, 3, 3, 5, 7, 7, 8, 9}
   0  1  2  3  4  5  6  7  8  9
                   (j = 6 >= 0 && v[6] > v[7]) => false
	  i = 9 => (j = 8 >= 0 && v[8] > v[9]) => false
      end for
  {1, 2, 2, 3, 3, 5, 7, 7, 8, 9}
   0  1  2  3  4  5  6  7  8  9
      (gap = 0 > 0) => flase
  end for
   */

void shellsort(int v[], int n, int m)
{
        int gap, i, j;
	for (gap = n / 2; gap > 0; gap = gap / 2) {
		for (i = gap; i < n; ++i) {
		  for (j = i - gap; j >= 0 && ((m == 0) ? v[j] > v[j + gap] : v[j] < v[j + gap]) ; j -= gap) {
				int temp = v[j];
				v[j] = v[j + gap];
				v[j + gap] = temp;
			}
		}
	}
}
