#include <stdio.h>
#include <stdlib.h>
#include "p_queue.h"

void printData(DataPtr thatData){
	printf("\n");
	printf("Course name: %s\n", thatData->courseName);
	printf("Assignment name: %s\n", thatData->assignmentName);
	printf("Point Value: %d\n", thatData->points);
	printf("Date Due: %d/%d/%d\n", thatData->dueDate.month, thatData->dueDate.day, thatData->dueDate.year);
	printf("\n");
}

int main(int argc, char* argv[]){
	int i, temp;
	DataPtr tempData;
	PQueuePtr datPQueue = initPQueue();
	
	for(i = 0; i < 5; i++){
		tempData = (DataPtr)malloc(sizeof(Data));
		printf("Please enter the course the assignment is from: ");
		scanf("%99s", &tempData->courseName);
		printf("Please enter the name of the assignment: ");
		scanf("%99s", &tempData->assignmentName);
		printf("Enter the point value of the assignment: ");
		scanf("%d", &tempData->points);
		printf("Enter the year the assignment is due: ");
		scanf("%d", &tempData->dueDate.year);
		printf("Enter the month the assignment is due: ");
		scanf("%d", &tempData->dueDate.month);
		printf("Enter the day the assignment is due: ");
		scanf("%d" , &tempData->dueDate.day);
		enPQueue(datPQueue, tempData);
		printf("\n");
	}
	printf("The size of the queue is %d.\n", getSize(datPQueue));
	
	printData(getHighestPr(datPQueue)->daData);
	dePQueue(datPQueue);
	printData(getHighestPr(datPQueue)->daData);
	dePQueue(datPQueue);
	
	printf("The size of the queue is %d.\n", getSize(datPQueue));
	printData(getHighestPr(datPQueue)->daData);
	empty(datPQueue);
	printf("The size of the queue is %d.\n", getSize(datPQueue));
	destroyPQueue(datPQueue);
}