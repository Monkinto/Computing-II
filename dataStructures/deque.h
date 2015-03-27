typedef struct Data{
	char* nameOfStock;
	int numberOfShares;
	double PurchaseCostPerShare;
	double CurrentCostPerShare;
} Data, *DataPtr; 

typedef struct Node{
	Data daData;
	struct Node* next;
	struct Node* pervious;
} Node, *NodePtr;

typedef struct deQue{
	NodePtr head;
	NodePtr tail;
	int size;
} deQue, *deQuePtr;

QueuePtr initDeQue();

void destroyDeQue(QueuePtr daQueue);

void addFront(QueuePtr daQueue, Data daData);

void addBack(QueuePtr daQueue, Data daData);

void removeFront(QueuePtr daQueue);

void removeBack(QueuePtr daQueue);

int isEmpty(QueuePtr daQueue);

void empty(QueuePtr daQueue);

Data getFront(QueuePtr daQueue);

Data getBack(QueuePtr daQueue);

int getSize(QueuePtr daQueue);