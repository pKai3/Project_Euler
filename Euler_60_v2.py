'''

The primes 3, 7, 109, and 673, are quite remarkable. By taking any two primes and concatenating them
in any order the result will always be prime. For example, taking 7 and 109, both 7109 and 1097 are prime.
The sum of these four primes, 792, represents the lowest sum for a set of four primes with this property.

Find the lowest sum for a set of five primes for which any two primes concatenate to produce another prime.

'''

def is_prime(n):
    """"pre-condition: n is a nonnegative integer
    post-condition: return True if n is prime and False otherwise."""
    if n < 2:
         return False;
    if n % 2 == 0:
         return n == 2  # return False
    k = 3
    while k*k <= n:
         if n % k == 0:
             return False
         k += 2
    return True

def concat(a, b):
    c = b
    while (c > 0): 
        a *= 10
        c = c // 10
    
    return a + b

from datetime import datetime
startTime = datetime.now()

from itertools import count, permutations
count()

def genprimes(n):
    """ Returns a list of primes < n """
    sieve = [True] * n
    for i in range(3,int(n**0.5)+1,2):
        if sieve[i]:
            sieve[i*i::2*i]=[False]*((n-i*i-1)//(2*i)+1)
    return [2] + [i for i in range(3,n,2) if sieve[i]]

primes = genprimes(1000000)
lowprimes=[]

for i in range (0,10000):
    lowprimes.append(primes[i])
    if primes[i] > 8500: break #8500: break

relations = {}

for i in lowprimes:
    relations[i] = []
    print(i)
    #if i > 999: break
    for j in lowprimes:
        
        if i > j and i in relations[j]: #just some speedup code
            relations[i].append(j)
        else:
            k  = concat(i,j)
            k2 = concat(j,i)
            #if k in primes and k2 in primes:
            if is_prime(k) == True and is_prime(k2) == True:
                relations[i].append(j)

pos = {}

for i in lowprimes:
    if len(relations[i])>4:
        print(i, relations[i])
        pos[i]=relations[i]

checklist = []
for key in pos:
    checklist.append([key] + list(pos[key]))

for aind, a in enumerate(checklist):
    
    for bind, b in enumerate(checklist[aind+1:]):
        if len(set([a[0],b[0]])) == 2: #unique
            if len(set(a).intersection(set(b))) >= 5:
                print([a[0],b[0]])
                
                for cind, c in enumerate(checklist[bind+1:]):
                    if len(set([a[0],b[0],c[0]])) == 3: #unique
                        if len(set(a).intersection(set(b),set(c))) >= 5:
                            print([a[0],b[0],c[0]])
                            
                            for dind, d in enumerate(checklist[cind+1:]):
                                if len(set([a[0],b[0],c[0],d[0]])) == 4: #unique
                                    if len(set(a).intersection(set(b),set(c),set(d))) >= 5:
                                        print([a[0],b[0],c[0],d[0]])
                                        
                                        for eind, e in enumerate(checklist[dind+1:]):
                                            if len(set([a[0],b[0],c[0],d[0],e[0]])) == 5: #unique
                                                if len(set(a).intersection(set(b),set(c),set(d),set(e))) >= 5:
                                                    
                                                    m=[a[0],b[0],c[0],d[0],e[0]]
                                                    print(m, sum(m))
                                                    exit()
            




print('execution time:', datetime.now() - startTime)
