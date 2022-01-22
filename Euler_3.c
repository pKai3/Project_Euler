/*
The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include <stdio.h>
#include <math.h>
#include <time.h>

int main(){

	clock_t start = clock();

	long top = 600851475143; //600851475143, 13195

	int prime = 2;
	int n = 2;

	while (prime <= sqrt(top)){
		n=2;
		while (n < prime){

			if (prime % n == 0 && n != prime)
				prime++;
			else
				n++;
		}

		if (top % prime == 0){

			printf("%d ", prime);

			clock_t end = clock();
			double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
			printf("found in %fs\n", time_spent);

		}

		prime++;

	}

}
