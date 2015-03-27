#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "deque.h"

double magicalRandNum(){
	return (double)(rand() % 50)/100 + .75;
}

void magicalStockUpdate(deQuePtr datdaQue){
	NodePtr datNode = datdaQue->head;
	printf("\nUpdating stock prices.\n\n");
	while(datNode != NULL){
		datNode->daData->CurrentCostPerShare = datNode->daData->CurrentCostPerShare * magicalRandNum();
		datNode = datNode->next;
	}
}

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
	int i, menu = 0, input;
	DataPtr tempData;
	double capital = 1000;
	deQuePtr ledger = initDeQue();
	srand(time(NULL));
	fillLedger(ledger);
	printf("Welcome to ridicoulous stock market simulation!\n");
	printf("You start with $1000 and five random stocks, enjoy!\n");
	while(menu != 8){
		printf("Please enter one of the numbers below:\n");
		printf(" 1:\tShow your capital.\n");
		printf(" 2:\tCheck the status of the front.\n");
		printf(" 3:\tCheck the status of the back.\n");
		printf(" 4:\tBuy more shares of the front.\n");
		printf(" 5:\tBuy more shares of the back.\n");
		printf(" 6:\tSell shares from the front.\n");
		printf(" 7:\tSell shares from the back.\n");
		printf(" 8:\tQuit.\n");
		printf("Enter a number: ");
		scanf("%d", &menu);
		while(menu > 8 || menu < 1){
			printf("Please enter a number between 1 and 8: ");
			scanf("%d", &menu);
		}
		switch(menu){
			case 1:
				printf("\nCurrent capital: %lf\n", capital);
			break;
			case 2:
				printf("You choose option %d.\n", menu);
				printData(getFront(ledger));
			break;
			case 3:
				printf("You choose option %d.\n", menu);
				printData(getBack(ledger));
			break;
			case 4:
				printf("You choose option %d.\n", menu);
				tempData = getFront(ledger);
				printData(tempData);
				printf("\nEnter the number of shares that you want to buy: ");
				scanf("%d", &input);
				if(input >= 0){
					if(((double)input * tempData->CurrentCostPerShare) < capital){
						printf("Purchasing %d shares of stock %d.\n", input, tempData->nameOfStock);
						capital = capital - ((double)input * tempData->CurrentCostPerShare);
						tempData->numberOfShares = tempData->numberOfShares + input;
						tempData->PurchaseCostPerShare = tempData->CurrentCostPerShare;
					} else {
						printf("You can't afford that many shares of stock %d.\n", tempData->nameOfStock);
					}
				} else {
					printf("You can't buy a negative number of shares.\n");
				}
				magicalStockUpdate(ledger);
			break;
			case 5:
				printf("You choose option %d.\n", menu);
				tempData = getBack(ledger);
				printData(tempData);
				printf("\nEnter the number of shares that you want to buy: ");
				scanf("%d", &input);
				if(input >= 0){
					if(((double)input * tempData->CurrentCostPerShare) < capital){
						printf("Purchasing %d shares of stock %d.\n", input, tempData->nameOfStock);
						capital = capital - ((double)input * tempData->CurrentCostPerShare);
						tempData->numberOfShares = tempData->numberOfShares + input;
						tempData->PurchaseCostPerShare = tempData->CurrentCostPerShare;
					} else {
						printf("You can't afford that many shares of stock %d.\n", tempData->nameOfStock);
					}
				} else {
					printf("You can't buy a negative number of shares.\n");
				}
				magicalStockUpdate(ledger);
			break;
			case 6:
				printf("You choose option %d.\n", menu);
				tempData = getFront(ledger);
				printData(tempData);
				printf("\nEnter the number of shares that you want to sell: ");
				scanf("%d", &input);
				if(input >= 0){
					if(input <= tempData->numberOfShares){
						printf("Selling %d shares of stock %d.\n", input, tempData->nameOfStock);
						capital = capital + (input * tempData->CurrentCostPerShare);
						if(tempData->numberOfShares == 0){
							removeFront(ledger);
						}
					} else {
						printf("You don't have enough shares of stock %d.\n", tempData->nameOfStock);
					}
				} else {
					printf("You can't sell a negative number of shares.\n");
				}
				magicalStockUpdate(ledger);
			break;
			case 7:
				printf("You choose option %d.\n", menu);
				tempData = getBack(ledger);
				printData(tempData);
				printf("\nEnter the number of shares that you want to sell: ");
				scanf("%d", &input);
				if(input >= 0){
					if(input <= tempData->numberOfShares){
						printf("Selling %d shares of stock %d.\n", input, tempData->nameOfStock);
						capital = capital + (input * tempData->CurrentCostPerShare);
						if(tempData->numberOfShares == 0){
							removeBack(ledger);
						}
					} else {
						printf("You don't have enough shares of stock %d.\n", tempData->nameOfStock);
					}
				} else {
					printf("You can't sell a negative number of shares.\n");
				}
				magicalStockUpdate(ledger);
			break;
			case 8:
				printf("You choose option %d.\n", menu);
				destroyDeQue(ledger);
				return 0;
			break;
		}
	}
	return 0;
}