#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "stack_list.h"

int main(int argc, char* argv[]){
	StackPtr theStack = initStack();
	int i;
	char Ctemp;
	srand(clock());
	if(isEmpty(theStack) == 1){
		printf("The stack is empty.\n");
	} else {
		printf("The stack isn't empty.\n");
	}
	for(i = 0; i < 10; i++){
		push(theStack, (rand()%26)+65);
	}
	if(isEmpty(theStack) == 1){
		printf("The stack is empty.\n");
	} else {
		printf("The stack isn't empty.\n");
	}
	printf("%c\n", peak(theStack));
	for(i = 0; i < 10; i++){
		printf("%c\n", peak(theStack));
		pop(theStack);
	}
	if(isEmpty(theStack) == 1){
		printf("The stack is empty.\n");
	} else {
		printf("The stack isn't empty.\n");
	}
	return 0;
}