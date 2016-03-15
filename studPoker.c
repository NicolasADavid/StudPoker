/**
 * File:    studPoker.c
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
 * Determines which hands in an array of hands have the highest rank.
 * Prints player number or winners.
 * @param players
 * @param hands
 */
void determineWinner(int players, struct hand * hands) {
    int player;
    int highRank = 0;
    for (player = 0; player < players; player++) {
        if (hands[player].rank > highRank) {
            highRank = hands[player].rank;
        }
    }

    printf("Winners: ");
    for (player = 0; player < players; player++) {
        if (hands[player].rank == highRank) {
            printf("%i", player + 1);
            printf(",");
        }
    }
    printf("\n");

}

/**
 * Not done yet.
 * @param players
 * @param hands
 */
void determineWinnerExtra(int players, struct hand * hands){
    
}

/**
 * Prints hands with their rank and hand name included.
 * @param players
 * @param hands
 */
void printHandsRanked(int players, struct hand * hands) {

    int player;
    int card;

    for (player = 0; player < players; player++) { //For each player

        char s[20]; //Get name of hand from rank
        switch (hands[player].rank) {
            case 0:
                strcpy(s, "High card");
                break;
            case 1:
                strcpy(s, "One Pair");
                break;
            case 2:
                strcpy(s, "Two Pair");
                break;
            case 3:
                strcpy(s, "Three of a Kind");
                break;
            case 4:
                strcpy(s, "Straight");
                break;
            case 5:
                strcpy(s, "Flush");
                break;
            case 6:
                strcpy(s, "Full House");
                break;
            case 7:
                strcpy(s, "Four of a Kind");
                break;
            case 8:
                strcpy(s, "Straight Flush");
                break;
            default:
                break;
        }

        printf("Player %i: Rank: %i, %s\n", player + 1, hands[player].rank, s);

        for (card = 0; card < 5; card++) { //For each card in hand

            //Print
            printf("\t");
            printCard(hands[player].cards[card]);
            printf("\n");

        }

        printf("\n");

    }

}

/**
 * Pair.
 * @param theHand
 */
void rank1(struct hand * theHand) {
    int i;
    int j;
    int pass = 0;

    for (i = 0; i < 5; i++) {
        for (j = i + 1; j < 5; j++) {
            if (theHand->cards[i].value == theHand->cards[j].value) {
                pass = 1;
            }
        }

    }

    if (pass == 1) {
        theHand->rank = 1;
    }

}

/**
 * Two Pair.
 * @param theHand
 */
void rank2(struct hand * theHand) {
    /* Check for aa bb x */
    if (
            theHand->cards[0].value == theHand->cards[1].value &&
            theHand->cards[2].value == theHand->cards[3].value) {
        theHand->rank = 2;
    }

    /* Check for aa x bb */
    if (
            theHand->cards[0].value == theHand->cards[1].value &&
            theHand->cards[3].value == theHand->cards[4].value) {
        theHand->rank = 2;
    }

    /* Check for x aa bb */
    if (
            theHand->cards[1].value == theHand->cards[2].value &&
            theHand->cards[3].value == theHand->cards[4].value) {
        theHand->rank = 2;
    }

}

/**
 * Three of a kind.
 * @param theHand
 */
void rank3(struct hand * theHand) {

    /* Check for x x x a b */
    if (
            theHand->cards[0].value == theHand->cards[1].value &&
            theHand->cards[1].value == theHand->cards[2].value) {
        theHand->rank = 3;
    }

    /* Check for a x x x b */
    if (
            theHand->cards[1].value == theHand->cards[2].value &&
            theHand->cards[2].value == theHand->cards[3].value) {
        theHand->rank = 3;
    }

    /* Check for a b x x x */
    if (
            theHand->cards[2].value == theHand->cards[3].value &&
            theHand->cards[3].value == theHand->cards[4].value) {
        theHand->rank = 3;
    }

}

/**
 * Straight.
 * @param theHand
 */
void rank4(struct hand * theHand) {
    //If there is an Ace, check for straights with it
    if (theHand->cards[0].value == 1) {
        //Low straight
        if (
                theHand->cards[1].value == 2 &&
                theHand->cards[2].value == 3 &&
                theHand->cards[3].value == 4 &&
                theHand->cards[4].value == 5
                ) {
            theHand->rank = 4;
        }
        //High straight
        if (
                theHand->cards[1].value == 10 &&
                theHand->cards[2].value == 11 &&
                theHand->cards[3].value == 12 &&
                theHand->cards[4].value == 13
                ) {
            theHand->rank = 4;
        }

    } else {
        //General straights

        int expected = theHand->cards[0].value + 1;
        int fail = 0;
        int i;

        for (i = 1; i < 5; i++) {
            if (theHand->cards[i].value != expected) {
                fail = 1;
            }
            expected++;
        }

        if (fail == 0) {
            theHand->rank = 4;
        }

    }

}

