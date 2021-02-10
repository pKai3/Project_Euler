
"""The Fibonacci sequence is defined by the recurrence relation:

Fn = Fn−1 + Fn−2, where F1 = 1 and F2 = 1.
It turns out that F541, which contains 113 digits, is the first Fibonacci number for which the last nine digits are 1-9 pandigital 
(contain all the digits 1 to 9, but not necessarily in order). And F2749, which contains 575 digits, is the first Fibonacci number for 
which the first nine digits are 1-9 pandigital.

Given that Fk is the first Fibonacci number for which the first nine digits AND the last nine digits are 1-9 pandigital, find k."""



t=0
a = 0
b = 1

term = 0

found = 0


while (found == 0):

    digs = ["1", "2", "3", "4", "5", "6", "7", "8", "9"]

    fdigs = []
    ldigs = []
    
    a += b
    a, b = b, a
    
    f_s = str(a)
     
    start = 10
    stop = len(f_s) - 10
    # Remove charactes from index 10 to len(f_s) - 10
    if len(f_s) > stop :
        f_s = f_s[0: start:] + f_s[stop + 1::]
    
    '''f_s = list(str(a))


    if len(f_s) > 100:.
        i=0
        repeats = len(f_s) - 25
        while i < repeats:
            del f_s[12]
    
    f_s = str(f_s)'''
        
    term += 1
    
    if term % 1000 == 0:
        print(term)
    
    if len(f_s) >= 18:
        for i in range(0, 9):
            fdigs.append( f_s[i] )
            ldigs.append( f_s[len(f_s) - 1 - i] )

        fdigs = set(fdigs)
        ldigs = set(ldigs)
        digs = set(digs)

        #if (digs == fdigs == ldigs):
        #    print(f, term)
        #   found = 1
        if (digs == ldigs and digs == fdigs):
            print(a, term)
            found = 1


