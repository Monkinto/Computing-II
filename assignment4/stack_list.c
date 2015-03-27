#include <stdio.h>
#include <stdlib.h>

#include "stack_list.h"

StackPtr initStack(){
	StackPtr theStack = (StackPtr)malloc(sizeof(Stack));
	if(theStack == NULL){
		printf("Ran out of memory!");
	}
	theStack->top = NULL;
	return theStack;
}

void push(StackPtr theStack, Data theData){
	NodePtr theNode = (NodePtr)malloc(sizeof(Node));
	if(theNode == NULL){
		printf("Ran out of memory!");
		return;
	}
	theNode->data = theData;
	theNode->next = theStack->top;
	theStack->top = theNode;
}

void pop(StackPtr theStack){
	NodePtr theNode = theStack->top;
	if(theNode != NULL){
		theStack->top = theNode->next;
		free(theNode);
	} else {
		printf("The stack is already empty.");
	}
}

Data peak(StackPtr theStack){
	NodePtr theNode = theStack->top;
	return theNode->data;
}

int isEmpty(StackPtr theStack){
	if(theStack->top == NULL){
		return 1;
	} else {
		return 0;
	}
}

void empty(StackPtr theStack){
	while(theStack->top != NULL){
		pop(theStack);
	}
}

void destroyStack(StackPtr theStack){
	empty(theStack);
	free(theStack);
}