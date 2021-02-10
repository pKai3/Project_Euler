/*

In the 5 by 5 matrix below, the minimal path sum from the top left to the bottom right,
by only moving to the right and down, is indicated in bold red and is equal to 2427.

131* 673 234 103 18
201* 96* 342* 965 150
630 803 746* 422* 111
537 699 497 121* 956
805 732 524 37 331*

Find the minimal path sum, in matrix.txt (right click and "Save Link/Target As..."),
a 31K text file containing a 80 by 80 matrix, from the top left to the
bottom right by only moving right and down.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"
#define SIZE 5 //or 80 or 5

int MIN(int x, int y){
	if (x < y)
		return x;
	else
		return y;
}

int main(){

	clock_t start = clock();

	int matrix[SIZE][SIZE] = {{}};

	FILE *data;
	data = fopen("Euler_81_smatrix.txt", "r"); // read only, smatrix(5x5) or matrix(80x80)

	int number, row, col;
	//fscanf(data, "%d", &number );
	for (row=0; row < SIZE; row++)
		for (col = 0; col < SIZE; col++)
			if ( fscanf(data, "%d", &number ) == 1 ) matrix[row][col] = number;

	//MATRIX PRINTOUT
	for (row=0; row<SIZE; row++){
      for(col=0; col<SIZE; col++){
      		printf("%d   ", matrix[row][col]);
      }
      printf("\n\n");
  }

  int score[SIZE][SIZE] = {{}};

  for (int i = 0; i < SIZE; i++){
  	for (int j = 0; j <SIZE; j++){ //set initial scores to themselves
  		score[i][j] = matrix[i][j];
  	}
  }

	for (int j = SIZE - 2; j >= 0; j--){ //set bottom row scores leaving bottom corner untouched
		score[SIZE - 1][j] = score[SIZE - 1][j] + score[SIZE - 1][j + 1];
	}
	for (int i = SIZE - 2; i >= 0; i--){ //set right column scores leaving bottom corner untouched
		score[i][SIZE - 1] = score[i][SIZE - 1] + score[i + 1][SIZE - 1];
	}


  for (int i = SIZE - 2; i >= 0; i--){ //excluding bottom row and rightmost column
  	for (int j = SIZE - 2; j >= 0; j-- ){
  		score[i][j] += MIN(score[i+1][j], score[i][j+1]);
			//score for given entry is itself + min[entry below , entry to right]
  	}
  }

	//SCORE PRINTOUT
	printf("\n\n");
  for (row=0; row<SIZE; row++) {
      for(col=0; col<SIZE; col++){
       	printf("%4d    ", score[row][col]);
      }
  	printf("\n\n");
  }

  printf("%d\n", score[0][0]);


	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
