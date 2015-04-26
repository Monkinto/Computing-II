//Beggining of the functions called to run the game


//Beggining of the functions used to maintain the deck of cards
typedef char* cardName;

typedef struct card{
	cardName theName;
	int upDown;
	struct card* next;
} card, *cardPtr;

typedef struct deck{
	cardPtr top;
} deck, *deckPtr;

deckPtr initDeck();

void addCardDeck(deckPtr theDeck, cardName theCardName);

void removeCardDeck(deckPtr theDeck);

cardName checkCardDeck(deckPtr theDeck);

int isDeckEmpty(deckPtr theDeck);

void emptyDeck(deckPtr theDeck);

void destroyDeck(deckPtr theDeck);

//Beggining of the Code to maintain the Hand of the players
typedef struct hand{
	cardPtr head;
}hand, *handPtr;

handPtr initHand();

cardPtr getCard(handPtr hand, int number);

void addHandCard(handPtr hand);

void removeHandCard(handPtr hand, int number);

void displayHand(handPtr hand);

void emptyHand(handPtr hand);

int isHandEmpty(handPtr hand);

handPtr destroyHand(handPtr hand);

//Beggining of the functions used to maintain the players
typedef struct player{
	int number;
	int handSize;
	int folded;
	handPtr playersHand;
	struct player *next;
}player, *playerPtr;

typedef struct playerList{
	playerPtr head;
}playerList, *playerListPtr;

playerListPtr initPlayerList();

playerPtr checkPlayer(playerListPtr list, int position);

void displayPlayer(playerListPtr list, int number);

void addPlayer(playerListPtr list);

void removePlayer(playerListPtr list, int position);

void emptyPlayerList(playerListPtr list);

int isPlayerListEmpty(playerListPtr list);

playerListPtr destroyPlayerList(playerListPtr list);