/*
By listing the first six prime numbers: 2, 3, 5, 7, 11, and 13, we can see that the 6th prime is 13.

What is the 10 001st prime number?
*/

#include <stdio.h>

int main()
{
	int n, c, t, p;
	
	printf("\nenter target: ");
	scanf("%d", &t);

	c = p = 0;
	n = 2;

	while (p < t) 
	{

		for (c = 2; c <= n; c++)
		{
			if (n % c == 0)
				break;
		}

		if (c == n) 
		{
			p = p + 1;
			printf("%d, %d \n", n, p);
		}

	n = n + 1;
	}

}
