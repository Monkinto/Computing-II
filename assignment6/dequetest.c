#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deque.h"

void fillLedger(deQuePtr datdaQue){
	int i, numberofStocks;
	DataPtr tempData;
	numberofStocks = (rand() % 44) + 5;
	printf("Creating %d stocks.\n", numberofStocks);
	for(i = 0; i < numberofStocks; i++){
		tempData = (DataPtr)malloc(sizeof(Data));
		tempData->nameOfStock = (rand() % 899) + 100;
		tempData->numberOfShares = rand() % 10;
		tempData->PurchaseCostPerShare = 0;
		tempData->CurrentCostPerShare = (double)((rand() % 99999) / 100) + 0.01;
		addBack(datdaQue, tempData);
	}
}

void printData(DataPtr datData){
	printf("Name of stock: %d\n", datData->nameOfStock);
	printf("Number of shares: %d\n", datData->numberOfShares);
	printf("Purchase cost per share: %lf\n", datData->PurchaseCostPerShare);
	printf("Current cost per share: %lf\n", datData->CurrentCostPerShare);
}

int main(int argc, char* argv[]){
	deQuePtr deck = initDeQue();
	DataPtr tempData = (DataPtr)malloc(sizeof(Data));
	fillLedger(deck);
	tempData->nameOfStock = 101;
	tempData->numberOfShares = rand();
	tempData->PurchaseCostPerShare = rand();
	tempData->CurrentCostPerShare = rand();
	addFront(deck, tempData);
	printf("\nPrinting out the first element.\n\n");
	printData(getFront(deck));
	printf("\nPrinting out the last element.\n\n");
	printData(getBack(deck));
	printf("Removing the first and last elements.");
	removeFront(deck);
	removeBack(deck);
	printf("\nPrinting out the first element.\n\n");
	printData(getFront(deck));
	printf("\nPrinting out the first element.\n\n");
	printData(getBack(deck));
	printf("isEmpty %d\n", isEmpty(deck));
	printf("getSize %d\n", getSize(deck));
	empty(deck);
	printf("isEmpty %d\n", isEmpty(deck));
	destroyDeQue(deck);
	return 0;
}