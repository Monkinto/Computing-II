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
#include "linkedlist.h"

int main(int argc, char *argv[]){
	LINKEDLISTPTR list = initLinkedList();
	int i;
	for(i = 0; i < 5; i++){
		add(list, i+1, i);
	}
	display(list, 5);
	replace(list, 3, 100);
	display(list, 5);
	remove_(list, 2);
	display(list, 5);
	printf("Is the list empty: %d\n", isEmpty(list));
	empty(list);
	display(list, 5);
	printf("Is the list empty: %d\n", isEmpty(list));
	destroy(list);
	return 0;
}