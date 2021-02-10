/*

There are exactly ten ways of selecting three from five, 12345:

123, 124, 125, 134, 135, 145, 234, 235, 245, and 345

In combinatorics, we use the notation, 5C3 = 10.

In general,
nCr = n!/r!(n−r)!
	,where r ≤ n, n! = n×(n−1)×...×3×2×1, and 0! = 1.

It is not until n = 23, that a value exceeds one-million: 23C10 = 1144066.

How many, not necessarily distinct, values of  nCr, for 1 ≤ n ≤ 100, are greater than one-million?

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

long long fac(long long num){

	long long ans = 1;

	while (num > 1){
		ans = ans * num;
		num--;
	}

	return ans;

}

long long nCr(n, r){

	return fac(n)/( fac(r)*fac(n-r) );

}

int main()
{
	clock_t start = clock();

	long long n,r;

	//printf("%lld\n\n", fac(99))

	for (n = 1; n <= 100; n++){
		for (r = 1; r <= 100; r++){

			if (r <= n){
				printf("%lldC%lld = %lld\n", n, r, nCr(n, r) );
			}

		}
	}



	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
