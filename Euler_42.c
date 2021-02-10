/*

The nth term of the sequence of triangle numbers is given by,
tn = ½n(n+1); so the first ten triangle numbers are:

1, 3, 6, 10, 15, 21, 28, 36, 45, 55, ...

By converting each letter in a word to a number corresponding to its alphabetical position
and adding these values we form a word value.
For example, the word value for SKY is 19 + 11 + 25 = 55 = t10. If the word value is a
triangle number then we shall call the word a triangle word.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file containing nearly
two-thousand common English words, how many are triangle words?

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>



int main()
{
	clock_t start = clock();

	FILE *data;
	data = fopen("Euler_42_words.txt", "r"); // read only


	char words[2000][20]; //2000, 20 letter long words allocated
	char c;

	int i = 0;
	int j = 0;

	for (int z = 0; z < 2000; z++){
		for (int zz = 0; zz < 20; zz++){
			words[z][zz] = '\0';
		}
	}

	while ( fscanf(data, "%c", &c ) == 1 ){

		if (c == ','){
			i++;
			j = 0;
		}

		else{
			words[i][j] = c;
			j++;
		}

	}

	//printf("%s\n\n", words[7]);
	//printf("%d\n", 'B' - 64);
	//printf("%d\n\n", words[1][4] - 64);
	//printf("%ld\n", strlen(words[1]));


	int wordval[2000];

	for (int i = 0; i < 2000; i++){
		for (int j = 0; j < strlen(words[i]); j++){
			wordval[i] += (words[i][j] - 64);
		}
		//printf("%d\n\n", wordval[i]);
	}


	int triangles[10000];

	for (int i = 1; i < 1000; i++){
		triangles[i] = i*(i+1)/2;
		//printf("%d\n", triangles[i]);
	}

	int count = 0;

	for (int i = 0; i < 2000; i++){
		for (int j = 0; j < 10000; j++){
			if (wordval[i] == triangles[j] && wordval[i] != 0){
				count++;
				printf("%s = %d\n", words[i], triangles[j]);
				break;
			}
		}
	}

	printf("\n%d triangle words found\n\n", count);


	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
