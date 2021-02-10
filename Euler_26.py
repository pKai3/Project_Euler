"""A unit fraction contains 1 in the numerator. The decimal representation of the unit fractions with denominators 2 to 10 are given:

1/2 =   0.5
1/3 =   0.(3)
1/4 =   0.25
1/5 =   0.2
1/6 =   0.1(6)
1/7 =   0.(142857)
1/8 =   0.125
1/9 =   0.(1)
1/10    =   0.1
Where 0.1(6) means 0.166666..., and has a 1-digit recurring cycle. It can be seen that 1/7 has a 6-digit recurring cycle.

Find the value of d < 1000 for which 1/d contains the longest recurring cycle in its decimal fraction part."""


def longestRepeatedSubstring(str): 
  
    n = len(str) 
    LCSRe = [[0 for x in range(n + 1)]  
                for y in range(n + 1)] 
  
    res = "" # To store result 
    res_length = 0 # To store length of result 
  
    # building table in bottom-up manner 
    index = 0
    for i in range(1, n + 1): 
        for j in range(i + 1, n + 1): 
              
            # (j-i) > LCSRe[i-1][j-1] to remove 
            # overlapping 
            if (str[i - 1] == str[j - 1] and
                LCSRe[i - 1][j - 1] < (j - i)): 
                LCSRe[i][j] = LCSRe[i - 1][j - 1] + 1
  
                # updating maximum length of the 
                # substring and updating the finishing 
                # index of the suffix 
                if (LCSRe[i][j] > res_length): 
                    res_length = LCSRe[i][j] 
                    index = max(i, index) 
                  
            else: 
                LCSRe[i][j] = 0
  
    # If we have non-empty result, then insert  
    # all characters from first character to  
    # last character of string 
    if (res_length > 0): 
        for i in range(index - res_length + 1, 
                                    index + 1): 
            res = res + str[i - 1] 
  
    #print('length=', res_length)
    return res



from decimal import *

getcontext().prec = 2000

l = []

for d in range(1, 1000):

    r = str(Decimal(1)/Decimal(d))
    l.append(r)

#segment = '0.142857142857142857142857142857'
longestsegments = []


'''
segment = l[983]

while (len(segment) > 0):

    last_segment = segment
    segment = longestRepeatedSubstring(segment)

print(last_segment)
'''

for i in range(0, len(l)):

    segment = l[i]

    while (len(segment) > 0):

        last_segment = segment
        segment = longestRepeatedSubstring(segment)

    #print(last_segment)
    longestsegments.append(last_segment)


d = 0
curlength = 0
longest = 0

for i in range(0, len(l) - 1):
    curlength = len(longestsegments[i])
    
    if (curlength > longest):
        longest = curlength
        d = i+1

for i in range(0, len(l)):
    print(i+1, l[i], longestsegments[i])


print('d with longest repeating substring of digits is', d)