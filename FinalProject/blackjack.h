//include Statements
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

//Defines

#define MAXSTRINGSIZE 100

//Beggining of the functions used to maintain the deck of cards
typedef char* cardName;

typedef struct card{
	char theName[MAXSTRINGSIZE];
	int upDown;
	int pointValue;
	struct card* next;
} card, *cardPtr;

typedef struct deck{
	cardPtr top;
} deck, *deckPtr;

deckPtr initDeck();

void addCardDeck(deckPtr theDeck, cardName theCardName, int upDown);

void removeCardDeck(deckPtr theDeck);

cardPtr checkCardDeck(deckPtr theDeck);

int isDeckEmpty(deckPtr theDeck);

void emptyDeck(deckPtr theDeck);

deckPtr destroyDeck(deckPtr theDeck);

//Beggining of the Code to maintain the Hand of the players
typedef struct hand{
	cardPtr head;
}hand, *handPtr;

handPtr initHand();

cardPtr getCard(handPtr hand, int number);

void addHandCard(handPtr hand, cardName theCardName, int upDown);

void removeHandCard(handPtr hand, int number);

void displayHand(handPtr hand);

void emptyHand(handPtr hand);

int isHandEmpty(handPtr hand);

handPtr destroyHand(handPtr hand);

//Beggining of the functions used to maintain the players
typedef struct player{
	int folded;
	int type;
	handPtr playersHand;
	struct player *next;
}player, *playerPtr;

typedef struct playerList{
	playerPtr head;
	playerPtr tail;
}playerList, *playerListPtr;

playerListPtr initPlayerList();

playerPtr checkPlayer(playerListPtr list, int position);

void displayPlayer(playerListPtr list, int number);

void addPlayer(playerListPtr list, int type);

void removePlayer(playerListPtr list, int position);

int isPlayerListEmpty(playerListPtr list);

void emptyPlayerList(playerListPtr list);

playerListPtr destroyPlayerList(playerListPtr list);