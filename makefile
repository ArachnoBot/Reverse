flags = -Wall -Werror

reverse : main.o functions.o
	gcc $(flags) -o reverse main.o functions.o

main.o : main.c functions.h
	gcc -c main.c

functions.o : functions.c functions.h
	gcc -c functions.c

clean :
	rm reverse main.o functions.o
