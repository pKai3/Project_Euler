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

#define SIZE 1000

long n_facs[SIZE];
long d_facs[SIZE];

void nfacs(long long n) {

    memset(n_facs, 0, sizeof(n_facs));
    // memset(pows, 0, sizeof(pows));

    long ws[] = {1,2,2,4,2,4,2,4,6,2,6};
    long f = 2; int w = 0;
    int i = 0;
    int j = 0;

    while (f * f <= n) {
        if (n % f == 0) {
            // printf("%ld\n", f);

              n_facs[i] = f; i++;

            n /= f;
        } else {
            f += ws[w];
            w = (w == 10) ? 3 : (w+1);
        }
    }
    // printf("%ld\n", n);
      n_facs[i] = n;
			i++;
         if (i == SIZE){ printf("*WARN*\n");}

}

void dfacs(long long d) {

    memset(d_facs, 0, sizeof(d_facs));
    // memset(pows, 0, sizeof(pows));

    long ws[] = {1,2,2,4,2,4,2,4,6,2,6};
    long f = 2; int w = 0;
    int i = 0;
    int j = 0;

    while (f * f <= d) {
        if (d % f == 0) {
            // printf("%ld\n", f);

              d_facs[i] = f; i++;

            d /= f;
        } else {
            f += ws[w];
            w = (w == 10) ? 3 : (w+1);
        }
    }
    // printf("%ld\n", n);
      d_facs[i] = d;
			i++;
         if (i == SIZE){ printf("*WARN*\n");}

}

int main(){

	clock_t start = clock();

	long long n, d;
	int rCheck, rCount;
	double res, smallest_res; //count of reducable fractions

	smallest_res = 1; //start large

	d = 1; //2*3*5*7*11*13*17*23*10;

   double target = 15499.0/94744.0; //0.1635881956

	while (/*d < 100 */ smallest_res > (target)){

		dfacs(d);
		rCount = 0;

		// for (n = d-1; n > 0; n--){ //for each possible numerator
		n = d - 1;

		while ( ( ( (double)rCount / (double)(d-1) ) < smallest_res) && n > 0){

			nfacs(n);
			rCheck = 0;

			/*
			for (int i = 0; i < SIZE; i++){
				if (n_facs[i] != 0) printf("%d\n", n_facs[i]);
			}

			printf("/\n");

			for (int i = 0; i < SIZE; i++){
				if (d_facs[i] != 0) printf("%d\n", d_facs[i]);
			}
*/

			int a = 0;
			int b = 0;
			while (a < SIZE && rCheck == 0 && n_facs[a] != 0){ //compare factorization of num and denom
				while (b < SIZE && rCheck == 0 && d_facs[b] != 0){
					if (n_facs[a] == d_facs[b]){
						rCheck++;
						//printf("\n%ld = %ld\n", n_facs[a], d_facs[b]);
		 			}
					b++;
				}
				a++;
			}

			if (rCheck == 0){
				rCount++;
			}

			n--;

		}

		//printf("\n*%d\n", rCount);
		res = ((double)rCount / (double)(d-1));
		//printf("\n*%lf\n", res);

      if (d%1000 == 0){ printf("R(%lld) = %lf\n", d, res);}

		if (res < smallest_res){
			smallest_res = res;
			printf("***R(%lld) = %lf***\n", d, smallest_res);
		}

		d++;

	}


	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