/**
 * Flush.
 * @param theHand
 */
void rank5(struct hand * theHand) {

    int suit = theHand->cards[0].suit;
    int count = 0;
    int i;

    for (i = 0; i < 5; i++) {
        if (theHand->cards[i].suit == suit) {
            count++;
        }
    }

    if (count == 5) {
        theHand->rank = 5;
    }

}

/**
 * Full House.
 * @param theHand
 */
void rank6(struct hand * theHand) {

    /* Check for x x x y y */
    if (
            theHand->cards[0].value == theHand->cards[1].value &&
            theHand->cards[1].value == theHand->cards[2].value &&
            theHand->cards[3].value == theHand->cards[4].value) {
        theHand->rank = 6;
    }

    /* Check for x x y y y */
    if (
            theHand->cards[0].value == theHand->cards[1].value &&
            theHand->cards[2].value == theHand->cards[3].value &&
            theHand->cards[3].value == theHand->cards[4].value) {
        theHand->rank = 6;
    }
}

/**
 * Four of a kind.
 * @param theHand
 */
void rank7(struct hand * theHand) {

    /* Check for x x x x y */
    if (
            theHand->cards[0].value == theHand->cards[1].value &&
            theHand->cards[1].value == theHand->cards[2].value &&
            theHand->cards[2].value == theHand->cards[3].value) {
        theHand->rank = 7;
    }

    /* Check for x y y y y */
    if (
            theHand->cards[1].value == theHand->cards[2].value &&
            theHand->cards[2].value == theHand->cards[3].value &&
            theHand->cards[3].value == theHand->cards[4].value) {
        theHand->rank = 7;
    }
}

/**
 * Straight Flush.
 * @param theHand
 */
void rank8(struct hand * theHand) {

    //Check if the hand is a flush
    int suit = theHand->cards[0].suit;
    int count = 0;
    int i;

    for (i = 0; i < 5; i++) {
        if (theHand->cards[i].suit == suit) {
            count++;
        }
    }

    if (count == 5) {
        //The hand is a flush. Check if it is also a straight
        //If there is an Ace, check for straight with it
        if (theHand->cards[0].value == 1) {
            //Low straight
            if (
                    theHand->cards[1].value == 2 &&
                    theHand->cards[2].value == 3 &&
                    theHand->cards[3].value == 4 &&
                    theHand->cards[4].value == 5
                    ) {
                theHand->rank = 8;
            }
            //High straight
            if (
                    theHand->cards[1].value == 10 &&
                    theHand->cards[2].value == 11 &&
                    theHand->cards[3].value == 12 &&
                    theHand->cards[4].value == 13
                    ) {
                theHand->rank = 8;
            }

        } else {
            //General straight

            int expected = theHand->cards[0].value + 1;
            int fail = 0;
            int i;

            for (i = 1; i < 5; i++) {
                if (theHand->cards[i].value != expected) {
                    fail = 1;
                }
                expected++;
            }

            if (fail == 0) {
                theHand->rank = 8;
            }

        }


    }

}

/**
 * Possible ranks: high card (0) .... straight flush (8)
 * Runs the hand through functions that qualify the hand as a certain
 * hand type, starting from lowest rank to highest rank.
 * 
 * @param theHand
 */
void rankHand(struct hand * theHand) {

    //High card(0)
    //Automatic

    //One pair(1)
    rank1(theHand);

    //Two pair(2)
    rank2(theHand);

    //Three of a kind(3)
    rank3(theHand);

    //Straight(4)
    rank4(theHand);

    //Flush(5)
    rank5(theHand);

    //Full House(6)
    rank6(theHand);

    //Four of a kind(7)
    rank7(theHand);

    //Straight Flush(8)
    rank8(theHand);

}

/**
 * Ranks multiple hands
 * @param players number of hands to rank in the hand array
 * @param hands pointer to an array of hands to rank
 */
void rankHands(int players, struct hand * hands) {

    int i;

    for (i = 0; i < players; i++) {

        rankHand(&hands[i]);

    }
}