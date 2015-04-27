#include "blackjack.h"

playerListPtr initPlayerList(){
	playerListPtr theList = malloc(sizeof(playerList));
	theList->head = NULL;
	theList->tail = NULL;
	return theList;
}

playerPtr checkPlayer(playerListPtr list, int position){
	int i;
	playerPtr current = list->head;
	if(isPlayerListEmpty(list) == 1){
		for(i = 0; i < position && current->next != NULL; i++){
			current = current->next;
		}
		return current;
	} else {
		return NULL;
	}
}

void displayPlayer(playerListPtr list, int number){
	playerPtr current = checkPlayer(list, number);
	printf("This player's information:\n");
	if(current->folded == 0){
		printf("This player has not folded.\n");
	} else {
		printf("This player has folded.\n");
	}
	displayHand(current->playersHand);
}

void addPlayer(playerListPtr list, int type){
	playerPtr newPlayer = malloc(sizeof(player));
	newPlayer->folded = 0;
	newPlayer->type = type;
	newPlayer->playersHand = initHand();
	newPlayer->next = NULL;
	if(list->head == NULL && list->tail == NULL){
		list->head = newPlayer;
		list->tail = newPlayer;
	} else {
		list->tail->next = newPlayer;
		list->tail = newPlayer;
	}
}

void removePlayer(playerListPtr list, int position){
	int i;
	playerPtr current = list->head;
	playerPtr previous;
	if(position == 0){
		if(list->head == list->tail){
			list->tail = list->tail->next;
		}
		list->head = list->head->next;
		destroyHand(current->playersHand);
		free(current);
	} else {
		for(i = 0; i < position && current->next != NULL; i++){
			previous = current;
			current = current->next;
		}
		previous->next = NULL;
		if(list->tail == current){
			list->tail = previous;
		}
		destroyHand(current->playersHand);
		free(current);
	}
}

int isPlayerListEmpty(playerListPtr list){
	if(list->head == NULL){
		return 0;
	} else {
		return 1;
	}
}

void emptyPlayerList(playerListPtr list){
	while(isPlayerListEmpty(list) == 1){
		removePlayer(list, 0);
	}
}

playerListPtr destroyPlayerList(playerListPtr list){
	emptyPlayerList(list);
	free(list);
	return NULL;
}