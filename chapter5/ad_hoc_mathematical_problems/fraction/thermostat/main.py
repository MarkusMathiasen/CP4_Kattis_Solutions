from fractions import Fraction
n,q = map(int, input().split())
A = []
for i in range(n):
	x,y = map(int, input().split())
	A.append((x,y))

def to_cel(x, i):
	val = 0
	one = Fraction(100, A[i][1] - A[i][0])
	val += (x-A[i][0])*one
	return val

def from_cel(x, i):
	val = A[i][0]
	one = Fraction(A[i][1]-A[i][0], 100)
	val += x*one
	return val

for i in range(q):
	x,y,v = map(int, input().split())
	x -= 1
	y -= 1
	cel = to_cel(v, x)
	res = from_cel(cel, y)
	print(str(res.numerator)+"/"+str(res.denominator))
