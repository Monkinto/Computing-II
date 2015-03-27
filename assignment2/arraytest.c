/**************************************************************************************************/
/* Programmer: Mike diBenedetto                                                                   */
/*                                                                                                */
/* Program assignment02: To Do list 2                                                             */
/*                                                                                                */
/* Approximate completion time: ... minutes                                                       */
/**************************************************************************************************/

/* Example: #inlcude <stdio.h> */
#include <stdio.h>
#include <stdlib.h>

/*Headers provided by the user*/
/* Example: #include "something.h" */
#include "array.h"

int main(int argc, char *argv[]){
	ARRAYPTR ar;
	int capacity = 100, numberofelements = 0;
	int i, temp;
	ar = initArray(capacity);
	for(i = 0; i < 5; i++){
		add(&ar, &numberofelements, &capacity, i+1, i);
	}
	display(ar, numberofelements);
	replace(ar, numberofelements, 3, 15);
	display(ar, numberofelements);
	temp = check(ar, numberofelements, 2);
	printf("temp = %d\n", temp);
	remove_(ar, &numberofelements, 1);
	display(ar, numberofelements);
	printf("Array is empty: %d\n", isEmpty(ar, &numberofelements));
	empty(ar, &numberofelements);
	printf("Array is empty: %d\n", isEmpty(ar, &numberofelements));
	destroy(ar, numberofelements);
	return 0;
}