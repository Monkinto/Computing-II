#include <stdio.h>
#include <stdlib.h>
#include "queue.h"

int main(int argc, char* argv[]){
	QueuePtr datQueue = initQueue();
	int i;
	printf("0 = Queue Filled\n1 = Queue Empty\nQueue Status: %d\n", isEmpty(datQueue));
	for(i = 0; i < 5; i++){
		printf("Adding: %d\n", i);
		enQueue(datQueue, i);
	}
	printf("The size of the queue is: %d\n", getSize(datQueue));
	printf("The front of the queue is: %d\n", getFront(datQueue));
	for(i = 0; i < 3; i++){
		printf("Removing %d\n", getFront(datQueue));
		deQueue(datQueue);
	}
	printf("The front of the queue is: %d\n", getFront(datQueue));
	empty(datQueue);
	printf("0 = Queue Filled\n1 = Queue Empty\nQueue Status: %d\n", isEmpty(datQueue));
	printf("The size of the queue is: %d\n", getSize(datQueue));
	destroyQueue(datQueue);
	return 0;
}