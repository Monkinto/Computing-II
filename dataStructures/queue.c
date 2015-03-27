#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

QueuePtr initQueue(){
	QueuePtr daQueue = (QueuePtr)malloc(sizeof(Queue));
	daQueue->head = NULL;
	daQueue->tail = NULL;
	daQueue->size = 0;
	return daQueue;
}

void destroyQueue(QueuePtr daQueue){
	empty(daQueue);
	free(daQueue);
}

void enQueue(QueuePtr daQueue, Data daData){
	NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	newNode->daData = daData;
	newNode->next = NULL;
	daQueue->size++;
	if(daQueue->head == NULL && daQueue->tail == NULL){
		daQueue->head = newNode;
		daQueue->tail = newNode;
	} else {
		daQueue->tail->next = newNode;
		daQueue->tail = daQueue->tail->next;
	}
}

void deQueue(QueuePtr daQueue){
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

int getSize(QueuePtr daQueue){
	return daQueue->size;
}