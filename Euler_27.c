/*

Euler discovered the remarkable quadratic formula:

n2+n+41
It turns out that the formula will produce 40 primes for the consecutive integer values 0≤n≤39. However, when n=40,402+40+41=40(40+1)+41 is divisible by 41, and certainly when n=41,412+41+41 is clearly divisible by 41.

The incredible formula n2−79n+1601 was discovered, which produces 80 primes for the consecutive values 0≤n≤79. The product of the coefficients, −79 and 1601, is −126479.

Considering quadratics of the form:

n2+an+b, where |a|<1000 and |b|≤1000

where |n| is the modulus/absolute value of n
e.g. |11|=11 and |−4|=4
Find the product of the coefficients, a and b, for the quadratic expression that produces the maximum number of primes for consecutive values of n, starting with n=0.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

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

int main()
{
	clock_t start = clock();

	int n = 0;
	int v = 0;
	int primes = 0;
	int most_primes = 0;


	int a = 0;
	int b = 0;

	int mostp_a = 0;
	int mostp_b = 0;

	for (a = -999; a < 1000; a++){
		for (b = -1000; b <= 1000; b++){
			
			primes = 0;
			n = 0;
			
			v = b ; //n * n + a * n + b;

			while(isPrime(abs(v)) == 1){
				primes++;
				//printf("%d = |%d^2 + %d*%d + %d|\n", abs(v), n, a, n, b);
	
				n++;
				v = n * n + a * n + b;
			}

			if (primes > most_primes){
				most_primes = primes;
				mostp_a = a;
				mostp_b = b;
			}
		}
	}

	printf("\n\nn^2 + %dn + %d; %d primes found\n", mostp_a, mostp_b, most_primes);
	printf("%d * %d = %d\n\n", mostp_a, mostp_b, mostp_a * mostp_b);

	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
