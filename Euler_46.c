/*

It was proposed by Christian Goldbach that every odd composite number can be written
as the sum of a prime and twice a square.

9 = 7 + 2×1^2
15 = 7 + 2×2^2
21 = 3 + 2×3^2
25 = 7 + 2×3^2
27 = 19 + 2×2^2
33 = 31 + 2×1^2

It turns out that the conjecture was false.

What is the smallest odd composite that cannot be written as the sum of a prime and twice a square?
*/

#include <stdio.h>
#include <math.h>
#include <time.h>

int main()
{

/*
find composites
{for n, find first prime factor, divide n by factor, repeat until n is 1}
{if cannot reduce to 1, go to next number (n++)}

find components of given composite
{start with largest found prime factor}

clock_t start = clock();

here, do your time-consuming job

clock_t end = clock();
double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;

*/

	clock_t start = clock();

	int n = 2;
	int c = 0;
	int s = 0;
	int k = 0;

	int foundans = 0;

	while (n < 50000){

		if (n % 2 != 0){ //only odd composite numbers

			for (c = 2; c <= n; c++){
					if (n % c == 0){
						break;
					}
			}

			if (c == n){
				//printf("(%d) prime\n", n);
			}

			else{
				printf("\n[%d] ", n);

				for (k = n - 1; k > 1; k--){ 	//start with k one less than n, find largest prime less than n
					for (c = 2; c <= k; c++){	//check if prime
						if (k % c == 0){
							break;
						}
					}

					if (c == k){				//k is prime, check to see if can make k + 2*square == n

							//printf("*%d\n",c);

							for (s = 1; s <= sqrt( (n-k)/2 ); s++){ //find s such that k + 2s^2 = n

								if ( (k + 2*s*s)  == n ){
									printf("= %d + 2*%d^2\n", k , s);
									//foundans = 1;
									goto yeet;						//if found goto incrememnt n
								}


							}

					}
					
					//else not prime, or nested loop failed: decremement k and try again

				}

				goto sadreac; //no solution found for current n

			}

		}

		yeet:

		n++;

	}

	sadreac:
	printf("is non-compliant\n");
	
	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
