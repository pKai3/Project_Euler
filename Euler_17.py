"""
If the numbers 1 to 5 are written out in words: 
one, two, three, four, five, then there are 
3 + 3 + 5 + 4 + 4 = 19 letters used in total.

If all the numbers from 1 to 1000 (one thousand) inclusive 
were written out in words, how many letters would be used?


NOTE: Do not count spaces or hyphens. For example, 342 
(three hundred and forty-two) contains 23 letters and 115 
(one hundred and fifteen) contains 20 letters. 
The use of "and" when writing out numbers is in compliance with British usage.
"""

#t thousands x hundred y ten z one
t=x=y=z=c=0

ones = {
  0: "",   
  1: "one",
  2: "two",
  3: "three",
  4: "four",
  5: "five",
  6: "six",
  7: "seven",
  8: "eight",
  9: "nine"
}

tens = {
  0: "",
  1: "ten",
  2: "twenty",
  3: "thirty",
  4: "forty",
  5: "fifty",
  6: "sixty",
  7: "seventy",
  8: "eighty",
  9: "ninety"
}

teens = {
  0: "ten",
  1: "eleven",
  2: "twelve",
  3: "thirteen",
  4: "fourteen",
  5: "fifteen",
  6: "sixteen",
  7: "seventeen",
  8: "eighteen",
  9: "nineteen"
}


#print(n)
#c is count
summ = 0

while t < 1:
    
        c += 1
        z += 1
        
        if z == 10:
            y += 1
            z = 0
            
        if y == 10:
            x += 1
            y = 0
            
        if x == 10:
            t += 1
            x = 0
            
        print(t, x, y, z)
            
        l = []

        if c > 99:
            l.append( ones[x] )
            l.append( 'hundred' )
            if y != 0 or z != 0:
                l.append('and')
       
        if y == 1:
            l.append( teens[z] )
        if y != 1:
            l.append( tens[y] )
            l.append( ones[z] )
        
        s = ''.join(l)
        
        if c == 1000:
            s = 'onethousand'
            
        summ += len(s)
        print(s)

print(summ, "characters used")

            