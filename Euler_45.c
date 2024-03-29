/*

Triangle, pentagonal, and hexagonal numbers are generated by the following formulae:

Triangle	 	Tn=n(n+1)/2	 	1, 3, 6, 10, 15, ...
Pentagonal	 	Pn=n(3n−1)/2	 	1, 5, 12, 22, 35, ...
Hexagonal	 	Hn=n(2n−1)	 	1, 6, 15, 28, 45, ...
It can be verified that T285 = P165 = H143 = 40755.

Find the next triangle number that is also pentagonal and hexagonal.
*/

#include <stdio.h>

long t = 1;
long p = 1;
long h = 1;

long tn = 1;
long pn = 1;
long hn = 1;


int main()
{


	for (t = 1; t <= 100000; t++){

		tn = t*(t+1)/2;

		for (p = 1; p <= 100000; p++){

			pn = p*(3*p-1)/2;

			if (pn > tn){
				break;
			}

			else if (pn < tn){
				//continue
			}

			else { //pn == tn; check h, hn

				for (h = 1; h <= 100000; h++){

					hn = h*(2*h-1);

					if (hn > pn){
						break;
					}

					else if (hn < pn){
						//continue
					}

					else{
						printf("%ld: t(%ld), p(%ld), h(%ld)\n", hn, t, p, h);
					}


				}

			}


		}

	}


}
