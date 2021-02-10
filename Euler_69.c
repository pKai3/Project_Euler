/*
Euler's Totient function, φ(n) [sometimes called the phi function],
is used to determine the number of numbers less than n which are relatively prime to n.
For example, as 1, 2, 4, 5, 7, and 8, are all less than nine and
relatively prime to nine, φ(9)=6.

It can be seen that n=6 produces a maximum n/φ(n) for n ≤ 10.

Find the value of n ≤ 1,000,000 for which n/φ(n) is a maximum.
*/

#include <stdio.h>
#include <string.h>
#include <time.h>

int factors[200]; //global
int distinctfactors[200]; //global

long wheel(long n) {

    memset(factors, 0, sizeof(factors));
    memset(distinctfactors, 0, sizeof(distinctfactors));

    long ws[] = {1,2,2,4,2,4,2,4,6,2,6};
    long f = 2; int w = 0;
    int keep = 0;

    while (f * f <= n) {
        if (n % f == 0) {
            factors[keep] = f;
            keep++;
            n /= f;
        }
        else {
            f += ws[w];
            w = (w == 10) ? 3 : (w+1);
        }
    }
    factors[keep] = n;
    keep++;

    return 0;
}

void FindDistinctFactors(){

  int k = 0; //current factor
  int i = 0;

  distinctfactors[k] = factors[i];

  while (factors[i] != 0){

    while (factors[i] <= distinctfactors[k] && factors[i] != 0){
      i++;
    }

    k++;
    distinctfactors[k] = factors[i];
    i++;

  }

}

double NovPhi(int n){

  wheel(n);
  FindDistinctFactors();

  double mult = 1;

  int i = 0;
  while (distinctfactors[i] != 0){
    mult = mult*(1 - (double)1/(double)distinctfactors[i]);
    i++;
  }
  return 1/mult; //returning essentially n/phi(n)
}

int main(){

	clock_t start = clock();

  int n = 0;
  double NovP = 0;
  double largest = 0;

  printf("n : phi(n) : n/phi(n)\n\n");

  for (n = 2; n <= 1000000; n++){
    NovP = NovPhi(n);
    if (NovP > largest){
      printf("%d : %lf : %lf\n", n, (1/NovP)*(double)n, NovP);
      largest = NovP;
    }
  }

	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
