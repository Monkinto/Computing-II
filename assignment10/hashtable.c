#include "hashtable.h"

HashTablePtr initHashTable(){
	int i;
	HashTablePtr theTable = malloc(sizeof(HashTable));
	for(i = 0; i < hashtableSize; i++){
		theTable->table[i] = malloc(sizeof(LinkedListPtr));
		theTable->table[i]->head = NULL;
	}
	return theTable;
}

int hash(int number){
	printf("Hash of:%d = %d\n", number, number);
	return number;
}

NodePtr search(HashTablePtr theTable, int number){
	int theHash = hash(number);
	NodePtr current;
	if(theTable->table[theHash]->head == NULL){
		printf("There is no course with that ID number in the table.\n");
		return NULL;
	}
	current = theTable->table[theHash]->head;
	while(current != NULL){
		if(current->theData.number == number){
			printf("Found it!\n");
			return current;
		} else {
			current = current->next;
		}
	}
	printf("There is no course with that ID number in the table.\n");
	return NULL;
}

int add(HashTablePtr theTable, Data newData){
	int theHash = hash(newData.number);
	NodePtr current = theTable->table[theHash]->head;
	if(current == NULL){
		theTable->table[theHash]->head = makeNode(newData);
		return 1;
	} else {
		while(current->next != NULL){
			current = current->next;
		}
		current->next = makeNode(newData);
		return 1;
	}
	return 0;
}

NodePtr makeNode(Data NewData){
	NodePtr theNode = malloc(sizeof(Node));
	theNode->theData.number = NewData.number;
	strcpy(theNode->theData.name, NewData.name);
	strcpy(theNode->theData.semester, NewData.semester);
	strcpy(theNode->theData.instructor, NewData.instructor);
	theNode->theData.liked = NewData.liked;
	return theNode;
}