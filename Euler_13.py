#Work out the first ten digits of the sum of the following one-hundred 50-digit numbers.



from numpy import loadtxt

numbers = loadtxt("Euler_13_numbers.txt", comments="#", delimiter="\n", unpack=False)

summ = 0

for i in range(0, len(numbers)):
    summ = summ + numbers[i]

print(summ)
