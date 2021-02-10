/*

By replacing each of the letters in the word CARE with 1, 2, 9, and 6 respectively,
we form a square number: 1296 = 36^2. What is remarkable is that, by using the same
digital substitutions, the anagram, RACE, also forms a square number: 9216 = 96^2.
We shall call CARE (and RACE) a square anagram word pair and specify further that
leading zeroes are not permitted, neither may a different letter have the same
digital value as another letter.

Using words.txt (right click and 'Save Link/Target As...'), a 16K text file
containing nearly two-thousand common English words, find all the square anagram
word pairs (a palindromic word is NOT considered to be an anagram of itself).

What is the largest square number formed by any member of such a pair?

NOTE: All anagrams formed must be contained in the given text file.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

char words[2000][30] = {{}};
char wordscopy[2000][30] = {{}};

char anagrams[2000][30] = {{}};

unsigned long long squareNums[31625];
char squareNumStr[31625][15];

void readFile(char path[], char delimiter){

	memset(words, '\0', sizeof(words));

	FILE *data;
	data = fopen(path, "r"); // read only

	char c;
	int i = 0;
	int j = 0;
	int charcount;

	for (i = 0; i < 2000; i++){ // clean array
		for (j = 0; j < 30; j++){
			words[i][j] = '\0';
		}
	}

	i = 0;
	j = 0;

	while ( fscanf(data, "%c", &c ) == 1 ){
		if (c == delimiter){
			i++;
			j = 0;
		}
		else{
			words[i][j] = c;
			j++;
		}
	}

	for (i = 0; i < 2000; i++){
		strcpy(wordscopy[i], words[i]);
	}

}

int partition(char a[], int left, int right){
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

void quickSortChar(char a[], int left, int right){
    int j;
    if (left < right)
    {
        j = partition(a, left, right);
        quickSortChar(a, left, j - 1);
        quickSortChar(a, j + 1, right);
    }
}

void findAnagrams(){

	//for each word, check every other for same length. if same length, check for presence of each char.
	memset(anagrams, '\0', sizeof(anagrams));

	int curr, check, curr_l, check_l; //currWord, checkWord, letter
	int i = 0;

	for (curr = 0; curr < 2000; curr++){ //for each word
		for (check = curr + 1; check < 2000; check++){ //check = curr + 1?

				// } //if we get here then the words are the same
				if (strcmp(words[curr], words[check]) == 0 && curr != check && strlen(words[curr]) > 0){
					//printf("%d, %s\n", i, words[curr]);
					strcpy(anagrams[i], wordscopy[curr]);
					i++;
					strcpy(anagrams[i], wordscopy[check]);
					i++;
				}

		}
	}


}

void genSquares(){

	int i;

	for (i = 0; i < 31625; i++){
		squareNums[i] = i*i;
    sprintf(squareNumStr[i], "%llu", squareNums[i]);

		// printf("%d\n", squareNums[i]);
	}

}

int largestSquare(char word[], char anagram[]){

  char codex[10];

  char anaSquareStr[15];
  int anaSquare;

  int len = strlen(word);
  int i, j, a, b;

  int largest = 0;

  for (i = 0; i < 31625; i++){

    memset(codex, '\0', sizeof(codex));

    if ( strlen(squareNumStr[i]) == strlen(word) ) {

      for (j = 0; j < len; j++){ //assign letters to codex

        if (codex[squareNumStr[i][j] - '0' ] != '\0' && codex[squareNumStr[i][j] - '0'] != word[j])
          goto noFit;

        else
          codex[ squareNumStr[i][j] - '0' ] = word[j];

      }

      // printf("%llu\n", squareNums[i]);
      // for (int k = 0; k < 10; k++)
      // printf("%d%c\n", k, codex[k]);

      memset(anaSquareStr, '\0', sizeof(anaSquareStr));

      for (int a = 0; a < len; a++){
        for (int b = 0; b < 10; b++){

          if (anagram[a] == codex[b]){
            anaSquareStr[a] = b + '0';
          }

        }
      }

      anaSquare = atoi(anaSquareStr);

      for (a = 0; a < 31625; a++){
        if (squareNums[a] == anaSquare && anaSquareStr[0] != '0' && anaSquare > largest){
          largest = anaSquare;
        }
      }

    }



    noFit: ; //do nothing important
  }

  return largest;

}

int main(){

	clock_t start = clock();

	readFile("Euler_98_words.txt", ',');

	// printf("------------------SORTED------------------\n");
	for (int z = 0; z < 1790; z++){
		quickSortChar(words[z], 0, strlen(words[z]) - 1);
		// printf("%20s    %s\n", wordscopy[z], words[z]);
	}

	findAnagrams();

	// printout
	// printf("------------------ANAGRAMS------------------\n");
	// for (int i=0; i<50; i+=2){ //1785
	// 	printf("%20s   %s\n", anagrams[i], anagrams[i+1]);
	// }

	genSquares();

  // printf("%d\n", largestSquare("BOARD", "BROAD") );

  int largest = 0;
  for (int i = 0; i < 2000; i+=2){

    if (strlen(anagrams[i]) > 1)
    printf("%10s  %5d  %s\n", anagrams[i], largestSquare(anagrams[i], anagrams[i+1]), anagrams[i+1] );

    if (largestSquare(anagrams[i], anagrams[i+1]) > largest)
      largest = largestSquare(anagrams[i], anagrams[i+1]);

  }


  printf("\n\n%d\n\n", largest);

	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
