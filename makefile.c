# TrabalhoDeLaboratorioDeProgramacao
CC=gcc
CFLAGS=-Wall -g

all:main

main: main.o
    $(CC)$FLAGS -c main.cc

clean:
    rm -f*.o main
