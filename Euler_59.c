/*

Each character on a computer is assigned a unique code and the preferred standard is ASCII 
(American Standard Code for Information Interchange). 

For example, uppercase A = 65, asterisk (*) = 42, and lowercase k = 107.

A modern encryption method is to take a text file, convert the bytes to ASCII, 
then XOR each byte with a given value, taken from a secret key. The advantage with the XOR function 
is that using the same encryption key on the cipher text, restores the plain text; for example, 
65 XOR 42 = 107, then 107 XOR 42 = 65.

For unbreakable encryption, the key is the same length as the plain text message, 
and the key is made up of random bytes. The user would keep the encrypted message and the encryption key 
in different locations, and without both "halves", it is impossible to decrypt the message.

Unfortunately, this method is impractical for most users, so the modified method is to use a password as a key. 
If the password is shorter than the message, which is likely, the key is repeated cyclically throughout the message. 
The balance for this method is using a sufficiently long password key for security, but short enough to be memorable.

Your task has been made easy, as the encryption key consists of three lower case characters. 
Using cipher.txt (right click and 'Save Link/Target As...'), a file containing the encrypted ASCII codes, 
and the knowledge that the plain text must contain common English words, decrypt the message and find the 
sum of the ASCII values in the original text.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>


int bitXor(int x, int y)
{
    return x ^ y;
}

int main()
{
	clock_t start = clock();

	FILE *cipher; 
	cipher = fopen("cipher.txt", "r"); // read only  
	
	//ASCII's for LOWERCASE LETTERS ARE 97-122
	//ASCII's for UPPERCASE LETTERS ARE 65-90
	//39 = ' , 44 == , 46 == ., ' ' == 32

	int cipherdig;

	int i,j,k,z = 0;

	int key[3];

	for (i = 97; i <= 122; i++){
		for (j = 97; j <= 122; j++){
			for (k = 97; k <=122; k++){


				key[0] = i;
				key[1] = j;
				key[2] = k;
				printf("key = [%c%c%c]\n",i,j,k);

				while ( fscanf(cipher, "%d", &cipherdig ) == 1 ){

					if (z == 3){
						z = 0;
					}
					
					char c = bitXor(cipherdig, key[z]);
					if ( (97 <= c && c <= 122) || (65 <= c && c <= 90) || (c == 39) || (c == 44) || (c == 46) || (c == 32)){
						printf("%c", c);
					}

					z++;
					//else{
					//	break;
					//}

				}

				rewind(cipher);

				printf("\n\n\n");

			}
		}
	}

	key[0] = 'o';
	key[1] = 'd';
	key[2] = 'g';
	
	printf("key = [%c%c%c]\n",'o','d','g');

	int sum = 0;

	while ( fscanf(cipher, "%d", &cipherdig ) == 1 ){

		if (z == 3){
			z = 0;
		}
		
		char c = bitXor(cipherdig, key[z]);
		printf("%c", c);

		sum = sum + c;

		z++;

	}

	printf("\n\nASCII sum = [%d]\n", sum);

	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("\nfound in %fs\n", time_spent);

}
