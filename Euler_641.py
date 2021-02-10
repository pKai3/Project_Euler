
#Consider a row of n dice all showing 1.

#First turn every second die,(2,4,6,…), so that the number showing is increased by 1. 
#Then turn every third die. The sixth die will now show a 3. Then turn every fourth die and so on 
#until every nth die (only the last die) is turned. If the die to be turned is showing a 6 then it is changed to show a 1.

#Let f(n) be the number of dice that are showing a 1 when the process finishes. You are given f(100)=2 and f(10^8)=69.

#Find f(10^36).

import numpy

n = 10**4     # number of dice
l = 0

dice = numpy.empty((n, 1))

for i in range(0, n-1):
    dice[i] = 1
    
for s in range(2, n): #every second, third, ... n( - 1)th die
    
    for i in range(0, int(n/s)):
        index = i*s+(s-1)          # index = n / s * i * s + 1 = n * i + 1
        
        #print (s, index)
        
        dice[index] += 1
        
        if dice[index] == 7:
            
            dice[index] = 1
            
    l += 1
    #if l == 3:
        #break

ones = 0

for i in range(0, n):
    if dice [i] == 1:
        ones += 1
        
print(ones, l)

l = 0


#10^2 --> 2

#10^3 --> 3

#10^4 --> 5

#10^5 --> 11

#10^6 --> 19

#10^7 --> ?

#10^8 --> 69