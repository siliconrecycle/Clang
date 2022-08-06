#include <stdio.h>

void printptr(void *p) {
	printf("p = %p; *p = %016lx\n", p, *(long *)p);
}

int x;

int main(int argc, char *argv[]) {
	printptr(main);
	printptr(&main);
	printptr(&x);
	printptr(&argc);
	printptr(argv);
	printptr(&argv);
	printptr(argv[0]);
}
