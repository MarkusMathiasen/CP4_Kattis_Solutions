import math
m,n,t = map(int, input().split())

def fac(n):
	res = 1
	for j in range(2, n+1):
		if res > m:
			break
		res *= j
	return res

if t == 7:
	res = n <= m
elif t == 6:
	res = n*math.log2(n) <= m
elif 3 <= t and t <= 5:
	res = n**(7-t) <= m
elif t == 2:
	res = n <= math.log2(m)
elif t == 1:
	res = fac(n) <= m
print("AC" if res else "TLE")

