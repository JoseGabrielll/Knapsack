main:	main.o
	gcc main.o -o main

main.o:	main.c
	gcc -c main.cpp

clean:
	rm *.o
