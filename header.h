/**
 * File:    header.h
 * Author:  Nicolas David
 * PID:     3587814
 * 
 * Assignment 4
 * 
 * Program to play stud poker.
 * 
 * "I hereby certify that this collective work is my own and none of it is 
 * the work of any other person or entity. “
 * 
 * ND
 */

#ifndef HEADER_H
#define	HEADER_H

/***************************************************/
/* Includes */
#include <stdio.h> //For scanf and prints
#include <stdlib.h> //For srand
#include "string.h" //For strcopy
#include "time.h" //For use with srand in shuffleDeck

/***************************************************/
/* Constants */
#define SUITS 4
#define FACES 13
#define NUMCARDS SUITS*FACES
#define MINCARDS 5
#define MAXCARDS 5
#define MINPLAYERS 2
#define MAXPLAYERS 7

//static const int SUITS = 4;
//static const int FACES = 13;
//static const int NUMCARDS = 4 * 13;
//
//static const int MINCARDS = 5;
//static const int MAXCARDS = 5;
//
//static const int MINPLAYERS = 2;
//static const int MAXPLAYERS = 7;

/***************************************************/
/* Structures */

/**
* Card structure. Has a suit and a value (integers).
* Suits: Clubs 1, Spades 2, Hearts 3, Diamonds 4
* Values: Ace 1, Jack 11, Queen 12, King 13
*/
struct card {
    int suit;
    int value;
};

/**
 * Hand structure.
 * Has an array of card structures of size MAXCARDS.
 * Has an int for use in ranking.
 */
struct hand{
    int rank;
    struct card cards[MAXCARDS];
};


/***************************************************/
/* function prototypes */
//card.c
char * getCardName(struct card x);
struct card makeCard();
void printCard(struct card aCard);

//deck.c
void createDeck(struct card * deck);
struct hand * dealDeck(int players, int cards, struct card * deck);
void printDeck(struct card * deck);
void printDeckColumned(struct card * deck);
void printHands(int players, int cards, struct hand * hands);
void printHandsNamed(int players, int cards, struct hand * hands);
void sortHand(int numCards, struct card * cards);
void sortHands(int players, int cards, struct hand * hands);
void shuffleDeck(struct card * deck);
void swapCard(struct card * a, struct card * b);

//studPoker.c
void determineWinner(int players, struct hand * hands);
void determineWinnerExtra(int players, struct hand * hands);
void printHandsRanked(int players, struct hand * hands);
void rankHands(int players, struct hand * hands);


#ifdef	__cplusplus
extern "C" {
#endif
    
    


    
    
#ifdef	__cplusplus
}
#endif

#endif	/* HEADER_H */

