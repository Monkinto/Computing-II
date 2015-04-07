#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinarySTree.h"

void fillTree(BinTreePtr theTree, FILE* fin){
	char tempData[MAXSIZE];
	fscanf(fin, "%s", tempData);
	addRoot(theTree, tempData);
	while(fscanf(fin, "%s", tempData) != EOF){
		addBST(theTree->root, tempData);
	}
}

int main(int argc, char const *argv[]){
	BinTreePtr theTree = initBinaryTree();
	char tempData[MAXSIZE];
	FILE* fin = fopen("courses_taken.txt", "r");
	fillTree(theTree, fin);
	inorderTraverse(theTree->root);
	return 0;
}