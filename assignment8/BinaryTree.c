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
	BinTreePtr temp = malloc(sizeof(BinTree));
	if(temp == NULL){
		printf("ERROR RAN OUT OF MEMORY!!\n");
		return NULL;
	}
	temp->root = NULL;
	return temp;
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
	if(node == NULL){
	}
	if(isLeaf(node) == 1){
		free(node);
		node = NULL;
	} else {
		if(hasLeft(node) == 1){
			emptySubtree(node->left);
		}
		if(hasRight(node) == 1){
			emptySubtree(node->right);
		}
	}
	free(node);
	node = NULL;
	return node;
}

BinTreePtr destroyTree(BinTreePtr tree){
	return NULL;
}

int numNodesSubtree(NodePtr node){
	if(node == NULL){
		return 0;
	}
	return (numNodesSubtree(node->left) + numNodesSubtree(node->right) + 1);
}

int numLeavesSubTree(NodePtr node){
	if(isLeaf(node) == 1){
		return 1;
	}
	if(node == NULL){
		return 0;
	}
	return (numLeavesSubTree(node->left) + numLeavesSubTree(node->right));
}

int heightSubtree(NodePtr node){
	if(node == NULL){
		return 0;
	}
	return (1 + max(heightSubtree(node->left)), heightSubtree(node->right));
}