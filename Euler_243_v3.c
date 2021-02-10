/*

A positive fraction whose numerator is less than its denominator is called a proper fraction.
For any denominator, d, there will be d−1 proper fractions; for example, with d = 12:
1/12 , 2/12 , 3/12 , 4/12 , 5/12 , 6/12 , 7/12 , 8/12 , 9/12 , 10/12 , 11/12 .

We shall call a fraction that cannot be cancelled down a resilient fraction.
Furthermore we shall define the resilience of a denominator, R(d), to be the
ratio of its proper fractions that are resilient; for example, R(12) = 4/11 .
In fact, d = 12 is the smallest denominator having a resilience R(d) < 4/10 .

Find the smallest denominator d, having a resilience R(d) < 15499/94744 .

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>


int phi(int n)
{
  int result = n;
  for(int i=2;i*i <= n;i++)
  {
    if (n % i == 0) result -= result / i;
    while (n % i == 0) n /= i;
    if (i!=2) i++;
  }
  if (n > 1) result -= result / n;
  return result;
}

int main(){

	clock_t start = clock();

	long long d;
	double res, smallest_res; //count of reducable fractions

	smallest_res = 1; //start large

	d = 330; //2*3*5*7*11*13*17*19*23*4;

   double target = 15499.0/94744.0; //0.1635881956

	while (smallest_res > (target)){


		res = ((double)phi(d) / (double)(d-1));

      //printf("R(%lld) = %lf\n", d, res);

		if (res < smallest_res){
			smallest_res = res;
			printf("***R(%lld) = %lf***\n", d, smallest_res);
		}

		d += 330;

	}


	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
