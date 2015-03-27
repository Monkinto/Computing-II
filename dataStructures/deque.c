#include <stdio.h>
#include <stdlib.h>
#include "deque.h"

deQuePtr initDeQue(){
	QueuePtr daQueue = (QueuePtr)malloc(sizeof(Queue));
	daQueue->head = NULL;
	daQueue->tail = NULL;
	daQueue->size = 0;
	return daQueue;
}

void destroyDeQue(QueuePtr daQueue){
	empty(daQueue);
	free(daQueue);
}

void addFront(QueuePtr daQueue, Data daData){
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

void addBack(QueuePtr daQueue, Data daData){
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

void removeFront(QueuePtr daQueue){
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

void removeBack(QueuePtr daQueue){
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

int isEmpty(QueuePtr daQueue){
	if(daQueue->head == NULL && daQueue->tail == NULL){
		return 1;
	} else {
		return 0;
	}
}

void empty(QueuePtr daQueue){
	while(daQueue->head != NULL){
		deQueue(daQueue);
	}
}

Data getFront(QueuePtr daQueue){
	return daQueue->head->daData;
}

Data getBack(QueuePtr daQueue){
	return daQueue->tail->daData;
}

int getSize(QueuePtr daQueue){
	return daQueue->size;
}