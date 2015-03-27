typedef int Data; 

typedef struct Node{
	Data daData;
	struct Node* next;
} Node, *NodePtr;

typedef struct queue{
	NodePtr head;
	NodePtr tail;
	int size;
} Queue, *QueuePtr;

QueuePtr initQueue();

void destroyQueue(QueuePtr daQueue);

void enQueue(QueuePtr daQueue, Data daData);

void deQueue(QueuePtr daQueue);

int isEmpty(QueuePtr daQueue);

void empty(QueuePtr daQueue);

Data getFront(QueuePtr daQueue);

int getSize(QueuePtr daQueue);