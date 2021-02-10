/*

A number chain is created by continuously adding the square of the digits in a number to form a new number until it has been seen before.

For example,

44 → 32 → 13 → 10 → 1 → 1
85 → 89 → 145 → 42 → 20 → 4 → 16 → 37 → 58 → 89

Therefore any chain that arrives at 1 or 89 will become stuck in an endless loop. 
What is most amazing is that EVERY starting number will eventually arrive at 1 or 89.

How many starting numbers below ten million will arrive at 89?

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

int testNumber = 0;

int chain(int n){

	char n_s[10];

	// base case
	if (n == 89 || n == 1) return (n) ;

	sprintf(n_s, "%d", n);

	int sum = 0;
	int digit = 0;

	for (int i = 0; i <strlen(n_s); i++){
		digit = n_s[i] - '0';
		digit = digit*digit;
		sum  += digit;
	}
	return (chain (sum)) ;
}

int main()
{
	clock_t start = clock();

	int n = 0;
	int temp = 0;
	int found = 0;

	for (n = 2; n < 10000000; n++){ if (n % 1000000 == 0) printf(".\n"); if (chain(n)==89) found++; }

	printf("%d numbers below 10,000,000 cycle into 89, not 1\n\n", found);

	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
