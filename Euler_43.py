
"""The number, 1406357289, is a 0 to 9 pandigital number because it is made up of each of the digits 0 to 9 in some order, but it also has a rather interesting sub-string divisibility property.

Let d1 be the 1st digit, d2 be the 2nd digit, and so on. In this way, we note the following:

d2d3d4=406 is divisible by 2
d3d4d5=063 is divisible by 3
d4d5d6=635 is divisible by 5
d5d6d7=357 is divisible by 7
d6d7d8=572 is divisible by 11
d7d8d9=728 is divisible by 13
d8d9d10=289 is divisible by 17
Find the sum of all 0 to 9 pandigital numbers with this property."""

#============================================================
    
primes = [2,3,5,7,11,13,17]
summ = 0;
    
import itertools

l = list(itertools.permutations([0, 1, 2, 3, 4, 5, 6, 7, 8, 9]))
l.sort()

for i in range(0,len(l)):
    
    #l[4] = ['1','4','0','6','3','5','7','2','8','9']
    #check = [] #check is one element in l
    #for j in range(0, len(l[i])):
    #    check.append(str(l[i][j]))
    
    sub = [ [],[],[],[],[],[],[] ] #substrings are 3 consequtive digits of check
    for s in range(0, 7): #make seven substrings
        for j in range(s+1, s+4): #each with 3 consecutive digits
           #print(i,j)
           sub[s].append(str(l[i][j]))
    
        sub[s] = int("".join(sub[s]))
        #sub[i] = int(sub[i])
        
    for r in range(0,7):
        if sub[r] % primes[r] != 0:
            break
        if r == 6:
            partial = []
            for k in range(0, len(l[i])):
                partial.append(str(l[i][k]))
            
            summ += int("".join(partial))
            

print(summ, "is the sum of all numbers with the requested property")
    
    
    
        
        
        