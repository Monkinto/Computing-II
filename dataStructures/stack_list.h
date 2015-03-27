typedef char Data;

typedef struct Node{
	Data data;
	struct Node* next;
} Node, *NodePtr;

typedef struct Stack{
	NodePtr top;
} Stack, *StackPtr;

StackPtr initStack();

void push(StackPtr theStack, Data theData);

void pop(StackPtr theStack);

Data peak(StackPtr theStack);

int isEmpty(StackPtr theStack);

void empty(StackPtr theStack);

void destroyStack(StackPtr theStack);