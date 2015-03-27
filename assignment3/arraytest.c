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
#include <time.h>

/*Headers provided by the user*/
/* Example: #include "something.h" */
#include "array.h"

#define NUM_TESTS 1

int main(int argc, char *argv[]){
	ARRAYPTR ar;
	int capacity = 1000000000, numberofelements = 0;
	int i, i2, temp, testsdone = 0;
	clock_t start, end;
	double test_results[NUM_TESTS][8];
	int tests[NUM_TESTS] = {5000};
	ar = initArray(capacity);

	for(i2 = 0; i2 < NUM_TESTS; i++){

		Fillwithstuff(&ar, &numberofelements, capacity, tests[i2]);

		printf("Beginning \"Check the data in the middle\" test for %d.\n", tests[i2]);
		start = clock();

		temp = check(ar, numberofelements, tests[i2]);
		
		end = clock();
		test_results[i2][testsdone] = (double)end - start;
		printf("That test took %f\t\tClocks\nEnd test\n\n\n", test_results[i2][testsdone]);
		testsdone++;

		printf("Beginning \"Replace the data in the middle\" test for %d.\n", tests[i2]);
		start = clock();
		
		replace(ar, numberofelements, tests[i2]/2, tests[i2]/2);

		end = clock();
		test_results[i2][testsdone] = (double)end - start;
		printf("That test took %f\t\tClocks\nEnd test\n\n\n", test_results[i2][testsdone]);
		testsdone++;

		printf("Beginning \"Add an element at the start\" test for %d.\n", tests[i2]);
		start = clock();

		add(&ar, &numberofelements, &capacity, tests[i2]/2, 0);

		end = clock();
		test_results[i2][testsdone] = (double)end - start;
		printf("That test took %f\t\tClocks\nEnd test\n\n\n", test_results[i2][testsdone]);
		testsdone++;

		printf("Beginning \"Add an element at the middle\" test for %d.\n", tests[i2]);
		start = clock();

		add(&ar, &numberofelements, &capacity, tests[i2]/2, tests[i2]);
		
		end = clock();
		test_results[i2][testsdone] = (double)end - start;
		printf("That test took %f\t\tClocks\nEnd test\n\n\n", test_results[i2][testsdone]);
		testsdone++;

		printf("Beginning \"Remove an element at the start\" test for %d.\n", tests[i2]);
		start = clock();

		remove_(ar, &numberofelements, 0);
		
		end = clock();
		test_results[i2][testsdone] = (double)end - start;
		printf("That test took %f\t\tClocks\nEnd test\n\n\n", test_results[i2][testsdone]);
		testsdone++;

		printf("Beginning \"Remove an element at the middle\" test for %d.\n", tests[i2]);
		start = clock();

		remove_(ar, &numberofelements, tests[i2]/2);
		
		end = clock();
		test_results[i2][testsdone] = (double)end - start;
		printf("That test took %f\t\tClocks\nEnd test\n\n\n", test_results[i2][testsdone]);
		testsdone++;

		/*printf("Beginning \"Remove outliers\" test for %d.\n", tests[i2]);
		start = clock();

		remove_outliers(&ar, &numberofelements, min(RAND_MAX, tests[i2])/2);
		
		end = clock();
		test_results[i2][testsdone] = (double)end - start;
		printf("That test took %f\t\tClocks\nEnd test\n\n\n", test_results[i2][testsdone]);
		testsdone++;*/

		printf("Beginning \"Smooth list\" test for %d.\n", tests[i2]);
		start = clock();

		smooth_list(&ar, &numberofelements, &capacity);
		
		end = clock();
		test_results[i2][testsdone] = (double)end - start;
		printf("That test took %f\t\tClocks\nEnd test\n\n\n", test_results[i2][testsdone]);
		testsdone++;
	}

	return 0;
}