#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

deQuePtr initDeQue(){
	deQuePtr daQueue = (deQuePtr)malloc(sizeof(deQue));
	daQueue->head = NULL;
	daQueue->tail = NULL;
	daQueue->size = 0;
	return daQueue;
}

void destroyDeQue(deQuePtr daQueue){
	empty(daQueue);
	free(daQueue);
}

void addFront(deQuePtr daQueue, DataPtr daData){
	NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	newNode->daData = daData;
	newNode->next = NULL;
	newNode->previous = NULL;
	daQueue->size++;
	if(daQueue->head == NULL && daQueue->tail == NULL){
		daQueue->head = newNode;
		daQueue->tail = newNode;
	} else {
		newNode->next = daQueue->head;
		daQueue->head->previous = newNode;
		daQueue->head = newNode;
	}
}

void addBack(deQuePtr daQueue, DataPtr daData){
	NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	newNode->daData = daData;
	newNode->next = NULL;
	newNode->previous = NULL;
	daQueue->size++;
	if(daQueue->head == NULL && daQueue->tail == NULL){
		daQueue->head = newNode;
		daQueue->tail = newNode;
	} else {
		daQueue->tail->next = newNode;
		newNode->previous = daQueue->tail;
		daQueue->tail = newNode;
	}
}

void removeFront(deQuePtr daQueue){
	NodePtr theNode = daQueue->head;
	if(daQueue->head == NULL){
		daQueue->tail = NULL;
		printf("The queue is already empty.\n");
	} else if(theNode->next == NULL){
		daQueue->tail = NULL;
		daQueue->head = NULL;
		daQueue->size--;
		free(theNode);
	} else {
		daQueue->head = daQueue->head->next;
		daQueue->head->previous = theNode->previous;
		daQueue->size--;
		free(theNode);
	}
}

void removeBack(deQuePtr daQueue){
	NodePtr theNode = daQueue->tail;
	if(daQueue->head == NULL){
		daQueue->tail = NULL;
		printf("The queue is already empty.\n");
	} else if(theNode->previous == NULL){
		daQueue->tail = NULL;
		daQueue->head = NULL;
		daQueue->size--;
		free(theNode);
	} else {
		daQueue->tail = daQueue->tail->previous;
		daQueue->tail->next = theNode->next;
		daQueue->size--;
		free(theNode);
	}
}

int isEmpty(deQuePtr daQueue){
	if(daQueue->head == NULL && daQueue->tail == NULL){
		return 1;
	} else {
		return 0;
	}
}

void empty(deQuePtr daQueue){
	while(daQueue->head != NULL){
		removeBack(daQueue);
	}
}

DataPtr getFront(deQuePtr daQueue){
	return daQueue->head->daData;
}

DataPtr getBack(deQuePtr daQueue){
	return daQueue->tail->daData;
}

int getSize(deQuePtr daQueue){
	return daQueue->size;
}