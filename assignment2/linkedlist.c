/**************************************************************************************************/
/* Programmer: Mike diBenedetto                                                                   */
/*                                                                                                */
/* Program assignment02: To Do list 2                                                             */
/*                                                                                                */
/* Approximate completion time: ... minutes                                                       */
/**************************************************************************************************/

/*Headers provided by C*/
/* Example: #inlcude <stdio.h> */
#include <stdio.h>
#include <stdlib.h>

/*Headers provided by the user*/
/* Example: #include "something.h" */
#include "linkedlist.h"

LINKEDLISTPTR initLinkedList(){
	LINKEDLISTPTR temp = (LINKEDLISTPTR)malloc(sizeof(LINKEDLIST));
	if(temp == NULL){
		printf("OUT OF MEMORY!");
	} else {
		temp->head = NULL;
	}
	return temp;
}

DATA check(LINKEDLISTPTR list, int position){
	NODEPTR nodepoint;
	int i;
	nodepoint = list->head;
	for(i = 1; i < position; i++){
		nodepoint = nodepoint->next;
	}
	return nodepoint->data;
}

void replace(LINKEDLISTPTR list, int position, DATA data){
	NODEPTR nodepoint;
	int i;
	nodepoint = list->head;
	for(i = 1; i < position; i++){
		nodepoint = nodepoint->next;
	}
	nodepoint->data = data;
}

void display(LINKEDLISTPTR list, int num_elements){
	NODEPTR nodepoint;
	int i = 0;
	nodepoint = list->head;
	while(nodepoint != NULL && i < num_elements){
		i++;
		printf("%d: %d\n", i, nodepoint->data);
		nodepoint = nodepoint->next;
	}
}

void add(LINKEDLISTPTR list, DATA data, int position){
	NODEPTR nodehead = list->head;
	NODEPTR nodepoint = (NODEPTR)malloc(sizeof(NODE));
	int i;
	if(position == 0){
		nodepoint->next = NULL;
		nodepoint->data = data;
		list->head = nodepoint;
	} else {
		for(i = 0; i < position-1; i++){
			nodehead = nodehead->next;
		}
		nodepoint->next = nodehead->next;
		nodepoint->data = data;
		nodehead->next = nodepoint;
	}

}

void remove_(LINKEDLISTPTR list, int position){
	NODEPTR nodehead = list->head;
	NODEPTR nodepoint;
	int i;
	if(position == 0){
		nodepoint = list->head;
		list->head = nodepoint->next;
	} else {
		for(i = 1; i < position-1; i++){
			nodehead = nodehead->next;
		}
		nodepoint = nodehead->next;
		nodehead->next = nodepoint->next;
	}
	free(nodepoint);
}

void empty(LINKEDLISTPTR list){ 
	NODEPTR nodepoint;
	nodepoint = list->head;
	int i, numberofnodes;
	for(numberofnodes = 0; nodepoint != NULL; numberofnodes++){
		nodepoint = nodepoint->next;
	}
	for(i = 0; i < numberofnodes; i++){
		remove_(list, 0);
	}
}

int isEmpty(LINKEDLISTPTR list){
	if(list->head == NULL){
		return 1;
	} else {
		return 0;
	}
}

LINKEDLISTPTR destroy(LINKEDLISTPTR list){
	if(list == NULL){
		printf("Linked list destroyed!\n");
		return NULL;
	} else{
		return list;
	}
	
}