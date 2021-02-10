#include <stdio.h>
#include <stdlib.h>

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
	int triangle[15][15] = {{}};

	FILE *data;
	data = fopen("Euler_18_triangle.txt", "r"); // read only

	int number;
	//fscanf(data, "%d", &number );
	for (int i=0; i < 15; i++)
		for (int j = 0; j <= i; j++)
			if ( fscanf(data, "%d", &number ) == 1 ) triangle[i][j] = number;


	char option[15][15] = {{}};

	for (int i=0; i < 15; i++)
		for (int j = 0; j <= i; j++){

			if  (triangle[i+1][j] > triangle[i+1][j+1])
				option[i][j] = 'd';
			else
				option[i][j] = 'r';
		}


	int row;
	int col;

    for (row=0; row<15; row++) {
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

    for (row=0; row<15; row++) {
        for(col=0; col<=row; col++){
         	printf("%c    ", option[row][col]);
        }
    	printf("\n\n");
    }
	printf("\n\n");

//SCORE FOR A GIVEN ENTRY IS ITSELF + THE MAX OF THE TWO ENTRIES BELOW

    int score[15][15] = {{}};
    for (int i = 0; i < 15; i++){
    	for (int j = 0; j <= i; j++){ //set bottom row scores to themselves
    		score[i][j] = triangle[i][j];
    	}
    }
    //printf("%d\n", score[14][3]);

    for (int i = 13; i >= 0; i--){
    	for (int j = 0; j <= i; j++ ){
    		score[i][j] += MAX(score[i+1][j], score[i+1][j+1]);
    	}
    }

    for (row=0; row<15; row++) {
        for(col=0; col<=row; col++){
         	printf("%4d    ", score[row][col]);
        }
    	printf("\n\n");
    }
    printf("%d\n", score[0][0]);
    /*
    printf("%sred\n", KRED);
    printf("%sgreen\n", KGRN);
    printf("%syellow\n", KYEL);
    printf("%sblue\n", KBLU);
    printf("%smagenta\n", KMAG);
    printf("%scyan\n", KCYN);
    printf("%swhite\n", KWHT);
    printf("%snormal\n", KNRM);
	*/
    return 0;
}
