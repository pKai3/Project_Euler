/*

The decimal number, 585 = 1001001001 (binary), is palindromic in both bases.

Find the sum of all numbers, less than one million, which are palindromic in base 10 and base 2.

(Please note that the palindromic number, in either base, may not include leading zeros.)

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int isPalindrome(unsigned long long number){

	unsigned long long reversed = 0, remainder = 0, c = 0;

    c = number;    // original integer is stored in variable 
    while( c!=0 )
    {
        remainder = c%10;
        reversed = reversed*10 + remainder;
        c /= 10;
    }

    // palindrome if orignalInteger and reversed are equal
    if (number == reversed) return 1;

    else 					return 0;
}

unsigned long long convert(long number,long base){
    if (number == 0 || base==10)	return number;

    return (number % base) + 10*convert(number / base, base);
}

int main()
{
	clock_t start = clock();

	long n = 0;
	int sum = 0;
	
	printf("\n\nBase 10                Base 2\n");
	printf("-----------------------------\n");


	for (n = 0; n < 1000000; n++){

		if (isPalindrome(n) == 1){
			if (isPalindrome(convert(n, 2)) == 1 ){
				printf("%6ld | %20llu\n", n, convert(n,2));
				sum += n;
			}
		}

	}

	printf("------\n");
	printf("\n%d\n\n", sum);


	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
