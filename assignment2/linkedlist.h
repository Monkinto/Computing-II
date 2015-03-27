#define DATA int

typedef struct node{
	DATA data;
	struct node *next;
}NODE, *NODEPTR;

typedef struct linkedlist{
	NODEPTR head;
}LINKEDLIST, *LINKEDLISTPTR;

LINKEDLISTPTR initLinkedList();

DATA check(LINKEDLISTPTR list, int position);

void replace(LINKEDLISTPTR list, int position, DATA data);

void display(LINKEDLISTPTR list, int num_elements);

void add(LINKEDLISTPTR list, DATA data, int position);

void remove_(LINKEDLISTPTR list, int position);

void empty(LINKEDLISTPTR list);

int isEmpty(LINKEDLISTPTR list);

LINKEDLISTPTR destroy(LINKEDLISTPTR list);

void remove_outliers(LINKEDLISTPTR list, DATA x);

void smooth_list(LINKEDLISTPTR list);