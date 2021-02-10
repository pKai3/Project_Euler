/*

Starting with 1 and spiralling anticlockwise in the following way, a square spiral with side length 7 is formed.

37 36 35 34 33 32 31
38 17 16 15 14 13 30
39 18  5  4  3 12 29
40 19  6  1  2 11 28
41 20  7  8  9 10 27
42 21 22 23 24 25 26
43 44 45 46 47 48 49

It is interesting to note that the odd squares lie along the bottom right diagonal, 
but what is more interesting is that 8 out of the 13 numbers lying along both diagonals are prime; 
that is, a ratio of 8/13 ≈ 62%.

If one complete new layer is wrapped around the spiral above, a square spiral with side length 9 will be formed. 
If this process is continued, what is the side length of the square spiral for which the ratio of primes 
along both diagonals first falls below 10%?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define SIZE 26241 //26241

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

int checkPrime(n){

	if (n == 1){
		return 0;
	}
    if (n == 2){
       return 1;
    }
    if (n == 3){
       return 1;
    }
    if (n % 2 == 0){
       return 0;
    }
    if (n % 3 == 0){
       return 0;
    }

    int i = 5;
    int w = 2;

    while (i * i <= n){
        if (n % i == 0){
           return 0;
        }

        i += w;
        w = 6 - w;

    }

    return (1);

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

	//(w1),r,u[1],l[2],d[2],r[2],(w2),r,u[3],l[4],d[4],r[4],(w3),r,u[5],l[6],d[6],r[6],(w4)

	//start; right(1), up(2w-1), left(w+1), down(w+1), right(w+1); w++

	grid[m][m] = 1;

	while (w <= (SIZE - 1)/2){
		right(1);
		up(2*w-1);
		left(2*w);
		down(2*w);
		right(2*w);
		w++;
	}	

	//for (entry = 0; entry <= 2; entry++){ //RIGHT
	//	grid[m][m+entry] = entry + 1;
	//}

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
	
	printf("now checking for primes\n");

	int primes = 0;

	for (col = 0; col < SIZE; col++){
		for (row = 0; row < SIZE; row++){
			if ( col == row || col + row == SIZE - 1 ){ //if entry on a diagonal
				primes += checkPrime(grid[col][row]);
			}

		}
	}

	double percent = 100 * (double)primes/(double)(SIZE*2 - 1);

	printf("\n\n%d, %f\n\n", primes, percent);

	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
