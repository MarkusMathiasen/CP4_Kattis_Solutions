from fractions import Fraction
n = int(input())
A = list(map(int, input().split()))

def to_frac(A):
	if len(A) == 1:
		return A[0]
	return A[0] + Fraction(1, to_frac(A[1:]))

res = to_frac(A)
print(str(res.numerator)+"/"+str(res.denominator))
