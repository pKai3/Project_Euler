/*

Comparing two numbers written in index form like 211 and 37 is not difficult, as any calculator would confirm that 211 = 2048 < 37 = 2187.

However, confirming that 632382518061 > 519432525806 would be much more difficult, as both numbers contain over three million digits.

Using base_exp.txt (right click and 'Save Link/Target As...'), a 22K text file containing one thousand lines with a base/exponent pair on each line, determine which line number has the greatest numerical value.

NOTE: The first two lines in the file represent the numbers in the example given above.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

unsigned long long values[1000][2] = {{}};
long double results[1000] = {};

void readFile(){

	FILE *data;
	data = fopen("Euler_99_base_exp.txt", "r");

	unsigned long long number;
	int row, col;
	//fscanf(data, "%d", &number );
	for (row=0; row < 1000; row++)
		for (col = 0; col < 2; col++)
			if ( fscanf(data, "%llu", &number ) == 1 ) values[row][col] = number;


	// for (row=0; row<1000; row++){
  //     for(col=0; col<2; col++){
  //     		printf("%llu   ", values[row][col]);
  //     }
  //     printf("\n\n");
  // }
}

int main(){

	clock_t start = clock();

	readFile();

	for (int i = 0; i < 1000; i++){
		results[i] = logl(values[i][0]) * values[i][1];
	}

	int largest_index = 0;
	long double largest_result = 0;

	for (int i = 0; i < 1000; i++){
		if (results[i] > largest_result){
			largest_result = results[i];
			largest_index = i+1;
			printf("%d, %Lf\n", largest_index, largest_result);
		}
	}

	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
