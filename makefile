.PHONY: clean

main.exe : main-team-2.o functions-team-2.o
	cc -o main.exe main-team-2.o functions-team-2.o

functions-team-2.o : functions-team-2.c
	cc -c functions-team-2.c

main-team-2.o : main-team-2.c functions-team-2.c
	cc -c main-team-2.c

clean :
	rm -f *.o
