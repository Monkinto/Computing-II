#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "BinaryTree.h"

void fillDecisionTree(BinTreePtr tree){
	NodePtr CurrentNode;
	NodePtr temp;
	CurrentNode = addRoot(tree, "Do you want to be melee or ranged?");
	printf("%s\n", tree->root->theData);
	temp = addChild(CurrentNode, 1, "Do you want to tank or DPS?");
	CurrentNode = addChild(CurrentNode, 0, "Do you want to Heal or DPS?");
	addChild(CurrentNode, 1, "Do you want to be able to do DPS?");
	CurrentNode = addChild(CurrentNode, 0, "Do you want to be able to move and cast at the same time?");
	addChild(CurrentNode, 1, "You should play a Hunter.");
	addChild(CurrentNode, 0, "You should play a Druid.");
	CurrentNode = tree->root;
	CurrentNode = CurrentNode->left;
	addChild(CurrentNode, 1, "Do you want to tank or DPS?");
	CurrentNode = addChild(CurrentNode, 0, "Do you want to be stealthy?");
	addChild(CurrentNode, 1, "You should play a Rouge.");
	addChild(CurrentNode, 0, "You should play a Death Knight");
	CurrentNode = tree->root;
	CurrentNode = CurrentNode->left;
	CurrentNode = addChild(CurrentNode, 1, "Do you want to have tons of damage mobility?");
	addChild(CurrentNode, 1, "You should be a Monk.");
	addChild(CurrentNode, 0, "You should be a Warrior.");
	CurrentNode = tree->root;
	CurrentNode = CurrentNode->right;
	CurrentNode = CurrentNode->left;
	addChild(CurrentNode, 1, "You should play a Monk.");
	addChild(CurrentNode, 0, "You should play a priest.");
}

int play(BinTreePtr tree){
	return 1;
}

int main(int argc, char const *argv[])
{
	BinTreePtr theTree = initBinaryTree();
	int repeat;
	fillDecisionTree(theTree);
	printf("\nThe number of nodes is: %d\n", numNodesSubtree(theTree->root));
	printf("The number of leaves is: %d\n", numLeavesSubtree(theTree->root));
	printf("The height of the tree is: %d\n", heightSubtree(theTree->root));
	do{
		repeat = play(theTree);
	}while(repeat == 0);
	destroyTree(theTree);
	return 0;
}