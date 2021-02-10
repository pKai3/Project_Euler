/*
A segment is uniquely defined by its two endpoints.
By considering two line segments in plane geometry there are three possibilities:
the segments have zero points, one point, or infinitely many points in common.

Moreover when two segments have exactly one point in common it might be the case that that common point
is an endpoint of either one of the segments or of both. If a common point of two segments is not an endpoint
of either of the segments it is an interior point of both segments.

We will call a common point T of two segments L1 and L2 a true intersection point of L1 and L2 if T is the only
common point of L1 and L2 and T is an interior point of both segments.

Consider the three segments L1, L2, and L3:

L1: (27, 44) to (12, 32)
L2: (46, 53) to (17, 62)
L3: (46, 70) to (22, 40)

It can be verified that line segments L2 and L3 have a true intersection point.
We note that as the one of the end points of L3: (22,40) lies on L1 this is not considered to be a true point of intersection.
L1 and L2 have no common point. So among the three line segments, we find one true intersection point.

Now let us do the same for 5000 line segments.
To this end, we generate 20000 numbers using the so-called "Blum Blum Shub" pseudo-random number generator.

s0 = 290797

sn+1 = sn×sn (modulo 50515093)

tn = sn (modulo 500)

To create each line segment, we use four consecutive numbers tn. That is, the first line segment is given by:

(t1, t2) to (t3, t4)

The first four numbers computed according to the above generator should be: 27, 144, 12 and 232. The first segment would thus be (27,144) to (12,232).

How many distinct true intersection points are found among the 5000 line segments?
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <time.h>
#include <stdbool.h>

struct Point {

	int x;
	int y;

};

struct Segment {

	struct Point P1, P2;

};

int max(int a, int b){
	if (a > b) return a;
	else return b;
}

int min(int a, int b){
	if (a < b) return a;
	else return b;
}

// Given three colinear points p, q, r, the function checks if
// point q lies on line segment 'pr'
bool onSegment(struct Point p, struct Point q, struct Point r)
{
    if (q.x < max(p.x, r.x) && q.x > min(p.x, r.x) &&
        q.y < max(p.y, r.y) && q.y > min(p.y, r.y))
       return true;

    return false;
}

int orientation(struct Point p, struct Point q, struct Point r) {
    // See https://www.geeksforgeeks.org/orientation-3-ordered-points/
    // for details of below formula.
    int val = (q.y - p.y) * (r.x - q.x) -
              (q.x - p.x) * (r.y - q.y);

    if (val == 0) return 0;  // colinear

    return (val > 0) ? 1 : 2; // clock or counterclock wise
}

bool doIntersect(struct Segment s1, struct Segment s2){

	struct Point p1 = s1.P1;
	struct Point q1 = s1.P2;

	struct Point p2 = s2.P1;
	struct Point q2 = s2.P2;

    // Find the four orientations needed for general and special cases
	int o1 = orientation(p1, q1, p2);
	int o2 = orientation(p1, q1, q2);
	int o3 = orientation(p2, q2, p1);
	int o4 = orientation(p2, q2, q1);

    // General case
    if (o1 != o2 && o3 != o4) // if segments have intersection
										// proceed to check if endpoint is the intersection point
        return true;

    // Special Cases
    // p1, q1 and p2 are colinear and p2 lies on segment p1q1
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;

    // p1, q1 and q2 are colinear and q2 lies on segment p1q1
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;

    // p2, q2 and p1 are colinear and p1 lies on segment p2q2
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;

     // p2, q2 and q1 are colinear and q1 lies on segment p2q2
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;

    return false; // Doesn't fall in any of the above cases
}

int main(){

	clock_t start = clock();

	struct doublePoint {

		double x;
		double y;

	};

	struct Intersection {

		struct doublePoint P;

		int Seg1; //record indices of intersected line segments
		int Seg2;

	};

	int generated[20000];
	long long sn = 290797;

	int i = 0;

	/*
	s0 = 290797

	sn+1 = sn×sn (modulo 50515093)

	tn = sn (modulo 500)
	*/

	for(i = 0; i < 20000; i++){

		sn = (sn * sn) % 50515093;

		//printf("%llu\n", sn);
		generated[i] = sn % 500;

	}

	// for (i = 0; i < 20; i++){
	// 	printf("%d\n", generated[i]);
	// }

	struct Segment LS[5000];

	for(i = 0; i < 20000; i = i+4){

		LS[i/4].P1.x = generated[i];
		LS[i/4].P1.y = generated[i+1];
		LS[i/4].P2.x = generated[i+2];
		LS[i/4].P2.y = generated[i+3];

	}

	int testnums[] = {27,44,12,32,46,53,17,62,46,70,22,40};

	for(i = 0; i < 12; i = i+4){

		LS[i/4].P1.x = testnums[i];
		LS[i/4].P1.y = testnums[i+1];
		LS[i/4].P2.x = testnums[i+2];
		LS[i/4].P2.y = testnums[i+3];

	}

	// L1: (27, 44) to (12, 32)
	// L2: (46, 53) to (17, 62)
	// L3: (46, 70) to (22, 40)

	for(i = 0; i < 3; i++){

		printf( "SEG:%d\n", i+1);
	   printf( "X1 : %d\n", LS[i].P1.x);
	   printf( "Y1 : %d\n", LS[i].P1.y);
	   printf( "X2 : %d\n", LS[i].P2.x);
	   printf( "Y2 : %d\n", LS[i].P2.y);

	}

	struct Intersection INTR[20000];

	long Intersections = 0;

		 i = 0; //current line
	int j = 0; //checking line
	int num = 3;

	for (i = 0; i < num; i++){
		for (j = i; j < num; j++){
			if (i != j){
				printf("Seg%d on Seg%d? : ", i+1,j+1);
				doIntersect(LS[i], LS[j]) ? printf("Yes: %ld\n", ++Intersections) : printf("No\n");
			}
		}
	}


	clock_t end = clock();
	double time_spent = (double)(end - start) / CLOCKS_PER_SEC;
	printf("found in %fs\n", time_spent);

}
