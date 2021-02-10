/*

The following iterative sequence is defined for the set of positive integers:

n → n/2 (n is even)
n → 3n + 1 (n is odd)

Using the rule above and starting with 13, we generate the following sequence:

13 → 40 → 20 → 10 → 5 → 16 → 8 → 4 → 2 → 1
It can be seen that this sequence (starting at 13 and finishing at 1) contains 10 terms. Although it has not been proved yet (Collatz Problem), it is thought that all starting numbers finish at 1.

Which starting number, under one million, produces the longest chain?

NOTE: Once the chain starts the terms are allowed to go above one million.
*/

#include <stdio.h>

int main()
{

	long term = 0;
	int n = 0;

	long start = 0;
	int largest_start = 0;
	int most_terms = 0;

	for (start = 1000000; start >= 2; start--){

		term = start;
		n = 1;

		while (term != 1){


			if (term % 2 == 0){
				term = term/2;
				n = n + 1;
				//printf("%d\n", term);

			}

			else{

				term = 3 * term + 1;
				n = n + 1;
				//printf("%d\n", term);

			}

		}

		if (n > most_terms){
			most_terms = n;
			largest_start = start;

			printf("%ld had %d terms \n", start, n);

		}


	}

}
