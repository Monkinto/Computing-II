#define MAXSIZE 100

#define MAX(a, b) ((a) > (b) ? ( a) : (b))

typedef char Data[MAXSIZE] ;

typedef struct node{
	Data theData;
	struct node *left;
	struct node *right;
}Node, *NodePtr;

typedef struct tree{
	NodePtr root;
}BinTree, *BinTreePtr;

int hasLeft(NodePtr node);

int hasRight(NodePtr node);

int isLeaf(NodePtr node);

BinTreePtr initBinaryTree();

NodePtr makeNode(Data theData);

int isEmpty(BinTreePtr tree);

NodePtr addRoot(BinTreePtr tree, Data theData);

NodePtr addBST(NodePtr node, Data theData);

NodePtr emptySubtree(NodePtr node);

BinTreePtr destroyTree(BinTreePtr tree);

int numNodesSubtree(NodePtr node);

int numLeavesSubtree(NodePtr node);

int heightSubtree(NodePtr node);

void inorderTraverse(NodePtr node);

NodePtr search(NodePtr node, char key[]);

