#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
It is possible to show that the square root of two can be expressed as an infinite continued fraction.

√ 2 = 1 + 1/(2 + 1/(2 + 1/(2 + ... ))) = 1.414213...

By expanding this for the first four iterations, we get:

1 + 1/2 = 3/2 = 1.5
1 + 1/(2 + 1/2) = 7/5 = 1.4
1 + 1/(2 + 1/(2 + 1/2)) = 17/12 = 1.41666...
1 + 1/(2 + 1/(2 + 1/(2 + 1/2))) = 41/29 = 1.41379...

The next three expansions are 99/70, 239/169, and 577/408, but the eighth expansion, 1393/985, 
is the first example where the number of digits in the numerator exceeds the number of digits in the denominator.

In the first one-thousand expansions, how many fractions contain a numerator with more digits than denominator?

"""

frac = []

from decimal import *

getcontext().prec = 25

depth = 10

def divide(depth, target):
    global frac
    if depth == target:
        return 0
    
    print("*", depth)
    return( Decimal(1/(2 + divide(depth + 1, target) ) ) )
    frac.append(( Decimal(1/(2 + divide(depth + 1, target) ) ) ))
    frac.append(divide(depth+1, target))



def fact(n):
    
    if n > 1:
        return n*fact(n-1)
    else:
        return 1

#frac = 1 + divide(0, 5)

frac_s = []

divide(0, 10)

"""
for i in range(0, 1000):
    frac.append( Decimal(1 + divide(0, i) ))
    frac_s.append(str(Decimal(1 + divide(0, i) )))
    
diff = []
diff_s = []

for i in range(0, len(frac)):
    diff.append(frac[i+1] -frac[i] )
    diff_s.append(str(frac[i+1] -frac[i] ) )"""