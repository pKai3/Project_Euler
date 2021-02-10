/*

The number, 197, is called a circular prime because all rotations of the digits: 197, 971, and 719, are themselves prime.

There are thirteen such primes below 100: 2, 3, 5, 7, 11, 13, 17, 31, 37, 71, 73, 79, and 97.

How many circular primes are there below one million?

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	int n, c, t, p;

	t = 1000000;

	c = 0;
	p = 0;
	n = 2;

	int x = 0;
	int z = 0;
	int k = 0;
	
	int cprime = 0;

	char prime[10];

	int i = 0;

	for (i = 0; i <= 9; i++){
		prime[i] = '\0';
	}

	while (n <= t) 
	{

		for (c = 2; c <= n; c++)
		{
			if (n % c == 0)
				break;
		}

		if (c == n) 
		{

			printf("%d: [", n);

			sprintf(prime, "%d", n); //convert to str

			//printf("; strlen: %lu", strlen(prime));

			//printf("%s\n", prime);

			k = 1;

			for (x = 1; x < strlen(prime); x++){ //do x times where x is number of digits

				prime[strlen(prime)] = prime[0]; //first digit appended at end

				for (z = 1; z <= strlen(prime); z++){ //shift all left one

					prime [z - 1] = prime[z];
					
					//printf("; strlen: %lu\n", strlen(prime));

					//printf("%s\n", prime);

				//cprime = atoi(prime); //convert back to int
				//printf("cprime: %d\n", cprime);


				}

				//prime[strlen(prime)] = '\0'; //re-append null character at end of string

				cprime = atoi(prime); //convert back to int
				printf(" %d ", cprime);

				for (c = 2; c <= cprime; c++){ //recheck if prime
					
					if (cprime % c == 0)
					break;
				}

				if (c == cprime){ //if prime, k++
					k++;
				}

			}

			if (k == strlen(prime) ){ //if all permutations were prime

				p++;
				printf("]\n");

			}

			else {
				fpurge(stdout);
				}


			//printf("%d, %d \n", n, p);
		}

	n++;

	}

	printf("%d\n", p);

}