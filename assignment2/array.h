#define DATA int
#define ARRAYPTR int*

ARRAYPTR initArray(int capacity);

DATA check(ARRAYPTR ar, int num_elements, int position);

void replace(ARRAYPTR ar, int num_elements, int position, DATA data);

void display(ARRAYPTR ar, int num_elements);

void add(ARRAYPTR *ar, int* p_num_elements, int* capacity, DATA data, int position);

void remove_(ARRAYPTR ar, int* p_num_elements, int position);

void empty(ARRAYPTR ar, int* p_num_elements);

int isEmpty(ARRAYPTR ar, int* p_num_elements);

ARRAYPTR destroy(ARRAYPTR ar, int num_elements);

void remove_outliers(ARRAYPTR ar, int *num_elements, DATA x);

void smooth_list(ARRAYPTR ar, int *p_num_elements, int* capacity);