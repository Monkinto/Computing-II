#include "blackjack.h"

deckPtr initDeck(){
	deckPtr theDeck = malloc(sizeof(deck));
	theDeck->top = NULL;
	return theDeck;
}

void addCardDeck(deckPtr theDeck, char theCardName[], int upDown){
	cardPtr newCard = malloc(sizeof(card));
	strcpy(newCard->theName, theCardName);
	newCard->upDown = upDown;
	newCard->next = theDeck->top;
	theDeck->top = newCard;
}

void removeCardDeck(deckPtr theDeck){
	cardPtr toRemove = theDeck->top;
	theDeck->top = theDeck->top->next;
	free(toRemove);
}

void popCardDeck(deckPtr theDeck){
	cardPtr toRemove = theDeck->top;
	theDeck->top = theDeck->top->next;
}

cardPtr checkCardDeck(deckPtr theDeck){
	return theDeck->top;
}

int isDeckEmpty(deckPtr theDeck){
	if(theDeck->top == NULL){
		return 0;
	} else {
		return 1;
	}
}

void emptyDeck(deckPtr theDeck){
	while(isDeckEmpty(theDeck) == 1){
		removeCardDeck(theDeck);
	}
}

deckPtr destroyDeck(deckPtr theDeck){
	emptyDeck(theDeck);
	free(theDeck);
	return NULL;
}