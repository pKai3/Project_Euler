/*The prime factors of 13195 are 5, 7, 13 and 29.

What is the largest prime factor of the number 600851475143 ?
*/

#include <stdio.h>
#include <math.h>

int main(){

	long top = 600851475143;

	long prime = 2;
	long n = 2;

	while (prime <= sqrt(top)){
		n=2;
		while (n < prime){

			if (prime % n == 0 && n != prime)
				prime++;
			else
				n++;
		}

		if (top % prime == 0)

			printf("%ld\n", prime);

		prime++;

	}
}