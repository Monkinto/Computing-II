#include "hashtable.h"

void readInData(HashTablePtr theTable, FILE* fin, Data tempData){
	string temp;
	while(fscanf(fin, "%s", temp) != EOF){
		tempData.number = atoi(temp);
		fscanf(fin, "%s", tempData.name);
		fscanf(fin, "%s", tempData.semester);
		fscanf(fin, "%s", tempData.instructor);
		fscanf(fin, "%s", temp);
		tempData.liked = atoi(temp);
		//add(theTable, tempData);
	}
}

int main(int argc, char const *argv[]){
	HashTablePtr theTable = initHashTable();
	Data tempData;
	FILE* fin = fopen("input.txt", "r");
	readInData(theTable, fin, tempData);
	return 0;
}