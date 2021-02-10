/*

The proper divisors of a number are all the divisors excluding the number itself.
For example, the proper divisors of 28 are 1, 2, 4, 7, and 14. As the sum of these
divisors is equal to 28, we call it a perfect number.

Interestingly the sum of the proper divisors of 220 is 284 and the sum of the proper
divisors of 284 is 220, forming a chain of two numbers. For this reason, 220 and 284 are called an amicable pair.

Perhaps less well known are longer chains. For example, starting with 12496, we form a chain of five numbers:

12496 → 14288 → 15472 → 14536 → 14264 (→ 12496 → ...)

Since this chain returns to its starting point, it is called an amicable chain.

Find the smallest member of the longest amicable chain with no element exceeding one million.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


long lookup[1000000];
long factors[100];
int  pows[100];

unsigned long long expp(long base, long exponent){

	int result = 1;

	while (exponent != 0){

		result *= base;
		exponent--;
	}

	return result;

}

long wheel(long n) {

	memset(factors, 0, sizeof(factors));
	// memset(pows, 0, sizeof(pows));
	for (int m = 0; m < 100; m++){ //memwipe
		pows[m] = 1;
	}
	long ws[] = {1,2,2,4,2,4,2,4,6,2,6};
	long f = 2; int w = 0;
	int i = 0;
	int j = 0;

	while (f * f <= n) {
		if (n % f == 0) {
			// printf("%ld\n", f);

			if (f != factors[i-1]){
			  factors[i] = f; i++; //if distinct factor, new entry.
			}
			else{
			  pows[i-1] += 1; //increment exponent
			}

			n /= f;
		} else {
			f += ws[w];
			w = (w == 10) ? 3 : (w+1);
		}
	}
	// printf("%ld\n", n);
	if (n != factors[i-1]){
	  factors[i] = n; i++; //if distinct factor, new entry.
	}
	else{
	  pows[i-1] += 1; //increment exponent
	}
	return 0;
}

void findAllSums(){

	int n;

	clock_t start = clock();

	printf("generating all divSums under 10^6\n");

	lookup[0] = 0;
	lookup[1] = 1;

	for (n = 2; n < 1000000; n++){

		if (n % 100000 == 0) printf("*\n");

		wheel(n);
		int i = 0;
	// while (factors[i] != 0 ){
	//   // printf("%ld^%d\n", factors[i], pows[i]);
		// 	i++;
	// }

	// unsigned long long mult = 1;
	// i = 0;
	// while (factors[i] != 0){ //for each base (distinct factor)
	//   // printf("*%ld\n", ( (expp(factors[i], pows[i] + 1) - 1) / (factors[i] - 1) ));
	//   mult *= ( (expp(factors[i], pows[i] + 1) - 1) / (factors[i] - 1) );
	//   i++;
	// }

		unsigned long long  mult = 1;
		long sum = 0;
		int pow = 0;
		i = 0;

		while (factors[i] != 0){
			sum = 0;
			pow = 0;
			while (pow <= pows[i]){
				sum += expp(factors[i], pow);
				pow++;
			}
			mult *= sum;
			i++;
		}
		lookup[n] = mult - n;

  // printf("%d\n", mult);
	}


	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found all divSums under 10^6 in %fs\n", time_spent);

}

int main(){

	findAllSums();

	clock_t start = clock();

	long record[1000];

	int n;

	int longest = 0;
	int longest_n = 0;
	int smallest_term = 999999;

	for (n = 2; n < 1000000; n++){

		memset(record, 0, sizeof(record));

	record[0] = n; //n , 12496

	int i = 1;
	int a, b, broken;

	while(1){ //record
		record[i] = lookup[record[i-1]];
		i++;

		// for (int p = 0; p < 1000; p++){ //debug printout
		//
		// 	if (record[p] != 0){
		// 		printf("%ld\n", record[p]);
		// 	}
		//
		// }

		if (record[i-1] > 1000000){
			broken = 1;
			goto found;
		}

		for (a = 0; a < 1000; a++){ //search for repeat

			if (record[a] == 0) break;
			//found last entry without finding repeat, break and continue adding to chain

			for (b = a+1; b < 1000; b++){

				if ( record[a] == record[b] && record[a] != 0 ){ //if found repeat
					goto found;
				}

			}
		}

	}

	found://go here

	if (record[b] == record[b-1] || broken == 1){ //kill if wasnt a chain
		b = 0;
		broken = 0;
	}

	if (b-a >= longest){ //FOUND NEW LONGEST CHAIN
		longest = b-a;
		longest_n = n;


		//PREVIOUS SMALLEST TERM INVALID, CHECK AGAIN
		smallest_term = 999999;
		for (int z = a; z < 1000; z++){ //find smallest term in valid range !!!!STARTING AT record[a]
			if (record[z] < smallest_term && record[z] != 0){
				smallest_term = record[z];
			}
		}

		printf("new chain >= last, checking for lowest value:\n");
		for (int p = 0; p < 1000; p++){

			if (p == a) printf("--*--*--\n");

			if (record[p] != 0){
				printf("%ld\n", record[p]);
			}

		}

		printf("--*--*--\nchain length : %d\nsmallest term: %d\n\n", b-a, smallest_term);

	}

	if (n % 10000 == 0) printf("*\n");

}
printf("\n\nlongest chain: %d\nstarting value: %d\nsmallest term: %d\n\n",
	longest, longest_n, smallest_term);

clock_t end = clock();
double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
printf("found in %fs\n", time_spent);
}
