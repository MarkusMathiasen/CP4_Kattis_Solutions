A = list(map(int, input().split()[1:]))[::-1]
n = len(A)

def P(x):
	res = 0
	for i,a in enumerate(A):
		res += a*x**i
	return res

def fac(n):
	res = 1
	for i in range(1, n+1):
		res *= i
	return res

def choose(n,k):
	return fac(n)//fac(k)//fac(n-k)

res = []

for ti in range(0, n):
	val = 0
	for i in range(0, ti+1):
		c = choose(ti, i)
		b = (-1)**(ti-i)
		p = P(i)
		val += c*b*p
	res.append(str(val))

print(" ".join(res))
