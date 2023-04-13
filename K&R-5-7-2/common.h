#include "qsort.c"
#include "getline01.c"
#include "alloc.c"
#include "readlines.c"

//void qsort(void *v[], int left, int right, int cmp(void *, void *))
int readlines(char *lineptr[], int maxline);
void writelines(char *lineptr[], int num);

int getline01(char *line, int max);
void copyto(char *lineptr[], char *str, int p);


char *alloc(int n);
void afree(char *p);
