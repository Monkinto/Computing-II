typedef struct Data{
	int nameOfStock;
	int numberOfShares;
	double PurchaseCostPerShare;
	double CurrentCostPerShare;
} Data, *DataPtr; 

typedef struct Node{
	DataPtr daData;
	struct Node* next;
	struct Node* previous;
} Node, *NodePtr;

typedef struct deQue{
	NodePtr head;
	NodePtr tail;
	int size;
} deQue, *deQuePtr;

deQuePtr initDeQue();

void destroyDeQue(deQuePtr daQueue);

void addFront(deQuePtr daQueue, DataPtr daData);

void addBack(deQuePtr daQueue, DataPtr daData);

void removeFront(deQuePtr daQueue);

void removeBack(deQuePtr daQueue);

int isEmpty(deQuePtr daQueue);

void empty(deQuePtr daQueue);

DataPtr getFront(deQuePtr daQueue);

DataPtr getBack(deQuePtr daQueue);

int getSize(deQuePtr daQueue);