/*

It can be seen that the number, 125874, and its double, 251748, contain exactly the same digits, but in a different order.

Find the smallest positive integer, x, such that 2x, 3x, 4x, 5x, and 6x, contain the same digits.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{

int n = 1;

int z = 6;

char snmult[100];

char sn[10][100];

int found_dig = 0;
int found_all_dig = 0;
int found_ans = 0;

int i = 0;
int j = 0;
int k = 0;


	while (found_ans == 0){
		
		//strcpy(sn[0], "blah");
		//strcpy(sn[3], "kek");

		for (i = 1; i <= z; i++){ //copy multiples of n into sn[] as strings

			sprintf(snmult, "%d", n*i);

			strcpy(sn[i], snmult);

			printf(" %s |", sn[i]);

		}

		printf("\n\n");

		for (i = 2; i <= z; i++){
			if ( strlen(sn[1]) != strlen(sn[i]) ){
				goto skip;
			}
		}


		for (i = 2; i <= z; i++){
			for (j = 0; j < strlen(sn[i]); j++){
				for (k = 0; k < strlen(sn[i]); k++){

					if (sn[1][j] == sn[i][k]){			

						//printf("------->%c = %c\n", sn[1][j], sn[i][k]);

						found_dig++; //need n found_digs to find right number
						break; //check for next digit
					}		
					else{
						//increase k
						//printf("%c != %c\n", sn[1][j], sn[i][k]);


					}

				}

				if (k == strlen(sn[1]) )
					break;

			}

			if (found_dig < strlen(sn[i]) ){
					//printf("oof\n");
					found_dig = 0;
					break;
			}

			else{
				//printf("yay\n");
				found_dig = 0;
				found_all_dig++;
			}
	
		}

		if (found_all_dig < z-1){
			found_all_dig = 0;
			skip:
			n++;
		}

		else{
			found_ans = 1;
		}
	
	}

	printf("\n\n\t\t\t%d\n\n", n);

}


