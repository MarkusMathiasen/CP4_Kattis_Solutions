fact = [1]
for i in range(1, 51):
	fact.append(fact[-1]*i)

import sys

for line in sys.stdin:
	n,k = map(int, line.split())
	A = list(range(1, n+1))
	while n > 0:
		n -= 1
		idx = k // fact[n]
		k %= fact[n]
		print(A[idx], end=" ")
		del A[idx]
	print()
