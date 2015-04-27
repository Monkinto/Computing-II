#include "blackjack.h"

handPtr initHand(){
	handPtr theHand = malloc(sizeof(hand));
	theHand->head = NULL;
	return theHand;
}

cardPtr getCard(handPtr hand, int number){
	int i;
	cardPtr current = hand->head;
	for(i = 0; i < number; i++){
		current = current->next;
	}
	return current;
}

void addHandCard(handPtr hand, cardName theCardName, int upDown){
	cardPtr newCard = malloc(sizeof(card));
	cardPtr current = hand->head;
	strcpy(newCard->theName, theCardName);
	newCard->upDown = upDown;
	newCard->next = NULL;
	while(current->next != NULL){
		current = current->next;
	}
	current->next = newCard;
}

void removeHandCard(handPtr hand, int number){
	int i;
	cardPtr current = hand->head;
	cardPtr previous;
	if(number == 0){
		hand->head = hand->head->next;
		free(current);
	} else {
		for(i = 0; i < number && current->next != NULL; i++){
			previous = current;
			current = current->next;
		}
		previous->next = NULL;
		free(current);
	}
	
}

void displayHand(handPtr hand){
	cardPtr current = hand->head;
	while(current != NULL){
		if(current->upDown == 0){
			printf("%s\t", current->theName);
		} else {
			printf("Face Down Card\t");
		}
	}
	printf("\n");
}

void emptyHand(handPtr hand){
	while(isHandEmpty(hand) == 1){
		removeHandCard(hand, 0);
	}
}

int isHandEmpty(handPtr hand){
	if(hand->head == NULL){
		return 0;
	} else {
		return 1;
	}
}

handPtr destroyHand(handPtr hand){
	emptyHand(hand);
	free(hand);
	return NULL;
}

void moveCardDeck(handPtr hand, deckPtr deck){
	
}