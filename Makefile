.PHONY: all clean maxclean

CC=gcc
DIRSRC = ./src
DIROBJ = ./obj
CFLAGS= -g -Wall -std=c99
LDFLAGS=-lm

all : EXEC

Coordinates.o :
	$(CC) -c $(DIRSRC)/Coordinates.c -o $(DIROBJ)/Coordinates.o
Box.o :
	$(CC) -c $(DIRSRC)/Box.c -o $(DIROBJ)/Box.o
Object.o :
	$(CC) -c $(DIRSRC)/Object.c -o $(DIROBJ)/Object.o
Trap.o :
	$(CC) -c $(DIRSRC)/Trap.c -o $(DIROBJ)/Trap.o
Character.o :
	$(CC) -c $(DIRSRC)/Character.c -o $(DIROBJ)/Character.o
WorldGame.o :
	$(CC) -c $(DIRSRC)/WorldGame.c -o $(DIROBJ)/WorldGame.o
main.o :
	$(CC) -c $(DIRSRC)/main.c -o $(DIROBJ)/main.o
EXEC : Coordinates.o Box.o Object.o Trap.o Character.o WorldGame.o main.o
	$(CC) $(CFLAGS) -o ./bin/Labyrinth $(DIROBJ)/*.o  $(LDFLAGS) 	#-lSDL -lSDL_image

clean: ;
	rm $(DIROBJ)/*.o

maxclean:
	rm $(DIROBJ)/*.o ./bin/Labyrinth
