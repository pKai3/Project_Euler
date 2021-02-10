/*

We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once; 
for example, the 5-digit number, 15234, is 1 through 5 pandigital.

The product 7254 is unusual, as the identity, 39 × 186 = 7254, containing multiplicand, multiplier, and product is 1 through 9 pandigital.

Find the sum of all products whose multiplicand/multiplier/product identity can be written as a 1 through 9 pandigital.

HINT: Some products can be obtained in more than one way so be sure to only include it once in your sum.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

int main()
{
	clock_t start = clock();

	int a = 0;
	int b = 0;
	int p = 0;

	int sum = 0;

	char a_s[10];
	char b_s[10];
	char p_s[10];

	char concat[300];

	int answers[300];
	int count = 0;

	for (int z = 0; z < 300; z++){
		concat[z] = 0;
	}

	for (a = 1; a < 2000; a++){

		for (b = a; b > 0; b--){

			p = a * b; 

			for (int z = 0; z < 300; z++){ //clear concat array each time through
				concat[z] = '\0';
			}

			sprintf(a_s, "%d", a);
			sprintf(b_s, "%d", b);
			sprintf(p_s, "%d", p);

			strcat(concat, a_s);
			strcat(concat, b_s);
			strcat(concat, p_s);

			int size = 9;

			int foundzero = 0;

			//printf("%s\n", concat);

			//check concatenation for all digits

			for (int z = 0; z < strlen(concat); z++){
				if (concat[z] == '0'){
					foundzero = 1;
				}
			}

			if (strlen(concat) == 9 && foundzero == 0){
				
				//printf("%d * %d = %d\n", a,b,p);

			    for (int i = 0; i < size; i++) // for each entry
			    {
			        for (int j = i + 1; j < size;) // check every other entry
			        {
			            if (concat[j] == concat[i])
			            {
			                for (int k = j; k < size; k++) //if duplicate found truncate left one and remove first occurrence
			                {
			                    concat[k] = concat[k + 1];
			                }
			                size--;
			            }
			            else
			            {
			                j++;
			            }
			        }
			    }
			    //for (int i = 0; i < size; i++) {
			    //    printf("%c", concat[i]);
			    //}

			    if (size == 9){
					printf("%d * %d = %d\n", a,b,p);

			    	printf("%s\n", concat);
			    	//sum += p;
			    	answers[count] = p;
			    	count++;
			    }
		    
		    }

		}

	}

	for (int i = 0; i < count; i++) // for each entry
    {
        for (int j = i + 1; j < count;) // check every other entry
        {
            if (answers[j] == answers[i])
            {
                for (int k = j; k < count; k++) //if duplicate found truncate left one and remove first occurrence
                {
                    answers[k] = answers[k + 1];
                }
                count--;
            }
            else
            {
                j++;
            }
        }
    }

    for (int i = 0; i < count; i++){
    	sum += answers[i];
    }

    printf("\n\n");

    printf("%d\n\n", sum);

	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
