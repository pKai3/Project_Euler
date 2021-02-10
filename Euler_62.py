#!/usr/bin/env python3
# -*- coding: utf-8 -*-
"""
The cube, 41063625 (345^3), can be permuted to produce two other cubes: 56623104 (384^3) and 66430125 (405^3). 
In fact, 41063625 is the smallest cube which has exactly three permutations of its digits which are also cube.

Find the smallest cube for which exactly five permutations of its digits are cube.
"""

import itertools

#for n in range (100, 99999):
"""
n = 345

nc = n**3

n_s = str(nc)
    
toPermute = []
    
for i in range(0, len(n_s)):
    toPermute.append(n_s[i])
    
l = []

l = list(itertools.permutations(toPermute))
l.append([n, list(itertools.permutations(toPermute))])


k = [1,[3, 4, 5]]
"""


l = []

for n in range(0, 350):
    
    nc = n**3
    nc_s = str(nc)
     
    toPermute = []

    for i in range(0, len(nc_s)):
        toPermute.append(nc_s[i])
    
    l.append( [ n, nc, list(itertools.permutations(toPermute)) ] )