/*

Three distinct points are plotted at random on a Cartesian plane, for which -1000 ≤ x, y ≤ 1000, such that a triangle is formed.

Consider the following two triangles:

A(-340,495), B(-153,-910), C(835,-947)

X(-175,41), Y(-421,-714), Z(574,-645)

It can be verified that triangle ABC contains the origin, whereas triangle XYZ does not.

Using triangles.txt (right click and 'Save Link/Target As...'),
a 27K text file containing the co-ordinates of one thousand "random" triangles,
find the number of triangles for which the interior contains the origin.

NOTE: The first two examples in the file represent the triangles in the example given above.

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>

#define KNRM  "\x1B[0m"
#define KRED  "\x1B[31m"
#define KGRN  "\x1B[32m"
#define KYEL  "\x1B[33m"
#define KBLU  "\x1B[34m"
#define KMAG  "\x1B[35m"
#define KCYN  "\x1B[36m"
#define KWHT  "\x1B[37m"

double MAX(double x, double y, double z){

	return fmax(x, fmax(y, z) );

	/*if (x >= y && x >= z) 		return x;
	else if (y >= x && y >= z)	return y;
	else 						return z;*/
}

double MIN(double x, double y, double z){

	return fmin(x, fmin(y, z) );

	/*if (x <= y && x <= z) 		return x;
	else if (y <= x && y <= z)	return y;
	else 						return z;*/
}

int inRange(double x, double y, double z){
	if (x <= y && y <= z)		return 1;
	else if (z <= y && y <= x)	return 1;
	else 						return 0;
}

double checkintercept(double intercept, int c1, int c2){

	if (inRange(c1, intercept, c2) == 1) 	return intercept;
	else 									return 0.0/0.0;		//produce a NaN

}

int main()
{
	clock_t start = clock();
/*
	struct pair
	{
		int a, b ;
	}
	struct point
	{
		pair a, b, c ;
	}
	struct triangle
	{
		point a, b ,c ;

	};

	// allocation of memory for n triangles
	triangles = malloc (1000* sizeof(triangle)) ;
*/
	FILE *data;
	data = fopen("Euler_102_points.txt", "r"); // read only

	int dataset[6000];
	int number = 0;
	int i = 0;

	while ( fscanf(data, "%d", &number ) == 1 ){
		dataset[i] = number;
		i++;
	}


	//for (int i = 0; i < 6000; i++){
	//	printf("%d\n", dataset[i]);
	//}

	rewind(data);
	//int z = 0;

	int points[1000][3][2];
	//fscanf(data, "%d", &number );
	for (int i=0; i < 1000; i++){
		for (int j = 0; j < 3; j++){
			for (int k = 0; k < 2; k++){

				if ( fscanf(data, "%d", &number ) == 1 ){
					points[i][j][k] = number;
				}

				//points[i][j][k] = dataset[z]; OR THIS, WORKS TOO
				//z++;
			}
		}
	}

	int found = 0;
	int Ax, Ay, Bx, By, Cx, Cy;


	for (i = 0; i < 1000; i++){

		printf("%s\n", KCYN);

		Ax = points[i][0][0];
		Ay = points[i][0][1];

		Bx = points[i][1][0];
		By = points[i][1][1];

		Cx = points[i][2][0];
		Cy = points[i][2][1];

		double sAB, sAC, sBC;

		printf("\n\n%d: (%d,%d),(%d,%d),(%d,%d)\n",i+1,Ax,Ay,Bx,By,Cx,Cy);
		/*if (Bx - Ax != 0) sAB = (double)(By - Ay)/(double)(Bx - Ax); else sAB = 69;
		if (Cx - Ax != 0) sAC = (double)(Cy - Ay)/(double)(Cx - Ax); else sAC = 69;
		if (Cx - Bx != 0) sBC = (double)(Cy - By)/(double)(Cx - Bx); else sBC = 69;*/

		sAB = (double)(By - Ay)/(double)(Bx - Ax); //get slopes
		sAC = (double)(Cy - Ay)/(double)(Cx - Ax);
		sBC = (double)(Cy - By)/(double)(Cx - Bx);
		printf("[slopes]: %7.2f | %7.2f | %7.2f\n", sAB, sAC, sBC);

		double yAB, yAC, yBC;
		//double x = 0;

		yAB = sAB * -(double)Ax + (double)Ay; //get y ints of lines
			yAB = checkintercept(yAB, Ay, By);
		yAC = sAC * -(double)Ax + (double)Ay;
			yAC = checkintercept(yAC, Ay, Cy);
		yBC = sBC * -(double)Bx + (double)By;
			yBC = checkintercept(yBC, By, Cy);

		printf("[y-ints]: %7.2f | %7.2f | %7.2f\n", yAB, yAC, yBC);

		double xAB, xAC, xBC;
		//double y = 0;

		xAB = ( -(double)Ay/sAB ) + (double)Ax; //get x ints of lines
			xAB = checkintercept(xAB, Ax, Bx);
		xAC = ( -(double)Ay/sAC ) + (double)Ax;
			xAC = checkintercept(xAC, Ax, Cx);
		xBC = ( -(double)By/sBC ) + (double)Bx;
			xBC = checkintercept(xBC, Bx, Cx);

		printf("[x-ints]: %7.2f | %7.2f | %7.2f\n", xAB, xAC, xBC);

		if ( (Ax == 0 && Ay == 0) || (Bx == 0 && By == 0) || (Cx == 0 && Cy == 0) ) { //if a triangle includes the origin as a point
			found++;

			printf("%scontains origin\n", KRED);
		}

		else if ( (MAX(yAB, yAC, yBC) >= 0 && MIN(yAB, yAC, yBC) <= 0) && (MAX(xAB, xAC, xBC) >= 0 && MIN(xAB, xAC, xBC) <= 0) ){
			found++;
			printf("%scontains origin\n", KRED);
		}

		//else printf("no origin\n");

	}

	printf("\n\n%s%d out of 1000 triangles contain the origin\n\n", KMAG, found);

	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("%sfound in %fs\n\n", KNRM, time_spent);

}
