/*

Let d(n) be defined as the sum of proper divisors of n (numbers less than n which divide evenly into n).
If d(a) = b and d(b) = a, where a ≠ b, then a and b are an amicable pair and each of a and b are called amicable numbers.

For example, the proper divisors of 220 are 1, 2, 4, 5, 10, 11, 20, 22, 44, 55 and 110; therefore d(220) = 284. 
The proper divisors of 284 are 1, 2, 4, 71 and 142; so d(284) = 220.

Evaluate the sum of all the amicable numbers under 10000.

*/

#include <stdio.h>

int main()
{

	int a = 0;
	int div_a = 0;
	int divsum_a = 0;

	int b = 0;
	int div_b = 0;
	int divsum_b = 0;

	int amsum = 0;

	for (a = 1; a < 10000; a++){

		for (b = 1; b < 10000; b++){

			divsum_a = divsum_b = 0;

			for (div_a = 1; div_a <= a/2; div_a++){

				if (divsum_a > b){
					break;
				}

				if (a % div_a == 0){
					divsum_a = divsum_a + div_a;
					//printf("%d\n", div_a);
				}

			}
			if (divsum_a <= b){
				for (div_b = 1; div_b <= b/2; div_b++){

					if (divsum_b > a){
						break;
					}

					if (b % div_b == 0){
						divsum_b = divsum_b + div_b;
						//printf("%d\n", div_b);
					}

				}
			}

			if (a > b && divsum_a == b && divsum_b == a){

				amsum = amsum + a + b;

				printf("\ndivsum(%d) = %d & divsum(%d) = %d | ", a, divsum_a, b, divsum_b);
				printf("amsum = %d\n", amsum);

			}

		}

	}

		//printf("\ndivsum(%d) = %d\n", a, divsum_a);


}
