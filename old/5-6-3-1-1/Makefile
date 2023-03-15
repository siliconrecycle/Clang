expr : main.o
	cc -g -Werror main.o -lm

main.o : main.c expr.h
	cc -c main.c

clean:
	rm main.o
