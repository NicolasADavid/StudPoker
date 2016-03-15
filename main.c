/**
 * File:    main.c
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

/***************************************************/
/* Includes */

/* to provide access to structures , constants, and prototypes */
#include "header.h"


/**
 * 
 * @param argc
 * @param argv
 * @return 
 */
int main(int argc, char** argv) {
    
    //Command line input
    int players;
    int cards;
    
    cards = atoi(argv[1]);
    players = atoi(argv[2]);
    
    cards = 5; //Force cards to 5
//    players = 5;

    //Validate
    if (players < MINPLAYERS || players > MAXPLAYERS) {
        printf("Players too high or too low!!!\n");
        return 0;
    }
    if (cards < MINCARDS || cards > MAXCARDS) {
        printf("Cards too high or too low!!!\n");
        return 0;
    }
        
    //Create
    struct card deck[NUMCARDS]; //Create the deck
    createDeck(deck); //Fill the deck
    
    //Display
    printf("Unshuffled deck(suit, val):\n");
    //printDeck(deck);
    printDeckColumned(deck);
    printf("\n");
    
    //Shuffle
    shuffleDeck(deck);
    
    //Display
    printf("Shuffled deck(suit, val):\n");
    //printDeck(deck);
    printDeckColumned(deck);
    printf("\n");
    
    //Deal
    printf("Dealing.\n\n");
    struct hand * hands = dealDeck(players, cards, deck);
    
    //Show Hands
    printf("Player's hands(unsorted):\n");
    printHandsNamed(players, cards, hands);
    printf("\n");
    
    //Sort Hands
    sortHands(players, cards, hands);
    
    //Show Hands
    printf("Player's hands(sorted):\n");
    printHandsNamed(players, cards, hands);
    printf("\n");
    
//    //Fixed cards for testing (suit, value)
//    struct card card1 = makeCard(4,3);
//    struct card card2 = makeCard(4,4);
//    struct card card3 = makeCard(4,5);
//    struct card card4 = makeCard(4,6);
//    struct card card5 = makeCard(4,7);
//    
//    //Fixed hand for testing
//    struct hand fixedHand;
//    fixedHand.cards[0] = card1;
//    fixedHand.cards[1] = card2;
//    fixedHand.cards[2] = card3;
//    fixedHand.cards[3] = card4;
//    fixedHand.cards[4] = card5;
//    
//    printHandsNamed(1,5,&fixedHand);
//    rankHand(&fixedHand);
//    printHandsNamed(1,5,&fixedHand);
//    printf("%i",fixedHand.rank);
    
    //Rank hands
    rankHands(players, hands);
    
    //Show hands with ranks
    printf("Players hands' ranks:\n");
    printHandsRanked(players, hands);
    
    //Determine winner
    determineWinner(players, hands);
    
    return (0);
}
