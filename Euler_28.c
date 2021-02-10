/*

Starting with the number 1 and moving to the right in a clockwise direction a 5 by 5 spiral is formed as follows:

21 22 23 24 25
20  7  8  9 10
19  6  1  2 11
18  5  4  3 12
17 16 15 14 13

It can be verified that the sum of the numbers on the diagonals is 101.

What is the sum of the numbers on the diagonals in a 1001 by 1001 spiral formed in the same way?

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 1001

int entry = 1;

int grid[SIZE][SIZE];

int curr_i;
int curr_k;

void right(int x){

	for (int i = 1; i <= x; i++){
		curr_k++;
		entry++;

		grid[curr_i][curr_k] = entry;
	}
}

void up(int x){

	for (int i = 1; i <= x; i++){
		curr_i--;
		entry++;

		grid[curr_i][curr_k] = entry;
	}
}

void left(int x){

	for (int i = 1; i <= x; i++){
		curr_k--;
		entry++;
		
		grid[curr_i][curr_k] = entry;
	}
}

void down(int x){

	for (int i = 1; i <= x; i++){
		curr_i++;
		entry++;

		grid[curr_i][curr_k] = entry;
	}
}

int main()
{
	clock_t start = clock();

	int m = (SIZE - 1)/2;

	printf("generating grid size %dx%d\n", SIZE, SIZE);

	int col, row;
	for(col=0;col<SIZE;col++){ //Initialize to zero
    	for(row=0;row<SIZE;row++){
        	grid[col][row] = 0;
    	}
	}

	curr_i = m;
	curr_k = m;

	int w = 1;
	grid[m][m] = 1;

	while (w <= (SIZE - 1)/2){
		right(1);
		down(2*w-1);
		left(2*w);
		up(2*w);
		right(2*w);
		w++;
	}	
	/*
	for(col=0;col<SIZE;col++){ //PRINTOUT
    	for(row=0;row<SIZE;row++){
    		if (grid[col][row] / 10 < 1){ //IF SINGLE DIGIT PRINT SPACE TO JUSTIFY
    			printf("  ");
    		}

    		else if (grid[col][row] / 100 < 1){
    			printf(" ");
    		} 
        	printf(" %d ", grid[col][row]);
    	}
    printf("\n\n");
    }
*/

	int sum = 0;

	for (col = 0; col < SIZE; col++){
		for (row = 0; row < SIZE; row++){
			if ( col == row || col + row == SIZE - 1 ){ //if entry on a diagonal
				sum += grid[col][row];
			}

		}
	}
	
	printf("\n\nsum of diagonal entries: %d\n\n", sum);

	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
