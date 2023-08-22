C = [1]*5001
for i in range(5000):
	C[i+1] = C[i] * (4*i+2) // (i+2)

T = int(input())
for _ in range(T):
	n = int(input())
	print(C[n])

