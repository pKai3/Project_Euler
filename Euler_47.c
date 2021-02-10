/*

The first two consecutive numbers to have two distinct prime factors are:

14 = 2 × 7
15 = 3 × 5

The first three consecutive numbers to have three distinct prime factors are:

644 = 2² × 7 × 23
645 = 3 × 5 × 43
646 = 2 × 17 × 19.

Find the first four consecutive integers to have four distinct prime factors each. 
What is the first of these numbers?
*/

#include <stdio.h>

int target = 4;

int consecutive = 0;

int n = 2;
int div = 0;
int prime = 0;
int pfac = 0;

int main()
{

	while (consecutive < target && n < 134043 + 5){

		div = 2;
		while (pfac < target && div <= n){

			printf("\n%d\n", n);

			for ( /*div*/; div <= n; div++){ //find divisors
				if (n % div == 0) {
					printf("/%d\n",div);
				for (prime = 2; prime <= div; prime++){ //check if divisor is prime factor (can be div/2??)
					if (div % prime == 0){
						break;
					}
				}

				if (div == prime){ //div is prime factor, increment div to check for next divisor
					pfac ++;
					printf("*\n");

					div ++;
				}

				else{ //keep searching for pfacs
					div ++;
				}

			}


			}

		}

		n++;

		if (pfac == target){
			pfac = 0;
			consecutive++;
			printf("conseq\n");
		}

		else{
			pfac = 0;
			consecutive = 0;
			printf("notconseq\n");
		}

	}


}
