typedef struct date{
	int day;
	int month;
	int year;
} Date, *DatePtr;

typedef struct Data{
	char courseName[100];
	char assignmentName[100];
	int points;
	Date dueDate;
} Data, *DataPtr;

typedef struct Node{
	DataPtr daData;
	struct Node* next;
} Node, *NodePtr;

typedef struct pqueue{
	NodePtr head;
	NodePtr tail;
	int size;
} PQueue, *PQueuePtr;

PQueuePtr initPQueue();

void destroyPQueue(PQueuePtr daQueue);

void enPQueue(PQueuePtr daQueue, DataPtr daData);

void dePQueue(PQueuePtr daQueue);

int isEmpty(PQueuePtr daQueue);

void empty(PQueuePtr daQueue);

NodePtr getHighestPr(PQueuePtr daQueue);

int getSize(PQueuePtr daQueue);

int compare(DataPtr data1, DataPtr data2);