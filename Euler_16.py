#2^15 = 32768 and the sum of its digits is 3 + 2 + 7 + 6 + 8 = 26.

#What is the sum of the digits of the number 21000?

string = str(2**1000)
summ = 0

for i in range(0, len(string)):
    summ = summ + int(string[i])

print(summ)
