#Using names.txt (right click and 'Save Link/Target As...'), a 46K text file containing over five-thousand first names, begin by sorting it into alphabetical order. Then working out the alphabetical value for each name, multiply this value by its alphabetical position in the list to obtain a name score.

#For example, when the list is sorted into alphabetical order, COLIN, which is worth 3 + 15 + 12 + 9 + 14 = 53, is the 938th name in the list. So, COLIN would obtain a score of 938 × 53 = 49714.

#What is the total of all the name scores in the file?


with open('Euler_22_names.txt', 'r') as f:
    names = f.read().split(',')
    names = sorted(names)
    del names[0]
    
summ = 0
namesumm=0

for i in range(0, len(names) ):
    for j in range(0, len(names[i]) ):
    
        #letter = names[i][j]
        namesumm = namesumm + (i+1)*( ord(names[i][j]) - 64)
        #namesumm = namesumm + ( ord(names[i][j]) - 64)
        
        
    print(i+1, names[i], namesumm)
    
    summ = summ + namesumm
    namesumm = 0
    
print(summ)
