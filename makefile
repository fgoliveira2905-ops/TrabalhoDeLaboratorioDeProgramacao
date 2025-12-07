.PHONY: clean

main.exe: main-team-2.o functions-team-2.o
	cc -o $@ $^

%.o: %.c
	cc -c $<

clean:
	rm -f *.o
