/*



The minimal path sum in the 5 by 5 matrix below, by starting in any cell in the left column and
finishing in any cell in the right column, and only moving up, down, and right, is indicated in
red and bold; the sum is equal to 994.

131 673 234* 103* 18*
201* 96* 342* 965 150
630 803 746 422 111
537 699 497 121 956
805 732 524 37 331

Find the minimal path sum, in matrix.txt (right click and "Save Link/Target As..."), a 31K text
file containing a 80 by 80 matrix, from the left column to the right column.
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
#define SIZE 5 //or 80 or 5 (matrix, smatrix)

int MIN(int x, int y){
	if (x < y)
		return x;
	else
		return y;
}

int MIN3(int x, int y, int z){
	if (x <= y && x <= z) 			return x;
	else if (y <= x && y <= z)	return y;
	else 												return z;
}



int main(){

	clock_t start = clock();

	int matrix[SIZE][SIZE] = {{}};

	FILE *data;
	data = fopen("Euler_81_smatrix2.txt", "r"); // read only, smatrix(5x5) or matrix(80x80)

	int number, row, col;
	//fscanf(data, "%d", &number );
	for (row=0; row < SIZE; row++)
		for (col = 0; col < SIZE; col++)
			if ( fscanf(data, "%d", &number ) == 1 ) matrix[row][col] = number;

	 //MATRIX PRINTOUT
	for (row=0; row<SIZE; row++){
      for(col=0; col<SIZE; col++){
      		printf("%4d   ", matrix[row][col]);
      }
      printf("\n\n");
  }

	/*

	 // TRY ONE :)
  int score[SIZE][SIZE] = {{}};
  for (int i = 0; i < SIZE; i++){
  	for (int j = 0; j <SIZE; j++){ //set initial scores to themselves
  		score[i][j] = matrix[i][j];
  	}
  }

	for (int j = SIZE - 2; j >= 1; j--){ //set top row scores leaving top right corner untouched
		score[0][j] += MIN(score[0][j + 1], score[1][j]);
	}
	for (int j = SIZE - 2; j >= 1; j--){ //set bottom row scores leaving bottom right corner untouched
		score[SIZE - 1][j] += MIN(score[SIZE - 1][j + 1], score[SIZE - 2][j]);
	}
	// for (int i = SIZE - 2; i >= 0; i--){ //set right column scores leaving corners untouched
		// score[i][SIZE - 1] = score[i][SIZE - 1] + score[i + 1][SIZE - 1];
	// }


  for (int i = SIZE - 2; i >= 1; i--){ //excluding bottom row and rightmost column
  	for (int j = SIZE - 2; j >= 1; j-- ){
  		score[i][j] += MIN3(score[i+1][j], score[i][j+1], score[i-1][j]);
			//score for given entry is itself + min[entry below , entry to right, entry above]
  	}
  }

	for (int i = 0; i < SIZE; i++){ //set first column scores to themselves + second row
		score[i][0] = score[i][0] + score[i][1];
	}
*/


//TRY TWO
	int score[SIZE][SIZE] = {{}};

	for (int i = 0; i < SIZE; i++){
		for (int j = 0; j <SIZE; j++){ //set initial scores to themselves
			score[i][j] = matrix[i][j];
		}
	}

	for (int i = SIZE - 1; i >= 1; i--){
  	for (int j = SIZE - 2; j >= 1; j-- ){

	//for (int j = 1; j <= SIZE - 2; j++){
	//	 for (int i = SIZE - 1; i >= 1; i-- ){

			//right row conditions
			if ( j == SIZE - 1 ){
				//do nothing
			}
			//bottom row condition
			if (i == SIZE - 1) 	score[SIZE - 1][j] += MIN(score[SIZE - 1][j + 1], score[SIZE - 2][j]);
			//top row condition
			if (i == 0)					score[0][j] += MIN(score[0][j + 1], score[1][j]);
			//left column condition
			if (j == 0){
				//do nothing
			}
			//score for given entry is itself + min[entry below , entry to right, entry above]
			else score[i][j] += MIN3(score[i+1][j], score[i][j+1], score[i-1][j]);
  	}
  }


	for (int i = 0; i < SIZE; i++){ //set first column scores to themselves + second row
		score[i][0] += score[i][1];
	}



	 //SCORE PRINTOUT
	 printf("\n\n");
  for (row=0; row<SIZE; row++) {
      for(col=0; col<SIZE; col++){
       	printf("%4d    ", score[row][col]);
      }
  	printf("\n\n");
  }

	// find lowest val on left column
	int smallest_i = 0;
	for (int i = 0; i < SIZE; i++){
		if (score[i][0] < score[smallest_i][0]) smallest_i = i;
	}
  printf("%d\n", score[smallest_i][0]);


	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
