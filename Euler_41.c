/*

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int isPrime(n){

	if (n == 1){
		return 0;
	}
    if (n == 2){
       return 1;
    }
    if (n == 3){
       return 1;
    }
    if (n % 2 == 0){
       return 0;
    }
    if (n % 3 == 0){
       return 0;
    }

    int i = 5;
    int w = 2;

    while (i * i <= n){
        if (n % i == 0){
           return 0;
        }

        i += w;
        w = 6 - w;

    }

    return (1);

}

int dupCheck(char string[]){

	for (int i = 0; i < strlen(string); i++){
		for (int j = i + 1; j < strlen(string); j++){
			if (string[j] == string[i]){
				return 0;
			}
		}
	}

	return 1;

}

int main()
{
	clock_t start = clock();

	//printf("%d\n\n", dupCheck("1124"));
	//printf("%d\n\n", dupCheck("1234"));

	long n = 999999999;
	char n_s[300];

	int size = 9;

	int foundzero = 0;

	for (n = 100000000; n < 999999999; n++){ //starting at 9 digit numbers

		if (n%100000 == 0) printf("%ld\n", n);

		    //printf("\n%s\n", n_s);

	    if (isPrime(n) == 1){

			for (int z = 0; z < 300; z++){ //reset n_s
				n_s[z] = '\0';
			}

			sprintf(n_s, "%ld", n);

			foundzero = 0;
			for (int z = 0; z < strlen(n_s); z++){ //check for zeros
				if (n_s[z] == '0'){
					foundzero = 1;
				}
			}

	    	if (dupCheck(n_s) == 1 && foundzero == 0){ //check for dups
	    		printf("%ld\n",n);
	    		break;
	    	}
	    }

	}



	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}








