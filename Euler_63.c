/*

The 5-digit number, 16807=7^5, is also a fifth power. Similarly, the 9-digit number, 134217728=8^9, is a ninth power.

How many n-digit positive integers exist which are also an nth power?

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

unsigned long long int_pow(int base, int exp)
{
    unsigned long long result = 1;
    while (exp)
    {
        if (exp & (unsigned long long) 1)
           result *= (unsigned long long) base;
        exp /= (unsigned long long) 2;
        base *= base;
    }
    return result;
}

int main()
{
	clock_t start = clock();


	int b = 1;
	int n = 1;

	unsigned long long result = 0;
	unsigned long len = 0;
	char str[100];

	int found = 0;

	//printf("%d\n", int_pow(2,4));
	while (b < 10){
		while (n < 20){//len <= n){

			result = int_pow(b,n);
			sprintf(str, "%llu", result);
			len = strlen(str);

			if ( len == n ){
				found++;
				printf("** %d^%d = %llu [%lu] {%d}\n", b, n, result, strlen(str), found);
			}

			else printf("%d^%d = %llu [%lu] {%d}\n", b, n, result, strlen(str), found);


			n++;
		}

		n = 1;

		b++;
	}


	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}





