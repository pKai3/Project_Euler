/*

The sum of the primes below 10 is 2 + 3 + 5 + 7 = 17.

Find the sum of all the primes below two million.

*/

#include <stdio.h>

int isPrime(int n){

	if (n == 1){
		return 0;
	}
    if (n == 2){
       return 1;
    }
    if (n == 3){
       return 1;
    }
    if (n % 2 == 0){
       return 0;
    }
    if (n % 3 == 0){
       return 0;
    }

    int i = 5;
    int w = 2;

    while (i * i <= n){
        if (n % i == 0){
           return 0;
        }

        i += w;
        w = 6 - w;

    }

    return (1);

}

int main(){

	int n = 1;
	int t = 2000000;
	long psum = 0;

	for (n = 1; n < t; n++){

		if (isPrime(n) == 1) psum += n;

	}

	printf("sum of primes below 2,000,000: %ld\n", psum);

}
