/*

The number 145 is well known for the property that
the sum of the factorial of its digits is equal to 145:

1! + 4! + 5! = 1 + 24 + 120 = 145

Perhaps less well known is 169, in that it produces the
longest chain of numbers that link back to 169; it turns
out that there are only three such loops that exist:

169 → 363601 → 1454 → 169
871 → 45361 → 871
872 → 45362 → 872

It is not difficult to prove that EVERY starting number
will eventually get stuck in a loop. For example,

69 → 363600 → 1454 → 169 → 363601 (→ 1454)
78 → 45360 → 871 → 45361 (→ 871)
540 → 145 (→ 145)

Starting with 69 produces a chain of five non-repeating
terms, but the longest non-repeating chain with a starting
number below one million is sixty terms.

How many chains, with a starting number below one million,

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int factorial(int n){
	int fac = 1;
	while (n > 1){
		fac = fac*n;
		n--;
	}
	return fac;
}

int chain(int n){

	char n_s[10];

	sprintf(n_s, "%d", n);

	int sum = 0;
	int digit = 0;
	int fac = 1;

	for (int i = 0; i <strlen(n_s); i++){

		digit = n_s[i] - '0';

		sum += factorial(digit);

	}
	return sum;
}

int main(){

	clock_t start = clock();

	int record[100];

	int n = 69;

	int count = 0;

	for (n = 2; n < 1000000; n++){

		memset(record, 0, sizeof(record));

		int i = 0;
		record[i] = n; //first entry in record is n
		i++;


		int temp = chain(n);
		record[i] = temp;
		i++;

		int a, b;

		while (1){
			temp = chain(temp);
			record[i] = temp;
			i++;

			for (a = 0; a < 100; a++){
				for (b = a+1; b < 100; b++){

					if ( record[a] == record[b] && record[a] != 0 ){
						goto found;
					}

				}
			}

		}

		found:

		//if (n % 10000 == 0) printf("*\n");

		if (n % 10000 == 0){ // PRINTOUT / DEBUGGING
			printf("example printout:\n");
			for (int p = 0; p < 100; p++){

				if (record[p] != 0){
					printf("%d", record[p]);
					if (p == a) printf("***\n");
					else				printf("\n");
				}

			}
			printf("------\n%d non repeating units\n\n\n", b);

		}

		if (b == 60) count++;

	}

	printf("\n\n%d chains with 60 non-repeating terms found\n\n", count);

	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
