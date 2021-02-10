

#The 5-digit number, 16807=7^5, is also a fifth power. Similarly, the 9-digit number, 134217728=8^9, is a ninth power.

#How many n-digit positive integers exist which are also an nth power?


b = 1
n = 1

result = 0
length = 0

found = 0;

while (b < 10):
    while (n < 25):
        result = b**n
        string = str(result)
        length = len(string);

        if ( length == n ):
            found = found + 1
            print('** ', b, '^', n, '=', result, '[', len(string), '] {', found, '}' )


        #else:
            #print(b, '^', n, '=', result, '[', len(string), ']' )


        n = n + 1


    n = 1

    b = b + 1

print(found)




