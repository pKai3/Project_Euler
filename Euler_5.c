/*
2520 is the smallest number that can be divided by each of the numbers from 1 to 10 without any remainder.

What is the smallest positive number that is evenly divisible by all of the numbers from 1 to 20?
*/

#include <stdio.h>

int main(){

	long t = 1;
	int n = 1;
	int d = 20;
	int largestn = 0;


	while (1){

		if (t % n == 0){
			if (n > largestn) {
				largestn = n;
			    printf("%ld_%d\n", t, n); 
			}
			n++;
			//printf("*");
		}
		else{
			t++;
			n = 1;
			//printf("^");
		}
		if (n > d){
			printf("%ld\n", t);
			break;
		}
		//printf("%ld_%d\n", t, n);
	}

}
