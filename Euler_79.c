/*

A common security method used for online banking is to ask the user for three
random characters from a passcode. For example, if the passcode was 531278,
they may ask for the 2nd, 3rd, and 5th characters; the expected reply would be: 317.

The text file, keylog.txt, contains fifty successful login attempts.

Given that the three characters are always asked for in order, analyse the
file so as to determine the shortest possible secret passcode of unknown length.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

char entries[50][4]; //50, entries of max 3 (+\0) in length allocated

void LoadData(){

	FILE *data;
	data = fopen("Euler_79_keylog.txt", "r"); // read only

	char c;

	int i = 0;
	int j = 0;

	for (int z = 0; z < 50; z++){
		for (int zz = 0; zz < 10; zz++){
			entries[z][zz] = '\0';
		}
	}

	while ( fscanf(data, "%c", &c ) == 1 ){

		if (c == '\n'){
			i++;
			j = 0;
		}

		else{
			entries[i][j] = c;
			j++;
		}

	}

	for (int z = 0; z < 50; z++){
			printf("%s\n", entries[z]);
	}

}

int main(){

	clock_t start = clock();

	LoadData();


	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
