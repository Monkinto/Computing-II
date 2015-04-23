#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define hashtableSize 67

typedef char* string;

typedef struct data{
	int number;
	string name;
	string semester;
	string instructor;
	int liked;
} Data, *DataPtr;

typedef struct node{
	Data theData;
	struct node *next;	
}Node, *NodePtr;

typedef struct linkedlist{
	NodePtr head;
}LinkedList, *LinkedListPtr;

typedef struct hashtable{
	LinkedListPtr table[hashtableSize];
}HashTable, *HashTablePtr;

HashTablePtr initHashTable();

int hash(int number);

NodePtr search(HashTablePtr theTable, int number);

int add(HashTablePtr table, Data dat);

NodePtr makeNode(Data dat);