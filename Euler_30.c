/*

Surprisingly there are only three numbers that can be written as the sum of fourth powers of their digits:

1634 = 1^4 + 6^4 + 3^4 + 4^4
8208 = 8^4 + 2^4 + 0^4 + 8^4
9474 = 9^4 + 4^4 + 7^4 + 4^4
As 1 = 1^4 is not a sum it is not included.

The sum of these numbers is 1634 + 8208 + 9474 = 19316.

Find the sum of all the numbers that can be written as the sum of fifth powers of their digits.

*/

#include <stdio.h>
#include <math.h>
#include <string.h>

//max value to check would be 9^5 * 5

int main()
{
	int test = 2;
	int n = 0;
	int digit[10];
	int digitexp = 0;
	int sum = 0;
	int totsum = 0;

	int saved[100];
	int count = -1;

	while (test <= (9*9*9*9*9*5) ){

		char teststring[10];

		sprintf(teststring, "%d", test); 

		printf("%s: ", teststring);

		for (n = 0; n < strlen(teststring); n++){

			digit[n] = teststring[n] - '0';

			digitexp = (digit[n]*digit[n]*digit[n]*digit[n]*digit[n]);

			sum = sum + digitexp;

			printf("(%d)+", digitexp);

		}


		printf("=[%d]\n", sum);


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


	printf("= %d\n", totsum);




}
