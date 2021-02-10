/*

Euler's Totient function, φ(n) [sometimes called the phi function],
is used to determine the number of positive numbers less than or equal
to n which are relatively prime to n. For example, as 1, 2, 4, 5, 7, and 8,
are all less than nine and relatively prime to nine, φ(9)=6.

The number 1 is considered to be relatively prime to every positive number, so φ(1)=1.

Interestingly, φ(87109)=79180, and it can be seen that 87109 is a permutation of 79180.

Find the value of n, 1 < n < 10^7, for which φ(n) is a permutation of n
and the ratio n/φ(n) produces a minimum.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int factors[200]; //global
int distinctfactors[200]; //global

static int partition(char a[], int left, int right){
    int pivot, i, j, t;
    pivot = a[left];
    i = left; j = right + 1;

    while (1)
    {
        do i++; while (a[i] <= pivot && i <= right);
        do j--; while (a[j] > pivot);
        if (i >= j) break;
        t = a[i]; a[i] = a[j]; a[j] = t;
    }
    t = a[left]; a[left] = a[j]; a[j] = t;
    return j;
}

extern void quickSortChar(char a[], int left, int right){
    int j;
    if (left < right)
    {
        j = partition(a, left, right);
        quickSortChar(a, left, j - 1);
        quickSortChar(a, j + 1, right);
    }
}

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

  char PhiS[100];
  char nS[100];

  int n = 0;
  double NovP = 0;
  double smallest = 9999;

  printf("n : phi(n) : n/phi(n)\n\n");

  for (n = 2; n < 10000000; n++){

    NovP = NovPhi(n);
    int Phi = round((1/NovP)*(double)n);

    memset(PhiS, '\0', sizeof(PhiS));
    sprintf(PhiS, "%d", Phi);

    memset(nS, '\0', sizeof(nS));
    sprintf(nS, "%d", n);

    quickSortChar(PhiS, 0, strlen(PhiS) - 1);
    quickSortChar(nS, 0, strlen(PhiS) - 1);

    if (strcmp(nS, PhiS) == 0){

      if (NovP < smallest){
        printf("%d : %lf : %lf\n", n, (1/NovP)*(double)n, NovP);
        smallest = NovP;
      }

    }

  }

	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
