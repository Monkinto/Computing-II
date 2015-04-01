#include <stdio.h>
#include <stdlib.h>
#include "BinaryTree.h"

int hasLeft(NodePtr node){
	if(node->left != NULL){
		return 1;
	}
	return 0;
}

int hasRight(NodePtr node){
	if(node->right != NULL){
		return 1;
	}
	return 0;
}

int isLeaf(NodePtr node){
	if(node->right == NULL && node->left == NULL){
		return 1;
	}
	return 0;
}

BinTreePtr initBinaryTree(){
	return NULL;
}

NodePtr makeNode(Data theData){
	return NULL;
}

int isEmpty(BinTreePtr tree){
	return 0;
}

NodePtr addRoot(BinTreePtr tree, Data theData){
	return NULL;
}

NodePtr addChild(NodePtr Parent, int leftOrRightChild, Data theData){
	return NULL;
}

NodePtr emptySubtree(NodePtr node){
	return NULL;
}

BinTreePtr destroyTree(BinTreePtr tree){
	return NULL;
}

int numNodesSubtree(NodePtr node){
	return 0;
}

int numLeavesSubTree(NodePtr node){
	return 0;
}

int heightSubtree(NodePtr node){
	return 0;
}