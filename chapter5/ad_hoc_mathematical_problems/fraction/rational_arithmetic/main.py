from fractions import Fraction
n = int(input())
for _ in range(n):
	line = input().split()
	x1, y1 = map(int, line[:2])
	f1 = Fraction(x1, y1)
	x2, y2 = map(int, line[3:])
	f2 = Fraction(x2, y2)
	if line[2] == "+":
		res = f1 + f2
	elif line[2] == "-":
		res = f1 - f2
	elif line[2] == "*":
		res = f1 * f2
	else:
		res = f1 / f2
	print(str(res.numerator)+" / "+str(res.denominator))
