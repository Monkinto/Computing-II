#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
	NodePtr theNode = malloc(sizeof(Node));
	theNode->left = NULL;
	theNode->right = NULL;
	strcpy(theNode->theData, theData);
	return theNode;
}

int isEmpty(BinTreePtr tree){
	if(tree->root == NULL){
		return 1;
	}
	return 0;
}

NodePtr addRoot(BinTreePtr tree, Data theData){
	NodePtr theNode = makeNode(theData);
	tree->root = theNode;
	return theNode;
}

NodePtr addChild(NodePtr Parent, int leftOrRightChild, Data theData){
	NodePtr theNode = makeNode(theData);
	if(leftOrRightChild == 1 && hasLeft(Parent) == 0){
		Parent->left = theNode;
	}
	if(leftOrRightChild == 0 && hasRight(Parent) == 0){
		Parent->right = theNode;
	}
	return theNode;
}

NodePtr emptySubtree(NodePtr node){
	if(node == NULL){
		return NULL;
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
	tree->root = emptySubtree(tree->root);
	free(tree);
	return NULL;
}

int numNodesSubtree(NodePtr node){
	if(node == NULL){
		return 0;
	}
	return (numNodesSubtree(node->left) + numNodesSubtree(node->right) + 1);
}

int numLeavesSubtree(NodePtr node){
	if(node == NULL){
		return 0;
	}
	if(isLeaf(node) == 1){
		return 1;
	}
	return (numLeavesSubtree(node->left) + numLeavesSubtree(node->right));
}

int heightSubtree(NodePtr node){
	if(node == NULL){
		return 0;
	}
	return (1 + MAX(heightSubtree(node->left), heightSubtree(node->right)));
}