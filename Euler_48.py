
"""The series, 11 + 22 + 33 + ... + 1010 = 10405071317.

Find the last ten digits of the series, 1^1 + 2^2 + 3^3 + ... + 1000^1000."""

summ = 0

for n in range (1, 1001):
	summ += n**n

print("sum :", summ)

print("last 10 : ", end="")

for i in range(len( str(summ) ) - 10, len( str(summ) ) ):
	print(str(summ)[i], end="")
