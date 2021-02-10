/*
A palindromic number reads the same both ways. The largest palindrome made from the product of two 2-digit numbers is 9009 = 91 × 99.

Find the largest palindrome made from the product of two 3-digit numbers.
*/

#include <stdio.h>

int main(){

	int t = 999;
	int bot = 100;

	int a = 0;
	int b = 0;
	int c = 0;

	int largestP = 0;

	for (a=t; a >= bot; a--){

		for (b=t; b >= bot; b--){

			c = a*b;
			//printf("%d\n",c);

			int reversedInteger = 0, remainder, originalInteger;

		    originalInteger = c;

		    // reversed integer is stored in variable 
		    while( c!=0 )
		    {
		        remainder = c%10;
		        reversedInteger = reversedInteger*10 + remainder;
		        c /= 10;
		    }

		    // palindrome if orignalInteger and reversedInteger are equal
		    if (originalInteger == reversedInteger) //&& originalInteger > 900000)

		    	if  (originalInteger > largestP)
		    		largestP = originalInteger;


		        //printf("*\n");
		    
		}
	}

	printf("%d\n", largestP);
}





