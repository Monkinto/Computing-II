#include "hashtable.h"

void readInData(HashTablePtr theTable, FILE* fin, Data tempData){
	string temp = malloc(MAXSTRINGSIZE);
	while(fscanf(fin, "%s", temp) != EOF){
		tempData.number = atoi(temp);
		fscanf(fin, "%s", tempData.name);
		fscanf(fin, "%s", tempData.semester);
		fscanf(fin, "%s", tempData.instructor);
		fscanf(fin, "%s", temp);
		tempData.liked = atoi(temp);
		add(theTable, tempData);
	}
}

void printData(NodePtr printThis){
	printf("The course number is: %d\n", printThis->theData.number);
	printf("The name of the course was: %s\n", printThis->theData.name);
	printf("The semseter taken was: %s\n", printThis->theData.semester);
	printf("The instructor's name was: %s\n", printThis->theData.instructor);
	if(printThis->theData.liked == 0){
		printf("The course was not liked.\n");
	} else {
		printf("The course was liked.\n");
	}
}

int main(int argc, char const *argv[]){
	HashTablePtr theTable = initHashTable();
	Data tempData;
	FILE* fin = fopen("input.txt", "r");
	readInData(theTable, fin, tempData);
	printData(search(theTable, 49201));
	printData(search(theTable, 49268));
	printData(search(theTable, 92129));
	return 0;
}