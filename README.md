# StudPoker
A program that creates a deck, shuffles it, deals it to an amount of players specified by command line input, and determines winner(s) like in StudPoker written for Programming 3 (C)

Nicolas David 3587814 Assignment 4

Instructions to compile/execute with CMD

1.	Place main.c, deck.c, studPoker.c, and header.h in a directory that you can access via cmd
2.	In cmd, navigate to that directory
3.	Enter command: gcc main.c deck.c studPoker.c -o main.out
⁃	Program will compile
⁃	main.out will appear in directory
4.	Enter command: main.out 5 6
⁃	You may enter another number as the second argument to play with less/more players. Program allows 2-7 players and forces first argument to 5 (cards per player)
⁃	program will run and finish when winning hands have been determined
