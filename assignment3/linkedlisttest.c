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
#include <time.h>

/*Headers provided by the user*/
/* Example: #include "something.h" */
#include "linkedlist.h"

#define NUM_TESTS 1

int min(int one, int two){
	if(one < two){
		return one;
	} else {
		return two;
	}
}

int main(int argc, char *argv[]){
	LINKEDLISTPTR list = initLinkedList();
	int i, i2, temp, testsdone = 0;
	clock_t start, end;
	double test_results[NUM_TESTS][8];
	int tests[NUM_TESTS] = {100000};

	for(i2 = 0; i2 < NUM_TESTS; i2++){
		printf("Creating Linked List of size %d for testing.\n", tests[i2]);
		printf("Beginning to add items to Linked List.\n");
		for(i = 0; i < tests[i2]; i++){
			add(list, (rand () % min(RAND_MAX, tests[i2])), i);
		}
		printf("Finished Adding Items to Linked List.\n");

		printf("Beginning \"Check the data in the middle\" test for %d.\n", tests[i2]);
		start = clock();

		temp = check(list, tests[i2]/2);
		
		end = clock();
		test_results[i2][testsdone] = (double)end - start;
		printf("That test took %f\t\tClocks\nEnd test\n\n\n", test_results[i2][testsdone]);
		testsdone++;

		printf("Beginning \"Replace the data in the middle\" test for %d.\n", tests[i2]);
		start = clock();
		
		replace(list, tests[i2]/2, tests[i2]/2);
		
		end = clock();
		test_results[i2][testsdone] = (double)end - start;
		printf("That test took %f\t\tClocks\nEnd test\n\n\n", test_results[i2][testsdone]);
		testsdone++;

		printf("Beginning \"Add an element at the start\" test for %d.\n", tests[i2]);
		start = clock();

		add(list, tests[i2]/2, 0);

		end = clock();
		test_results[i2][testsdone] = (double)end - start;
		printf("That test took %f\t\tClocks\nEnd test\n\n\n", test_results[i2][testsdone]);
		testsdone++;

		printf("Beginning \"Add an element at the middle\" test for %d.\n", tests[i2]);
		start = clock();

		add(list, tests[i2]/2, tests[i2]/2);
		
		end = clock();
		test_results[i2][testsdone] = (double)end - start;
		printf("That test took %f\t\tClocks\nEnd test\n\n\n", test_results[i2][testsdone]);
		testsdone++;

		printf("Beginning \"Remove an element at the start\" test for %d.\n", tests[i2]);
		start = clock();

		remove_(list, 0);
		
		end = clock();
		test_results[i2][testsdone] = (double)end - start;
		printf("That test took %f\t\tClocks\nEnd test\n\n\n", test_results[i2][testsdone]);
		testsdone++;

		printf("Beginning \"Remove an element at the middle\" test for %d.\n", tests[i2]);
		start = clock();

		remove_(list, tests[i2]/2);
		
		end = clock();
		test_results[i2][testsdone] = (double)end - start;
		printf("That test took %f\t\tClocks\nEnd test\n\n\n", test_results[i2][testsdone]);
		testsdone++;

		printf("Beginning \"Remove outliers\" test for %d.\n", tests[i2]);
		start = clock();

		remove_outliers(list, min(RAND_MAX, tests[i2])/2);
		
		end = clock();
		test_results[i2][testsdone] = (double)end - start;
		printf("That test took %f\t\tClocks\nEnd test\n\n\n", test_results[i2][testsdone]);
		testsdone++;

		printf("Beginning \"Smooth list\" test for %d.\n", tests[i2]);
		start = clock();

		smooth_list(list);
		
		end = clock();
		test_results[i2][testsdone] = (double)end - start;
		printf("That test took %f\t\tClocks\nEnd test\n\n\n", test_results[i2][testsdone]);
		testsdone++;

		empty(list);
	}
	return 0;
}