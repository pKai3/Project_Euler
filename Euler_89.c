/*
For a number written in Roman numerals to be considered valid there are
basic rules which must be followed. Even though the rules allow some numbers
to be expressed in more than one way there is always a "best" way of writing a particular number.

For example, it would appear that there are at least six ways of writing the number sixteen:

IIIIIIIIIIIIIIII
VIIIIIIIIIII
VVIIIIII
XIIIIII
VVVI
XVI

However, according to the rules only XIIIIII and XVI are valid, and the last example
is considered to be the most efficient, as it uses the least number of numerals.

The 11K text file, roman.txt (right click and 'Save Link/Target As...'), contains
one thousand numbers written in valid, but not necessarily minimal, Roman numerals;
see About... Roman Numerals for the definitive rules for this problem.

Find the number of characters saved by writing each of these in their minimal form.

Note: You can assume that all the Roman numerals in the file contain no more than
four consecutive identical units.

Traditional Roman numerals are made up of the following denominations:

I = 1
V = 5
X = 10
L = 50
C = 100
D = 500
M = 1000

In order for a number written in Roman numerals to be considered valid there
are three basic rules which must be followed.

Numerals must be arranged in descending order of size.
M, C, and X cannot be equalled or exceeded by smaller denominations.
D, L, and V can each only appear once.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

char roman[1000][50] = {{}};
char romanFix[1000][50] = {{}};
int  romanVal[1000];
int  romanValCopy[1000];

int readFile(){

	FILE *data;
	data = fopen("Euler_89_roman.txt", "r"); // read only

	char c;
	int i = 0;
	int j = 0;
	int charcount;

	for (i = 0; i < 1000; i++){ // clean array
		for (j = 0; j < 50; j++){
			roman[i][j] = '\0';
		}
	}

	i = 0;
	j = 0;

	while ( fscanf(data, "%c", &c ) == 1 ){
		if (c == '\n'){
			i++;
			j = 0;
		}
		else{
			roman[i][j] = c;
			j++;
			charcount++;
		}
	}

	// // printout
	// for (i=0; i<1000; i++){
  //     for(j=0; j<50; j++){
  //     		printf("%c", roman[i][j]);
  //     }
  //     printf("\n");
  // }

	return charcount;

}

int checkVal(char input){

	if (input == 'I') return 1;
	if (input == 'V') return 5;
	if (input == 'X') return 10;
	if (input == 'L') return 50;
	if (input == 'C') return 100;
	if (input == 'D') return 500;
	if (input == 'M') return 1000;

	else 							return 0;

}

int checkNextTwoVals(char input[]){

	if (strcmp("CM", input) == 0)	return 900;
	if (strcmp("CD", input) == 0)	return 400;
	if (strcmp("XC", input) == 0)	return 90;
	if (strcmp("XL", input) == 0)	return 40;
	if (strcmp("IX", input) == 0)	return 9;
	if (strcmp("IV", input) == 0)	return 4;

	else 							return 0;

}

void findValues(){

	int i = 0;
	int j = 0;

	int a = 0;

	memset (romanVal, 0, sizeof(romanVal));

	for (i = 0; i < 1000; i++){

		j = 0;

		while (roman[i][j] != '\0'){
			//if there are at least two chars left
			//check next two chars for possible funky shit
			if (strlen(roman[i]) - j >= 2){

				char nextTwo[3];
				for (a = 0; a < 2; a++){
					nextTwo[a] = roman[i][j+a];
				}
				nextTwo[2] = '\0'; //ADDED THIS FOR SAFETY

				if (checkNextTwoVals(nextTwo) != 0){ //if nextTwo contained a string of interest, use it
					romanVal[i] += checkNextTwoVals(nextTwo);
					j += 2;
				}

				else{
					romanVal[i] += checkVal(roman[i][j]);
					j++;
				}

			}

			else{
			romanVal[i] += checkVal(roman[i][j]);
			j++;
			}

		}
	}

	for (i = 0; i < 1000; i++){
		romanValCopy[i] = romanVal[i];
	}

}

int fixRomans(){

	int i;
	int charcount = 0;

	for (i = 0; i < 1000; i++){
		while (romanVal[i] != 0){

			char toAppend[3];
   		memset(toAppend, '\0', sizeof(toAppend));

			if (romanVal[i] >= 1000){
				strcpy(toAppend, "M");
				romanVal[i] -= 1000;
			}

			else if (romanVal[i] >= 900){
				strcpy(toAppend, "CM");
				romanVal[i] -= 900;
			}

			else if (romanVal[i] >= 500){
				strcpy(toAppend, "D");
				romanVal[i] -= 500;
			}

			else if (romanVal[i] >= 400){
				strcpy(toAppend, "CD");
				romanVal[i] -= 400;
			}

			else if (romanVal[i] >= 100){
				strcpy(toAppend, "C");
				romanVal[i] -= 100;
			}

			else if (romanVal[i] >= 90){
				strcpy(toAppend, "XC");
				romanVal[i] -= 90;
			}

			else if (romanVal[i] >= 50){
				strcpy(toAppend, "L");
				romanVal[i] -= 50;
			}

			else if (romanVal[i] >= 40){
				strcpy(toAppend, "XL");
				romanVal[i] -= 40;
			}

			else if (romanVal[i] >= 10){
				strcpy(toAppend, "X");
				romanVal[i] -= 10;
			}

			else if (romanVal[i] >= 9){
				strcpy(toAppend, "IX");
				romanVal[i] -= 9;
			}

			else if (romanVal[i] >= 5){
				strcpy(toAppend, "V");
				romanVal[i] -= 5;
			}

			else if (romanVal[i] >= 4){
				strcpy(toAppend, "IV");
				romanVal[i] -= 4;
			}

			else if (romanVal[i] >= 1){
				strcpy(toAppend, "I");
				romanVal[i] -= 1;
			}

			strcat(romanFix[i], toAppend);

			//romanFix[i][j] = findNumeral(romanVal[i]);
			//romanVal[i] -= checkVal(romanFix[i][j]); //subtract value of last appended numeral
			//j++;
			charcount += strlen(toAppend);


		}
	}

	return charcount;

}

//-----------------------------------------------------

int main(){

	clock_t start = clock();

	int initialCount = readFile();
	findValues();
	int finalCount = fixRomans();

	int i;

	for (i=0; i<1000; i++){
  	printf("%20s = %20s = %6d\n\n", roman[i], romanFix[i], romanValCopy[i]);
  }

	printf("\n\n");
	printf("Initial Char Count: %d\n", initialCount);
	printf("Final Char Count: %d\n\n", finalCount);
	printf("Characters Saved: %d\n\n", abs(finalCount - initialCount));

	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
