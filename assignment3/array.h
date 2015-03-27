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

void removeAtStart(ARRAYPTR *array, int *p_num_elements);

void removeAfter(ARRAYPTR *array, int *p_num_elements, int position);

void remove_outliers(ARRAYPTR *ar, int *num_elements, DATA x);

void smooth_list(ARRAYPTR *ar, int *p_num_elements, int *capacity);

void Fillwithstuff(ARRAYPTR *thing, int *num_elements, int capacity, int thatint);

void addAfter(ARRAYPTR *array, int *p_num_elements, int *capacity, DATA data, int position);

int min(int one, int two);