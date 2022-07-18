#include <stdio.h>
#include <stdlib.h>
#include <errno.h>

int main(int argc, const char **argv)
{
	printf("%s\n", "hello");
	FILE *fp;
	int ch;

	fp = fopen("Yuan", "w+");
	if (fp == NULL) {
		perror("Open file yuan");
		exit(1);
	}

	while ((ch = getchar()) != EOF) {
		fputc(ch, fp);
	}

	long n = ftell(fp);
	printf("%d\n", n);

	if (fseek(fp, 1, SEEK_SET) != 0) {
		perror("Seek file Yuan");
		exit(1);
	}
	fputc('K', fp);


	rewind(fp);
	while ((ch = fgetc(fp)) != EOF) {
		putchar(ch);
	}

	fclose(fp);
	return 0;
}
