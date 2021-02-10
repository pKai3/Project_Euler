/*

145 is a curious number, as 1! + 4! + 5! = 1 + 24 + 120 = 145.

Find the sum of all numbers which are equal to the sum of the factorial of their digits.

Note: as 1! = 1 and 2! = 2 are not sums they are not included.

*/

#include <stdio.h>
#include <string.h>


int main()
{
	int test = 3;
	int n = 0;
	int f = 0;
	int digit[10];
	int digitfac = 1;
	int sum = 0;
	int totsum = 0;

	int saved[100];
	int count = -1;

	while (test <= (100000) ){

		char teststring[10];

		sprintf(teststring, "%d", test); 

		printf("%s: ", teststring);

		for (n = 0; n < strlen(teststring); n++){

			digit[n] = teststring[n] - '0';

			digitfac = 1;

			for (f = 1; f <= digit[n]; f++){

				digitfac = digitfac * f;
				//printf("%d ",digitfac);
			}

			sum = sum + digitfac;

			printf("%d! +", digit[n]);

		}


		printf(" =[%d]\n", sum);


		if (sum == test){

			totsum = totsum + sum;
			printf("%d\n", totsum);

			count++;
			saved[count] = test;

		}

		sum = 0;
		test++;

	}

	for (n = 0; n <= count; n++){

		printf("%d + ", saved[n]);
	}


	printf(" = %d\n", totsum);




}