/*

If p is the perimeter of a right angle triangle with integral length sides, {a,b,c}, there are exactly three solutions for p = 120.

{20,48,52}, {24,45,51}, {30,40,50}

For which value of p ≤ 1000, is the number of solutions maximised?

*/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	clock_t start = clock();

	int a, b, c, p;
	int m_p;

	int sols, max_sols;

	//p = a+b+c
	//c^2 = a^2 + b^2
	//p = a + b + sqrt(a^2 + b^2)

	max_sols = 0;

	for (p = 1; p <= 1000; p++){
		sols = 0;
		for (a = 1; a < (p-a)/2; a++){
			for (b = a + 1; b < (p-a)/2; b++){
				c = p - a - b;

				if (c*c == a*a + b*b){
					//printf("{%d,%d,%d}\n", a, b, c);
					sols += 1;
				}
				
			}
		}

		if (sols > max_sols){
			max_sols = sols;
			m_p = p;
		}

	}

	printf("\nP = %d, [%d solutions]\n\n", m_p, max_sols);


	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
