#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinarySTree.h"

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
	NodePtr theNode = (NodePtr)malloc(sizeof(Node));
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

NodePtr addBST(NodePtr node, Data theData){
	if(node != NULL){
		if(strcmp(theData, node->theData) == 0){
			printf("You have already taken %s.\n", theData);
			return NULL;
		}
		if(strcmp(theData, node->theData) < 0){
			if(node->left == NULL){
				node->left = makeNode(theData);
				return node->left;
			} else {
				return addBST(node->left, theData);
			}
		}
		if(strcmp(theData, node->theData) > 0){
			if(node->right == NULL){
				node->right = makeNode(theData);
				return node->right;
			} else {
				return addBST(node->right, theData);
			}
		}
	}
	return node;
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

void inorderTraverse(NodePtr node){
	if(node != NULL){
		if(isLeaf(node) == 1){
			printf("%s\n", node->theData);
		} else {
			inorderTraverse(node->left);
			printf("%s\n", node->theData);
			inorderTraverse(node->right);
		}
	}
}

NodePtr search(NodePtr node, char key[]){
	if(node != NULL){
		if(strcmp(key, node->theData) < 0){
			return search(node->left, key);
		}
		if(strcmp(key, node->theData) > 0){
			return search(node->right, key);
		}
		if(strcmp(key, node->theData)){
			printf("You have taken course %s before.\n", key);
		}
	} else {
		printf("You have not taken couse %s before.\n", key);
		return node;
	}
}