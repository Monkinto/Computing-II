#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>
#include "queue.h"

typedef struct Runway{
	int vacant;
	int timeTillVacant;
	Data planeUsing;
} Runway;

double makeRand(){
	return (double)rand() / RAND_MAX;
}

int flightNumber(){
	return (rand() % 899) + 100;
}

int main(int argc, char* argv[]){
	double randomAir, randomGr;
	QueuePtr airQueue = initQueue();
	QueuePtr groundQueue = initQueue();
	int i, timeDuration, planeTemp;
	Runway datRunway;

	datRunway.vacant = 0;
	datRunway.timeTillVacant = 0;
	Data planeUsing = 0;
	
	srand(time(NULL));

	printf("Enter the amount of seconds that you want the program to run for: ");
	scanf("%d", &timeDuration);

	printf("Enter the percentage chance of a plane showing up in the air: ");
	scanf("%lf", &randomAir);

	printf("Enter the percentage chance of a plane showing up on the ground: ");
	scanf("%lf", &randomGr);

	for(i = 0; i < timeDuration; i++){
		if(datRunway.vacant != 0){
			datRunway.timeTillVacant--;
			if(datRunway.timeTillVacant == 1){
				datRunway.vacant = 0;
			}
		} else {
			if(isEmpty(airQueue) == 0){
				datRunway.planeUsing = getFront(airQueue);
				datRunway.timeTillVacant = 2;
				datRunway.vacant = 1;
				printf("\nFlight %d from the air queue is now using the runway!\n\n", getFront(groundQueue));
				deQueue(airQueue);
			} else if(isEmpty(groundQueue) == 0){
				datRunway.planeUsing = getFront(groundQueue);
				datRunway.timeTillVacant = 2;
				datRunway.vacant = 1;
				printf("\nFlight %d from the ground queue is now using the runway!\n\n", getFront(groundQueue));
				deQueue(groundQueue);
			}

		}
		if(makeRand() > randomAir){
			planeTemp = flightNumber();
			enQueue(airQueue, planeTemp);
			printf("Flight %d enters the air queue!\n", planeTemp);
		}
		if(makeRand() > randomAir){
			planeTemp = flightNumber();
			enQueue(airQueue, planeTemp);
			printf("Flight %d enters the air queue!\n", planeTemp);
		}
		if(makeRand() > randomGr){
			planeTemp = flightNumber();
			enQueue(groundQueue, planeTemp);
			printf("Flight %d enters the ground queue!\n", planeTemp);
		}
		//printf("\n");
		sleep(1);
	}
	return 0;
}