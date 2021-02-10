"""An irrational decimal fraction is created by concatenating the positive integers:

0.12345678910 1 112131415161718192021...

It can be seen that the 12th digit of the fractional part is 1.

If dn represents the nth digit of the fractional part, find the value of the following expression.

d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000"""

n = 0

s = []

for n in range(1, 1000000):
    s.append(str(n))
    
    if (n % 10000 == 0):
        print(n)

s = ''.join(s)

ans = int(s[0]) * int(s[9]) * int(s[99]) * int(s[999]) * int(s[9999]) * int(s[99999]) * int(s[999999])

print("d1 × d10 × d100 × d1000 × d10000 × d100000 × d1000000 =", ans)