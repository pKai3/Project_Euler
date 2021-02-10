#A googol (10^100) is a massive number: one followed by one-hundred zeros; 
#100^100 is almost unimaginably large: one followed by two-hundred zeros. 
#Despite their size, the sum of the digits in each number is only 1.

#Considering natural numbers of the form, a^b, where a, b < 100, what is the maximum digital sum?

maxsum = 0

for a in range(0, 101):
    for b in range(0,101):
        result = str(a**b)
        summ = 0
        for i in range(0, len(result)):
            summ += int(result[i])
            
        if summ > maxsum:
            maxsum = summ
            
print(maxsum)