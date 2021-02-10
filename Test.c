/*

PASTE QUESTION HERE

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main(){

	clock_t start = clock();

	int x, i;
	i = 2;

	// for (int i = 0; i < 6; ++i) {

		x = ++i;
    printf("%d\n", x) ;

		x = i++;
		printf("%d\n", x) ;

		printf("%d\n", i) ;

	  // printf("%d\n", i);
	// }


	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
