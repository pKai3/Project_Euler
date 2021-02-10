"""A perfect number is a number for which the sum of its proper divisors is exactly equal to the number. 
For example, the sum of the proper divisors of 28 would be 1 + 2 + 4 + 7 + 14 = 28, which means that 28 is a perfect number.

A number n is called deficient if the sum of its proper divisors is less than n and it is called abundant if this sum exceeds n.

As 12 is the smallest abundant number, 1 + 2 + 3 + 4 + 6 = 16, the smallest number that can be written as the sum of two 
abundant numbers is 24. By mathematical analysis, it can be shown that all integers greater than 28123 can be written as 
the sum of two abundant numbers. However, this upper limit cannot be reduced any further by analysis even though it is known 
that the greatest number that cannot be expressed as the sum of two abundant numbers is less than this limit.

Find the sum of all the positive integers which cannot be written as the sum of two abundant numbers."""

import time

def abundancy(n):
    summ = 0
    for i in range(1, int(n/2)+1 ):
        if n % i == 0:
            #print(i)
            summ += i
    
    if summ > n:
        return 1
    if summ == n:
        return 0
    if summ < n:
        return -1
    
    
l = []
print("finding abundant numbers below 29000")
for n in range(0, 29000):
    
    #print(n, abundancy(n))
    if abundancy(n) == 1:
        l.append(n)


s = []
print("finding all possible abundant number sums below 28500")
for a in range(len(l) - 1, -1, -1):
    for b in range(0, len(l) - 1):
        
        r = l[a]+ l[b]
        
        if r < 28500:
        
            s.append(r) 

 
s.sort()

s = list(set(s))

print("finding all numbers which cannot be expressed as a sum of abundant numbers")

time.sleep(3)

summ = 0
for k in range(0, 28450):
    
    found = 0
    for i in range(0, len(s) - 1):
    
        if k == s[i]:
            found = 1
            break

    if found == 0:
        print(k)
        summ += k

print("sum =", summ)







    