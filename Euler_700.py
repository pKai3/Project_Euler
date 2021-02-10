"""
Leonhard Euler was born on 15 April 1707.

Consider the sequence 1504170715041707n mod 4503599627370517.

An element of this sequence is defined to be an Eulercoin
if it is strictly smaller than all previously found Eulercoins.

For example, the first term is 1504170715041707 which is the first Eulercoin.
The second term is 3008341430083414 which is greater than 1504170715041707 so is not an Eulercoin.
However, the third term is 8912517754604 which is small enough to be a new Eulercoin.

The sum of the first 2 Eulercoins is therefore 1513083232796311.

Find the sum of all Eulercoins. """

# 1504170715041707*n = x*mod(4503599627370517)

def sum_array(array):
    
    sum = 0
    
    for i in range(0, len(array)):
        sum += array[i]
    return sum

def egcd(a, b):
    x,y, u,v = 0,1, 1,0
    while a != 0:
        q, r = b//a, b%a
        m, n = x-u*q, y-v*q
        b,a, x,y, u,v = a,r, u,v, m,n
    gcd = b
    return gcd, x, y


n=1
i = 0

E = []

while (True):

    valid = True

    E_n = 1504170715041707*n % 4503599627370517

    for j in range(0, len(E)):
        if (E_n > E[j]):
            valid = False
            break

    if (valid == True):
        E.append(E_n)

        print(E[i], sum_array(E), n)
        i += 1


    n += 1
