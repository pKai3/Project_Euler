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

def egcd(a, b):
    x,y, u,v = 0,1, 1,0
    while a != 0:
        q, r = b//a, b%a
        m, n = x-u*q, y-v*q
        b,a, x,y, u,v = a,r, u,v, m,n
    gcd = b
    return gcd, x, y

def modinv(a, m):
    g, x, y = egcd(a, m)
    if g != 1:
        raise Exception('modular inverse does not exist')
    else:
        return x % m


from datetime import datetime
startTime = datetime.now()


coin1 = 1504170715041707
modi  = 4503599627370517

gen  = modinv(coin1, modi)

coins = []

coin = 1
lastind = 2^300
for coin in range(1, 20000000):
    ind = (coin * gen) % modi
    
    if (lastind>ind) or (coin==1):
        lastind = ind
        print(coin, ind)
        coins.append((coin, ind))

lastind = 1
ind = 1

lastcoin = 2*1504170715041707

while (True):

    coin = 1504170715041707*ind % 4503599627370517
    #print(coin, ind)

    if (coin < lastcoin):
        lastcoin = coin
        if ((coin,ind) not in coins):
            coins.append((coin,ind))
            print(coin, ind)

        else:
            break
        
    ind += 1


coins.sort(key=lambda x:x[1])

coinsum = 0
for i in range (0, len(coins)):
    coinsum += coins[i][0]

print(coins)

print("sum of coins =", coinsum)


print('execution time:', datetime.now() - startTime)
