/*

A Pythagorean triplet is a set of three natural numbers, a < b < c, for which,

a^2 + b^2 = c^2
For example, 3^2 + 4^2 = 9 + 16 = 25 = 5^2.

There exists exactly one Pythagorean triplet for which a + b + c = 1000.
Find the product abc.

*/

#include <stdio.h>
#include <math.h>

int main()
{

	float a = 0, b = 0, c = 0, t = 1000;

	for (a = 1; a <= 1000; a++){
		
		for (b = 1; b <= 1000; b++){

				c = sqrt(a*a + b*b);

				if (a + b + c == t){
					printf("%f^2 + %f^2 = %f^2\n", a,b,c);
					printf("%f * %f * %f = %f\n", a,b,c, a*b*c);
				}

		}
	}

}






