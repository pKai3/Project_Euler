/*
By starting at the top of the triangle below and moving to adjacent numbers on the row below, the maximum total from top to bottom is 23.

3
7 4
2 4 6
8 5 9 3

That is, 3 + 7 + 4 + 9 = 23.

Find the maximum total from top to bottom in triangle.txt (right click and 'Save Link/Target As...'), a 15K text file containing a triangle with one-hundred rows.

NOTE: This is a much more difficult version of Problem 18. It is not possible to try every route to solve this problem, as there are 299 altogether! If you could check one trillion (1012) routes every second it would take over twenty billion years to check them all. There is an efficient algorithm to solve it. ;o)
*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

//#define MAX(x, y) (((x) > (y)) ? (x) : (y))

int MAX(int x, int y){
	if (x > y)
		return x;
	else
		return y;
}

int main()
{
	clock_t start = clock();

	int triangle[100][100] = {{}};

	FILE *data;
	data = fopen("Euler_67_triangle.txt", "r"); // read only

	int number;
	//fscanf(data, "%d", &number );
	for (int i=0; i < 100; i++)
		for (int j = 0; j <= i; j++)
			if ( fscanf(data, "%d", &number ) == 1 ) triangle[i][j] = number;


	char option[100][100] = {{}};

	for (int i=0; i < 100; i++)
		for (int j = 0; j <= i; j++){

			if  (triangle[i+1][j] > triangle[i+1][j+1])
				option[i][j] = 'd';
			else
				option[i][j] = 'r';
		}


	int row;
	int col;

    for (row=0; row<100; row++) {
        for(col=0; col<=row; col++){
        	if (triangle[row][col] > 75)
         		printf("%s%2d    ", KRED, triangle[row][col]);

        	if (50 < triangle[row][col] && triangle[row][col] <= 75)
         		printf("%s%2d    ", KMAG, triangle[row][col]);

        	if (25 < triangle[row][col] && triangle[row][col] <= 50)
         		printf("%s%2d    ", KCYN, triangle[row][col]);

        	if (0 <= triangle[row][col] && triangle[row][col] <= 25)
         		printf("%s%2d    ", KWHT, triangle[row][col]);
         }

        printf("\n\n");
    }

    for (row=0; row<100; row++) {
        for(col=0; col<=row; col++){
         	printf("%c    ", option[row][col]);
        }
    	printf("\n\n");
    }
	printf("\n\n");

//SCORE FOR A GIVEN ENTRY IS ITSELF + THE MAX OF THE TWO ENTRIES BELOW

    int score[100][100] = {{}};

    for (int i = 0; i < 100; i++){
    	for (int j = 0; j <= i; j++){ //set initial scores to themselves
    		score[i][j] = triangle[i][j];
    	}
    }
    //printf("%d\n", score[14][3]);

    for (int i = 98; i >= 0; i--){
    	for (int j = 0; j <= i; j++ ){
    		score[i][j] += MAX(score[i+1][j], score[i+1][j+1]);
    	}
    }

    for (row=0; row<100; row++) {
        for(col=0; col<=row; col++){
         	printf("%4d    ", score[row][col]);
        }
    	printf("\n\n");
    }
    printf("%d\n", score[0][0]);

    clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

    return 0;
}
