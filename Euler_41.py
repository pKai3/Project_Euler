"""We shall say that an n-digit number is pandigital if it makes use of all the digits 1 to n exactly once. For example, 2143 is a 4-digit pandigital and is also prime.

What is the largest n-digit pandigital prime that exists?"""



def isPrime(n):

    if (n == 1):
        return 0
    
    if (n == 2):
       return 1
    
    if (n == 3):
       return 1
    
    if (n % 2 == 0):
       return 0
    
    if (n % 3 == 0):
       return 0
    

    i = 5
    w = 2

    while (i * i <= n):
        if (n % i == 0):
           return 0
        

        i += w
        w = 6 - w

    

    return (1)

#---------------------------------------------------------------------------

import itertools
import time

toPermute = []

for counter in range(1, 10):
    
    toPermute.append(counter)
    
    print("permuting", toPermute)
    time.sleep(1)

    
    l = []
    
    #l = list(itertools.permutations([1, 2, 3, 4, 5, 6, 7, 8, 9]))
    l = list(itertools.permutations(toPermute))
    
    
    l.sort()
    
    
    for i in range(0, len(l)):
        
        check = []
        
        for j in range(0, len(l[i])):
            check.append(str(l[i][j]))
    
        
        check = "".join(check)
        check = int(check)
            
        if (isPrime(check) == 1):
            print(check)
