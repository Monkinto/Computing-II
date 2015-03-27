#include <stdio.h>
#include <stdlib.h>

#include "stack_list.h"

void matches(StackPtr theStack, char input, char against, int *balanced){
	if(input == '\0'){
		printf("You tried to close %c before you opened any brackets.\n", against);
	}
	switch(against){
		case'}':
			if(input == '{'){
				pop(theStack);
			} else {
				printf("You tried to close %c before you closed %c.\n", against, input);
				*balanced = 1;
			}
			break;
		case']':
			if(input == '['){
				pop(theStack);
			} else {
				printf("You tried to close %c before you closed %c.\n", against, input);
				*balanced = 1;
			}
			break;
		case')':
			if(input == '('){
				pop(theStack);
			} else {
				printf("You tried to close %c before you closed %c.\n", against, input);
				*balanced = 1;
			}
			break;
		default:
			printf("Some weird error occured...\n");
			break;
	}
}

int main(int argc, char* argv[]){
	StackPtr theStack = initStack();
	int i;
	int balance = 0;
	char theChar;
	FILE* fin = fopen("expressions.txt", "r");
	while((theChar = fgetc(fin)) != EOF){
		switch(theChar){
			case'{':
				push(theStack, '{');
				printf("Pushed {\n");
				break;
			case'[':
				push(theStack, '[');
				printf("Pushed [\n");
				break;
			case'(':
				push(theStack, '(');
				printf("Pushed (\n");
				break;
			case'}':
				if(isEmpty(theStack) == 1){
					printf("You never opened {!\n");
					balance = 1;
				} else {
					matches(theStack, peak(theStack), theChar, &balance);
				}
				break;
			case']':
				if(isEmpty(theStack) == 1){
					printf("You never opened [!\n");
					balance = 1;
				} else {
					matches(theStack, peak(theStack), theChar, &balance);
				}
				break;
			case')':
				if(isEmpty(theStack) == 1){
					printf("You never opened (!\n");
					balance = 1;
				} else {
					matches(theStack, peak(theStack), theChar, &balance);
				}	
				break;
			case'\n':
				if(isEmpty(theStack) == 1){
					printf("The expression is balanced.\n");
				} else {
					while(isEmpty(theStack) != 1){
						printf("You didn't close a %c!\n", peak(theStack));
						pop(theStack);
					}
				}
				break;
			default:
				//thePoint++;
				break;
		}
		if(balance != 0){
			printf("You did something wrong!\n");
			while(theChar != '\n' && theChar != EOF){
				theChar = fgetc(fin);
			}
			empty(theStack);
			balance = 0;
		}
	}
	fclose(fin);
	destroyStack(theStack);
	return 0;
}