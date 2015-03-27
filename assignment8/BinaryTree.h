typedef char* Data;

typedef struct node{
	NodeData Data;
	struct node * left;
	struct node * right;
}Node, *NodePtr;

typedef struct tree{
	NodePtr root;
}BinTree, *BinTreePtr;

