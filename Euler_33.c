/*

The fraction 49/98 is a curious fraction, as an inexperienced mathematician in attempting to simplify 
it may incorrectly believe that 49/98 = 4/8, which is correct, is obtained by cancelling the 9s.

We shall consider fractions like, 30/50 = 3/5, to be trivial examples.

There are exactly four non-trivial examples of this type of fraction, less than one in value, 
and containing two digits in the num and den.

If the product of these four fractions is given in its lowest common terms, find the value of the den.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main()
{
	clock_t start = clock();

	int num = 49;
	int den = 98;

	char n_s[5];
	char d_s[5];

	//printf("%s / %s \n", n_s, d_s);

	int n_f = 0;
	int d_f = 0;

	for (num = 10; num <= 99; num++){
		for (den = 10; den <= 99; den++){

			sprintf(n_s, "%d", num);
			sprintf(d_s, "%d", den);

			for (int i = 0; i < 2; i++){
				for (int k = 0; k < 2; k++){

					if (n_s[i] == d_s[k] && (n_s[i] != '0') && (d_s[i] != '0') && (n_s[0] != d_s[0] && n_s[1] != d_s[1]) ){

						if (i == 0) n_f = n_s[1] - '0';
						if (i == 1) n_f = n_s[0] - '0';

						if (k == 0) d_f = d_s[1] - '0';
						if (k == 1) d_f = d_s[0] - '0';
						
					}

				}
			}

			if ( ((double)n_f / (double)d_f) == ((double)num / (double)den) && ((double)n_f / (double)d_f) < 1){
				printf("%d/%d = %d/%d\n", n_f, d_f, num, den);
			}
		}
	}



	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
