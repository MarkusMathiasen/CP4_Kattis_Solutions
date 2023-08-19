import sys

def gcd(a, b):
	if a == 0: return b
	return gcd(b%a, a)

def lcm(a, b):
	return a//gcd(a, b)*b

for line in sys.stdin:
	A = list(map(int, line.split()))
	if len(A) == 0:
		break
	res = 1
	for x in A:
		res = lcm(res, x)
	print(res)
