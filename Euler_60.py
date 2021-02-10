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
    return int(f"{a}{b}")

def concat2(a, b):
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

for i in range (0,150):
    lowprimes.append(primes[i])

n = 4 #number of primes to concat
k =[0, 1, 2, 3]
p=list(permutations(k, 2))

q = 0
testprimes = [0,0,0,0]

relations = {}

for i in lowprimes:
    relations[i] = []
    print(i)
    #if i > 999: break
    for j in lowprimes:
        
        if i > j and i in relations[j]: #just some speedup code
            relations[i].append(j)
        else:
            k  = concat2(i,j)
            k2 = concat2(j,i)
            #if k in primes and k2 in primes:
            if is_prime(k) and is_prime(k2):
                relations[i].append(j)

pos = {}

for i in lowprimes:
    if len(relations[i])>4:
        #print(i, relations[i])
        pos[i]=relations[i]

checklist = []
for key in pos:
    checklist.append([key] + list(pos[key]))


for a in checklist:
    for b in checklist:
        for c in checklist:
            for d in checklist:
                if len(set([a[0],b[0],c[0],d[0]])) == 4:
                    if len(set(a).intersection(set(b),set(c),set(d))) == 4:
                        k=[a[0],b[0],c[0],d[0]]
                        print(k, sum(k))
                        #exit()

'''
for i in range(0,len(checklist)):
    for j in range(i,len(checklist)):
        for k in range(j,len(checklist)):
            for l in range(k,len(checklist)):
                if len(set([checklist[i][0],checklist[j][0],checklist[k][0],checklist[l][0]])) == 4:
                    if len(set(checklist[i]).intersection(set(checklist[j]),set(checklist[k]),set(checklist[l]))) == 4:
                        m=[checklist[i][0],checklist[j][0],checklist[k][0],checklist[l][0]]
                        print(m, sum(m))
                        #exit()
'''

#print(possibilities)
        
#now find a set of four that each contain all of the rest




'''
while (True):
    
    
    for i in range (0, n):
        testprimes[i] = primes[q]
        q += 1

    #testprimes = [3, 7, 109, 673]

    for (i,j) in p:
        #print(i,j)
        res = concat(testprimes[i],testprimes[j])
        print(testprimes[i],'+',testprimes[j],'=',res)
        if res not in primes: print('*')
'''

#print(concat(a,b))

print('execution time:', datetime.now() - startTime)
