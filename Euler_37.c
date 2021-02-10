/*
The number 3797 has an interesting property. Being prime itself, it is possible to continuously remove digits from left to right, 
and remain prime at each stage: 3797, 797, 97, and 7. Similarly we can work from right to left: 3797, 379, 37, and 3.

Find the sum of the only eleven primes that are both truncatable from left to right and right to left.

NOTE: 2, 3, 5, and 7 are not considered to be truncatable primes.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int isPrime(int n){

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


int main()
{
	clock_t start = clock();

	int n = 10; //firt prime to check is 11, 2 digits
	int check = 0;
	char check_s[20];
	char temp[20];
	int steps = 0;
	int found = 0;
	int found_n = 0;
	int sum_found = 0;

	while(found_n < 11){//keep finding new primes

		n++;
		check = n; //store original n
		steps = 0; //reset steps
		found = 0; //reset found

		while(isPrime(check) == 1){ //while check is prime, begin truncating check LEFT

			steps++;
			printf(" %6d ", check);
			
			sprintf(check_s, "%d", check);

			for (int i = 0; i < strlen(check_s); i++){
				temp[i] = check_s[i+1]; //truncate LEFT by one
			}

			strcpy(check_s, temp);
			check = strtol(check_s, (char **)NULL, 10);

		}

		sprintf(check_s, "%d", n); //check if all truncated steps produced primes
		if (steps == strlen( check_s ) ){
			found++;
		}

		if (found == 1){ //IF TRUNCATE LEFT WORKED, TRY RIGHT
			check = n; //reset check to original n
			steps = 0; //reset steps
			printf(" | ");
			while(isPrime(check) == 1){ //while check is prime, begin truncating check RIGHT

				steps++;
				printf(" %6d ", check);
				
				sprintf(check_s, "%d", check);

				for (int i = 0; i < strlen(check_s); i++){
					temp[i] = check_s[i]; //truncate RIGHT by one
				}

				temp[strlen(check_s) - 1] = '\0'; //erase last digit

				strcpy(check_s, temp);
				check = strtol(check_s, (char **)NULL, 10);

			}
			sprintf(check_s, "%d", n); //check if all truncated steps produced primes
			if (steps == strlen( check_s ) ){
				found++;

				if (found == 2){
					found_n ++;
					sum_found += n;
					printf("\n[found %d truncatable primes]\n\n", found_n);
				}

			}

		}

		fpurge(stdout); //clear print queue if prime not truncatable

	}

	printf("\n\nsum of 11 truncatable primes = %d\n\n", sum_found);


	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
