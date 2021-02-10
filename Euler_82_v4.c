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

#define SIZE 5 //or 80 or 5 or 3 (matrix, smatrix, ssmatrix)

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
	data = fopen("Euler_81_smatrix.txt", "r"); // read only, smatrix(5x5) or matrix(80x80)

	int number, row, col;
	for (row=0; row < SIZE; row++)
		for (col = 0; col < SIZE; col++)
			if ( fscanf(data, "%d", &number ) == 1 ) matrix[row][col] = number;

	 //MATRIX PRINTOUT
	for (row=0; row<SIZE; row++){
      for(col=0; col<SIZE; col++){
      		printf("%6d", matrix[row][col]);
      }
      printf("\n\n");
  }

  int score[SIZE][SIZE] = {{}};
	int score2[SIZE][SIZE] = {{}};

  for (int i = 0; i < SIZE; i++){
  	for (int j = 0; j <SIZE; j++){ //set initial scores to themselves
  		score[i][j] = matrix[i][j];
			score2[i][j] = matrix[i][j];
  	}
  }

	int Edge = SIZE - 1;
	int notEdge = SIZE - 2;


	for (int j = notEdge; j >= 1; j--){		//dont touch rightmost (and leftmost) column


		for (int i = Edge; i >=0; i--){ 		//do all rows INCREMENT UPWARDS
			if (i == Edge){
			score[i][j] += score[i][j+1];
			}
			else{
			score[i][j] += MIN(score[i+1][j], score[i][j+1]);
			}
			//score for given entry is itself + min[entry below , entry to right]
		}

		for (int i = 0; i <= Edge; i++){ 		//do all rows INCREMENT DOWNWARDS
			if (i == 0){
			score2[i][j] += score2[i][j+1];
			}
			else{
			score2[i][j] += MIN(score2[i-1][j], score2[i][j+1]);
			}
			//score for given entry is itself + min[entry above, entry to right]
		}

		// check which algorithym worked better on current column (lowest columnar sum)
		int u_lowest = 99999;
		int d_lowest = 99999;
		for (int i = 0; i <= Edge; i++){
			if (score[i][j] < u_lowest) u_lowest = score[i][j]; //score column
			if (score2[i][j] < d_lowest) d_lowest = score2[i][j]; //score column
		}

		if (d_lowest < u_lowest){	//set score column to score2 column if score2 is better
			for (int i = 0; i <= Edge; i++){
				score[i][j] = score2[i][j];
			}
		}

	}


	for (int i = 0; i < SIZE; i++){ //set first column scores to themselves + second row
		score[i][0] = score[i][0] + score[i][1];
		score2[i][0] = score2[i][0] + score2[i][1];
	}


	 //SCORE PRINTOUT
	 printf("\n\n");
  for (row=0; row<SIZE; row++) {
      for(col=0; col<SIZE; col++){
       	printf("%6d", score[row][col]);
      }
  	printf("\n\n");
  }


	 //SCORE2 PRINTOUT
	 printf("\n\n");
  for (row=0; row<SIZE; row++) {
      for(col=0; col<SIZE; col++){
       	printf("%6d", score2[row][col]);
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
