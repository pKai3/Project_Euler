"""

It is easily proved that no equilateral triangle exists with integral length sides and integral area.
However, the almost equilateral triangle 5-5-6 has an area of 12 square units.

We shall define an almost equilateral triangle to be a triangle for which two sides are equal
and the third differs by no more than one unit.

Find the summ of the perimeters of all almost equilateral triangles with integral side lengths
and area and whose perimeters do not exceed one billion (1,000,000,000).

"""

import math
from decimal import *

getcontext().prec = 50


def calcArea(s, b):

	check = 4*s*s - (b*b)
	root = math.sqrt( 4*s*s - (b*b))
	
	if (root**2 == check):
		return 1
	else:
		return 0


def newCalcArea(s, b):
	x = (2*s+b)/2

	area = math.sqrt( x * (x-s)**2 * (x-b) )
	
	#if (area==int(area)):
	#	print(s,s,b,area)

	return area

progress = 0 #progress counter faster than monitoring s (double)

s=0
b=0
Area=0
summ=0

#two equal sides denoted s
#differing side denoted b; visualized as base
#b = s + 1;

#for s in range(2, 1000000000): #1000000000

target = 1000000000
s = 2
while True:
	
	s += 1
	
	progress += 1

	if (progress % 5000000 == 0):
		print("*")

	b = s + 1	#differing side denoted b; visualized as base
	perim = 2*s + b

	if (perim > target):
		break	

	Area = newCalcArea(s, b)

	if (Area == int(Area)):
		# printf("*");
		
		summ += perim #add perimiter to summ
		print(s,s,b,'area:',Area,int(Area), 'perimiter sum:', summ)
			
		#print(s, b, perim)

	b = s - 1	#differing side denoted b; visualized as base
	perim = 2*s + b
	
	if (perim > target):
		break

	Area = newCalcArea(s, b)

	if (Area == int(Area)):
		#printf("*\n");

		summ += perim; #add perimiter to summ
		print(s,s,b,'area:',Area,int(Area), 'perimiter sum:', summ)

			
		#print(s, b, perim)

print('sum of perimiters:',summ)
