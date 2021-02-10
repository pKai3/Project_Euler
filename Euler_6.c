/*
The sum of the squares of the first ten natural numbers is,

1^2 + 2^2 + ... + 10^2 = 385
The square of the sum of the first ten natural numbers is,

(1 + 2 + ... + 10)^2 = 55^2 = 3025
Hence the difference between the sum of the squares of the first ten natural numbers and the square of the sum is 3025 − 385 = 2640.

Find the difference between the sum of the squares of the first one hundred natural numbers and the square of the sum.
*/

#include <stdio.h>

int t = 100;

int asum = 0;
int bsum = 0;
int diff = 0;

int i = 0;
int j = 0;


int main(){

	for (i = 0; i <= t; i++){

		asum = asum + i*i;
		//printf("%d\n",i*i);

	}

	for (j = 0; j <= t; j++){

		bsum = bsum + j;
		//printf("%d\n",bsum);


	}

	bsum = bsum * bsum;

	diff = bsum - asum;

	printf("%d\n", diff);

}