main.exe : main.o functions-1.o
	cc -o main.exe main.o functions-1.o

functions-1.o : functions-1.c
	cc -c functions-1.c

main.o : main.c functions-1.c
	cc -c main.c

clean :
	rm *.o
