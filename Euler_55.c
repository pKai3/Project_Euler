/*

If we take 47, reverse and add, 47 + 74 = 121, which is palindromic.

Not all numbers produce palindromes so quickly. For example,

349 + 943 = 1292,
1292 + 2921 = 4213
4213 + 3124 = 7337

That is, 349 took three iterations to arrive at a palindrome.

Although no one has proved it yet, it is thought that some numbers, like 196, never produce a palindrome. 
A number that never forms a palindrome through the reverse and add process is called a Lychrel number. 
Due to the theoretical nature of these numbers, and for the purpose of this problem, 
we shall assume that a number is Lychrel until proven otherwise. 
In addition you are given that for every number below ten-thousand, it will either (i) become a palindrome in less than fifty iterations, or, 
(ii) no one, with all the computing power that exists, has managed so far to map it to a palindrome. 
In fact, 10677 is the first number to be shown to require over fifty iterations before producing a palindrome: 4668731596684224866951378664 
(53 iterations, 28-digits).

Surprisingly, there are palindromic numbers that are themselves Lychrel numbers; the first example is 4994.

How many Lychrel numbers are there below ten-thousand?

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


unsigned long long mirror_string(unsigned long long number){ //NOT USED! MIRROR_MATH USED INSTEAD

	char str[100];
	char str_r[100];

	sprintf(str, "%lld", number);

	//printf("len(%s) = %lu\n", str, strlen(str));

	for ( int i = 0; i < strlen(str); i++ ){
		str_r[strlen(str) - 1 - i] = str[i];
	}

	str_r[strlen(str_r)] = '\0';
	
	//printf("%s\n", str_r);

	return atoll(str_r);

}

unsigned long long mirror_math(unsigned long long number){

	unsigned long long reversed = 0, remainder = 0, c = 0;

    c = number;    // original integer is stored in variable 
    while( c!=0 )
    {
        remainder = c%10;
        reversed = reversed*10 + remainder;
        c /= 10;
    }

    // palindrome if orignalInteger and reversed are equal
    
    return reversed;

}

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
    if (number == reversed)
    	return 1;

    else
    	return 0;
}

int main()
{
	clock_t start = clock();

	int n = 1;
	unsigned long long c_m = 0;
	unsigned long long c = 0;
	int tries = 0;
	int lychrel = 0;

	while (n < 10000){

		c = n; //hold original n in n
		//printf("%d\n", c);

		//printf("%d\n", isPalindrome(c));
		tries = 0;
		while (tries < 50){

			//printf("*\n");

			c_m = mirror_math(c);
			//printf("%d\n", n_m);

			c = c + c_m;

			tries++;

			if (isPalindrome(c) == 1){
				printf("%d --> %llu\n", n, c);
				n++;
				break;
			}

		}

		if (tries >= 50){
			printf("%d -------> NOTHING >:(\n", n);
			lychrel++;
			n++;
		}


	}

	printf("\n\n%d Lychrels below 10,000\n", lychrel);

	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}






