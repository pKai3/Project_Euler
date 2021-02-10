/*

It is easily proved that no equilateral triangle exists with integral length sides and integral area.
However, the almost equilateral triangle 5-5-6 has an area of 12 square units.

We shall define an almost equilateral triangle to be a triangle for which two sides are equal
and the third differs by no more than one unit.

Find the sum of the perimeters of all almost equilateral triangles with integral side lengths
and area and whose perimeters do not exceed one billion (1,000,000,000).

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

double calcArea(double s, double b){
	return ( (1.0/4.0) * (b) * sqrt( 4*s*s - (b*b) ) );
}

int main(){

	clock_t start = clock();

	int progress = 0; //progress counter faster than monitoring s (double)

	double s, b, Area, sum;
	//two equal sides denoted s
	//differing side denoted b; visualized as base
	// b = s + 1;
	sum = 0;

	for (s = 2; 3*s < 1000000000; s++){ //1000000000

		progress++;
		if (progress % 50000000 == 0) printf("*\n");

		b = s + 1;	//differing side denoted b; visualized as base
		Area = calcArea(s, b);
		// printf("%lf, %lf, %lf\n", s, b, Area);

		if (fabs(Area - (double)round(Area)) < 0.0000001){
			// printf("*\n");
			// printf("%lf, %lf, %lf\n", s, b, Area);
			sum += (2*s + b); //add perimiter to sum
		}

		b = s - 1;	//differing side denoted b; visualized as base
		Area = calcArea(s, b);
		// printf("%lf, %lf, %lf\n", s, b, Area);

		if (fabs(Area - (double)round(Area)) < 0.0000001){
			// printf("*\n");
			// printf("%lf, %lf, %lf\n", s, b, Area);
			sum += (2*s + b); //add perimiter to sum
		}
	}

	printf("%lf\n", sum);

	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
