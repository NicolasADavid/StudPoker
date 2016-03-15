/**
 * File:    deck.c
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
 * Creates a deck of cards
 * @param deck pointer to an array of cards
 */
void createDeck(struct card * deck) {

    int position = 0;

    int i;
    int j;

    for (i = 1; i <= SUITS; i++) { //A loop for each suit

        for (j = 1; j <= FACES; j++) { //A loop for each face value

            struct card aCard = makeCard(i, j); //Make card with suit and value

            deck[position] = aCard; //Put the card in the deck at position

            position++;

        }
    }

}

/**
 * Takes a deck (array of hand structures), a number of players, and a 
 * number of cards per player.
 * 
 * Creates an array of hand structures of size 13.
 * Copies the cards from beginning to end to each hand from beginning to end.
 * Copies the cards sequentially from the deck sequentially to the players
 * until each player has the required number of cards.
 * 
 * @param players number of players to deal to
 * @param cardsPerHand number of cards to deal to each player's hand
 * @param deck array of cards to copy into players' hands
 * @return pointer to first hand in the array of hands
 */
struct hand * dealDeck(int players, int cards, struct card * deck) {

    static struct hand hands[MAXPLAYERS];

    int card;
    int player;
    int k = 0; //Card from deck

    for (card = 0; card < cards; card++) { //Loop for each card a player has

        for (player = 0; player < players; player++) { //Loop for each player

            //Copy from deck to hand            
            hands[player].cards[card] = deck[k];
            k++;

        }

    }

    return hands;

}

/**
 * Takes a card and creates a char array with the card's name
 * @param x card to be used
 * @return pointer to first char in the array
 */
char * getCardName(struct card x) {

    char s[10]; //Will hold suit name
    char v[6]; //Will hold number value or face card name

    //Determine value
    switch (x.value) {
        case 1:
            strcpy(v, "Ace");
            break;
        case 11:
            strcpy(v, "Jack");
            break;
        case 12:
            strcpy(v, "Queen");
            break;
        case 13:
            strcpy(v, "King");
            break;
        default: //Catch cases where card is not a face card
            sprintf(v, "%i", x.value);
            break;
    }

    //Determine suit
    switch (x.suit) {
        case 1:
            strcpy(s, "Clubs");
            break;
        case 2:
            strcpy(s, "Spades");
            break;
        case 3:
            strcpy(s, "Hearts");
            break;
        case 4:
            strcpy(s, "Diamonds");
            break;
        default:
            break;
    }

    static char string[20]; //Array for holding complete name

    sprintf(string, "%s of %s ", v, s);

    return string;
}

/**
 * Function that returns a card structure with the input suit and value.
 * @param suit suit of the card to be returned.
 * 1 Clubs, 2 Spades, 3 Hearts, 4 Diamonds
 * @param value value of the card to be returned.
 * 1 Ace, 11 Jack, 12 Queen, 13 King
 * @return card with given suit and value.
 */
struct card makeCard(int suit, int value) {

    struct card aCard;

    aCard.suit = suit;
    aCard.value = value;

    return aCard;
}

/**
 * Prints the name of the card input.
 * @param aCard card to print name of.
 */
void printCard(struct card aCard) {

    char *c = getCardName(aCard); //Get a char array with the name

    printf("%s",c);

}

/**
 * Prints the deck that the argument points to. Doesn't use columns.
 * @param deck pointer to first card in the array.
 */
void printDeck(struct card * deck) {

    int i;

    for (i = 0; i < NUMCARDS; i++) {

        printCard(*(deck + i));
        printf("\n");

    }

}

/**
 * Prints the deck that the argument points to. Easier to see whole deck.
 * Expects 52 cards!!
 * @param deck pointer to first card.
 */
void printDeckColumned(struct card * deck) {
    int i;
    int col1 = 0;
    int col2 = 13;
    int col3 = 26;
    int col4 = 39;

    for (i = 0; i < 13; i++) {
        //printCard(*(deck + col1++)); //Doesn't fit in one line
        printf("%i,%i", deck[col1].suit, deck[col1].value);
        col1++;
        printf("\t");

        //printCard(*(deck + col2++));
        printf("%i,%i", deck[col2].suit, deck[col2].value);
        col2++;
        printf("\t");

        //printCard(*(deck + col3++));
        printf("%i,%i", deck[col3].suit, deck[col3].value);
        col3++;
        printf("\t");

        //printCard(*(deck + col4++));
        printf("%i,%i", deck[col4].suit, deck[col4].value);
        col4++;
        printf("\n");
    }

}

/**
 * Prints players' hands.
 * @param players number of hands to print
 * @param cardsPerHand number of cards per hand
 * @param hands pointer to first hand in the array of hands
 */
void printHands(int players, int cards, struct hand * hands) {

    int player;
    int card;

    for (player = 0; player < players; player++) { //For each player

        printf("Player %i: \n", player + 1);

        for (card = 0; card < cards; card++) { //for each card in hand

            //Print
            printf("\tCard%i Suit: %i Value: %i\n"
                    , card + 1, hands[player].cards[card].suit
                    , hands[player].cards[card].value);

        }

        printf("\n");
    }

}

/**
 * Prints players' hands using players' hands' cards' formal names.
 * @param players number of hands to print
 * @param cardsPerHand number of cards per hand
 * @param hands pointer to first hand in the array of hands
 */
void printHandsNamed(int players, int cards, struct hand * hands) {

    int player;
    int card;

    for (player = 0; player < players; player++) { //For each player

        printf("Player %i: \n", player + 1);

        for (card = 0; card < cards; card++) { //For each card in hand

            //Print
            printf("\t");
            printCard(hands[player].cards[card]);
            printf("\n");

        }

        printf("\n");

    }

}

/**
 * Takes a hand and sorts it by increasing card value.
 * @param numCards number of cards in each hand
 * @param cards the cards array
 */
void sortHand(int numCards, struct card * cards) {
    int i, j;

    for (j = 0; j < numCards - 1; j++) {

        /* assume first is smallest */
        int min = j;
        
        /* test against next elements */
        for (i = j + 1; i < numCards; i++) {
            
            /* if element is smaller, set to small */
            if (cards[i].value < cards[min].value) {
                min = i;
            }
        }

        if (min != j) {
            swapCard(&cards[j], &cards[min]);
        }
    }


}

/**
 * Takes an array of hands and sorts all of them
 * @param players
 * @param numCards
 * @param hands
 */
void sortHands(int players, int numCards, struct hand * hands) {

    int i;
    
    for (i = 0; i < players; i++) {
        sortHand(numCards, &hands[i].cards);
    }

}

/**
 * Shuffles a deck.
 * @param deck pointer to first card in a deck
 */
void shuffleDeck(struct card * deck) {

    srand(time(NULL)); //Generate seed

    //Fisher-Yates shuffling algorithm
    int i;
    for (i = NUMCARDS - 1; i > 0; i--) {

        //Pick random index from 0 to i
        int j = rand() % (i + 1);

        //Swap deck[i] with the element at random index
        swapCard(&deck[i], &deck[j]);
    }

}

/**
 * Swaps card a with card b
 * @param a card to be swapped with b
 * @param b card to be swapped with a
 */
void swapCard(struct card * a, struct card * b) {
    struct card temp = *a;
    *a = *b;
    *b = temp;
}