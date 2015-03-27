/**************************************************************************************************/
/* Programmer: Mike diBenedetto                                                                   */
/*                                                                                                */
/* Program assignment02: To Do list 2                                                             */
/*                                                                                                */
/* Approximate completion time: ... minutes                                                       */
/**************************************************************************************************/

/*Headers provided by C*/
/* Example: #inlcude <stdio.h> */
#include <stdio.h>
#include <stdlib.h>

/*Headers provided by the user*/
/* Example: #include "something.h" */
#include "array.h"

//Allocates dynamic memory for the array, returns a pointer to it
ARRAYPTR initArray(int capacity){
	ARRAYPTR temp = malloc(sizeof(DATA) * capacity);
	if(temp == NULL){
		printf("Ran out of memory!");
	}
	return temp;
}

//returns the data in the array at the given position
DATA check(ARRAYPTR ar, int num_elements, int position){
	return ar[position];
}

//Replaces the data in the array at the given position
void replace(ARRAYPTR ar, int num_elements, int position, DATA data){
	if(position < num_elements && position >= 0){
		ar[position] = data;
	}
}

//Displays all the data in the array
void display(ARRAYPTR ar, int num_elements){
	int i;
	for(i = 0; i < num_elements; i++){
		printf("%d:\t%d\n", i, ar[i]);
	}
}

//Inserts the data in the array at the given position, shifts backward all the subsequent elements
void add(ARRAYPTR *ar, int *p_num_elements, int *capacity, DATA data , int position){
	int i;
	DATA temp;
	if(*p_num_elements+1 > *capacity){
		*capacity += 1;
		*ar = (ARRAYPTR)realloc(*ar, sizeof(DATA) * *capacity);
	}
	if(*p_num_elements > 0){
		for(i = *p_num_elements; i >= position; i--){
			ar[0][i+1] = ar[0][i];
		}
	}
	ar[0][position] = data;
	*p_num_elements += 1;
}

//If the array is not empty, removes the data in the array at the given position, shifts forward all the subsequent elements
void remove_(ARRAYPTR ar, int *p_num_elements, int position){
	int i;
	if(*p_num_elements == 0 || *p_num_elements < position){
		return;
	} else {
		for(i = position; i < *p_num_elements; i++){
			ar[i] = ar[i+1];
		}
		*p_num_elements -= 1;
	}
}

//Removes all the elements in the array
void empty(ARRAYPTR ar, int *p_num_elements){
	*p_num_elements = 0;
}

//Checks whether the array has 0 elements, returns 1 if yes, 0 otherwise
int isEmpty(ARRAYPTR ar, int *p_num_elements){
	if(*p_num_elements == 0){
		return 1;
	} else {
		return 0;
	}
}

//Checks if an array is empty, if it is - frees the dynamic memory allocated for the array, returns a NULL pointer to it
ARRAYPTR destroy(ARRAYPTR ar, int num_elements){
	if(num_elements == 0){
		printf("Array destroyed!\n");
		free(ar);
		return NULL;
	} else {
		return ar;
	}
}

void addAfter(ARRAYPTR *array, int *p_num_elements, int *capacity, DATA data, int position){
    (*p_num_elements)++;
    int holder = *p_num_elements;
     
    int i;
    if (holder > *capacity){
        *capacity *= 2;
        *array = realloc(*array, sizeof(DATA) * holder);
    }
 
    for (i = holder - 1; i > position; i--){
            array[0][i + 1] = array[0][i];
    }
    array[0][position + 1] = data;
}

void removeAtStart(ARRAYPTR *array, int *p_num_elements){
    (*p_num_elements)--;
    int holder = *p_num_elements;
    int i;
    for (i = 0; i < holder; ++i){
        array[0][i] = array[0][i + 1];
    }
}
 
 
void removeAfter(ARRAYPTR *array, int *p_num_elements, int position){
    (*p_num_elements)--;
    int holder = *p_num_elements;
    int i;
    for (i = position; i < holder; ++i){
        array[0][i] = array[0][i + 1];
    }
}

void remove_outliers(ARRAYPTR *ar, int *p_num_elements, DATA x){
	int i;
    for (i = 0; i < *p_num_elements; ++i){
        if (ar[0][i] > x){
            removeAfter(ar, p_num_elements, i);
            i--;
        }
    }
}

void smooth_list(ARRAYPTR *ar, int *p_num_elements, int *capacity){
    int i;
    if (*p_num_elements < 1){
        return;
    }
    if (*capacity < ((*p_num_elements) * 2)){

        *capacity *= 2;
        *ar = realloc(*ar, sizeof(DATA) * (*capacity));
    }
 
    int temp;
    for (i = 0; i < *p_num_elements; i += 2){
        temp = (ar[0][i] + ar[0][i + 1])/2;
        addAfter(ar, p_num_elements, capacity, temp, i);
    }
}

void Fillwithstuff(ARRAYPTR *thing, int *num_elements, int capacity, int thatint){
    int i;
    for (i = 0; i < capacity; ++i)
    {
        int r = rand() % min(RAND_MAX, thatint);
        thing[0][i] = r;
        (*num_elements)++;
    }
}

int min(int one, int two){
	if(one < two){
		return one;
	} else {
		return two;
	}
}