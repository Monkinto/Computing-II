#include <stdio.h>
#include <stdlib.h>
#include "p_queue.h"

PQueuePtr initPQueue(){
	PQueuePtr daQueue = (PQueuePtr)malloc(sizeof(PQueue));
	daQueue->head = NULL;
	daQueue->tail = NULL;
	daQueue->size = 0;
	return daQueue;
}

void destroyPQueue(PQueuePtr daQueue){
	empty(daQueue);
	free(daQueue);
}

void enPQueue(PQueuePtr daQueue, DataPtr daData){
	NodePtr newNode = (NodePtr)malloc(sizeof(Node));
	NodePtr compNode;
	NodePtr prevNode;
	int i, broke;
	newNode->daData = daData;
	newNode->next = NULL;
	compNode = getHighestPr(daQueue);
	prevNode = NULL;
	//printf("\n\n%d\n\n", getSize(daQueue));
	for(i = 0; i < getSize(daQueue); i++){
		if(compare(newNode->daData, compNode->daData) == -1 || compare(newNode->daData, compNode->daData) == 0){
			prevNode = compNode;
			compNode = compNode->next;
		} else {
			//printf("\n\nBREAKING\n\n");
			break;
		}
	}
	if(prevNode == NULL){
		newNode->next = compNode;
		daQueue->head = newNode;
		//printf("\n\nNot else\n\n");
		if(getSize(daQueue) == 0 || newNode->next == NULL){
			daQueue->tail = newNode;
		}
	} else {
		prevNode->next = newNode;
		newNode->next = compNode;
		//printf("\n\nELSE\n\n");
	}
	daQueue->size++;
}

int compare(DataPtr data1, DataPtr data2){
	if(data1->dueDate.year < data2->dueDate.year){
		//printf("\nThe year of new is less than comp.\n");
		return 1;
	}
	if(data1->dueDate.year > data2->dueDate.year){
		//printf("\nThe year of new is less than comp.\n");
		return -1;
	}
	if(data1->dueDate.month < data2->dueDate.month){
		//printf("\nThe month of new is less than comp.\n");
		return 1;
	}
	if(data1->dueDate.month > data2->dueDate.month){
		//printf("\nThe month of new is less than comp.\n");
		return -1;
	}
	if(data1->dueDate.day < data2->dueDate.day){
		//printf("\nThe day of new is less than comp.\n");
		return 1;
	}
	if(data1->dueDate.day > data2->dueDate.day){
		//printf("\nThe day of new is less than comp.\n");
		return -1;
	}
	if(data1->points > data2->points){
		//printf("\nThe points of new is less than comp.\n");
		return 1;
	}
	//printf("\n --> New has a lower priority than comp!\n");
	return 0;
}

void dePQueue(PQueuePtr daQueue){
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

int isEmpty(PQueuePtr daQueue){
	if(daQueue->head == NULL && daQueue->tail == NULL){
		return 1;
	} else {
		return 0;
	}
}

void empty(PQueuePtr daQueue){
	while(daQueue->head != NULL){
		dePQueue(daQueue);
	}
}

NodePtr getHighestPr(PQueuePtr daQueue){
	return daQueue->head;
}

int getSize(PQueuePtr daQueue){
	return daQueue->size;
}