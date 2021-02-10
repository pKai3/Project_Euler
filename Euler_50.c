
/*


The prime 41, can be written as the sum of six consecutive primes:

41 = 2 + 3 + 5 + 7 + 11 + 13
This is the longest sum of consecutive primes that adds to a prime below one-hundred.

The longest sum of consecutive primes below one-thousand that adds to a prime, contains 21 terms, and is equal to 953.

Which prime, below one-million, can be written as the sum of the most consecutive primes?

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
	         
	// 
	// 
	// C code to read a bunch of integers from a file... 
	// 
	// 

	int number; 

	FILE *in_file; 
	in_file = fopen("Euler_50_primes.txt", "r"); // read only  

	FILE *in_file2; 
	in_file2 = fopen("Euler_50_primes.txt", "r"); // read only  

	if (! in_file ) // equivalent to saying if ( in_file == NULL ) 
	 {  
	    printf("oops, file can't be read\n"); 
	    exit(-1); 
	 } 

	// attempt to read the next line and store 
	// the value in the "number" variable 

	int sum = 0;
	int summand = 0;
	int c = 0;
	int p = 0;

	int largestprime = 0;
	int largestc = 0;

	while ( fscanf(in_file, "%d", &number ) == 1 ){

		p++;
		sum = 0;

		if (number > 1000000){
			break;
		}
		
		printf("\n--> [%d] -%d\n", number, p); 

		while (sum < number && fscanf(in_file2, "%d", &summand ) == 1){

			printf("+%d\n",summand);

			sum = sum + summand;

			c++;

		}

		if (sum == number){

			printf("#%d",c);

			if (c > largestc){
				largestc = c;
				largestprime = number;
			}

		}

		else{

			rewind(in_file2);
			while (sum > number && fscanf(in_file2, "%d", &summand ) == 1){

				printf("-%d\n",summand);


				sum = sum - summand;

				c--;
			}

			if (sum == number){

			printf("#%d",c);

				if (c > largestc){
					largestc = c;
					largestprime = number;
				}
			}

		}
	
		c = 0;
		rewind(in_file2);

	 } 

	 printf("%d, with %d prime summation terms\n", largestprime, largestc);
}


